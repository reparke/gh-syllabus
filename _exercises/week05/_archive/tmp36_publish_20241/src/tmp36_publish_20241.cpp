#include "Particle.h"
SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_WARN);

// TMP 36 is analog input device
const int PIN_TMP = A5;

// print out the temperature in fahrenheit
//   try by looking at the datasheet

void setup() {
    Serial.begin(9600);
    pinMode(PIN_TMP, INPUT);
}

// CONVERT  ADC_VALUE --> VOLTAGE --> Celsius --> Fahr
void loop() {
    int tmpReading = analogRead(PIN_TMP);  // 0 - 4095 ADC
    /*
    ADC (0-4095) ---> Voltage (0-3.3)
    */
    // float voltage = tmpReading / 4095 * 3.3;  //what's wrong with this?
    float voltage = tmpReading / 4095.0 * 3.3;  // what's wrong with this?

    // voltage to C --> 10mV / C with 0.5 voltage offset
    float tempC = (voltage - 0.5) / 0.01;
    float tempF = tempC * 9 / 5.0 + 32;

    Serial.println("Fahrenheit temp = " + String(tempF));

    //publish to cloud
    //we use delay, but know that we SHOULD NOT
    Particle.publish("temp", String(tempF,1)); // this tempF is the {{{PARTICLE_EVENT_VALUE}}}

    delay(2000);
}

/*
  1) read and calc temp - test with serial monitor
  2) publish to cloud - test with console.particle.io
  3) data is sent to initial state - if problems, check the particle integration
*/