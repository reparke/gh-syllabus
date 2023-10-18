#include "argon_ble_setup.h"

/*
  Use Adafruit Bluefruit app
  (https://learn.adafruit.com/bluefruit-le-connect/controller)
  Connect to Argon -> controller

  - control fan motor and servo
  - use controller flash on-board LED
  - use color picker to change LED

RGB LED (common cathode)
  R - A2
  G - A1
  B - A0

Servo: D2
On-board LED - D7

Specifications
  When "1" is pressed down, on-board LED D7 will blink twice
  When "2" is pressed down, on-board LED D7 will turn on
  When "2" is released, on-board LED D7 will turn off

  When "UP" is pressed down, fan blade speed decreases
  When "DOWN" is pressed down, fan blade speed decreases
  When "3" is pressed down, change direction of fan blades
  When "RIGHT" is pressed down, rotate servo clockwise
  When "LEFT" is pressed down, rotate servo counter clockwise

  When "4" is pressed, turn on fan auto mode (OPTIONAL BONUS)


  When color picker is used, change RGB LED color
  format: [‘!’] [‘C’] [byte red] [byte green] [byte blue] [CRC]

*/

// for changing fan blade speed or servo position, every you press a button
// just increase or decrease the value by a certain amount (remember each has a
// max and min)

// RBG LED Pins
const int PIN_RED = A2;
const int PIN_GREEN = A1;
const int PIN_BLUE = A0;

const int PIN_LED = D7;

const int PIN_SERVO = D2;

// motor pins
const int AIN1 = D3;
const int AIN2 = D4;
const int PWMA = D5;
const int MOTOR_DELTA = 15;
const int SERVO_DELTA = 15;

Servo servo;
int servoPosition = 90;  // range of 15-165

int motorSpeed = 0;

bool isFanSpinningForward = true;
// fan auto mode variables
bool isFanAutomaticMode = false;
unsigned long prevMillis = 0;
unsigned long INCREMENT_TIMER = 20;
bool isServoPosIncreasing = true;  // direction

void spinFanBackward() {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
}
void spinFanForward() {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
}
void spinFanOff() {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
}

void setup() {
    argon_ble_setup();  // BLE setup

    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_RED, OUTPUT);
    Serial.begin(9600);
    servo.attach(PIN_SERVO);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);
    spinFanForward();  // this aligns with isFanSpinningForward = true
}
void loop() {}

/* onDataReceived() is event handler for incoming data via RX characteristic
   When the RXCharacteristic receives data, the event handler is called
   Note: uint8_t is a byte ("unsigned integer of length 8 bits")

    The command scheme is from the Adafruit Bluefruit app
    https://learn.adafruit.com/bluefruit-le-connect/controller

    ex: [‘!’] [‘B’] [‘4’] [‘1’] [CRC]
*/
void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer,
                    void* context) {
    if (len > 4) {  // make sure that the command has finished sending
        // button 1 pressed
        if (data[0] == '!' && data[1] == 'B' && data[2] == '1' &&
            data[3] == '1') {
            digitalWrite(PIN_LED, HIGH);
            delay(200);
            digitalWrite(PIN_LED, LOW);
            delay(200);
        } else if (data[0] == '!' && data[1] == 'B' && data[2] == '2' &&
                   data[3] == '1') {
            digitalWrite(PIN_LED, HIGH);
        } else if (data[0] == '!' && data[1] == 'B' && data[2] == '2' &&
                   data[3] == '0') {
            digitalWrite(PIN_LED, LOW);
        }
        // right arrow
        else if (data[0] == '!' && data[1] == 'B' && data[2] == '8' &&
                 data[3] == '1') {
            // move servo clockwise by a fixed amount
            servoPosition = servoPosition + SERVO_DELTA;
            if (servoPosition >= 165) {
                servoPosition = 165;
            }
            servo.write(servoPosition);
        } else if (data[0] == '!' && data[1] == 'B' && data[2] == '7' &&
                   data[3] == '1') {
            // move servo clockwise by a fixed amount
            servoPosition = servoPosition - SERVO_DELTA;
            if (servoPosition <= 15) {
                servoPosition = 15;
            }
            servo.write(servoPosition);
        }
        // up arrow
        else if (data[0] == '!' && data[1] == 'B' && data[2] == '5' &&
                 data[3] == '1') {
            motorSpeed = motorSpeed + MOTOR_DELTA;
            if (motorSpeed >= 255) {
                motorSpeed = 255;
            }
            analogWrite(PWMA, motorSpeed);
        }
        // down arrow
        else if (data[0] == '!' && data[1] == 'B' && data[2] == '6' &&
                 data[3] == '1') {
            motorSpeed = motorSpeed - MOTOR_DELTA;
            if (motorSpeed <= 0) {
                motorSpeed = 0;
            }
            analogWrite(PWMA, motorSpeed);
        }
        // button 3
        else if (data[0] == '!' && data[1] == 'B' && data[2] == '3' &&
                 data[3] == '1') {
            isFanSpinningForward = !isFanSpinningForward;
            if (isFanSpinningForward == true) {
                spinFanForward();
            } else {
                spinFanBackward();
            }
        }
    }
}
/*
 ** When "RIGHT" is pressed down, rotate servo (by fixed amount) clockwise
* When "LEFT" is pressed down, rotate servo (by fixed amount)  counter
clockwise
* When "UP" is pressed down, speed up motor (by fixed amount)
* When "DOWN" is pressed down, slow motor(by fixed amount)
* When "3" is pressed down, change direction of fan


  When "2" is pressed down, on-board LED D7 will turn on
 * When "2" is released, on-board LED D7 will turn off
 *
 */
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

void changeRgbLight(int r, int g, int b) {
    analogWrite(PIN_RED, r);
    analogWrite(PIN_GREEN, g);
    analogWrite(PIN_BLUE, b);
}