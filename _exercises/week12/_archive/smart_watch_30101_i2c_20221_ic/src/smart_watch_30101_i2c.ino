/*
    (website) add the webhook

    subscribe to a webhook response

    publish the message to particle cloud

    write the subcription handler

*/

/*
  Uses code from
  Optical Heart Rate Detection (PBA Algorithm) using the MAX30105 Breakout
  By: Nathan Seidle @ SparkFun Electronics
  Date: October 2nd, 2016
  https://github.com/sparkfun/MAX30105_Breakout
*/

/*
  Hardware Connections (Breakoutboard to Arduino):
  -5V = 5V (3.3V is allowed)
  -GND = GND
  -SDA = A4 (or SDA)
  -SCL = A5 (or SCL)
  -INT = Not connected
*/
// libraries for heart rate sensor
#include "JsonParserGeneratorRK.h"
#include "MAX30105.h"
#include "SparkFunMicroOLED.h"  // Include MicroOLED library
#include "bitmaps_watch.h"
#include "bitmaps_weather.h"
#include "heartRate.h"

// libraries for OLED
#include <Wire.h>
MAX30105 particleSensor;
JsonParser jsonParser;

float weatherTemp = 0;
String weatherDescripton = "description";
int weatherCode = 0;  // describe conditions
int weatherHumidity = 0;
int weatherUvIndex = 0;

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

//////////////////////////
// Heart Screen         //
//////////////////////////
/* refreshing the OLED is very slow and it causes
    the heart rate detection to fail
    This delay was determined experimentally to work well
*/
unsigned long prevScreenUpdateMillis = 0;
unsigned long HEART_SCREEN_UPDATE_MS = 5000;
unsigned long TIME_SCREEN_UPDATE_MS = 500;

const int LOW_BPM_THRESHOLD = 45;
const int LOW_IR_THRESHOLD = 50000;
const byte RATE_SIZE = 4;  // Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE];     // Array of heart rates
byte rateSpot = 0;
long lastBeat = 0;  // Time at which the last beat occurred

float beatsPerMinute;
int beatAvg;
long irValue = 0;

float tempF;

//////////////////////////
// Button Variables     //
//////////////////////////
const int PIN_BUTTON = D3;
int prevReading = HIGH;  // the last VERIFIED state

//////////////////////////
// States               //
//////////////////////////
// TODO: create state enum and variable(s) to track state
enum State { Heart, TimeMode, Weather };
State currentState = Heart;

// TODO
void getNextState() {
    switch (currentState) {
        case Heart:
            currentState = TimeMode;
            break;
        case TimeMode:
            currentState = Weather;
            break;
        case Weather:
            currentState = Heart;
            break;
    }
}

// TODO
void loadNextScreen() {
    switch (currentState) {
        case Heart:
            runHeartScreen();
            break;
        case TimeMode:
            runTimeScreen();
            break;
        case Weather:
            runWeatherScreen();
            break;
    }
}

// TODO
void runHeartScreen() {
    // for debugging
    // Serial.println("Heart");
    // // oled.clear(PAGE);  // Clear the display
    // // oled.setCursor(0, 0);
    // // oled.print("Heart");
    // // oled.display();
    /*
        check / update heart rate as fast/often as possible
        update OLED as infrequently as possible
    */
    updateBPM();  // outsiee any millis timer
    Serial.println("Avg BPM: " + String(beatAvg));
    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis > HEART_SCREEN_UPDATE_MS) {
        prevScreenUpdateMillis = curMillis;
        if (irValue < LOW_IR_THRESHOLD || beatAvg < LOW_BPM_THRESHOLD) {
            oled.clear(PAGE);
            oled.drawBitmap(heart16x12);
            oled.setFontType(1);
            oled.setCursor(20, 0);
            oled.print("---");
        } else {
            oled.clear(PAGE);
            oled.drawBitmap(heart16x12);
            oled.setFontType(1);
            oled.setCursor(20, 0);
            oled.print(String(beatAvg));
        }
        float tempF = particleSensor.readTemperatureF();
        oled.setCursor(0, 20);
        oled.setFontType(1);
        oled.print("Temp ");
        oled.print(String(tempF, 0));

        // float voltage = analogRead(BATT) * 0.0011224;
        float voltage = analogRead(A6) * 0.0011224;
        oled.setCursor(0, 40);
        oled.setFontType(0);
        oled.print("Batt ");
        oled.print(String(voltage, 2));
        oled.display();
        /*
            Charging ( V > 4.3)
            Full Charge (V >=4.2
            Nominal (4.2 > V > 3.5)
            Low/Needs Recharge (3.5 > V >= 3.4)
            Critical (3.4 > V)

        */
    }
}

// TODO
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

// TODO
void runWeatherScreen() {
    unsigned long curMillis = millis();
    if (curMillis - prevScreenUpdateMillis > 10512000) {
        String data = "90089";
        Particle.publish("WeatherStackJSON", data, PRIVATE);
    }

    // rainy is 296, 302, 308
    //  for debugging
    //  Serial.println("Weather");
    oled.clear(PAGE);  // Clear the display
    weatherDescripton = "Partially cloudy";
    switch (weatherCode) {
        case 296:
        case 302:
        case 308:  // match ANY of these (basically OR)
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

    oled.setCursor(38, 3);
    oled.setFontType(1);
    oled.print(weatherTemp, 0);
    oled.setFontType(0);
    oled.print("o");

    oled.setCursor(0, 24);
    oled.setFontType(0);
    oled.print(weatherDescripton.substring(0, 9));

    oled.setCursor(0, 40);
    oled.print("H ");
    oled.print(weatherHumidity);
    oled.print("%");

    oled.setCursor(38, 40);
    oled.print("UV ");
    oled.print(weatherUvIndex);
    oled.display();
}

//////////////////////////
// SETUP                //
//////////////////////////
void setup() {
    Serial.begin(115200);
    Serial.println("Initializing...");

    // Initialize sensor
    if (!particleSensor.begin(
            Wire, I2C_SPEED_FAST))  // Use default I2C port, 400kHz speed
    {
        Serial.println("MAX30105 was not found. Please check wiring/power. ");
        while (1);
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

    Particle.subscribe("hook-response/WeatherStackJSON", myHandler, MY_DEVICES);

    // run once on startup to get the proper data
    String data = "90089";
    Particle.publish("WeatherStackJSON", data, PRIVATE);
}

//////////////////////////
// LOOP                 //
//////////////////////////
// TODO
void loop() {
    // create latch for buttons changes
    int curButtonVal = digitalRead(PIN_BUTTON);
    if (curButtonVal == HIGH && prevReading == LOW) {
        getNextState();
    }
    prevReading = curButtonVal;
    loadNextScreen();
}

void myHandler(const char *event, const char *data) {
    // Part 1 allows for webhook responses to be delivered in multple "chunks";
    // you don't need to change this
    int responseIndex = 0;
    const char *slashOffset = strrchr(event, '/');
    if (slashOffset) responseIndex = atoi(slashOffset + 1);
    if (responseIndex == 0) jsonParser.clear();
    jsonParser.addString(data);

    // Part 2 is where you can parse the actual data; you code goes in the IF
    if (jsonParser.parse()) {
        /****** YOUR PARSING CODE GOES HERE ********/
        // Serial.println(jsonParser.getBuffer());
        weatherTemp = jsonParser.getReference()
                          .key("current")
                          .key("temperature")
                          .valueFloat();
        weatherCode = jsonParser.getReference()
                          .key("current")
                          .key("weather_code")
                          .valueInt();
        weatherHumidity =
            jsonParser.getReference().key("current").key("humidity").valueInt();
        weatherUvIndex =
            jsonParser.getReference().key("current").key("uv_index").valueInt();
        weatherDescripton = jsonParser.getReference()
                                .key("current")
                                .key("weather_descriptions")
                                .index(0)
                                .valueString();

        Serial.println(weatherDescripton +
                       "\n  temperature: " + String(weatherTemp, 1) +
                       " F\n  humidity: " + String(weatherHumidity) +
                       "\n  uv index: " + String(weatherUvIndex) +
                       "\n  weather code: " + String(weatherCode));
    }
}

/* =================================================
   ================================================= */
//////////////////////////
// HEART RATE FUNCTIONS //
//////////////////////////
// These functions are completed and shouldn't be modified

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

    Serial.print("IR=");
    Serial.print(irValue);
    Serial.print(", BPM=");
    Serial.print(beatsPerMinute);
    Serial.print(", Avg BPM=");
    Serial.print(beatAvg);

    if (irValue < 50000) Serial.print(" No finger?");
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
