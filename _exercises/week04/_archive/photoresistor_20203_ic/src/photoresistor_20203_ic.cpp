/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Rob/Documents/_GitHub/ITP_348_Content_Public/_exercises/week04/photoresistor_20203_ic/src/photoresistor_20203_ic.ino"
void setup();
void loop();
#line 1 "c:/Users/Rob/Documents/_GitHub/ITP_348_Content_Public/_exercises/week04/photoresistor_20203_ic/src/photoresistor_20203_ic.ino"
const int PIN_PHOTORESISTOR = A5;

/*
  bright 3800
  ambient 1200
  dark 200

  */

 const int THRESHOLD_DARK = 400;  //0-400 is dark
 const int THRESHOLD_AMBIENT = 2000; // 400-2000 is ambient light
 //bright is 2000-4095

int lightReading; //global
String lightString; //global

void setup() {
  Serial.begin(9600);
  pinMode(PIN_PHOTORESISTOR, INPUT);

  //register my variables
  Particle.variable("Light String", lightString);
  Particle.variable("Light Reading", lightReading);
}

void loop() {
  lightReading = analogRead(PIN_PHOTORESISTOR);
  if (0 < lightReading && lightReading < THRESHOLD_DARK) {
    lightString = "dark";
  }
  else if (THRESHOLD_DARK <= lightReading && lightReading < THRESHOLD_AMBIENT){
    lightString = "ambient";
  }
  else {
    lightString = "bright";
  }
  //ADC will never be negative
  //ADC from 0 to 4095

  Serial.println("Photoresitor value = " + String(lightReading));
  Serial.println("LightString  = " + lightString);

  delay(500); //do this so we don't crash our serial monitor
}