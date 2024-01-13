#include "Particle.h"
SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_INFO);


void setup() {
  //tell the argon if pin D2 is input or output
  pinMode(D2, OUTPUT);
}

void loop() {
  //turn on led
  digitalWrite(D2, HIGH);
  //pause with "delay"
  delay(1000);  //1000 milliseconds or 1 sec
  digitalWrite(D2, LOW);
  delay(1000);
}

/*
1: Make new project
2: configure project for device
3: write some code
4: Cloud Flash
*/