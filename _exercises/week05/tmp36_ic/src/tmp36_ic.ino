/*
* 10 mV / deg Celsius with a 500 mV offset
* Try this: if **Vout** is 1.2V, what is the temperature in Celsius? in
Fahrenheit?
* *Remember:*
  * T(fahr) = T(cel) * (9/5) + 32
  * T(cel) = (T(fahr) - 32 ) * (5/9)

1.2v - 500mv = 1.2V - 0.5V = 0.7V
now handle conversion
 0.7 V * degC / 10mV = 0.7V * degC / 0.01V
=0.7V * degC * 100 = 70 degC
Now to fahrenheit
158 degF
*/

const int PIN_TMP36 = A5;
double tempC = 0;
double tempF = 0;

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(PIN_TMP36, INPUT);
  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  int val = analogRead(PIN_TMP36);
  Serial.println("TMP36 ADC val: " + String(val));

  double tmp36Voltage = val * 3.3 / 4095;
  Serial.println("TMP36 voltage: " + String(tmp36Voltage));

  tempC = (tmp36Voltage - 0.5) * 100;   //divide 0.01 mv
  Serial.println("TMP36 tempC: " + String(tempC));

  tempF =
      tempC * (9.0 / 5) + 32;  // NOTE: C++ division of ints truncates decimal
  Serial.println("TMP36 tempF: " + String(tempF));

  Serial.println();

  delay(2000);
}  