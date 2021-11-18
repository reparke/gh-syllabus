#include "SparkFunMMA8452Q.h"

const int PIN_RED = A5;
const int PIN_GREEN = A4;
const int PIN_BLUE = A3;
const int ON_BOARD_LED = D7;


void setup() {
  Serial.begin(9600);
  Serial.println("MMA8452Q Test Code!");
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(ON_BOARD_LED, OUTPUT);

}

void loop() {}