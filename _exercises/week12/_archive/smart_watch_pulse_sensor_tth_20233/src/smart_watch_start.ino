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

// these need to go first
#define ARDUINOJSON_ENABLE_ARDUINO_STRING 1
#include <ArduinoJson.h>
#include <PulseSensorAmped.h>

#include "SparkFunMicroOLED.h"  // Include MicroOLED library
#include "bitmaps_watch.h"
#include "bitmaps_weather.h"

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

const int LOW_BPM_THRESHOLD = 40;
const int HIGH_BPM_THRESHOLD = 200;

//////////////////////////
// Clock  Screen         //
//////////////////////////
/*
 */
unsigned long CLOCK_SCREEN_UPDATE_MS = 500;

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
int prevButtonVal = HIGH;  // the last VERIFIED state

//////////////////////////
// States               //
//////////////////////////
// TODO: create state enum and variable(s) to track state
enum State { Clock, Weather, Heart };
State currentState = Heart;

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
            runClockScreen();
            break;
        case Heart:
            runHeartScreen();
            break;
        case Weather:
            runWeatherScreen();
            break;
    }
}

// TODO
void runHeartScreen() {
    // should we track the HR all the time, or only when the Heart screen is
    // shown? track all the time: the BPM will be instantly visible when on
    // Heart screen track ONLY on Heart screen: if you don't need, then you
    // wasting battery AND slower

    // how OFTEN should update the screen?
    //  OLED IS SLOOOOOOOOOOW!
    //  if order to keep the device "responsive" AND save battery life,
    //           we should update the screen as INFREQUENTLY as we can
    // approach 1: update only when BPM changes
    // approach 2: just update rgularly with millis

    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis > HEART_SCREEN_UPDATE_MS) {
        prevScreenUpdateMillis = curMillis;

        oled.clear(PAGE);
        oled.drawBitmap(heart16x12);
        oled.setFontType(1);
        oled.setCursor(20, 0);
        if (beatAvg < LOW_BPM_THRESHOLD || beatAvg > HIGH_BPM_THRESHOLD) {
            oled.print("---");  // invalid
        } else {
            oled.print(String(beatAvg));
        }

        // calc batt life
        float voltage = analogRead(BATT) * 0.0011224;
        oled.setCursor(0, 40);
        oled.setFontType(0);
        oled.print("Batt: ");
        oled.print(String(voltage, 1));
        oled.display();
    }
}
/*
    estimate of battery life

    Charging ( V > 4.3)
    Full Charge (V >=4.2
    Nominal (4.2 > V > 3.5)
    Low/Needs Recharge (3.5 > V >= 3.4)
    Critical (3.4 > V)

*/

// TODO
void runClockScreen() {
    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis > CLOCK_SCREEN_UPDATE_MS) {
        prevScreenUpdateMillis = curMillis;
        oled.clear(PAGE);
        oled.drawBitmap(clock_16x12);

        oled.setCursor(25, 0);
        oled.print(Time.format("%h %d"));

        String dayFormat = "%a";
        oled.setCursor(25, 10);
        oled.print(Time.format(dayFormat));

        String timeFormat = "%I:%M:%S";
        oled.setCursor(0, 25);
        oled.print(Time.format(timeFormat));
        oled.display();
    }
}

// TODO
void runWeatherScreen() {
    /*
        code: 119, 116, 122 -> load the cloudy bitmap (weather_cloudy_up_left)
        code: 296 -> load rain bitmap
        otherwise, just load sunny bitmap

        step 1: just focus on the temperature and description
            add the code from before to connect the API

        step 2: then try to add the weather code and uv index
            this will require editing the "response template" in the webhook
       integration
    */
    // step 2 webhook - publish
    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis > WEATHER_SCREEN_UPDATE_MS) {
        prevScreenUpdateMillis = curMillis;
        String data = String(10);
        // Trigger the integration
        Particle.publish("WeatherStackJSON", data, PRIVATE);
    }
    oled.clear(PAGE);
    switch (weatherCode) {
        case 119:  // with swtich, we can mimic "OR" by not having break
        case 116:
        case 122:
            oled.drawBitmap(weather_cloudy_up_left);
            break;
        case 296:
            oled.drawBitmap(weather_rainy_up_left);
            break;
        default:
            oled.drawBitmap(weather_sunny_up_left);
            break;
    }

    oled.setCursor(38, 0);
    oled.print(String(tempWeather,0));

    oled.setCursor(0, 28);
    oled.print(weatherDescription.substring(0,9));

    oled.display();
}

void setup() {
    /*
https://community.particle.io/t/pulse-sensor-amped-incompatible-with-os-5-3-0/64313/4?u=rob7
*/
    analogRead(pulseSignalPin);  // bug workaround

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
    Time.zone(-8);  // GMT -8
    // Time.beginDST();      // we are in ST

    // webhook integration step 1
    Particle.subscribe("hook-response/WeatherStackJSON", myHandler, MY_DEVICES);

    //initial publish to trigger weather webhook
    String data = String(10);
    // Trigger the integration
    Particle.publish("WeatherStackJSON", data, PRIVATE);
}
// this function will be called when a response come back from weather stack
void myHandler(const char *event, const char *data) {
    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, data);

    if (error) {
        Serial.print(F("deserializeJson() failed: "));
        return;
    }
    // update global variables
    tempWeather = doc["temperature"];
    weatherDescription = String(doc["description"]);
    weatherCode = doc["weather_code"];
}

void loop() {
    int curButtonVal = digitalRead(PIN_BUTTON);

    // where do we load / update the OLED screen?

    if (curButtonVal == LOW && prevButtonVal == HIGH) {
        // button was pressed
        getNextState();
    }
    // the screen needs to be updated constantly because the data may change
    // constantly
    PulseSensorAmped.process();
    loadNextScreen();
    prevButtonVal = curButtonVal;
}
/* =================================================
   ================================================= */
//////////////////////////
// HEART RATE FUNCTIONS //
//////////////////////////

// this is an event handler...we DONT call it, it gets called AUTOMATICALLY
// this is asychronous
void PulseSensorAmped_data(int BPM, int IBI) { beatAvg = BPM; }

void PulseSensorAmped_lost(void) {}

/*
    s
*/