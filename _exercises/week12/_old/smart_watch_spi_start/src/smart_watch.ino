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
  D1/MOSI --------------- MO
  D0/SCK ---------------- SCK
  D2  ------------------- unused
  D/C ------------------- A0 (can be changed)
  RST ------------------- A1 (can be changed)
  CS  ------------------- A2 (can be changed)
Button: D3
Switch:
  Pin 1 -- GND
  Pin 2 -- EN
*/
// libraries for MAX30102
#include <Wire.h>

#include "MAX30105.h"
#include "heartRate.h"

// libraries for OLED
#include "SparkFunMicroOLED.h"  // Include MicroOLED library
#include "bitmaps_heart_watch.h"
#include "bitmaps_weather.h"

//////////////////////////
// MAX30105 Definition  //
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

float beatsPerMinute = 0;
int beatAvg = 0;

const int LOW_BPM_THRESHOLD = 40;
const int LOW_IR_THRESHOLD = 50000;

//////////////////////////
// Heart Screen         //
//////////////////////////
/* refreshing the OLED is very slow and it causes
    the heart rate detection to fail
    This delay was determined experimentally to work well
*/
unsigned long prevHeartScreenUpdateMillis = 0;
unsigned long HEART_SCREEN_UPDATE_MS = 1000;
long irValue = 0;
float tempF = 0;

//////////////////////////
// MicroOLED Definition //
//////////////////////////
const int PIN_OLED_DC = A0;   // Connect DC to pin 5 (required for SPI)
const int PIN_OLED_RST = A1;  // Connect RST to pin 6
const int PIN_OLED_CS = A2;   // Connect CS to pin A2 (required for SPI)
MicroOLED oled(MODE_SPI, PIN_OLED_RST, PIN_OLED_DC, PIN_OLED_CS);

//////////////////////////
// Time  Variables      //
//////////////////////////

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

void setup() {
    Serial.begin(115200);
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
    heartRateSensor.enableDIETEMPRDY();

    heartReadTimer.start();  // start recurring timer to read heart rate sensor

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

void runHeartScreen() {
    // for debugging
    Serial.println("Time");
    oled.clear(PAGE);  // Clear the display
    oled.print("Time");
    oled.display();
}

void runTimeScreen() {
    // for debugging
    Serial.println("Time");
    oled.clear(PAGE);  // Clear the display
    oled.print("Time");
    oled.display();
}

void runWeatherScreen() {
    // for debugging
    Serial.println("Weather");
    oled.clear(PAGE);  // Clear the display
    oled.print("Weather");
    oled.display();
}

void loop() {
    int reading = digitalRead(PIN_BUTTON);  // check button read
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