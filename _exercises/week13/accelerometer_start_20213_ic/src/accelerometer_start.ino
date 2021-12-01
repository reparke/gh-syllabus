#include "SparkFunMMA8452Q.h"

const int PIN_RED = A5;
const int PIN_GREEN = A4;
const int PIN_BLUE = A3;
const int ON_BOARD_LED = D7;

MMA8452Q accel;

//for detecting a tap, you would need to trial/error the figure what values work for what you're measuring

// Threshold can range from 1-127, with steps of 0.063g/bit.
byte threshold = 1;

// 0.625 * pulseTimeLimit = number of millisecods
byte pulseTimeLimit = 255;

// @50Hz: Each bit adds 10ms (max: 2.56s)
byte pulseLatency = 64;  // 1.25 * 64 = 640ms

void setup() {
  Serial.begin(9600);
  Serial.println("MMA8452Q Test Code!");
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(ON_BOARD_LED, OUTPUT);

  //setup sensor
  accel.begin(SCALE_2G, ODR_1);

  //initialize tap detection
  accel.setupTap(threshold, threshold, threshold, pulseTimeLimit, pulseLatency);
  
}


//print out the orientation of your Argon
//accel.readPL()
void loop() {
  if (accel.available()) {
    accel.read();
    // printOrientation();
    detectTap();
  }
}

void detectTap() {
  if (accel.readTap() > 0) {
    Serial.println("Tap detected!");
  }
}

void printOrientation() {
  byte orientation = accel.readPL();
  switch(orientation) {
    case PORTRAIT_U:
      Serial.println("Portrait Up");
      break;
    case PORTRAIT_D:
      Serial.println("Portrait Down");
      break;
    case LANDSCAPE_L:
      Serial.println("Landscape Left");
      break;
    case LANDSCAPE_R:
      Serial.println("Landscape Right");
      break;
    case LOCKOUT:
      Serial.println("Flat / lockout");
      break;
  }
}