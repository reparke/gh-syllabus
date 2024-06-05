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
#define ARDUINOJSON_ENABLE_ARDUINO_STRING 1
#include <ArduinoJson.h>

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

unsigned long TIME_SCREEN_UPDATE_MS = 500;

unsigned long WEATHER_SCREEN_UPDATE_MS = 10512000;
float tempWeather = 0;
String city = "city";
String weatherDescription = "desc";
int weatherCode = 0;
int uvIndex = 0;

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
#define PIN_RESET 9
#define DC_JUMPER 1
MicroOLED oled(MODE_I2C, PIN_RESET, DC_JUMPER);  // I2C declaration
#include <Wire.h>

void runHeartScreen() {
    unsigned long curMillis = millis();
    // if (pulseSensor.beatDetected()) {
    //     beatAvg = pulseSensor.getBPM();
    // }
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

        // float voltage = analogRead(BATT) * 0.0011224;
        float voltage = 0;
        oled.setCursor(0, 40);
        oled.setFontType(0);
        oled.print("Batt ");
        oled.print(String(voltage, 2));
        oled.display();
        Serial.println("BPM: " + String(beatAvg));
    }
}
void setup() {
    // analogRead(pulseSignalPin);

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
    pulseSensor.process();

    runHeartScreen();
}

// An optional function to recieve the Beats Per Minute (BPM) and Interbeat
// Interval (IBI) in mS
void PulseSensorAmped_data(int BPM, int IBI) {
    Serial.print("BPM:");
    Serial.print(BPM);
    Serial.print(" IBI: ");
    Serial.println(IBI);
    beatAvg = BPM;
}

// An optional function to indicate that the pulse signal has been lost
// (Due to the nature of pulse detection via reflected light, spurios signals
// are possible.
//  i.e. received data may not be valid)
void PulseSensorAmped_lost(void) {
    Serial.println("Pulse Lost");
    beatAvg = 0;
}
