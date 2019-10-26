/*
 * Project serial_monitor
 * Description:
 * Author:
 * Date:
 */

// const int PIN_INPUT = D2;
const int PIN_LED = D2;
int lightValue = 255;
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);   //est. communication rate
}

void loop() {
  // The core of your code will likely live here.

  // Serial.println("Entering loop");
  // int val = digitalRead(PIN_INPUT);

  // Serial.println("The value on pin D2 is " + String(val));
  // delay(1000);

  //write full brightness
  analogWrite(PIN_LED, 255); //100%
  delay(2000);
  analogWrite(PIN_LED, 127); //50%
  delay(2000);

  
  while (lightValue > 0) {
    lightValue = lightValue - 5;
    analogWrite(PIN_LED, lightValue);
    delay(50);
  }
  while (lightValue < 255) {
    lightValue = lightValue + 5;
    analogWrite(PIN_LED, lightValue);
    delay(50);
  }
}