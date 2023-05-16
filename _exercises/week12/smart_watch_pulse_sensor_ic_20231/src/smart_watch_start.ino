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
enum State { Heart, Clock, Weather };
State currentState = Weather;

// TODO
void getNextState() {
    switch (currentState) {
        case Weather:
            currentState = Heart;
            break;
        case Heart:
            currentState = Clock;
            break;
        case Clock:
            currentState = Weather;
            break;
    }
}

// TODO
void loadNextScreen() {
    switch (currentState) {
        case Weather:
            runWeatherScreen();
            break;
        case Heart:
            runHeartScreen();
            break;
        case Clock:
            runClockScreen();
            break;
    }
}

// TODO
void runHeartScreen() {
    // for debugging
    // Serial.println("Heart");
    // oled.clear(PAGE);  // Clear the display
    // oled.setCursor(0, 0);
    // oled.print("Heart");
    // oled.display();

    // we want to the OLED updates to be much less frequent than the HR
    // measuring
    unsigned long curMillis = millis();

    if (curMillis - prevScreenUpdateMillis > HEART_SCREEN_UPDATE_MS) {
        prevScreenUpdateMillis = curMillis;
        if (beatAvg > LOW_BPM_THRESHOLD && beatAvg < HIGH_BPM_THRESHOLD) {
            oled.clear(PAGE);
            oled.drawBitmap(heart16x12);
            oled.setFontType(1);
            oled.setCursor(20, 0);
            oled.print(String(beatAvg));
            // don't do display yet
        } else {  // invalid BPM
            oled.clear(PAGE);
            oled.drawBitmap(heart16x12);
            oled.setFontType(1);
            oled.setCursor(20, 0);
            oled.print("---");
        }
        // how to show battery level?
        /* for reference, these are approximates level of battery power

    Charging ( V > 4.3)
    Full Charge (V >=4.2
    Nominal (4.2 > V > 3.5)
    Low/Needs Recharge (3.5 > V >= 3.4)
    Critical (3.4 > V)

        */
        float voltage = analogRead(BATT) *
                        0.0011224;  // this tells us the current battery level
        oled.setCursor(0, 40);
        oled.setFontType(0);
        oled.print("Batt: " + String(voltage));
        oled.display();
        Serial.println("BeatAvg: " + String(beatAvg));
    }
}

// TODO
void runClockScreen() {
    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis > TIME_SCREEN_UPDATE_MS) {
        prevScreenUpdateMillis = curMillis;

        String dateFormat = "%b %d";
        String dayFormat = "%a";
        String timeFormat = "%I:%M";
        String secondsFormat = "%S";
        // String timeFormat = "%I:%M ";
        // for debugging
        Serial.println("Time");

        oled.clear(PAGE);  // Clear the display
        oled.drawBitmap(clock_16x12);

        oled.setCursor(25, 0);
        oled.setFontType(0);
        oled.print(Time.format(dateFormat));

        oled.setCursor(25, 10);
        oled.setFontType(0);
        oled.print(Time.format(dayFormat));

        oled.setFontType(1);
        oled.setCursor(0, 25);
        oled.print(Time.format(timeFormat));

        oled.setFontType(0);
        oled.setCursor(50, 30);
        oled.print(Time.format(secondsFormat));

        oled.display();
    }
}

// TODO
void runWeatherScreen() {
    // for debugging
    // Serial.println("Weather");
    // oled.clear(PAGE);  // Clear the display
    // oled.setCursor(0, 0);
    // oled.print("Weather");
    // oled.display();
    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis > WEATHER_SCREEN_UPDATE_MS) {
        prevScreenUpdateMillis = curMillis;
        Particle.publish("weatherstack", "");  // use your own
    }
    // we pretend that the data is already here
    oled.clear(PAGE);
    /*
    weather
    rain: 296, 302, 308
    snowing: 227
    sunny is the default / else
    */
    switch (weatherCode) {
        case 296:
        case 302:
        case 308:
            oled.drawBitmap(weather_rainy_up_left);
            break;
        case 227:
            oled.drawBitmap(weather_snowing_up_left);
            break;
        default:
            oled.drawBitmap(weather_sunny_up_left);
            break;
    }
    oled.setCursor(38, 5);
    oled.setFontType(1);
    oled.print(tempWeather, 0);
    oled.setFontType(0);
    oled.print("o");  // this makes it like the degree symbol

    oled.setCursor(0, 28);
    weatherDescription = "Moderate rain at times"; //just for testing
    oled.print(weatherDescription.substring(0,9));

    oled.setCursor(0, 40);
    oled.print("Hum " + String(humidity) + "%");

    oled.setCursor(40, 40);
    oled.print("UV " + String(uvIndex));
    oled.display();

    /*
    float tempWeather = 0;
    String city = "city";
    String weatherDescription = "desc";
    int weatherCode = 0;
    int humidity = 0;
    int uvIndex = 0;*/
}

#include "JsonParserGeneratorRK.h"

/*
{
   "request":{
      "type":"Zipcode",
      "query":"90089",
      "language":"en",
      "unit":"f"
      },
   "location":{
      "name":"Los Angeles",
      "country":"USA",
      "region":"California",
      "lat":"34.018",
      "lon":"-118.284",
      "timezone_id":"America\/Los_Angeles",
      "localtime":"2023-03-22 13:27",
      "localtime_epoch":1679491620,
      "utc_offset":"-7.0"
   },
   "current":{
      "observation_time":"08:27 PM",
      "temperature":54,
      "weather_code":296,
      "weather_icons":[
         "https:\/\/cdn.worldweatheronline.com\/images\/wsymbols01_png_64\/wsymbol_0017_cloudy_with_light_rain.png"
      ],
      "weather_descriptions":[
         "Light Rain"
      ],
      "wind_speed":4,
      "wind_degree":80,
      "wind_dir":"E",
      "pressure":1018,
      "precip":0,
      "humidity":80,
      "cloudcover":100,
      "feelslike":52,
      "uv_index":3,
      "visibility":6,
      "is_day":"yes"
   }
}
*/
// sample code
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
        //    Serial.println(jsonParser.getBuffer());
        Serial.println();

        // city, weather descript, temperature, humidity
        tempWeather = jsonParser.getReference()
                          .key("current")
                          .key("temperature")
                          .valueInt();
        humidity =
            jsonParser.getReference().key("current").key("humidity").valueInt();
        weatherCode = jsonParser.getReference()
                          .key("current")
                          .key("weather_ccode")
                          .valueInt();
        uvIndex =
            jsonParser.getReference().key("current").key("uv_index").valueInt();
        weatherDescription = jsonParser.getReference()
                                 .key("current")
                                 .key("weather_descriptions")
                                 .index(0)
                                 .valueString();
        Serial.println(jsonParser.getBuffer());
    }
}

void setup() {
    Time.beginDST();
    Time.zone(-8);
    analogRead(pulseSignalPin);
    Serial.begin(115200);
    Serial.println("Initializing...");

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
    Particle.publish("weatherstack", "");  // use your own
    Particle.subscribe("hook-response/weatherstack", myHandler, MY_DEVICES);
}

void loop() {
    int currentButtonVal = digitalRead(PIN_BUTTON);
    if (currentButtonVal == HIGH && prevReading == LOW) {  // buttonpress
        getNextState();
    }
    // we want to measure the current HR as often as possible
    PulseSensorAmped.process();  // this is measuring / sampling the HR
    loadNextScreen();
    prevReading = currentButtonVal;
}
/* =================================================
   ================================================= */
//////////////////////////
// HEART RATE FUNCTIONS //
//////////////////////////

void PulseSensorAmped_data(int BPM, int IBI) {
    // this is called AUTOMATICALLY for us
    // it has the current HR as measured by the sensor, as its
    //  first function parameter
    beatAvg = BPM;
}

void PulseSensorAmped_lost(void) {}
