#include "Particle.h"
SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_WARN);

// copy these 3 lines from Blynk website > devices > your device > device info
#define BLYNK_TEMPLATE_ID "TMPL2bpkvWhkl"
#define BLYNK_TEMPLATE_NAME "Week 6"
#define BLYNK_AUTH_TOKEN "hB0CUlmcrAQE6hYI0yXmXCBDt7kLITJl"

// include the library
#include <blynk.h>

// two other things we need to do to connect with Blynk
//      start connection in SETUP
//      update connection in LOOP

const int PIN_LED = D7;
const int PIN_RED = D3;
const int PIN_GREEN = D4;
const int PIN_BLUE = D5;
const int PIN_SWITCH = D2;

int prevDoorState = HIGH;
int currDoorState = HIGH;

unsigned long prevMillis = 0;
const unsigned long INTERVAL_BLYNK = 1000; //update from ARGON to APP every 1 sec

    void changeLedColor(int r, int g, int b) {
    // theoretical "recipe" or algorithm using these input
    analogWrite(PIN_RED, r);
    analogWrite(PIN_GREEN, g);
    analogWrite(PIN_BLUE, b);
}

void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_SWITCH, INPUT);
    Serial.begin(9600);

    // start Blynk connection
    Blynk.begin(BLYNK_AUTH_TOKEN);
}

void loop() {
    // update Blynk connection
    Blynk.run();
    /*
        if we are using Blynk, everything in LOOP must be within millis block
        we are sending data to Blynk--we had to make sure that all ddata we send
       in a millis block
    */

    unsigned long curMillis = millis();
    if (curMillis - prevMillis > INTERVAL_BLYNK) {
        prevMillis = curMillis;
        int randomNum = random(0,256);

        /*
        to send data FROM Argon TO App
            Blynk.virtualWrite(VIRTUAL_PIN, DATA);          
                virtual pin is a datastream we set up on the Blynk website
                data is whatever we are sending (int, float, string)
        */
       Blynk.virtualWrite(V6, randomNum);
       Serial.println("Random number = " + String(randomNum));

    }
}