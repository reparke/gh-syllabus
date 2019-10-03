/*
 * Project serial_monitor
 * Description:
 * Author:
 * Date:
 */

const int PIN_INPUT = D2;
int lightValue = 255;
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(PIN_INPUT, INPUT);
  Serial.begin(9600);  // est. communication rate
}

void loop() {
  // The core of your code will likely live here.

  Serial.println("Entering loop");
  int val = digitalRead(PIN_INPUT);

  Serial.println("The value on pin D2 is " + String(val));
  delay(1000);
}