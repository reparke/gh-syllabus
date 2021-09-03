/*
 * Project blink_ic_20201
 * Description:
 * Author:
 * Date:
 */

// setup() runs once, when the device is first turned on.
void setup() {

  //which pin on the argon am I using, what I am doing with it
  pinMode(D7, OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

  //turn on LED
  // digitalWrite(D7, HIGH);
  // //stay on for 1 sec
  // delay(1000);
  // //turn off led
  // digitalWrite(D7, LOW);
  // //stay off for 1 sec
  // delay(1000);

for (int i = 0; i < 255; i++) {
  analogWrite(D7, i);
  delay(10);
}

  //control (or command) + shift + 
}