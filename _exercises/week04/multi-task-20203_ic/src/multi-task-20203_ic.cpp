/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Rob/Documents/_GitHub/ITP_348_Content_Public/_exercises/week04/multi-task-20203_ic/src/multi-task-20203_ic.ino"
void setup();
void loop();
#line 1 "c:/Users/Rob/Documents/_GitHub/ITP_348_Content_Public/_exercises/week04/multi-task-20203_ic/src/multi-task-20203_ic.ino"
const int PIN_LED1 = D3;
const int PIN_LED2 = D4;
const int PIN_BUTTON = D2;

//millis() or time will be in unsigned long
//what was the LAST time we checked
unsigned long prevMillis = 0;

//any intervals we want to track
unsigned long intervalOnLed1 = 2000; // 2 sec

//what state are with in
//we need to know if LED is on or it is off
bool state_LED1 = false; //LED 1 starts off

void setup() {
  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  Serial.begin(9600);

}

//ver 2
void loop() {
  //get current time
  unsigned long currMillis = millis();

  //is the elapsed time since we LAST changed the LED GREATER than our interval time
  //    if yes, then switch light (on->off or off->on)
  //    if no,  do nothing
  int val = digitalRead(PIN_BUTTON);
  Serial.println("Button: " + String(val));
  if ((currMillis - prevMillis) > intervalOnLed1) {
    //update the prevMillis
    prevMillis = currMillis;

    //switch the light
    if (state_LED1 == false) {    //means light is off
      //change state
      state_LED1 = true;

      //turn on light
      digitalWrite(PIN_LED1, HIGH);
    }
    else {  //light is on now
      //change state
      state_LED1 = false;

      //turn off
      digitalWrite(PIN_LED1, LOW);
    }
  }

}


//LED blink at 5sec
//register button presses
// void loop() {
  // //delay is blocking -- v1
  // digitalWrite(PIN_LED1, HIGH);
  // delay(5000);
  // digitalWrite(PIN_LED2, LOW);
  // delay(5000);
  // int val = digitalRead(PIN_BUTTON);
  // Serial.println("Button press: " + String(val));





// }