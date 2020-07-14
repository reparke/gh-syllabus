/*  RGB LED Sketch with animation library
 *
 * Practice importing libraries and using  functions
 *
 * Components
 * ----------
 *  - Particle Argon
 *  - RGB LED
 *  - 330 Ohms Resistors
 *
 *  Libraries
 *  ---------
 *  - rgb-controls
 *  -
 *
 * Connections
 * -----------
 *  LED : Argon
 *  -----------------------------
 *      R         -> 330   -> D2
 *      Cathode   -> Ground
 *      G         -> 330   -> D3
 *      B         -> 330   -> D4
 *
 * Other information
 * -----------------
 *  - Good functions to try:
 *    fade (with two colors)
 *    fade (with array)
 *    flash
 *  - This library requires defining RGB colors: https://www.w3schools.com/colors/colors_picker.asp
 */

#include "Particle.h"


const int PIN_RED = D2;
const int PIN_GREEN = D3;
const int PIN_BLUE = D4;

//added for library
#include "rgb-controls.h"
using namespace RGBControls;
Led led(PIN_RED, PIN_GREEN, PIN_BLUE);
Color red(255, 0, 0);
Color blue(0, 0, 255);
Color purple(150, 0, 150);
Color orange(255, 128, 0);
Color green(0, 255, 0);
Color yellow(255, 255, 0);
Color magenta(255, 0, 255);
Color cyan(0, 255, 255);
 
Color colors[6] = {red, green, blue, yellow, magenta, cyan};


void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  // Fade the light between red and blue every second
  // led.fade(red, blue, 2000);

  // Pulse red from 10% brightness to 100% brightness every 5 seconds
  // led.fade(red.withBrightness(10), red, 5000);

  // Flash the led purple 3 times with the default on / off times
  // for (int i = 0; i < 3; i++) {
  //   led.flash(orange);
  // }

  // Flash all lights in the array for 1 second with 0 ms off time
  // led.flash(colors, 6, 500, 0);

    // Fade between each color in the array every 3 seconds
  led.fade(colors, 3, 3000);

}

void displayRandomColor() {
  int r = random(0, 256);
  int b = random(0, 256);
  int g = random(0, 256);
  analogWrite(PIN_RED, r);
  analogWrite(PIN_GREEN, g);
  analogWrite(PIN_BLUE, b);
}
void displayColor(int r, int g, int b) {
  analogWrite(PIN_RED, r);
  analogWrite(PIN_GREEN, g);
  analogWrite(PIN_BLUE, b);
}