/*
install Blynk app on your phone

connect RGB led to argon (D2, D3, D4)

connect switch (Gnd - A0 - 3.3v)
*/
#include <blynk.h>    //library
char auth[] = "bRWQIXbU2uQmtoarMYEmRT3s_d8gmAEn";  //this is a array of characters with our token

//if you're sending values to from ARGON to APP (push), we MUST use millis()
//limit is 10 values per sec
//in loop(), we MUST NOT use delay
unsigned long blynkDelay = 1000;
unsigned long prevMillis = 0;

const int PIN_RED = D2;
const int PIN_GREEN = D3;
const int PIN_BLUE = D4;
const int PIN_SWITCH = A0;

//virtual pin headers
const int VPIN_RED = V0;
const int VPIN_GREEN = V1;
const int VPIN_BLUE = V2;
const int VPIN_SWITCH = V3;
//you do NOT need to set PINMODE for these virtual pins


//retrieve from app
// app ==> argon
//  create a special function called BLYNK_WRITE(<<PIN>>)

BLYNK_WRITE(V0) {
  //event handler for when the user moves the sliders on the app
  //we have a slider that send an integer value from 0-255
  //lets read the value on the slider
  int sliderValue = param.asInt();      //represents slider value
  analogWrite(PIN_RED, sliderValue);
}
BLYNK_WRITE(V1) {
    int sliderValue = param.asInt();  //represents slider value
    analogWrite(PIN_GREEN, sliderValue);
}
BLYNK_WRITE(V2) {
    int sliderValue = param.asInt();  //represents slider value
    analogWrite(PIN_BLUE, sliderValue);
}

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_SWITCH, INPUT);
  //1. have delay
  delay(5000);    //needs to be delay, not millis

  //2. connect to blynk
  Blynk.begin(auth);
}

void loop() {
  Blynk.run(); // do NOT put in millis timer
  
  unsigned long currMillis = millis();
  if (currMillis - prevMillis > blynkDelay) {
    prevMillis = currMillis;

    // NOW we send value
    // Blynk.virtualWrite(<<PIN>>, <<VALUE>>)
    Blynk.virtualWrite(VPIN_SWITCH, digitalRead(A0)); //send data from argon ===> app
  }
}










