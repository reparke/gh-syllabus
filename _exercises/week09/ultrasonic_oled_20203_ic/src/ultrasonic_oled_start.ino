/*  Wiring

  OLED
  ----
    MicroOLED ------------- Argon
    GND ------------------- GND
    3.3 ------------------- 3.3V (VCC)
    D1/MOSI --------------- MO (don't change)
    D0/SCK ---------------- SCK (don't change)
    D2  ------------------- unused
    D/C ------------------- A0 (can be any digital pin)
    RST ------------------- A1 (can be any digital pin)
    CS  ------------------- A2 (can be any digital pin)

Ultrasonic Sensor
    Trigger: D3
    Echo: D2

*/
#include "SparkFunMicroOLED.h"  // Include MicroOLED library

//////////////////////////
// MicroOLED Definition //
//////////////////////////
#define PIN_OLED_RST A1  // Connect RST to pin 6
#define PIN_OLED_DC A0   // Connect DC to pin 5 (required for SPI)
#define PIN_OLED_CS A2   // Connect CS to pin A2 (required for SPI)
MicroOLED oled(MODE_SPI, PIN_OLED_RST, PIN_OLED_DC, PIN_OLED_CS);

//////////////////////////
// Ultrasonic Distance  //
//////////////////////////
const int PIN_ECHO = D2;    //Sensors sends to ARGON INPUT  
const int PIN_TRIGGER = D3; //ARGON OUTPUT sends to sensor

//global constant
double SPEED_SOUND_CM = 0.03444; //temperature dependent
double CONV_CM_TO_IN = 0.3437;

void setup() {
  Serial.begin(9600);  // begin serial communication with the computer
  oled.begin();        // Initialize the OLED
  oled.clear(ALL);     // Clear the display's internal memory
  oled.display();      // Display what's in the buffer (splashscreen)
  delay(1000);         // Delay 1000 ms

  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

/********************************************************************************/
void loop() {
  //start measurement
  //send low for 2 us, high for 10 us, low (sequence)
  digitalWrite(PIN_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER, LOW);
  //now sensor starts

  //measure time (measuring time it takes for pin to go High to Low)
  int roundTripTime = pulseIn(PIN_ECHO, HIGH); //listen when pin is HIGH, stop listening when pin is low

  double distanceCm = roundTripTime * SPEED_SOUND_CM / 2;
  double distanceIn = distanceCm * CONV_CM_TO_IN;

  Serial.println("Distance (cm): " + String(distanceCm) + ", Distance (in): " + String(distanceIn));
  delay(250);


}





