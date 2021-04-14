#include "SparkFunMMA8452Q.h"

const int PIN_RED = A0;
const int PIN_GREEN = A1;
const int PIN_BLUE = A2;
const int ON_BOARD_LED = D7;

MMA8452Q accel;

void setup() {
    Serial.begin(9600);
    Serial.println("MMA8452Q Test Code!");
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(ON_BOARD_LED, OUTPUT);

    // init
    accel.begin(SCALE_2G, ODR_1);


    //if you want to use TAP, you need to configure it first
    //threshold is "AT WHAT LEVEL OF ACCEL DO WE CONSIDER A TAP"
    //can define X Y Z threshold separately
    byte threshold = 1;   //0.063g

    //time elapsed between pulses (in increments of 0.0625 ms)
    byte pulseTimeLimit = 255;    //255 * 0.0625 = 159 ms

    //after a pulse is detected, how long does it wait before another is detected
    byte pulseLatency = 64;

    accel.setupTap(threshold, threshold, threshold, pulseTimeLimit, pulseLatency);

}

void loop() {
    // check if data available
    if (accel.available()) {
        // yes available
        accel.read();  // read the values of acceleration

        if (accel.readTap() > 0) {
          Serial.println("Tap!");
          digitalWrite(ON_BOARD_LED, HIGH);
        }
        else {
          digitalWrite(ON_BOARD_LED, LOW);
        }

        // HERE DO SOMETHING COOL
        // if you want actual multiple of G(ravity), cx, cy, cz
        // readTap, and readPL

        // PL - portrait and landscape

        byte orientation = accel.readPL();

        switch (orientation) {
            case PORTRAIT_D:
                Serial.println("portrait down");
                break;
            case PORTRAIT_U:
                Serial.println("portrait up");
                break;
            case LANDSCAPE_L:
                Serial.println("landscape left");
                break;
            case LANDSCAPE_R:
                Serial.println("landscape right");
                break;
            case LOCKOUT:
                Serial.println("lockout");
                break;
        }
    }
}