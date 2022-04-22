#include "SparkFunMMA8452Q.h"

const int PIN_RED = A5;
const int PIN_GREEN = A4;
const int PIN_BLUE = A3;
const int ON_BOARD_LED = D7;

MMA8452Q accel;


//to detect taps, there is some trial and error
//thresold: 1-127, each "step" is 0.063 g/bit
byte threshold = 1; 

//pulseTimeLimit: 0.625 * pulseTimeLimit = milliseconds
byte pulseTimeLimit = 255;

//pulseLatency: Each bit adds 10ms (max of 2.65s)
byte pulseLatency = 64; // 1.0 * 64 = 640ms



void setup() {
    Serial.begin(9600);
    Serial.println("MMA8452Q Test Code!");
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(ON_BOARD_LED, OUTPUT);

    accel.begin(SCALE_2G, ODR_1);
    accel.setupTap(threshold, threshold, threshold, pulseTimeLimit, pulseLatency);
}

void loop() {
    if (accel.available() == true) {
        accel.read();
        //detect taps
        if (accel.readTap() > 0) {
            Serial.println("Tap detected");
        }

        // use the accel values (.cx .cy .cz) to change the rgb led
        int r = map(accel.cx, -1.0, 1.0, 0.0, 255.0);
        int g = map(accel.cy, -1.0, 1.0, 0.0, 255.0);
        int b = map(accel.cz, -1.0, 1.0, 0.0, 255.0);
        analogWrite(PIN_RED, r);
        analogWrite(PIN_GREEN, g);
        analogWrite(PIN_BLUE, b);

        // determine orientation
        byte orientation = accel.readPL();
        switch (orientation) {
            case PORTRAIT_D:
                Serial.println("We are now portrait mode facing down");
                break;
            case PORTRAIT_U:
                Serial.println("We are now portrait mode facing up");
                break;
            case LANDSCAPE_L:
                Serial.println("We are now landscape mode facing left");
                break;
            case LANDSCAPE_R:
                Serial.println("We are now landscape mode facing right");
                break;
            case LOCKOUT:
                Serial.println("We are flat");
                break;
        }
    }
}
