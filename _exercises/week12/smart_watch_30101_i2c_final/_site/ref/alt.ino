/* refs:
  Heart rate monitor
  https://create.arduino.cc/projecthub/SurtrTech/measure-heart-rate-and-spo2-with-max30102-c2b4d8

  C++ time
  http://www.cplusplus.com/reference/ctime/strftime/

  Timezones
  https://greenwichmeantime.com/time-zone/definition/

  Heart rate algorithm
  https://github.com/sparkfun/MAX30105_Breakout
  It is best to attach the sensor to your finger using a rubber band or other
  tightening device. Humans are generally bad at applying constant pressure to a
  thing. When you press your finger against the sensor it varies enough to cause
  the blood in your finger to flow differently which causes the sensor readings
  to go wonky.

*/

/*  Wiring
MicroOLED --------------- Argon
  GND ------------------- GND
  VCC ------------------- 3.3V
  SDA (blue) ------------ SDA
  SCL (yellow) ---------- SCL

Button: D3

Switch:
  Pin 1 -- GND
  Pin 2 -- EN
*/
// libraries for MAX30101
#include <Wire.h>

#include "MAX30105.h"
#include "heartRate.h"

// libraries for OLED
#include "SparkFunMicroOLED.h"  // Include MicroOLED library
#include "bitmaps_watch.h"
#include "bitmaps_weather.h"

//////////////////////////
// MAX30101 Definition  //
//////////////////////////
MAX30105 heartRateSensor;

//////////////////////////
// Heart Rate Variables //
//////////////////////////
int heartRateReadMs = 25;                          // for timer
Timer heartReadTimer(heartRateReadMs, updateBPM);  // for updateing beats

const byte RATE_SIZE = 4;  // Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE];     // Array of heart rates
byte rateSpot = 0;
long lastBeat = 0;  // Time at which the last beat occurred

float beatsPerMinute;
int beatAvg;

const int LOW_BPM_THRESHOLD = 40;
const int LOW_IR_THRESHOLD = 50000;
long irValue = 0;

float tempF;

//////////////////////////
// Heart Screen         //
//////////////////////////
/* refreshing the OLED is very slow and it causes
    the heart rate detection to fail
    This delay was determined experimentally to work well
*/
unsigned long prevHeartScreenUpdateMillis = 0;
unsigned long HEART_SCREEN_UPDATE_MS = 3000;

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

// const int PIN_OLED_DC = A0;   // Connect DC to pin 5 (required for SPI)
// const int PIN_OLED_RST = A1;  // Connect RST to pin 6
// const int PIN_OLED_CS = A2;   // Connect CS to pin A2 (required for SPI)
// MicroOLED oled(MODE_SPI, PIN_OLED_RST, PIN_OLED_DC, PIN_OLED_CS);

//////////////////////////
// Time  Variables      //
//////////////////////////
const float TIMEZONE = -8;  // PST

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
// need to build this
enum State { HEART, TIME, WEATHER };
State currentState = HEART;

void getNextState() {
    switch (currentState) {
        case HEART:
            currentState = TIME;
            break;
        case TIME:
            currentState = WEATHER;
            break;
        case WEATHER:
            currentState = HEART;
            break;
    }
}
void loadNextScreen() {
    switch (currentState) {
        case HEART:
            runHeartScreen();
            break;
        case TIME:
            runTimeScreen();
            break;
        case WEATHER:
            runWeatherScreen();
            break;
    }
}
void setup() {
    Time.zone(TIMEZONE);
    Time.beginDST();

    Serial.begin(9600);
    Serial.println("Initializing MAX30105...");

    // Initialize MAX30105sensor
    if (!heartRateSensor.begin(
            Wire, I2C_SPEED_FAST)) {  // Use default I2C port, 400kHz speed
        Serial.println("MAX30105 was not found. Check wiring/power. ");
        while (1)
            ;
    }
    heartRateSensor.setup();  // Configure sensor with default settings
    heartRateSensor.setPulseAmplitudeRed(
        0x0A);  // Turn Red LED to low to indicate sensor is running
    heartRateSensor.setPulseAmplitudeGreen(0);  // Turn off Green LED
    heartRateSensor.enableDIETEMPRDY();

    // heartReadTimer.start();  // start recurring timer to read heart rate
    // sensor

    // initialize OLED
    oled.begin();      // Initialize the OLED
    oled.clear(PAGE);  // Clear the display
    oled.drawBitmap(trojan_bmp);
    oled.display();
    delay(1000);  // Delay 1000 ms
    oled.drawBitmap(usc_bmp);
    oled.display();
    delay(1000);  // Delay 1000 ms

    // initialize button
    pinMode(PIN_BUTTON, INPUT);
}

/*
    Calculate most recent heart BPM
        calcBeatAvg()
    If heart rate is above a threshold
        Display BPM
    Else display ---
    Display body temperature

*/
void runHeartScreen() {
    // for debugging
    // Serial.println("Heart");
    // oled.clear(PAGE);  // Clear the display
    // oled.print("Heart");
    // oled.display();

    // unsigned long curMillis = millis();
    // if (curMillis - prevHeartScreenUpdateMillis > HEART_SCREEN_UPDATE_MS) {
    //     prevHeartScreenUpdateMillis = curMillis;
    for (int i = 0; i < 40; i++) {
        updateBPM();
        Serial.print(".");
    }
    Serial.println();
    calcHeartBeatAvg();  // this is slow! -- beatAvg
    if (beatAvg > LOW_BPM_THRESHOLD && irValue > LOW_IR_THRESHOLD) {  // VALID!
        oled.clear(PAGE);
        oled.drawBitmap(heart16x12);
        oled.setFontType(1);
        oled.setCursor(20, 0);
        oled.print(String(beatAvg));
    } else {
        // INVALID!
        oled.clear(PAGE);
        oled.drawBitmap(heart16x12);
        oled.setFontType(1);
        oled.setCursor(20, 0);
        oled.print("---");
    }
    tempF = heartRateSensor.readTemperatureF();
    oled.setCursor(0, 20);
    oled.print("Temp ");
    oled.print(String(tempF, 0));
    oled.display();
    Serial.print("BPM: " + String(beatsPerMinute) +
                 ", Avg: " + String(beatAvg));
    Serial.println(", IRvalue: " + String(irValue) +
                   ", Temp: " + String(tempF));
    // }
}

void runTimeScreen() {
    unsigned long curMillis = millis();
    if (curMillis - prevHeartScreenUpdateMillis > HEART_SCREEN_UPDATE_MS) {
        prevHeartScreenUpdateMillis = curMillis;

        String dateFormat = "%a %d";
        // String timeFormat = "%I:%M:%S";
        String timeFormat = "%I:%M ";
        // for debugging
        Serial.println("Time");

        oled.clear(PAGE);  // Clear the display
        oled.drawBitmap(clock_16x12);

        oled.setCursor(20, 0);
        oled.setFontType(0);
        oled.print(Time.format(dateFormat));

        oled.setFontType(1);
        oled.setCursor(0, 20);
        oled.print(Time.format(timeFormat));

        oled.display();
    }
}
void runWeatherScreen() {
    unsigned long curMillis = millis();
    if (curMillis - prevHeartScreenUpdateMillis > HEART_SCREEN_UPDATE_MS) {
        prevHeartScreenUpdateMillis = curMillis;

        // for debugging
        Serial.println("Weather");
        // testing variables -- replace with JSON values later
        float tempWeather = 74.24;
        String city = "Los Angeles";

        oled.clear(PAGE);  // Clear the display
        oled.drawBitmap(weather_sunny_16x12);

        oled.setCursor(32, 5);
        oled.setFontType(1);
        oled.print(tempWeather, 0);

        oled.setFontType(0);
        oled.setCursor(0, 30);
        oled.print(city);

        oled.display();
    }
}
void loop() {
    int curReading = digitalRead(PIN_BUTTON);  // check button read
    unsigned long currentDebounceTime = millis();

    if (curReading != prevReading) {
        lastDebounceTime = millis();
    }

    // debounce delay often 50-200 ms
    // we check for stable signal
    if ((currentDebounceTime - lastDebounceTime) > debounceDelay) {
        // we know we have stable signal
        // see if input has changed
        if (curReading != curButtonState) {
            curButtonState = curReading;
            // legit button press so update current button state
            if (curButtonState == LOW) {
                getNextState();  // button was pressed down, we should change
                prevHeartScreenUpdateMillis =
                    0;  // make sure next screen loads immediately instead of
                        // waiting
            }

            // FINALLY! here is your button code
            // if want to execute when button pressed down ONLY
        }
    }
    loadNextScreen();
    prevReading = curReading;  // update for next loop
}

/* ====================== HEART RATE FUNCTIONS ===============
  These functions are completed and shouldn't be modified
*/
/* fn: updateBPM
This function is called by timer. It needs to execute
quickly otherwise sensor won't properly register beats
and BPM will be off
*/
void updateBPM() {
    irValue = heartRateSensor.getIR();

    if (checkForBeat(irValue) == true) {
        // We sensed a beat!
        long delta = millis() - lastBeat;
        lastBeat = millis();

        beatsPerMinute = 60 / (delta / 1000.0);

        if (beatsPerMinute < 255 && beatsPerMinute > 20) {
            rates[rateSpot++] =
                (byte)beatsPerMinute;  // Store this reading in the array
            rateSpot %= RATE_SIZE;     // Wrap variable
        }
    }
}

/* fn: calcHeartBeatAvg
This function is slow so it should be done during display
 NOT during timer reading of heart rate
*/
void calcHeartBeatAvg() {
    beatAvg = 0;
    for (byte x = 0; x < RATE_SIZE; x++) {
        beatAvg += rates[x];
    }
    beatAvg /= RATE_SIZE;
}
