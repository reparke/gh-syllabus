#include "SparkFunMicroOLED.h"  // Include MicroOLED library
#include "bitmaps_watch.h"
#include "bitmaps_weather.h"

const int pulseSignalPin = A0;

#include "PulseSensor.h"
PulseSensor pulseSensor;
int beatAvg;

unsigned long prevScreenUpdateMillis = 0;
unsigned long HEART_SCREEN_UPDATE_MS = 3000;

const int LOW_BPM_THRESHOLD = 40;
const int HIGH_BPM_THRESHOLD = 200;

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
#define PIN_RESET 9
#define DC_JUMPER 1
MicroOLED oled(MODE_I2C, PIN_RESET, DC_JUMPER);  // I2C declaration
#include <Wire.h>

void runHeartScreen() {
    unsigned long curMillis = millis();
    if (pulseSensor.beatDetected()) {
        beatAvg = pulseSensor.getBPM();
    }
    if (curMillis - prevScreenUpdateMillis > HEART_SCREEN_UPDATE_MS) {
        prevScreenUpdateMillis = curMillis;

        if (beatAvg > LOW_BPM_THRESHOLD &&
            beatAvg < HIGH_BPM_THRESHOLD) {  // VALID!
            oled.clear(PAGE);
            oled.drawBitmap(bitmap_heart_16x12);
            oled.setFontType(1);
            oled.setCursor(20, 0);
            oled.print(String(beatAvg));
        } else {
            // INVALID!
            oled.clear(PAGE);
            oled.drawBitmap(bitmap_heart_16x12);
            oled.setFontType(1);
            oled.setCursor(20, 0);
            oled.print("---");
        }

        oled.setCursor(0, 40);
        oled.setFontType(0);
        oled.display();
        Serial.println("BPM: " + String(beatAvg));
    }
}
void setup() {

    Serial.begin(115200);
    Serial.println("Initializing...");

    pulseSensor.attach(pulseSignalPin);
    pulseSensor.start();

    // initialize OLED
    oled.begin();      // Initialize the OLED
    oled.clear(PAGE);  // Clear the display
    oled.drawBitmap(bitmap_trojan_64x48);
    oled.display();
    delay(1000);  // Delay 1000 ms
    oled.drawBitmap(bitmap_usc_64x48);
    oled.display();
    delay(1000);  // Delay 1000 ms

    Time.zone(-8);
    Time.beginDST();
}

void loop() {
    runHeartScreen();
}

