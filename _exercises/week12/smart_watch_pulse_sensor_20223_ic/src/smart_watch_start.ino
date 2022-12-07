/* NOTE - Rob Parke
4/14/2022
    -Adding Weatherstack API / JSON

9/25/2021
    -Updated version for Qwiic I2C OLED + MAX30101
    -Eliminated software timers

8/29/2022
    -updated to use pulse sensor
    note from Bill Siever: Most of the real work is done by interrupts.  The
process() is needed to do the callbacks to user code (triggers the call to
either PulseSensorAmped_data() or PulseSensorAmped_lost ()).  If you’d want to
try to catch an individual beat, it should be called faster than the expected
heart rate (maybe 2x faster….So maybe 6x per second or ~166ms?) .  If you just
want occasional updates, you can call it less frequently.

*/

// libraries for OLED
#include <PulseSensorAmped.h>

#include "JsonParserGeneratorRK.h"
#include "SparkFunMicroOLED.h"  // Include MicroOLED library
#include "bitmaps_watch.h"
#include "bitmaps_weather.h"

JsonParser jsonParser;

const int pulseSignalPin = A4;

int beatAvg;
//////////////////////////
// Heart Screen         //
//////////////////////////
/* refreshing the OLED is very slow and it causes
    the heart rate detection to fail
    This delay was determined experimentally to work well
*/
unsigned long prevScreenUpdateMillis = 0;
unsigned long HEART_SCREEN_UPDATE_MS = 3000;
unsigned long lastRead = 0;
unsigned long samples = 0;

const int LOW_BPM_THRESHOLD = 40;
const int HIGH_BPM_THRESHOLD = 200;

//////////////////////////
// Time  Screen         //
//////////////////////////
/*
 */
unsigned long TIME_SCREEN_UPDATE_MS = 500;

//////////////////////////
// Weather Screen         //
//////////////////////////
/* Weatherstack only has 250 API calls in free plan so use
   very long delay (8 times per day)
*/
unsigned long WEATHER_SCREEN_UPDATE_MS = 10512000;
float tempWeather = 0;
String city = "city";
String weatherDescription = "desc";
int weatherCode = 0;
int humidity = 0;
int uvIndex = 0;

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
// The library assumes a reset pin is necessary. The Qwiic OLED has RST
// hard-wired, so pick an arbitrarty IO pin that is not being used
#define PIN_RESET 9

// The DC_JUMPER is the I2C Address Select jumper. Set to 1 if the jumper is
// open (Default), or set to 0 if it's closed.
#define DC_JUMPER 1
MicroOLED oled(MODE_I2C, PIN_RESET, DC_JUMPER);  // I2C declaration
#include <Wire.h>
//////////////////////////
// Button Variables     //
//////////////////////////
const int PIN_BUTTON = D3;
int prevReading = HIGH;     // the last VERIFIED state
int curButtonState;         // the current VERIFIED state
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 200;   // the debounce time; increase if the output
//////////////////////////
// States               //
//////////////////////////
// TODO: create state enum and variable(s) to track state
enum State { Clock, Weather, Heart };
State currentState = Weather;

// TODO
void getNextState() {
    switch (currentState) {
        case Clock:
            currentState = Weather;
            break;
        case Weather:
            currentState = Heart;
            break;
        case Heart:
            currentState = Clock;
            break;
    }
}

// TODO
void loadNextScreen() {
    switch (currentState) {
        case Clock:
            runTimeScreen();
            break;
        case Weather:
            runWeatherScreen();
            break;
        case Heart:
            runHeartScreen();
            break;
    }
}

/* goal: have the HR detection always running, but the screen showing the HR
   only update every so often
*/
void runHeartScreen() {
    // for debugging
    Serial.println("Heart " + String(beatAvg));
    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis >
        HEART_SCREEN_UPDATE_MS) {  // now redraw
        prevScreenUpdateMillis = curMillis;
        // if the BPM is valid, then display a heart icon and the BPM
        // else display the heart icon and either blank or "---"
        // ignore the temp and battery for now
        if (beatAvg >= LOW_BPM_THRESHOLD &&
            beatAvg <= HIGH_BPM_THRESHOLD)  // valid beat
        {
            oled.clear(PAGE);
            oled.drawBitmap(heart16x12);
            oled.setFontType(1);
            oled.setCursor(20, 0);
            oled.print(String(beatAvg));
        } else {  // invalid
            oled.clear(PAGE);
            oled.drawBitmap(heart16x12);
            oled.setFontType(1);
            oled.setCursor(20, 0);
            oled.print("---");
        }

        // show battery
        float voltage = analogRead(BATT) * 0.0011224;  // from documentation
        oled.setCursor(0, 20);
        oled.setFontType(0);
        oled.print("Batt: " + String(voltage, 1));
        oled.display();

        /* possible battery levels

    Charging ( V > 4.3)
    Full Charge (V >=4.2
    Nominal (4.2 > V > 3.5)
    Low/Needs Recharge (3.5 > V >= 3.4)
    Critical (3.4 > V)
*/
    }
}

// TODO
void runTimeScreen() {
    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis > TIME_SCREEN_UPDATE_MS) {  // 30 sec
        prevScreenUpdateMillis = curMillis;

        String dateFormat = "%a %d";  // Thu 14
        String timeFormat = "%I:%M";  // 05:56
        String secondsFormat = "%S";
        // String timeFormat = "%I:%M ";
        // for debugging
        Serial.println("Time");

        oled.clear(PAGE);  // Clear the display
        delay(10);
        oled.drawBitmap(clock_16x12);

        oled.setCursor(25, 0);
        oled.setFontType(0);
        oled.print(Time.format(dateFormat));

        oled.setFontType(1);
        oled.setCursor(0, 25);
        oled.print(Time.format(timeFormat));

        oled.setFontType(0);
        oled.setCursor(50, 30);
        oled.print(Time.format(secondsFormat));

        oled.display();
    }
}

void myHandler(const char *event, const char *data) {
    // Part 1 allows for webhook responses to be delivered in multple "chunks";
    // you don't need to change this
    int responseIndex = 0;
    const char *slashOffset = strrchr(event, '/');
    if (slashOffset) responseIndex = atoi(slashOffset + 1);
    if (responseIndex == 0) jsonParser.clear();
    jsonParser.addString(data);

    // Part 2 is where you can parse the actual data; you code goes in the IF
    if (jsonParser.parse()) {
        /****** YOUR PARSING CODE GOES HERE ********/
        tempWeather = jsonParser.getReference()
                          .key("current")
                          .key("temperature")
                          .valueDouble();
        weatherCode = jsonParser.getReference()
                          .key("current")
                          .key("weather_code")
                          .valueInt();
        uvIndex =
            jsonParser.getReference().key("current").key("uv_index").valueInt();
        humidity =
            jsonParser.getReference().key("current").key("humidity").valueInt();
        weatherDescription = jsonParser.getReference()
                                 .key("current")
                                 .key("weather_descriptions")
                                 .index(0)
                                 .valueString();
        Serial.println("Weather Desc: " + weatherDescription);
    }
}

// TODO
void runWeatherScreen() {
    // for debugging
    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis > WEATHER_SCREEN_UPDATE_MS) {
        Serial.println("Weather");
        Particle.publish("WeatherStackJSON", "90089", PRIVATE);
    }
    // draw weather info on screen
    // first draw graphic
    oled.clear(PAGE);
    switch (weatherCode) {
        case 296:  // when you have "case #" without a break, it's like each
                   // case
                   //  acts like an OR
        case 302:
        case 308:
            oled.drawBitmap(weather_rainy_up_left);
            break;
        case 116:
        case 119:
        case 122:
            oled.drawBitmap(weather_cloudy_up_left);
            break;
        default:  // this is like ELSE
            oled.drawBitmap(weather_sunny_up_left);
            break;
    }
    oled.setCursor(38, 5);
    oled.setFontType(1);
    oled.print(tempWeather, 0);  // 0 decimal places
    // to show the degree symbol
    oled.setFontType(0);
    oled.print("o");

    oled.setFontType(0);
    oled.setCursor(0, 20);
    oled.print(weatherDescription.substring(0,9));

    oled.setCursor(0, 40);
    oled.print("Hum ");
    oled.print(humidity);
    oled.print("%");

    oled.setCursor(40, 40);
    oled.print("UV ");
    oled.print(uvIndex);

    oled.display();
}

void setup() {
    Serial.begin(115200);
    Serial.println("Initializing...");

    // for time
    Time.zone(-8);  // pacific time
    // Time.beginDST();
    PulseSensorAmped.attach(pulseSignalPin);
    PulseSensorAmped.start();

    // initialize OLED
    oled.begin();      // Initialize the OLED
    oled.clear(PAGE);  // Clear the display
    oled.drawBitmap(trojan_bmp);
    oled.display();
    delay(1000);  // Delay 1000 ms
    oled.drawBitmap(usc_bmp);
    oled.display();
    delay(1000);  // Delay 1000 ms

    pinMode(PIN_BUTTON, INPUT);

    Particle.publish("WeatherStackJSON", "90089", PRIVATE);

    Particle.subscribe("hook-response/WeatherStackJSON", myHandler, MY_DEVICES);
}

void loop() {
    PulseSensorAmped.process();  // Joelle FTW!
    int curReading = digitalRead(PIN_BUTTON);
    if (curReading == HIGH && prevReading == LOW) {
        // this means buttons was pressed and we shoudl change state
        getNextState();
    }
    loadNextScreen();
    prevReading = curReading;
}
/* =================================================
   ================================================= */
//////////////////////////
// HEART RATE FUNCTIONS //
//////////////////////////

void PulseSensorAmped_data(int BPM, int IBI) {
    // beatAvg is OUR global variable for HR
    // BPM is the parameter from our HR sensor for the current HR
    beatAvg = BPM;
}

void PulseSensorAmped_lost(void) {}
