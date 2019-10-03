
#include "rgb-controls.h"
using namespace RGBControls;

Led led(D2, D3, D4);
Color red(255, 0, 0);
Color blue(0, 0, 255);
Color orange(255, 137, 1);    // "color" object with value 


const int PIN_RED = D2;
const int PIN_GREEN = D3;
const int PIN_BLUE = D4;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void loop() {
  // Fade the light between red and blue every second
  led.fade(orange, blue, 1000);
}

// const int PIN_RED = D2;
// const int PIN_GREEN = D3;
// const int PIN_BLUE = D4;

// void setup() {
//   pinMode(PIN_RED, OUTPUT);
//   pinMode(PIN_GREEN, OUTPUT);
//   pinMode(PIN_BLUE, OUTPUT);

//   randomSeed(analogRead(A0)); //read in "random noise"
// }

// void loop() {
//   //function call
//   displayRandomColor();
//   delay(2000);
// }

// //DEFINTIONS MUST BE OUTSIDE OF ANY OTHER FUNCTION
// //function definition
// //generates and displays a random color
// void displayRandomColor()   {     // pass in the pins, but typically we don't
// need to since pins are global
//   int r = random(0, 255);
//   int g = random(0, 255);
//   int b = random(0, 255);

//   analogWrite(PIN_RED, r);
//   analogWrite(PIN_GREEN, g);
//   analogWrite(PIN_BLUE, b);

//   // return;  // this is unnecessary
// }