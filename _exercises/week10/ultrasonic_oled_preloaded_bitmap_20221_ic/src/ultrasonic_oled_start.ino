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
#include "bitmaps_symbols.h"
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
const int PIN_ECHO = D2;
const int PIN_TRIGGER = D3;

// sensor reports time
// speed of sound is 343 m/s
const double SPEED_OF_SOUND_CM = 0.0343;
const int MAX_RANGE = 78;
const int MIN_RANGE = 0;
const int WARNING_RANGE = 5;

void setup() {
    Serial.begin(9600);  // begin serial communication with the computer
    oled.begin();        // Initialize the OLED
    oled.clear(ALL);     // Clear the display's internal memory
    oled.drawBitmap(itp348_bitmap);
    oled.display();  // Display what's in the buffer (splashscreen)
    delay(1000);     // Delay 1000 ms

    // TODO: configure ultrasonic pins
    pinMode(PIN_ECHO, INPUT);
    pinMode(PIN_TRIGGER, OUTPUT);
}

/********************************************************************************/
void loop() {
    // startup sequence
    digitalWrite(PIN_TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(PIN_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIGGER, LOW);
    // at this point, the sensor sends its pulses

    // listening
    int time = pulseIn(PIN_ECHO, HIGH);  // echo pin goes HIGH when pulse go
                                         // out, LOW when reflection back

    double distCm = time * SPEED_OF_SOUND_CM / 2;  // round trip time

    // Serial.println("Distance: " + String(distCm, 2));
    if (distCm < MIN_RANGE || distCm > MAX_RANGE) {
        Serial.print("out of range: " + String(distCm, 2) + " cm");
        oled.clear(PAGE);  // Clear the display
        oled.drawBitmap(no_bmp);
        // oled.setFontType(0);   // Switch to the large-number font
        // oled.setCursor(40, 0);  // Set the cursor to top-left
        // oled.print("Out of range");
        oled.display();  // Update the display
    } else if (distCm > MIN_RANGE && distCm < WARNING_RANGE) {
        Serial.print("Warning: " + String(distCm, 2) + " cm");
        oled.clear(PAGE);  // Clear the display
        oled.drawBitmap(warning_bmp_320x240);
        oled.setFontType(0);    // Switch to the large-number font
        oled.setCursor(0, 40);  // Set the cursor to top-left
        oled.print(String(distCm, 2) + " cm");
        oled.display();  // Update the display
    } else {
        Serial.print("OK distance: " + String(distCm, 2) + " cm");
        oled.clear(PAGE);  // Clear the display
        oled.drawBitmap(yes_bmp_320x240);
        oled.setFontType(0);    // Switch to the large-number font
        oled.setCursor(0, 40);  // Set the cursor to top-left
        oled.print(String(distCm, 2) + " cm");
        oled.display();  // Update the display
    }
    Serial.println();
    delay(500);  // sensor needs a pause in between reads
}
