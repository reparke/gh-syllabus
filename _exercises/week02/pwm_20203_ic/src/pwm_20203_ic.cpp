/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Rob/Documents/_GitHub/ITP_348_Content_Public/_exercises/week02/pwm_20203_ic/src/pwm_20203_ic.ino"

// global variables and constants
// assign a constant for each pin
void setup();
void loop();
#line 4 "c:/Users/Rob/Documents/_GitHub/ITP_348_Content_Public/_exercises/week02/pwm_20203_ic/src/pwm_20203_ic.ino"
const int PIN_LED = D2;
int brightness = 0;

// run once
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(PIN_LED, OUTPUT);  // every pin you use needs to be INPUT or OUTPUT
}

// infinite while loop
// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // analogWrite(PIN_LED, 0);  // 0-255; 0 off, 255 on, 127 is half
  // delay(2000);
  // analogWrite(PIN_LED, 127);  // 0-255; 0 off, 255 on, 127 is half
  // delay(2000);
  // analogWrite(PIN_LED, 255);  // 0-255; 0 off, 255 on, 127 is half
  // delay(2000);

  analogWrite(PIN_LED, brightness);
  delay(1000);

  if (brightness < 235) {
    brightness = brightness + 20; //incr brightnes
  }
  else {
    brightness = 0; //reset
  }
}