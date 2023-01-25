/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "f:/Github/ITP_348_Content_Public/_exercises/week03/button_20221_ic/src/button_20221_ic.ino"

void setup();
void loop();
#line 2 "f:/Github/ITP_348_Content_Public/_exercises/week03/button_20221_ic/src/button_20221_ic.ino"
const int PIN_BUTTON = D2;
const int PIN_LED = D3;

//global because it needs to PERSIST (or remember) value from loop to next loop
int prevButtonValue = HIGH;
bool isLedOn = false; //off

int buttonCounter = 0;

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int currentButtonValue = digitalRead(PIN_BUTTON);
  Serial.println("Button = " + String(currentButtonValue));

  //v1 - led follows button
  // if (buttonValue == LOW) {      //button not pressed
  //   digitalWrite(PIN_LED, HIGH);
  // }
  // else {                          //button presseed
  //   digitalWrite(PIN_LED, LOW);
  // }

  //v2 - toggle / latch

  if (prevButtonValue == HIGH && currentButtonValue == LOW) { //falling edge
    buttonCounter+=1;
    if (buttonCounter == 1) { 
      //turn on LED 1, turn off LED 2
    }
    else if (buttonCounter == 2 ){ 

    }
    if (buttonCounter > 3) {
      buttonCounter = 1;
    }
    // if (isLedOn == true) {
    //   digitalWrite(PIN_LED, LOW); //turn light off
    //   isLedOn = false;            //update led "state"
    // }
    // else{
    //   digitalWrite(PIN_LED, HIGH);  //turn light on
    //   isLedOn = true;               //update led state
    // }
  }

  //update our buttons values
  prevButtonValue = currentButtonValue;


  //v4 - pattern of lights

}