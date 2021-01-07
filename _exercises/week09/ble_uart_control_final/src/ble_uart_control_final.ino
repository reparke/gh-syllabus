#include "argon_ble_setup.h"

/*
  Use Adafruit Bluefruit app
  (https://learn.adafruit.com/bluefruit-le-connect/controller)
  Connect to Argon -> controller

  - use color picker to change LED
  - use controller to play a tone and flash on-board LED
  - control fan motor and servo
  - play a tone

| Motor Controller | Argon |
| ---------------- | ----- |
| PWMA             | D5    |
| AIN2             | D4    |
| AIN1             | D3    |
| VCC              | 3v3   |
| GND              | GND   |
| VM               | 3v3   |
| STBY             | 3v3   |

RGB LED (common cathode)
  R - A2
  G - A1
  B - A0

Buzzer - D6
Servo: D2
On-board LED - D7

Specifications
  When "1" is pressed down, on-board LED D7 will blink twice
  When "2" is pressed down, on-board LED D7 will turn on
  When "2" is released, on-board LED D7 will turn off
  When "4" is pressed, play a tone
  When "RIGHT" is pressed down, rotate servo clockwise
  When "LEFT" is pressed down, rotate servo counter clockwise
  When "3" is pressed down, change direction of fan

  When color picker is used, change RGB LED color
*/

const int PIN_RED = A2;
const int PIN_GREEN = A1;
const int PIN_BLUE = A0;

const int PIN_BUZZER = D6;

const int PIN_LED = D7;

const int PIN_SERVO = D2;

const int AIN1 = D3;
const int AIN2 = D4;
const int PWMA = D5;

const int MOTOR_DELTA = 15;
const int SERVO_DELTA = 15;

Servo servo;
int servoPos = 90;  // range of 15-165

int motorSpeed = 0;

bool isFanSpinningForward = true;

void setup() {
  /* === START BLE SETUP === */
  argon_ble_setup();
  /* === END BLE SETUP === */
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  Serial.begin(9600);

  servo.attach(PIN_SERVO);
  servo.write(servoPos);

  analogWrite(PWMA, motorSpeed);
  spinFanForward();
}

void loop() {}

/*  Sample Code to communicate from Argon to Adafruit Bluefruit app
    https://learn.adafruit.com/bluefruit-le-connect/controller
    
    The command scheme is from the Adafruit Bluefruit app
    ex: [‘!’] [‘B’] [‘4’] [‘1’] [CRC]
*/

// onDataReceived() is event handler for incoming data via RX characteristic
// When the RXCharacteristic receives data, the event handler is called
// Note: uint8_t is a byte ("unsigned integer of length 8 bits")
void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer,
                    void* context) {
  /* === START DEBUG PRINTING ===
           uncomment following loop to see commands being sent by app ==
   */
/*)
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
*/
  /* === END DEBUG PRINTING === */

  if (len > 4) {  // make sure there at least four bytes
    if (data[0] == '!' && data[1] == 'B' && data[2] == '1' &&
        data[3] == '1') {  // button 1 pressed -> blink
      digitalWrite(PIN_LED, HIGH);
      delay(200);
      digitalWrite(PIN_LED, LOW);
      delay(200);
    } else if (data[0] == '!' && data[1] == 'B' && data[2] == '2' &&
               data[3] == '1') {  // button UP pressed -> LED on
      digitalWrite(PIN_LED, HIGH);
    } else if (data[0] == '!' && data[1] == 'B' && data[2] == '2' &&
               data[3] == '0') {  // button UP released -> LED off
      digitalWrite(PIN_LED, LOW);
    }
    // added to send a tone to D6 when right arrow is pressed
    else if (data[0] == '!' && data[1] == 'B' && data[2] == '4' &&
             data[3] == '0') {  // button UP released -> LED off
      tone(PIN_BUZZER, 1000, 500);
    }
    // button RIGHT pressed -> turn servo
    else if (data[0] == '!' && data[1] == 'B' && data[2] == '8' &&
             data[3] == '1') {
      servoPos = servoPos + SERVO_DELTA;
      if (servoPos >= 165) {
        servoPos = 165;
      }
      servo.write(servoPos);

      // button LEFT pressed -> turn servo
    } else if (data[0] == '!' && data[1] == 'B' && data[2] == '7' &&
               data[3] == '1') {
      servoPos = servoPos - SERVO_DELTA;
      if (servoPos <= 0) {
        servoPos = 15;
      }
      servo.write(servoPos);

    }
    // button UP pressed -> speed up fan
    else if (data[0] == '!' && data[1] == 'B' && data[2] == '5' &&
             data[3] == '1') {
      motorSpeed = motorSpeed + MOTOR_DELTA;
      if (motorSpeed > 255) {
        motorSpeed = 255;
      }
      analogWrite(PWMA, motorSpeed);
      Serial.println("Motorspeed: " + String(motorSpeed));
      // button DOWN is  pressed -> slow down fan
    } else if (data[0] == '!' && data[1] == 'B' && data[2] == '6' &&
               data[3] == '1') {
      motorSpeed = motorSpeed - MOTOR_DELTA;
      if (motorSpeed < 0) {
        motorSpeed = 0;
      }
      analogWrite(PWMA, motorSpeed);

      Serial.println("Motorspeed: " + String(motorSpeed));
    } else if (data[0] == '!' && data[1] == 'B' && data[2] == '3' &&
               data[3] == '1') {
      isFanSpinningForward = !isFanSpinningForward;
      if (isFanSpinningForward == true) {
        spinFanForward();
      } else {
        spinFanBackward();
      }

    } else if (data[0] == '!' && data[1] == 'C') {
      Serial.print("R as uint ");
      Serial.println(data[2]);

      changeRgbLight(data[2], data[3], data[4]);
    }
  }
}
// void changeRgbLight(uint8_t r, uint8_t g, uint8_t b) {
void changeRgbLight(int r, int g, int b) {
  analogWrite(PIN_RED, r);
  analogWrite(PIN_GREEN, g);
  analogWrite(PIN_BLUE, b);
}

void spinFanForward() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
}
void spinFanBackward() {
  digitalWrite(AIN2, HIGH);
  digitalWrite(AIN1, LOW);
}
