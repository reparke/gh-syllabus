#include "Particle.h"
SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_INFO);



/* Good practice - things to do on starting a new project
  - configure project
  - define our pin labels (possibly other global vars)
  - set pinMode
  - Serial.begin
*/

const int PIN_POT = A0;
const int PIN_LED = D2;

void setup() {
  pinMode(PIN_POT, INPUT);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    // read the potentiometer value
    double potVal = analogRead(PIN_POT);  // what is this value? range: 0-4095 as int because ADC


    // we want to use the pot to vary the LED brightness
    // we connect the pot to the argon
    // we connect the led to the argon
    //the argon READS / samples the pot value
    // the argon then uses the pot value to write a different value to the led

    // analog output: PWM on a range of 0-255
    int ledBrightness = float(potVal) / 4095 * 255; // convert ADC value to PWM value


    analogWrite(PIN_LED, ledBrightness);

    // print it to the serial monitor
    Serial.println("Potentiometer value = " + String(potVal) + "; LED PWM = " + String(ledBrightness));

    delay(500); //500 millisecond delay

    /*
      in C++, when we use / (division) with integers, the answer is an int
          99 / 100  --> 0
          solution: when we have to do division with integers, make one of the
      number a float

          int ledBrightness = potVal / 4095.0 * 255

          int ledBrightness = float(potVal) / 4095 * 255
    */
 }

 /*
  green check means yes it works
  red x means no it doesn't
  random emoji means still working / need more time
 */