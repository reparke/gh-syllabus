/*  Basic RGB LED Sketch
 * 
 * Generates random colors on RGB LED by random selecting R, G, B values every 2 seconds
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
  int r = random(0, 256);
  int b = random(0, 256);
  int g = random(0, 256);
  analogWrite(PIN_RED, r);
  analogWrite(PIN_GREEN, g);
  analogWrite(PIN_BLUE, b);
  delay(2000);
}