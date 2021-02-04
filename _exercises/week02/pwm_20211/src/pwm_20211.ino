//start global declaration
// 1. define all my pins
//every pin is an int
const int PIN_LED = D2; //allowed pins are D8-D0; A5-A0
const int PIN_TEMP_SENSOR = A3; //another example
const int ONBOARD_LED = D7;



// setup() runs once, when the device is first turned on.
//initialize any important variables
//set pinMode for all the pins you'll be using 
void setup() {
  //we an LED
  pinMode(PIN_LED, OUTPUT);  //OUTPUT or INPUT
  pinMode(ONBOARD_LED, OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

  //send a signal to turn on LED
  //when the anode voltage is HIGH (3.3), the LED turns on
  //when the anode voltage is LOW, the LED turns off
  digitalWrite(PIN_LED, HIGH);  //HIGH or LOW
  digitalWrite(ONBOARD_LED, HIGH);
  delay(1000);                      //delay is function that pauses EVERYTHING for X milliseconds
  digitalWrite(PIN_LED, LOW);      //HIGH or LOW
  delay(500);     //500 millisecond or 1/2 second
  
}