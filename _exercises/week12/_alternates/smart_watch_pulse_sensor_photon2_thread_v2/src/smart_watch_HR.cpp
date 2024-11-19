#include "Particle.h"
SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_WARN);


//////////////////////////
// Pulse Sensor         //
//////////////////////////
#include "PulseSensor.h"
PulseSensor pulseSensor;
const int pulseSignalPin = A0;

//////////////////////////////////
// MicroOLED                    //
//////////////////////////////////
#include "SparkFunMicroOLED.h"
#include "bitmaps_watch.h"
#include "bitmaps_weather.h"
#define PIN_RESET 9
#define DC_JUMPER 1
MicroOLED oled(MODE_I2C, PIN_RESET, DC_JUMPER);  // I2C declaration
#include <Wire.h>

//////////////////////////
// Heart Screen         //
//////////////////////////
unsigned long prevScreenUpdateMillis = 0;
unsigned long HEART_SCREEN_UPDATE_MS = 3000;
const int LOW_BPM_THRESHOLD = 40;
const int HIGH_BPM_THRESHOLD = 200;
int beatAvg;


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

        float voltage = analogRead(A6) / 819.2; // for photon 2
        oled.setCursor(0, 40);
        oled.setFontType(0);
        oled.print("Batt " + String(voltage, 2));
        oled.display();
        Serial.println("BPM: " + String(beatAvg));
    }

}

void setup() {

    Serial.begin(115200);
    Serial.println("Initializing...");

    pulseSensor.start();
    pulseSensor.attach(pulseSignalPin);

    oled.begin(); 
    delay(1000);  
}

void loop() {
    runHeartScreen();
}
