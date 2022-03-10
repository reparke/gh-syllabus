// based on
// https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40

#include "argon_ble_setup.h"
/*
  Use Adafruit Bluefruit app
  (https://learn.adafruit.com/bluefruit-le-connect/controller)
  Connect to Argon -> controller

  CONFIGURATION
  Motor Controller
    PWMA    - D8
    AIN2    - D7
    AIN1    - D6
    BIN1    - D5
    BIN2    - D4
    PWMB    - D3

    VCC     - 3v3
    Standby - 3v3
    VM      - Li+
    Enable  - connect to switch

*/

// SYSTEM_MODE(MANUAL);  //uncomment to disable wifi and use BT only

// PIN VARIABLES
// the motor will be controlled by the motor A pins on the motor driver
const int AIN1 = D6;  // control pin 1 on the motor driver for the right motor
const int AIN2 = D7;  // control pin 2 on the motor driver for the right motor
const int PWMA =
    D8;  // speed control pin on the motor driver for the right motor

// the left motor will be controlled by the motor B pins on the motor driver
const int PWMB = D3;  // speed control pin on the motor driver for the left
                      // motor
const int BIN2 = D4;  // control pin 2 on the motor driver for the left motor
const int BIN1 = D5;  // control pin 1 on the motor driver for the left motor

// VARIABLES
int motorSpeed = 255;  // useful if you want to change speeds

/* onDataReceived() is event handler for incoming data via RX characteristic
   When the RXCharacteristic receives data, the event handler is called
   Note: uint8_t is a byte ("unsigned integer of length 8 bits")

    The command scheme is from the Adafruit Bluefruit app
    https://learn.adafruit.com/bluefruit-le-connect/controller

    ex: [‘!’] [‘B’] [‘4’] [‘1’] [CRC]
*/
void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer,
                    void* context) {
    if (len > 4) {
    }
    // btSerialDebug(data, len); // uncomment for serial monitor debug
}

void setup() {
    argon_ble_setup();

    // set the motor control pins as outputs
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);

    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMB, OUTPUT);

    Serial.begin(9600);  // begin serial communication
}

void loop() {}

/********************************************************************************/

/*
  btSerialDebug
      used for printing debug info to serial monitor ===
*/
void btSerialDebug(const uint8_t* data, size_t len) {
    for (size_t ii = 0; ii < len; ii++) {
        Serial.print(data[ii]);
        Serial.print(" ");
    }
    Serial.println();
    for (size_t ii = 0; ii < len; ii++) {
        Serial.write(data[ii]);
        Serial.print(" ");
    }
    Serial.println();
}