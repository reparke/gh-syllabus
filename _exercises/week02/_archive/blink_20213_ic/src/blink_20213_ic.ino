
// setup() runs once, when the device is first turned on.
//create a label for our LED
const int PIN_LED = D7;
const int PIN_RED_LED = D2;
const int PIN_POT = A0;

void setup() {
  //initialize our pins--any pins you plan to use as input / output
  //you have to configure
  Serial.begin(9600);   //put this in setup from now on
  Serial.println("We are on setup now!");
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_RED_LED, OUTPUT);
  pinMode(PIN_POT, INPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

  //potentiometers are using Analog to Digital Conversion (ADC)
  //this is using the ADC; it is sampling the input voltage at pin A0
  // voltage range is 0-3.3v
  // pot range is 0-4095 (12 bit)
  // pot varies the resistance; by using a voltage divider, we can then vary
  int potValue = analogRead(PIN_POT);
  float voltage = potValue / 4095.0 * 3.3;    //when you're doing division in C++, and you want a float, you need convert one of the number 
                                            // to be a float first

  // float voltage = (float) potValue / 4095 * 3.3;
  Serial.println("The pot value is " + String(potValue) + ", voltage is " +
                 String(voltage));

  int pwmValue = potValue * 255 / 4095.0;
analogWrite(PIN_RED_LED, pwmValue);

  // digitalWrite(PIN_LED, HIGH);
  // delay(500); // 1/2 second delay
  // digitalWrite(PIN_LED, LOW);
  // delay(500);

  //this was automatic
  // for (int i = 0; i <= 255; i++) {
  //   analogWrite(PIN_LED, i);
  //   delay(50);
  //   analogWrite(PIN_RED_LED, 255-i);
  //   delay(50);
  // }
  // analogWrite(PIN_LED, 255);
  // delay(500);
  // analogWrite(PIN_LED, 127);
  // delay(500);
  // analogWrite(PIN_LED, 0);
  // delay(500);


}