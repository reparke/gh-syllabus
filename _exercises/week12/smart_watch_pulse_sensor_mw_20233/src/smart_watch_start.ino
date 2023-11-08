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
unsigned long lastRead = 0;
unsigned long samples = 0;

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
State currentState = Heart;

// TODO
void getNextState() {
    switch (currentState) {
        case Heart:
            currentState = Clock;
            break;
        case Clock:
            currentState = Weather;
            break;
        case Weather:
            currentState = Heart;
            break;
    }
}

// TODO
void loadNextScreen() {
    switch (currentState) {
        case Heart:
            runHeartScreen();
            break;
        case Weather:
            runWeatherScreen();
            break;
        case Clock:
            runClockScreen();
            break;
    }
}

// TODO
void runHeartScreen() {
    // redrawing the OLED screen takes a long time
    // sometimes, it takes so long that it interferes with checking BPM
    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis > HEART_SCREEN_UPDATE_MS) {
        oled.clear(PAGE);
        oled.drawBitmap(heart16x12);
        oled.setFontType(1);
        oled.setCursor(20, 0);
        if (beatAvg > HIGH_BPM_THRESHOLD || beatAvg < LOW_BPM_THRESHOLD) {
            // invalid
            oled.print("---");
        } else {
            // valid
            oled.print(String(beatAvg));
        }
        //show battery
        float voltage = analogRead(BATT) * 0.0011224;
        oled.setCursor(0,40);
        oled.setFontType(0);
        oled.print("Batt: ");
        oled.print(String(voltage, 1));
        oled.display();
    }

    /*

    Charging ( V > 4.3)
    Full Charge (V >=4.2
    Nominal (4.2 > V > 3.5)
    Low/Needs Recharge (3.5 > V >= 3.4)
    Critical (3.4 > V)
*/
}

// TODO
void runClockScreen() {
    // for debugging
    Serial.println("Clock");
    oled.clear(PAGE);  // Clear the display
    oled.setCursor(0, 0);
    oled.print("Clock");
    oled.display();
}

// TODO
void runWeatherScreen() {
    // for debugging
    Serial.println("Weather");
    oled.clear(PAGE);  // Clear the display
    oled.setCursor(0, 0);
    oled.print("Weather");
    oled.display();
}

void setup() {
    /*
https://community.particle.io/t/pulse-sensor-amped-incompatible-with-os-5-3-0/64313/4?u=rob7
*/
    analogRead(pulseSignalPin);  // bug workaround

    Serial.begin(9600);
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
}

void loop() {
    // build a latch button so we can move between the three screens
    curButtonState = digitalRead(PIN_BUTTON);
    if (curButtonState == LOW && prevReading == HIGH) {
        getNextState();
        // we can't load the screen ONLY when the button is pressed
    }
    // we actually need to load the screen constanly
    // check HR here
    PulseSensorAmped.process();  // read current HR

    loadNextScreen();  // this will "redraw" or refresh the data on the OLED
    prevReading = curButtonState;
}
/* =================================================
   ================================================= */
//////////////////////////
// HEART RATE FUNCTIONS //
//////////////////////////
// this function is called AUTOMATICALLY, and it receives
//  as parameters the current BPM
void PulseSensorAmped_data(int BPM, int IBI) {
    // track the amount and take average
    // see if this is different than current, then update
    beatAvg = BPM;  // this takes new BPM and stores in our global var
}

void PulseSensorAmped_lost(void) {}
