#include "SparkFunMMA8452Q.h"

const int PIN_RED = A0;
const int PIN_GREEN = A1;
const int PIN_BLUE = A2;
const int ON_BOARD_LED = D7;

// Threshold can range from 1-127, with steps of 0.063g/bit.
byte threshold = 1;  // 2 * 0.063g = 0.063g (minimum threshold

// Pulse time limit: Maximum time interval that can elapse between the start
// of the acceleration exceeding the threshold, and the end, when
// acceleration goes below the threshold to be considered a valid pulse.
byte pulseTimeLimit = 255;  // 0.625 * 255 = 159ms (max)

// Pulse latency: the time interval that starts after first pulse detection,
// during which all other pulses are ignored. (Debounces the pulses).
// @50Hz: Each bit adds 10ms (max: 2.56s)
byte pulseLatency = 64;  // 1.25 * 64 = 640ms

MMA8452Q accel;

void setup() {
    Serial.begin(9600);
    Serial.println("MMA8452Q Test Code!");
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);

    accel.begin(SCALE_2G,
                ODR_1);  // 2g and 1 Hz refresh (helps output be easier to read)
    accel.setupTap(threshold, threshold, threshold, pulseTimeLimit,
                   pulseLatency);
}

void loop() {
    if (accel.available()) {
        // To update acceleration values from the accelerometer, call
        // accel.read();
        accel.read();

        // After reading, six class variables are updated: x, y, z, cx, cy, and
        // cz. Those are the raw, 12-bit values (x, y, and z) and the calculated
        // acceleration's in units of g (cx, cy, and cz).

        // displayExampleGraphs();
        changeOnBoardLEDWithTap();  
        // printOrientation();
    }
}
void displayExampleGraphs() {
    // use the printAccelGraph funciton to print the values along with a bar
    // graph, to see their relation to eachother:
    printAccelGraph(accel.cx, "X", 20, 2.0);
    printAccelGraph(accel.cy, "Y", 20, 2.0);
    printAccelGraph(accel.cz, "Z", 20, 2.0);
    Serial.println();
}

void changeOnBoardLEDWithTap() {
    Serial.println(accel.readTap());
    if (accel.readTap() > 0) {
        digitalWrite(ON_BOARD_LED, HIGH);
        Serial.println("Tapped!");
    }
}

void printOrientation() {
    // accel.readPL() will return a byte containing information
    // about the orientation of the sensor. It will be either
    // PORTRAIT_U, PORTRAIT_D, LANDSCAPE_R, LANDSCAPE_L, or
    // LOCKOUT.
    byte pl = accel.readPL();
    switch (pl) {
        case PORTRAIT_U:
            Serial.print("Portrait Up");
            break;
        case PORTRAIT_D:
            Serial.print("Portrait Down");
            break;
        case LANDSCAPE_R:
            Serial.print("Landscape Right");
            break;
        case LANDSCAPE_L:
            Serial.print("Landscape Left");
            break;
        case LOCKOUT:
            Serial.print("Flat");

            break;
    }
    Serial.println();
}

// printAccelGraph prints a simple ASCII bar graph for a single accelerometer
// axis value. Examples:
//	printAccelGraph(-0.1, "X", 20, 2.0) will print:
// 		X:                    =|                     (0.1 g)
//	printAccelGraph(1.0, "Z", 20, 2.0) will print:
//		Z:                     |==========           (1.0 g)
// Input:
//	- [value]: calculated value of an accelerometer axis (e.g accel.cx,
// accel.cy)
//	- [name]: name of the axis (e.g. "X", "Y", "Z")
//	- [numBarsFull]: Maximum number of bars either right or left of 0 point.
//	- [rangeAbs]: Absolute value of the maximum acceleration range
void printAccelGraph(float value, String name, int numBarsFull,
                     float rangeAbs) {
    // Calculate the number of bars to fill, ignoring the sign of numBars for
    // now.
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
        } else  // If our value is positive, just print spaces
            Serial.print(' ');
    }

    Serial.print('|');  // Print a pipe (|) to represent the 0-point

    // Do the positive half of the graph last:
    for (int i = 0; i < numBarsFull; i++) {
        if (value > 0) {  // If our position in the graph is in the range we
                          // want to graph
            if (i <= numBars)
                Serial.print('=');  // Print an '='
            else
                Serial.print(' ');  // otherwise print spaces
        } else                      // If value is negative, just print spaces
            Serial.print(' ');
    }

    // To end the line, print the actual value:
    Serial.println(" (" + String(value, 2) + " g)");
}