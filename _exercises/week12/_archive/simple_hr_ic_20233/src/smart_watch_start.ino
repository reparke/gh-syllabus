
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

// TODO
void getNextState() {}

// TODO
void loadNextScreen() {}

// TODO
void runHeartScreen() {
    // for debugging
    Serial.println("Heart");
    oled.clear(PAGE);  // Clear the display
    oled.setCursor(0, 0);
    oled.print("Heart");
    oled.display();
}

// TODO
void runTimeScreen() {
    // for debugging
    Serial.println("Time");
    oled.clear(PAGE);  // Clear the display
    oled.setCursor(0, 0);
    oled.print("Time");
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
}

void loop() {}
/* =================================================
   ================================================= */
//////////////////////////
// HEART RATE FUNCTIONS //
//////////////////////////

void PulseSensorAmped_data(int BPM, int IBI) {}

void PulseSensorAmped_lost(void) {}
