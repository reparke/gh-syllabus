/*
 * Project blink_ic
 * Description:
 * Author:
 * Date:
 */

//define a const everytime were refer to pin
const int PIN_LED = D7;
const int PIN_LED2 = D6;

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  digitalWrite(PIN_LED, HIGH);
  digitalWrite(PIN_LED2, LOW);
  delay(1000);
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_LED2, HIGH);
  delay(1000);
}