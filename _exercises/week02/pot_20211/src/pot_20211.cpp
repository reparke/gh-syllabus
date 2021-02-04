/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "f:/Github/ITP_348_Content_Public/_exercises/week02/pot_20211/src/pot_20211.ino"

void setup();
void loop();
#line 2 "f:/Github/ITP_348_Content_Public/_exercises/week02/pot_20211/src/pot_20211.ino"
void setup() {
  Serial.begin(9600);   //9600
  Serial.println("In setup");
  pinMode(D7, OUTPUT);
}
void loop() {
  digitalWrite(D7, HIGH);
  delay(500);

}