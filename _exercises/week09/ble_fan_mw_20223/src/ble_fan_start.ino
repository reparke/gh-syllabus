#include "argon_ble_setup.h"

// on board LED
const int PIN_LED = D7;

// Servo
const int PIN_SERVO = D2;

// motor pins
const int AIN1 = D3;
const int AIN2 = D4;
const int PWMA = D5;

// create servo object
Servo servoObj;
int servoPosition = 15;
int motorSpeed = 0;

void setup() {
    argon_ble_setup();  // BLE setup

    pinMode(PIN_LED, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);

    Serial.begin(9600);
    //attach servo pin
    servoObj.attach(PIN_SERVO);
}
void loop() {}

/* onDataReceived() is event handler for incoming data via RX characteristic
   When the RXCharacteristic receives data, the event handler is called
   Note: uint8_t is a byte ("unsigned integer of length 8 bits")

    The command scheme is from the Adafruit Bluefruit app
    https://learn.adafruit.com/bluefruit-le-connect/controller

    ex: [‘!’] [‘B’] [‘4’] [‘1’] [CRC] --> Button 4 is presssed
*/
// lets have the LED ON as long as button 2 is pressed (so led turns off when button 2 is released)

/*
    When “RIGHT” is pressed down, rotate servo (by fixed amount) clockwise '8'
    When “LEFT” is pressed down, rotate servo (by fixed amount) counter clockwise '7'
    When “UP” is pressed down, speed up motor (by fixed amount) '5'
    When “DOWN” is pressed down, slow motor(by fixed amount) '6'
*/
void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer,
                    void* context) {
    if (len > 4) { //we ware looking for codes that are at least 4 "characters"
        //when the '1' button is pressed, lets blink the onboard LED
        if(data[0] == '!' && data[1] == 'B' && data[2] == '1' && data[3] == '1') {
            // code: '!' 'B' '1' '1' --> button 1 was pressed
            digitalWrite(PIN_LED, HIGH);
            delay(100);
            digitalWrite(PIN_LED, LOW);
            delay(100);
        }
        //!B21 --> button 2 is pressed
        else if (data[0] == '!' && data[1] == 'B' && data[2] == '2' && data[3] == '1') {
            digitalWrite(PIN_LED, HIGH);
        }
        //! B20 --> button 2 is released
        else if (data[0] == '!' && data[1] == 'B' && data[2] == '2' && data[3] == '0') {
            digitalWrite(PIN_LED, LOW);
        }
        else if (data[0] == '!' && data[1] == 'B' && data[2] == '8' && data[3] == '1'){
            //right arrow was pressed
            //take current servo pos, increase it by SOME amount, write to servo
            //make sure we don't go above 165
            servoPosition = servoPosition + 15;
            if (servoPosition > 165) {
                servoPosition = 165;
            }
            servoObj.write(servoPosition);

        } else if (data[0] == '!' && data[1] == 'B' && data[2] == '7' && data[3] == '1') {
            // left arrow was pressed
            // take current servo pos, increase it by SOME amount, write to
            // servo make sure we don't go above 165
            servoPosition = servoPosition - 15;
            if (servoPosition < 15) {
                servoPosition = 15;
            }
            servoObj.write(servoPosition);
        }
        else if (data[0] == '!' && data[1] == 'B' && data[2] == '5' && data[3] == '1') {
            // up arrow was pressed
            // take current motorspeed pos, increase it by SOME amount, write to motor
            // servo make sure we don't go above 255
            motorSpeed = motorSpeed + 15;
            if (motorSpeed > 255) {
                motorSpeed = 255;
            }
            digitalWrite(AIN1, HIGH);
            digitalWrite(AIN2, LOW);
            analogWrite(PWMA, motorSpeed);
            Serial.println("Motorspeed: " + String(motorSpeed));

        } else if (data[0] == '!' && data[1] == 'B' && data[2] == '6' &&
                   data[3] == '1') {
            // up arrow was pressed
            // take current motorspeed pos, increase it by SOME amount, write to
            // motor servo make sure we don't go above 255
            motorSpeed = motorSpeed - 15;
            if (motorSpeed < 0 ) {
                motorSpeed = 0;
            }
            digitalWrite(AIN1, HIGH);
            digitalWrite(AIN2, LOW);
            analogWrite(PWMA, motorSpeed);
            Serial.println("Motorspeed: " + String(motorSpeed));
        }
    } 
/*
    in C++, a string has " ". For example, "hello world"
    a character is JUST ONE LETTER   ' '.  For example, 'J' '$' '5'
*/
    // btSerialDebug(data, len); /* uncomment for serial monitor debug */
}
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
