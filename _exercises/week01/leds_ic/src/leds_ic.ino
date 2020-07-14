
//global variables
//a constant for each pin you plan to use
const int PIN_LED = D2;   //pin D2

const int DELAY_LED1 = 1000;

// setup() runs once, when the device is first turned on.
void setup() {
  //initialize the pin mode
  pinMode(PIN_LED, OUTPUT);

}

// loop() runs over and over again, as quickly as it can execute.
void loop() { digitalWrite(PIN_LED, HIGH);
  delay(DELAY_LED1);
  digitalWrite(PIN_LED, LOW); //LOW means 0 volts or ground GND
  delay(DELAY_LED1);
}