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
  delay(100);
  // Put initialization like pinMode and begin functions here.

  pinMode(PIN_POT, INPUT);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  delay(500);
  potValue = analogRead(PIN_POT);  // 0-4095
  //Analog to Digital conversion
  //take analog input (voltage) and convert to digital value
  //  for argon, our "digital values" are 12 bit binary numbers [0-4095]
  //  0 --> 0v,   2048 --> 1.67v,   4095 --> 3.3v
  Serial.println("Pot value: " + String(potValue));


  //when we want to effect something in the real world
  //if that needs to have an analog "flavor" (signal) (e.g. varying light level
  //or vary motor speed)

  //Argon produces a digital signal but we FAKE an analog output using PWM
  //we use analogWrite to vary the output signal (aka changing the duty cycle)
  //when we use analogwrite, we get to specify 8 bit binary number [0-255]
  //0 --> 0v, 255 --> 3.3v

  //in c++, int / int --> int (truncates)
  //we need to convert (or cast) the number
  //Attempt 1
  int pwmValue = (float) potValue * 255 / 4095;

  // //attempt 2 -- incorrect
  // float pwmValue = potValue / 4095 * 255;

  // //attempt 3 -- correct
  // float pwmValue = (float) potValue / 4095 * 255;

  // //attempt 3 -- correct
  // float pwmValue = potValue / 4095.0 * 255;

  Serial.println("PWM: " + String(pwmValue)  );
   // float pwmValue = potValue / 409 * 255;ظ
  delay(100);
  analogWrite(PIN_LED, pwmValue);


}