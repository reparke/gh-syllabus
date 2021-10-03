/*Note: This corresponds to locally installed project "Week 6", tab "lab"
  Features
    - ZeRGBa to control LED (V0 V1 V2 app --> argon)
    - Display to show if switch is open (V3 argon --> app)
    - Gauge to display random number (V6 argon --> app)
    - Text box to send command (V4 app --> argon)

*/

/*
install Blynk app on your phone

connect RGB led to argon (D2, D3, D4)

connect switch (Gnd - A0 - 3.3v)
*/

#include <blynk.h>

#define BLYNK_TEMPLATE_ID "TMPL8pRjLGSG"
#define BLYNK_DEVICE_NAME "Week 6 Lab"
#define BLYNK_AUTH_TOKEN "CXGdYkgREo9JvRwFIZ4d8y9WCZ83Zr2b"

// #define BLYNK_TEMPLATE_ID "TMPL0A1ZpqoD"
// #define BLYNK_DEVICE_NAME "Week 6 Intro"
//char auth[] = "CXGdYkgREo9JvRwFIZ4d8y9WCZ83Zr2b";
#define BLYNK_IP \
    IPAddress(64, 225, 16, 22)  // https://ny3.blynk.cloud/ – New York

// if you're sending values to from ARGON to APP (push), we MUST use millis()
// limit is 10 values per sec
// in loop(), we MUST NOT use delay
unsigned long blynkDelay = 1000;
unsigned long prevMillis = 0;

const int PIN_LED = D7;
const int PIN_RED = D3;
const int PIN_GREEN = D4;
const int PIN_BLUE = D5;
const int PIN_SWITCH = D2;

// from app to argon
// create function for BLYNK_WRITE
BLYNK_WRITE(V0) {
    int redVal = param.asInt();  // range 0-255
    analogWrite(PIN_RED, redVal);
}

BLYNK_WRITE(V1) {
    int greenVal = param.asInt();  // range 0-255
    analogWrite(PIN_GREEN, greenVal);
}

BLYNK_WRITE(V2) {
    int blueVal = param.asInt();  // range 0-255
    analogWrite(PIN_BLUE, blueVal);
}

// trigger new color button
BLYNK_WRITE(V4) {
    int buttonVal = param.asInt();

    // this function gets called EVERYTIME the virtual buttons
    // it gets called when push, and it gets called when you release button
    // lets just pick one or the other (only press OR only release)
    if (buttonVal == 1) {
        // pick random number from 0, 3
        int rand = random(0, 3);
        if (rand == 0) {
            // white
            analogWrite(PIN_RED, 255);
            analogWrite(PIN_GREEN, 255);
            analogWrite(PIN_BLUE, 255);
            Blynk.virtualWrite(V7, "white");
        } else if (rand == 1) {
            // orange
            analogWrite(PIN_RED, 255);
            analogWrite(PIN_GREEN, 165);
            analogWrite(PIN_BLUE, 0);
            Blynk.virtualWrite(V7, "orange");
        } else if (rand == 2) {
            // magenta
            analogWrite(PIN_RED, 255);
            analogWrite(PIN_GREEN, 0);
            analogWrite(PIN_BLUE, 255);
            Blynk.virtualWrite(V7, "magenta");
        } else if (rand == 3) {
            // yellow
            analogWrite(PIN_RED, 255);
            analogWrite(PIN_GREEN, 255);
            analogWrite(PIN_BLUE, 0);
            Blynk.virtualWrite(V7, "yellow");
        }
    }
}

void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_SWITCH, INPUT);
    Serial.begin(9600);

    // 1. have delay
    delay(5000);  // needs to be delay, not millis

    // 2. connect to blynk
    // Blynk.begin(auth);
	Blynk.begin(BLYNK_AUTH_TOKEN, BLYNK_IP);
//    Blynk.begin(auth, BLYNK_IP);
}

void loop() {
    Blynk.run();  // do NOT put in millis timer

    unsigned long currMillis = millis();
    if (currMillis - prevMillis > blynkDelay) {
        prevMillis = currMillis;

        // to send data FROM ARGON TO APP, we use Blynk.virtualwrite
        int switchVal = digitalRead(PIN_SWITCH);
        if (switchVal == HIGH) {
            Blynk.virtualWrite(V3, "open");
        } else {
            Blynk.virtualWrite(V3, "closed");
        }
    }
}