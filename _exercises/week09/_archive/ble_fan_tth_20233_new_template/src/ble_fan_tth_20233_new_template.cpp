/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "argon_ble_setup.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);


// on board LED
const int PIN_LED = D7;

// Servo
const int PIN_SERVO = D2;

// motor pins
const int AIN1 = D3;
const int AIN2 = D4;
const int PWMA = D5;

int motorspeed = 0;
Servo servoObj;
int servoPos = 90;

// setup() runs once, when the device is first turned on
void setup() {
    argon_ble_setup();  // BLE setup

    pinMode(PIN_LED, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);

    Serial.begin(9600);
    // attach servo pin
    servoObj.attach(PIN_SERVO);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

  // Example: Publish event to cloud every 10 seconds. Uncomment the next 3 lines to try it!
  // Logging.info("Sending Hello World to the cloud!");
  // Particle.publish("Hello world!");
  // delay( 10 * 1000 ); // milliseconds and blocking - see docs for more info!
}
/*
  bluetoothSerialDebug
      used for printing debug info to serial monitor ===
*/
void bluetoothSerialDebug(const uint8_t* data, size_t len) {
    for (size_t index = 0; index < len; index++) {
        Serial.print((char)data[index]);
        Serial.print(" ");
    }
    Serial.println();
}

void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer,
                    void* context) {
  bluetoothSerialDebug(data, len); /* uncomment for serial monitor debug */
                                   // String: String msg = "hello"
  // char:   char letter = 'h';  '%'   'Y'    '5'
  // this function gets called WHEN YOU PRESS a button on the bluefruit app
  // data is an array of chars
  // our gooal is to write if statements to identify which button was pressed
  // and take approprioate action

  if (len > 4) {
      // when 1 button is pressed, lets blink the onboard LED
      // ! B 1 1
      if (data[0] == '!' && data[1] == 'B' && data[2] == '1' &&
          data[3] == '1') {
          digitalWrite(PIN_LED, HIGH);
          delay(100);
          digitalWrite(PIN_LED, LOW);
          delay(100);
      }
      // when button two is pressed (and held down), LED should stay on,
      // otherwise its off
      //  ! B 2 1 --> pressing button 2 --> turn on LED
      //  ! B 2 0 --> releasing button 2 --> turn off LED
      else if (data[0] == '!' && data[1] == 'B' && data[2] == '2' &&
               data[3] == '1') {
          digitalWrite(PIN_LED, HIGH);
      } else if (data[0] == '!' && data[1] == 'B' && data[2] == '2' &&
                 data[3] == '0') {
          digitalWrite(PIN_LED, LOW);
      } else if (data[0] == '!' && data[1] == 'B' && data[2] == '5' &&
                 data[3] == '1') {
          // press up arrow to increase speed
          motorspeed = motorspeed + 15;
          if (motorspeed > 255) {
              motorspeed = 255;
          }
          digitalWrite(AIN1, HIGH);
          digitalWrite(AIN2, LOW);
          analogWrite(PWMA, motorspeed);
      } else if (data[0] == '!' && data[1] == 'B' && data[2] == '6' &&
                 data[3] == '1') {
          // press down arrow to decrease speed
          motorspeed = motorspeed - 15;
          if (motorspeed < 0) {
              motorspeed = 0;
          }
          digitalWrite(AIN1, HIGH);
          digitalWrite(AIN2, LOW);
          analogWrite(PWMA, motorspeed);
      } else if (data[0] == '!' && data[1] == 'B' && data[2] == '7' &&
                 data[3] == '1') {
          // 7 is left arrow so servo
          servoPos = servoPos + 15;
          if (servoPos > 165) {
              servoPos = 165;
          }
          servoObj.write(servoPos);
      } else if (data[0] == '!' && data[1] == 'B' && data[2] == '8' &&
                 data[3] == '1') {
          // 8 is right arrow so servo
          servoPos = servoPos - 15;
          if (servoPos < 15) {
              servoPos = 15;
          }
          servoObj.write(servoPos);
      }
  }
}
/********************************************************************************/

