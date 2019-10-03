/*  RGB LED Sketch with functions
 *
 * Custom functions for generating colors
 *
 * Components
 * ----------
 *  - Particle Argon
 *  - RGB LED
 *  - 330 Ohms Resistors
 *
 *  Libraries
 *  ---------
 *  -
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
 *
 */

#include "Particle.h"

const int PIN_RED = D2;
const int PIN_GREEN = D3;
const int PIN_BLUE = D4;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  displayColor(255, 0, 0);
  delay(500);

  displayColor(0, 255, 0);
  delay(500);

  displayColor(0, 0, 255);
  delay(500);

  displayRandomColor();
  delay(500);
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