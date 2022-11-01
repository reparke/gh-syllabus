/*  Wiring

  OLED
  ----
    MicroOLED -------------  Argon
      GND ------------------- GND
      VDD ------------------- 3.3V (VCC)
      SDA ------------------- SDA
      SCL ------------------- SCL


Ultrasonic Sensor
    Trigger: D3
    Echo: D2

*/
#include "SparkFunMicroOLED.h"  // Include MicroOLED library

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
#define PIN_RESET 9
// The DC_JUMPER is the I2C Address Select jumper. Set to 1 if the jumper is
// open (Default), or set to 0 if it's closed.
#define DC_JUMPER 1

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
MicroOLED oled(MODE_I2C, PIN_RESET, DC_JUMPER);  // I2C declaration

//////////////////////////
// Ultrasonic Distance  //
//////////////////////////

/*
    Connect the ultrasonic distance sensor
    Using the serial monitor, display
        Error message when out of range
        Warning message when less than 5 inches
        Distance message otherwise

*/
const int PIN_ECHO = D3;
const int PIN_TRIGGER = D2;

int MAX_RANGE_CM = 78;
int MIN_RANGE_CM = 5;
double SOUND_CM_FAHR = 0.0344;

void setup() {
    Serial.begin(9600);  // begin serial communication with the computer
    oled.begin();        // Initialize the OLED
    oled.clear(ALL);     // Clear the display's internal memory
    oled.display();      // Display what's in the buffer (splashscreen)
    delay(1000);         // Delay 1000 ms

    pinMode(PIN_TRIGGER, OUTPUT);  // speaker
    pinMode(PIN_ECHO, INPUT);      // mix
}

/********************************************************************************/
void loop() {
    // start trigger
    digitalWrite(PIN_TRIGGER, LOW);  // preparing
    delayMicroseconds(2);
    digitalWrite(PIN_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIGGER, LOW);

    // now sensor is sending 8 quick pulses

    int roundTriptime = pulseIn(PIN_ECHO, HIGH);

    double distCm = roundTriptime * SOUND_CM_FAHR / 2;
    // dist = rate  * time

    if (distCm >= 0 && distCm < MIN_RANGE_CM) {
        Serial.println("You're too close!");
    } else if (distCm >= MIN_RANGE_CM && distCm < MAX_RANGE_CM) {
        Serial.println("The distance is " + String(distCm));
    } else {
        Serial.println("Out of range");
    }
}
