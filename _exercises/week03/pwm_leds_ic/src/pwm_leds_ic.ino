/*
 * Project pwm_leds_ic
 * Description:
 * Author:
 * Date:
 */

const int PIN_LED = D2;
const int PIN_POT = A0;
int potValue = 0;
int pwmValue = 0;

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.

  pinMode(PIN_POT, INPUT);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

  potValue = analogRead(PIN_POT);
  Serial.println("Pot value: " + String(potValue));



  // converting from ADC 0-4095...to PWM from 0-255
  // 255 int; 4095 int
  // int divide int => int
  pwmValue = (float) potValue * 255 /  4095;
  analogWrite(PIN_LED, pwmValue);
  Serial.println("PWM value: " + String(pwmValue));

}