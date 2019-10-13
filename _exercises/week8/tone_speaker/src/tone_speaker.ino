#include <Arduino.h>
/*  Passive buzzer demo sketch
 *
 * This sketch shows you how to play a tune using a passive
 * buzzer and the tone function that comes with the standard
 * Arduino library
 *
 * This sketch was adapted from the original that comes with the
 * Arduino IDE examples for Arduino Step by Step by Peter Dalmaris.
 *
 * Components
 * ----------
 *  - Arduino Uno
 *  - Passive buzzer with two or three pins
 *
 *  Libraries
 *  ---------
 *  - None
 *
 * Connections
 * -----------
 *  If you have a two pin passive buzzer, connect the pin marked "-"
 *  to Arduino GND, and the other pin to Arduino pin 8.
 *
 *  If you have a three pin passive buzzer, connect the pin marked "-"
 *  to GND, the pin marked "S" to Arduino digital pin 8, and the last
 *  pin to Arduino pin 8.
 *
 *  Created on November 21 2016 by Peter Dalmaris
 *
 */

/* This is the original sketch header. */
/*
  Melody
 Plays a melody
 circuit:
 * 8-ohm speaker on digital pin 8
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe
This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/Tone
 */
#include "pitches.h"

/*
  if button OR (alarm TRUE AND snooze FALSE)


*/

unsigned long currentTime;  // for testing
int songChoice = 1;
const int PIN_SPEAKER = D6;
const int PIN_SNOOZE = D5;

// notes in the melody:
int melody1[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3,
                 NOTE_G3, 0,       NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations1[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup() {
  pinMode(PIN_SPEAKER, OUTPUT);
  pinMode(PIN_SNOOZE, INPUT);

  Particle.variable("curTime", currentTime);

  Particle.function("playSong", playSong);
}

void loop() {
  // updateSnooze();
  unsigned long curTime = millis();

  currentTime = curTime;

  // bool condition1 = (alarmOn == true && snoozeOn == false);
  // bool condition2 =
  //     (alarmOn == true && snoozeOn == true && endSnoozeTime < curTime);
  // bool compound = (condition1 || condition2);
  // Serial.println("c1: " + String(condition1) + "; c1: " + String(condition2)
  // +
  //                "; OR: " + String(compound));

  playSong("");
}

int playSong(String input) {
  Serial.println("Inside play song");
  // iterate over the notes of the melody:
  if (songChoice == 1) {
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      // to calculate the note duration, take one second
      // divided by the note type.
      // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations1[thisNote];
      tone(PIN_SPEAKER, melody1[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(PIN_SPEAKER);
    }
  }
