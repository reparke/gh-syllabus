#include "SparkFunMMA8452Q.h"

const int PIN_RED = A0;
const int PIN_GREEN = A1;
const int PIN_BLUE = A2;
const int ON_BOARD_LED = D7;

MMA8452Q accel;  // create object

void setup() {
  Serial.begin(9600);
  Serial.println("MMA8452Q Test Code!");
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(ON_BOARD_LED, OUTPUT);

  accel.begin(SCALE_2G, ODR_1);
}

void loop() {
  if (accel.available()) {  // is sensor ready
    accel.read();           // read

    // Serial.println("x: " + String(accel.cx));
    //   printAccelGraph(accel.cx, "X", 20, 2.0);
    //   printAccelGraph(accel.cy, "Y", 20, 2.0);
    //   printAccelGraph(accel.cz, "Z", 20, 2.0);
    //   Serial.println();
    byte orientation = accel.readPL();  // gives an that determines direction
    switch (orientation) {
      case PORTRAIT_U:
        Serial.println("portrait up");
        break;
      case PORTRAIT_D:
        Serial.println("portrait down");
        break;
      case LANDSCAPE_L:
        Serial.println("landscape left");
        break;
      case LANDSCAPE_R:
        Serial.println("landscape right");
        break;
      case LOCKOUT:
        Serial.println("flat");
        break;
    }
  }
}

void printAccelGraph(float value, String name, int numBarsFull,
                     float rangeAbs) {
  // Calculate the number of bars to fill, ignoring the sign of numBars for now.
  int numBars = abs(value / (rangeAbs / numBarsFull));

  Serial.print(name + ": ");  // Print the axis name and a colon:

  // Do the negative half of the graph first:
  for (int i = 0; i < numBarsFull; i++) {
    if (value < 0)  // If the value is negative
    {
      // If our position in the graph is in the range we want to graph
      if (i >= (numBarsFull - numBars))
        Serial.print('=');  // Print an '='
      else
        Serial.print(' ');  // print spaces otherwise
    } else                  // If our value is positive, just print spaces
      Serial.print(' ');
  }

  Serial.print('|');  // Print a pipe (|) to represent the 0-point

  // Do the positive half of the graph last:
  for (int i = 0; i < numBarsFull; i++) {
    if (value >
        0) {  // If our position in the graph is in the range we want to graph
      if (i <= numBars)
        Serial.print('=');  // Print an '='
      else
        Serial.print(' ');  // otherwise print spaces
    } else                  // If value is negative, just print spaces
      Serial.print(' ');
  }

  // To end the line, print the actual value:
  Serial.println(" (" + String(value, 2) + " g)");
}