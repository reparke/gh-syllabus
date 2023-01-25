/* NOTE - Rob Parke
4/14/2022
    -Adding Weatherstack API / JSON

9/25/2021
    -Updated version for Qwiic I2C OLED + MAX30101
    -Eliminated software timers

*/
/*
  Uses code from
  Optical Heart Rate Detection (PBA Algorithm) using the MAX30105 Breakout
  By: Nathan Seidle @ SparkFun Electronics
  Date: October 2nd, 2016
  https://github.com/sparkfun/MAX30105_Breakout

  Hardware Connections (Breakoutboard to Arduino):
  -5V = 5V (3.3V is allowed)
  -GND = GND
  -SDA = A4 (or SDA)
  -SCL = A5 (or SCL)
  -INT = Not connected
*/

#include "MAX30105.h"
#include "heartRate.h"
// libraries for OLED
#include "JsonParserGeneratorRK.h"
#include "SparkFunMicroOLED.h"  // Include MicroOLED library
#include "bitmaps_watch.h"
#include "bitmaps_weather.h"

JsonParser jsonParser;

MAX30105 particleSensor;

const byte RATE_SIZE = 4;  // Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE];     // Array of heart rates
byte rateSpot = 0;
long lastBeat = 0;  // Time at which the last beat occurred

float beatsPerMinute;
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
const int LOW_IR_THRESHOLD = 50000;
float bodyTempF;
long irValue = 0;

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
// need to build this
enum State { HEART, TIME, WEATHER };
State currentState = WEATHER;
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
void runTimeScreen() {
    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis > TIME_SCREEN_UPDATE_MS) {
        prevScreenUpdateMillis = curMillis;

        String dateFormat = "%b %d";
        String dayFormat = "%a";
        String timeFormat = "%I:%M";
        String secondsFormat = "%S";
        // String timeFormat = "%I:%M ";
        // for debugging
        Serial.println("Time");

        oled.clear(PAGE);  // Clear the display
        delay(10);
        oled.drawBitmap(clock_16x12);

        oled.setCursor(25, 0);
        oled.setFontType(0);
        oled.print(Time.format(dateFormat));

        oled.setCursor(25, 10);
        oled.setFontType(0);
        oled.print(Time.format(dayFormat));

        oled.setFontType(1);
        oled.setCursor(0, 25);
        oled.print(Time.format(timeFormat));

        oled.setFontType(0);
        oled.setCursor(50, 30);
        oled.print(Time.format(secondsFormat));

        oled.display();
    }
}

void runWeatherScreen() {  // doesn't use JSON or webhook

    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis > WEATHER_SCREEN_UPDATE_MS) {
        prevScreenUpdateMillis = curMillis;
        String data = "90089";
        Particle.publish("WeatherStackJSON", data, PRIVATE);
    }

    oled.clear(PAGE);
    switch (weatherCode) {
        case 296:
        case 302:
        case 308:
            oled.drawBitmap(weather_rainy_up_left);
            break;
        case 116:
        case 119:
        case 122:
            oled.drawBitmap(weather_cloudy_up_left);
            break;
        case 227:
            oled.drawBitmap(weather_snowing_up_left);
            break;

        default:
            oled.drawBitmap(weather_sunny_up_left);
            break;
    }

    oled.setCursor(38, 5);
    oled.setFontType(1);
    oled.print(tempWeather, 0);
    oled.setFontType(0);
    oled.print("o");

    oled.setFontType(0);
    oled.setCursor(0, 28);
    oled.print(weatherDescription.substring(0, 9));

    oled.setFontType(0);
    oled.setCursor(0, 40);
    oled.print("Hum ");
    oled.print(humidity);
    oled.print("%");

    oled.setCursor(40, 40);
    oled.print("UV ");
    oled.print(uvIndex);

    oled.display();
}


void runHeartScreen() {
    updateBPM();
    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis > HEART_SCREEN_UPDATE_MS) {
        prevScreenUpdateMillis = curMillis;

        // calcHeartBeatAvg();  // this is slow! -- beatAvg
        if (beatAvg > LOW_BPM_THRESHOLD &&
            irValue > LOW_IR_THRESHOLD) {  // VALID!
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
        bodyTempF = particleSensor.readTemperatureF();
        oled.setCursor(0, 20);
        oled.setFontType(1);
        oled.print("Temp ");
        oled.print(String(bodyTempF, 0));

        float voltage = analogRead(BATT) * 0.0011224;
        oled.setCursor(0, 40);
        oled.setFontType(0);
        oled.print("Batt ");
        oled.print(String(voltage, 2));
        oled.display();
        Serial.print("BPM: " + String(beatsPerMinute) +
                     ", Avg: " + String(beatAvg));
        Serial.println(", IRvalue: " + String(irValue) +
                       ", Temp: " + String(bodyTempF));
    }
    // consider adding battery status bands
    // https://community.particle.io/t/can-argon-or-xenon-read-the-battery-state/45554/35?u=rob7
}
void setup() {
    Serial.begin(115200);
    Serial.println("Initializing...");

    // Initialize sensor
    if (!particleSensor.begin(
            Wire, I2C_SPEED_FAST))  // Use default I2C port, 400kHz speed
    {
        Serial.println("MAX30105 was not found. Please check wiring/power. ");
        while (1)
            ;
    }
    Serial.println(
        "Place your index finger on the sensor with steady pressure.");

    particleSensor.setup();  // Configure sensor with default settings
    particleSensor.setPulseAmplitudeRed(
        0x0A);  // Turn Red LED to low to indicate sensor is running
    particleSensor.setPulseAmplitudeGreen(0);  // Turn off Green LED

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
    Particle.subscribe("hook-response/WeatherStackJSON",
                       jsonSubscriptionHandler, MY_DEVICES);

    String data = "90089";
    Particle.publish("WeatherStackJSON", data, PRIVATE);
}

void loop() {
    int curReading = digitalRead(PIN_BUTTON);  // check button read

    if (curReading == HIGH && prevReading == LOW) {
        getNextState();  // button was pressed down, we should change
        prevScreenUpdateMillis = 0;  // make sure next screen loads
                                     // immediately instead of waiting
    }

    // FINALLY! here is your button code
    // if want to execute when button pressed down ONLY

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
    irValue = particleSensor.getIR();

    if (checkForBeat(irValue) == true) {
        // We sensed a beat!
        long delta = millis() - lastBeat;
        lastBeat = millis();

        beatsPerMinute = 60 / (delta / 1000.0);

        if (beatsPerMinute < 255 && beatsPerMinute > 20) {
            rates[rateSpot++] =
                (byte)beatsPerMinute;  // Store this reading in the array
            rateSpot %= RATE_SIZE;     // Wrap variable

            calcHeartBeatAvg();
        }
    }
    // Debugging
    /*
        Serial.print("IR=");
        Serial.print(irValue);
        Serial.print(", BPM=");
        Serial.print(beatsPerMinute);
        Serial.print(", Avg BPM=");
        Serial.print(beatAvg);

        if (irValue < 50000) Serial.print(" No finger?");

        unsigned long curRead = millis();
        samples++;
        Serial.print("\t\t\t\tHz[");
        Serial.print((float)1000.0 / (curRead - lastRead), 2);
        Serial.print("] Avg Hz[");
        Serial.print((float)samples * 1000.0 / (curRead), 2);
        Serial.print("]");
        Serial.println();
        lastRead = curRead;
        Serial.println();
        //   delay(50);
        */
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

void jsonSubscriptionHandler(const char *event, const char *data) {
    // Part 1 allows for webhook responses to be delivered in multple "chunks";
    // you don't need to change this
    int responseIndex = 0;
    const char *slashOffset = strrchr(event, '/');
    if (slashOffset) responseIndex = atoi(slashOffset + 1);
    if (responseIndex == 0) jsonParser.clear();
    jsonParser.addString(data);

    // Part 2 is where you can parse the actual data; you code goes in the IF
    if (jsonParser.parse()) {
        city =
            jsonParser.getReference().key("location").key("name").valueString();
        tempWeather = jsonParser.getReference()
                          .key("current")
                          .key("temperature")
                          .valueDouble();

        weatherCode = jsonParser.getReference()
                          .key("current")
                          .key("weather_code")
                          .valueInt();
        uvIndex =
            jsonParser.getReference().key("current").key("uv_index").valueInt();

        weatherDescription = jsonParser.getReference()
                                 .key("current")
                                 .key("weather_descriptions")
                                 .index(0)
                                 .valueString();

        Serial.println(city + "\n  " + weatherDescription +
                       "\n  temperature: " + String(tempWeather, 1) +
                       " F\n  humidith: " + String(humidity) +
                       "\n  uv index: " + String(uvIndex) +
                       "\n  weather code: " + String(weatherCode));
    }
}
