/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

const int PIN_BUTTON = D2;
const int PIN_ONBOARD_LED = D7;   //built in LED we can use

int prevButtonVal = HIGH;
int currButtonVal = HIGH;

void setup() {
  pinMode(PIN_ONBOARD_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
    /*
     exercise 1: Turn LED on only while button pressed
     

     exercise 2: Toggle LED on and off after each time button is pressed

    */
   // exercise 1
   // using a pull up resistor: when button is NOT pressed, input is HIGH
   //                           when button is PRESSED, input is LOW
  //  int buttonVal = digitalRead(PIN_BUTTON);
  //  if (buttonVal == LOW) {
  //   digitalWrite(PIN_ONBOARD_LED, HIGH);
  //  }
  //  else {
  //   digitalWrite(PIN_ONBOARD_LED, LOW);
  //  }

  //exercise 2: how do we build a latch / toggle

  currButtonVal = digitalRead(PIN_BUTTON);
  if (prevButtonVal == HIGH && currButtonVal == LOW) {
    // falling edge button was pressed
    //put to toggle LED on / off
  }
  prevButtonVal = currButtonVal;


}
