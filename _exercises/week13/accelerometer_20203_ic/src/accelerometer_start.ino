
#include "SparkFunMMA8452Q.h"

const int PIN_RED = A0;
const int PIN_GREEN = A1;
const int PIN_BLUE = A2;
const int ON_BOARD_LED = D7;

//create object
MMA8452Q accel;

void setup() {
    Serial.begin(9600);
    Serial.println("MMA8452Q Test Code!");
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(ON_BOARD_LED, OUTPUT);

    //set resolution and datarate
    accel.begin(SCALE_2G, ODR_1);
}

void loop() {
    if (accel.available()) {
        accel.read();  //now we have a current value of accel

        // Serial.println("X, y, z: " + String(accel.cx) + ", " + String(accel.cy) + ", " + String(accel.cz));

        //map convert an input of numbers to an output range of numbers

        int r = map(accel.cx, -1.0, 1.0, 0.0, 255.0);
        int g = map(accel.cy, -1.0, 1.0, 0.0, 255.0);
        int b = map(accel.cz, -1.0, 1.0, 0.0, 255.0);

        analogWrite(PIN_RED, r);
        analogWrite(PIN_GREEN, g);
        analogWrite(PIN_BLUE, b);

      //measure orientation
      byte value = accel.readPL();
      switch(value) {
        case PORTRAIT_U:    //port upward
          Serial.println("Device is in portrait up mode");
          break;
        case PORTRAIT_D:    //port upward
          Serial.println("Device is in portrait down mode");
          break;
        case LANDSCAPE_L:    //port upward
          Serial.println("Device is in landscape left mode");
          break;
        case LANDSCAPE_R:    //port upward
          Serial.println("Device is in landscape right mode");
          break;
        case LOCKOUT:    //port upward
          Serial.println("Device is flat");
          break;
      }
    }
}