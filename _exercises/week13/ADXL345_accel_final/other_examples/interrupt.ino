/*  *********************************************
 *  Particle ADXL345 Interrupt Example
 *  Rob Parke
 *  Based on SparkFun_ADXL345_Example
 *  Triple Axis Accelerometer Breakout - ADXL345
 *  Hook Up Guide Example
 *
 *  Utilizing Sparkfun's ADXL345 Library
 *  Bildr ADXL345 source file modified to support
 *  both I2C and SPI Communication
 *  *********************************************/

#include "SparkFun_ADXL345.h"  // SparkFun ADXL345 Library

/*********** COMMUNICATION SELECTION ***********/
/*    Comment Out The One You Are Not Using    */
// ADXL345 adxl = ADXL345(10);           // USE FOR SPI COMMUNICATION,
// ADXL345(CS_PIN);
ADXL345 adxl = ADXL345();  // USE FOR I2C COMMUNICATION

/****************** INTERRUPT ******************/
/*      Uncomment If Attaching Interrupt       */
const int INTERRUPT_PIN =
    A5;         // Setup pin 2 to be the interrupt pin (for most Arduino Boards)
int count = 0;  // for testing triggering of outputs
/******************** SETUP ********************/
/*          Configure ADXL345 Settings         */
void setup() {
    Serial.begin(9600);  // Start the serial terminal
    Serial.println("SparkFun ADXL345 Accelerometer Hook Up Guide Example");
    Serial.println();

    adxl.powerOn();  // Power on the ADXL345

    adxl.setRangeSetting(16);  // Give the range settings
                               // Accepted values are 2g, 4g, 8g or 16g
                               // Higher Values = Wider Measurement Range
                               // Lower Values = Greater Sensitivity

    adxl.setSpiBit(0);  // Configure the device to be in 4 wire SPI mode when
                        // set to '0' or 3 wire SPI mode when set to 1 Default:
                        // Set to 1 SPI pins on the ATMega328: 11, 12 and 13 as
                        // reference in SPI Library

    adxl.setActivityXYZ(
        1, 0, 0);  // Set to activate movement detection in the axes
                   // "adxl.setActivityXYZ(X, Y, Z);" (1 == ON, 0 == OFF)
    adxl.setActivityThreshold(75);  // 62.5mg per increment   // Set activity //
                                    // Inactivity thresholds (0-255)

    adxl.setInactivityXYZ(
        1, 0, 0);  // Set to detect inactivity in all the axes
                   // "adxl.setInactivityXYZ(X, Y, Z);" (1 == ON, 0 == OFF)
    adxl.setInactivityThreshold(
        75);  // 62.5mg per increment   // Set inactivity // Inactivity
              // thresholds (0-255)
    adxl.setTimeInactivity(10);  // How many seconds of no activity is inactive?

    adxl.setTapDetectionOnXYZ(
        0, 0, 1);  // Detect taps in the directions turned ON
                   // "adxl.setTapDetectionOnX(X, Y, Z);" (1 == ON, 0 == OFF)

    // Set values for what is considered a TAP and what is a DOUBLE TAP (0-255)
    adxl.setTapThreshold(50);      // 62.5 mg per increment
    adxl.setTapDuration(15);       // 625 μs per increment
    adxl.setDoubleTapLatency(80);  // 1.25 ms per increment
    adxl.setDoubleTapWindow(200);  // 1.25 ms per increment

    // Set values for what is considered FREE FALL (0-255)
    adxl.setFreeFallThreshold(7);  // (5 - 9) recommended - 62.5mg per increment
    adxl.setFreeFallDuration(30);  // (20 - 70) recommended - 5ms per increment

    // Setting all interupts to take place on INT1 pin
    adxl.setImportantInterruptMapping(1, 1, 1, 1, 1);  // Sets
    // "adxl.setEveryInterruptMapping(single tap, double tap, free fall,
    // activity, inactivity);"
    // Accepts only 1 or 2 values for pins INT1 and INT2. This chooses the pin
    // on the ADXL345 to use for Interrupts. This library may have a problem
    // using INT2 pin. Default to INT1 pin.

    // Turn on Interrupts for each mode (1 == ON, 0 == OFF)
    adxl.InactivityINT(1);
    adxl.ActivityINT(1);
    adxl.FreeFallINT(1);
    adxl.doubleTapINT(1);
    adxl.singleTapINT(1);

    pinMode(INTERRUPT_PIN, INPUT);
    attachInterrupt(INTERRUPT_PIN, ADXL_ISR,
                    RISING);    // Attach Interrupt adxl.getInterruptSource()
    adxl.getInterruptSource();  // clear interrupt
}
bool tapOccured = false;

/****************** MAIN CODE ******************/
/*     Accelerometer Readings and Interrupt    */
void loop() {
    if (tapOccured == true) {
        tapOccured = false;

        byte interrupts = adxl.getInterruptSource();

        if (adxl.triggered(interrupts, ADXL345_SINGLE_TAP)) {
            Serial.println(String(count) + " *** SINGLE TAP ***");
        }

        // Free Fall Detection
        if (adxl.triggered(interrupts, ADXL345_FREE_FALL)) {
            Serial.println(String(count) + "*** FREE FALL ***");
            // add code here to do when free fall is sensed
        }

        // Inactivity
        if (adxl.triggered(interrupts, ADXL345_INACTIVITY)) {
            Serial.println(String(count) + "*** INACTIVITY ***");
            // add code here to do when inactivity is sensed
        }

        // Activity
        if (adxl.triggered(interrupts, ADXL345_ACTIVITY)) {
            Serial.println(String(count) + "*** ACTIVITY ***");
            // add code here to do when activity is sensed
        }

        adxl.getInterruptSource();  // clear interrupt
    }
}
/********************* ISR *********************/
/* Look for Interrupts and Triggered Action    */
void ADXL_ISR() {
    tapOccured = true;
    count++;
    Serial.println("In ADXL_ISR!");
}
