// based on
// https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40

#include "argon_ble_setup.h"
/*
  Use Adafruit Bluefruit app
  (https://learn.adafruit.com/bluefruit-le-connect/controller)
  Connect to Argon -> controller

  CONFIGURATION
  Motor Controller
    PWMA  - D8
    AIN2  - D7
    AIN1  - D6
    BIN1  - D5
    BIN2  - D4
    PWMB  - D3



    ?? Questions
    VCC
    Standby
    VM
    enable
    
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
int motorSpeed = 125;      // starting speed for the motor
int motorLOWSpeed = 125;   // starting speed for the motor
int motorHIGHSpeed = 255;  // starting speed for the motor
bool isLowSpeed = true;




// onDataReceived() is event handler for incoming data via RX characteristic
// When the RXCharacteristic receives data, the event handler is called

// Note: uint8_t is a byte ("unsigned integer of length 8 bits")
void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer,
                    void* context) {
  /* === START DEBUG PRINTING ===
           uncomment following loop to see commands being sent by app ==
   */
  /*  for (size_t ii = 0; ii < len; ii++) {
      Serial.print(data[ii]);
      Serial.print(" ");
    }
    Serial.println();
    for (size_t ii = 0; ii < len; ii++) {
      Serial.write(data[ii]);
      Serial.print(" ");
    }
    Serial.println();
    */
  /* === END DEBUG PRINTING === */

  if (len > 4 ) {  // make sure there at least four bytes
    // the command scheme is from the Adafruit Bluefruit app
    // ex: [‘!’] [‘B’] [‘4’] [‘1’] [CRC]
    // https://learn.adafruit.com/bluefruit-le-connect/controller

    
  }
}

/*
  How do we get a motor to spin?
    set AIN1 HIGH, AIN2 LOW, PWMA 255 --> forward
    set BIN1 HIGH, BIN2 LOW, PWMB 255 --> forward

    set AIN1 LOW, AIN2 HIGH, PWMA 255 --> backward
    set BIN1 LOW, BIN2 HIGH, PWMB 255 --> backward

    leftMotor function( direction )
    rightMotor function (direction)

    carForward function
    carBackward 




*/

void setup() {
  argon_ble_setup();

  // set the motor control pins as outputs
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  Serial.begin(9600);  // begin serial communication with the computer

  // the serial monitor.
}

/********************************************************************************/
void loop() {}

