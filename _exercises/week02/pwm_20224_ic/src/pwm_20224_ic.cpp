#include "Particle.h"
SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_INFO);

//define constants that represent each pin
// step 1
const int PIN_LED = A1;
const int PIN_POT = A0;

/*
  how could we adjust the brightness automatically (so the LED gets brighter on its own)?
    -counter that increments with time
    -loop

    MCU
      setup() runs ONCE everytime device restarts
      loop() is an INFINITE that runs forever...DO NOT USE WHILE LOOPS
          - it's ok usually to use a for
      
      need a counter 0 - 255
      everytime we go through loop(), we increment our counter
      then we analogWrite with the counter value
      add a short delay

    we need to create GLOBAL VARIABLES for the important variables that we want
      to persist / exist across each time the loop runs

    ---
    It's really useful to have debug or output messages
    We use Serial print statements to display messages

    USing Serial
    in setup(), we configure the Serial port
      Serial.begin(9600);  
    in loop(), we use the print functions
      Serial.println(....)
    Two cautions
      - if we print too often, the ARgon sometimes locks up
      - println() we can't + with strings and ints...
*/

//global var
int brightness = 0;

void setup() {
  //step 2: set you pin mode
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_POT, INPUT);

  //step 1: serial
  Serial.begin(9600);

}

void loop() {
  // int brightness = 0;    this would be a LOCAL var that would get erased each loop()
  //step 3: write to pin
  //digital write is on / off
  // analogWrite(PIN_LED, 255); // full brightness
  // delay(1000);  // 1000 millisec or 1 sec
  // analogWrite(PIN_LED, 127);  // half brightness
  // delay(1000);
  // analogWrite(PIN_LED, 0);  // 0 brightness which the same as digitalWrite (LOW)
  // delay(1000);

  //step 2: let's print the brightness val
  // Serial.println("Brightness value = " + String(brightness));
  // analogWrite(PIN_LED, brightness);
  // delay(1000);
  // brightness = brightness + 20;
  // if (brightness >= 255) {
  //   brightness = 0;
  // }
  // read the potentiometer-- what are is the range of expected values?
  // because analog input does ADC, 0 - 4095
  int potValue = analogRead(PIN_POT);
  Serial.println("Pot value = " + String(potValue));
  delay(1000);

}

//step 3: open serial monitor


// void funct () {
//   int x = 6;

// }