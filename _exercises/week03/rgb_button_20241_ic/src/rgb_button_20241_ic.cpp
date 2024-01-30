
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

// cmd S or cntl S to format your code

const int PIN_BUTTON = D5;
const int PIN_ONBOARD_LED = D7;
const int PIN_RED = D2;
const int PIN_GREEN = D3;
const int PIN_BLUE = D4;

// global var
int counter = 0;
int prevButtonVal = HIGH;  // high means button not pressed
int currButtonVal = HIGH;
int stateOnBoardLed = LOW;

// define our function
//  this function has NO return ==> VOID
//  function input: three int values for RGB colors for analogwrite
void changeRgb(int r, int g, int b) {
    analogWrite(PIN_RED, r);
    analogWrite(PIN_GREEN, g);
    analogWrite(PIN_BLUE, b);
}

void changeRgbString(String color) {
  if (color == "red") {
    //write code to make light red
  }
}

void changeRgbRandom()  { // no input
  int randX = random(0,256);  //random(0,256) give a random number from 0-255
  int randY = random(0,256);
  int randZ = random(0,256);

  changeRgb(randX, randY, randZ);
}

void setup() {
    pinMode(PIN_BUTTON, INPUT);
    pinMode(PIN_ONBOARD_LED, OUTPUT);
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // // version 1 - no latch
    // int currButtonVal = digitalRead(PIN_BUTTON);
    // if (currButtonVal == LOW) {
    //     counter = counter + 1;  // counter += 1;
    //     // counter++;
    //     digitalWrite(PIN_ONBOARD_LED, HIGH);
    //     Serial.println("counter = " + String(counter));
    // } else {
    //     digitalWrite(PIN_ONBOARD_LED, LOW);
    // }

    // version 2 - latch
    //   goal: we need to store what happened LAST TIME in the loop for the
    //   button
    //           then we can compare to what's happening now
    //      key---> local var in functions disappear after functions end so we
    //      need global var for LAST STATE
    //     we need to know the STATE of the light (is it on or off?)

    // // int currButtonVal ---> this is incorrect!
    // currButtonVal = digitalRead(PIN_BUTTON);
    // // falling edge: prev button was high and current button is low-> button
    // was
    // // just pressed
    // if (prevButtonVal == HIGH &&
    //     currButtonVal == LOW) {  // button was just pressed
    //     // here is code to run when button is pressed
    //     counter = counter + 1;
    //     Serial.println("counter = " + String(counter));
    //     if (stateOnBoardLed == LOW) {  // if light is off
    //         stateOnBoardLed = HIGH;
    //         digitalWrite(PIN_ONBOARD_LED, HIGH);
    //     } else {  // if light is on
    //         stateOnBoardLed = LOW;
    //         digitalWrite(PIN_ONBOARD_LED, LOW);
    //     }
    // }
    // prevButtonVal = currButtonVal;  // this needs to happen at END of loop
    // and
    //                                 // OUTSIDE of the IF

    // version 3 - RGB
    // currButtonVal = digitalRead(PIN_BUTTON);
    // // falling edge: prev button was high and current button is low-> button was
    // // just pressed
    // if (prevButtonVal == HIGH &&
    //     currButtonVal == LOW) {  // button was just pressed
    //     // here is code to run when button is pressed
    //     counter = counter + 1;
    //     Serial.println("counter = " + String(counter));

    //     // show red for 1 sec, green for 1 sec, blue for 1 sec, white 1 sec
    //     // digitalWrite(PIN_RED, HIGH);  // red
    //     changeRgb(255,0,0);
    //     delay(500);
    //     // digitalWrite(PIN_RED, LOW);  // green
    //     // digitalWrite(PIN_GREEN, HIGH);
    //     changeRgb(0,255,0);
    //     delay(500);
    //     // digitalWrite(PIN_BLUE, HIGH);  // blue
    //     // digitalWrite(PIN_GREEN, LOW);
    //     changeRgb(0,0,255);
    //     delay(500);
    //     // digitalWrite(PIN_RED, HIGH);  // white
    //     // digitalWrite(PIN_GREEN, HIGH);
    //     changeRgb(255,255,255);
    //     delay(500);
    //     // digitalWrite(PIN_BLUE, LOW);
    //     // digitalWrite(PIN_RED, HIGH);  // yellow
    //     // digitalWrite(PIN_GREEN, HIGH);
    //     changeRgb(255, 255, 0);
    //     delay(500);
    //     // analogWrite(PIN_RED, 250);  // orange
    //     // analogWrite(PIN_GREEN, 150);
    //     // analogWrite(PIN_BLUE, 12);
    //     changeRgb(250, 150, 12);
    //     delay(500);
    //     // digitalWrite(PIN_RED, LOW);  // off
    //     // digitalWrite(PIN_BLUE, LOW);
    //     // digitalWrite(PIN_GREEN, LOW);
    //     changeRgb(0,0,0);

    //     // how do we show yellow and orange?
    // }
    // prevButtonVal = currButtonVal;  // this needs to happen at END of loop and
    //                                 // OUTSIDE of the IF

    // version 4 - random
    //when the button is pressed, display a random color
    currButtonVal = digitalRead(PIN_BUTTON);
    // falling edge: prev button was high and current button is low-> button was
    // just pressed
    if (prevButtonVal == HIGH &&
        currButtonVal == LOW) {  // button was just pressed
        // here is code to run when button is pressed
        counter = counter + 1;
        Serial.println("counter = " + String(counter));
        changeRgbRandom();

  
    }
    prevButtonVal = currButtonVal;  // this needs to happen at END of loop and
                                    // OUTSIDE of the IF
    /*
        prev    curr
        H       H
        H       L     ** BUTTON PRESS**
        L       L     HOLDING DOWN BUTTON
        L       H     ** BUTTON RELEASE **
        H       H

     */
}
