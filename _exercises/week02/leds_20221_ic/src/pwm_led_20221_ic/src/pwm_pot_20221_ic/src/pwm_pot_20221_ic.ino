const int PIN_LED = D2;
const int PIN_POT = A0;

// setup() runs once, when the device is first turned on.
void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_POT, INPUT);
}

void loop() {
  int potValue = analogRead(PIN_POT);

  // input: 0 to 3.3v but with ADC we will 0 - 4095
  // output: 0 to 255
  int pwmValue = potValue / 4095.0 * 255;
  int pwmValue = (float) potValue / 4095 * 255;
  Serial.println("Pot value: " + String(potValue) + ", PWM value: " + String(pwmValue));
  analogWrite(PIN_LED, pwmValue);
  delay(100);

}

//use the potetiometer to change LED brightness