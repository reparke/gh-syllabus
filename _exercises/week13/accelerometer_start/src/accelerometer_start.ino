#include "SparkFunMMA8452Q.h"

const int PIN_RED = A0;
const int PIN_GREEN = A1;
const int PIN_BLUE = A2;
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