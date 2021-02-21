
const int PIN_TMP36 = A0;
float tempC = 0;
float tempF = 0;
//float, double  is just a float var that uses twice as many bits
//double and float are BOTH "Floats" --> both numbers with decimals

void setup()
{
  pinMode(PIN_TMP36, INPUT);
}

void loop()
{
  Serial.begin(9600);
  int val = analogRead(PIN_TMP36); // what is this? an int betw 0-4995
  //this represents our ADC-->"digital approximation" of the actual voltage
  // val = 0 --> voltage is 0v      val = 4095 --> voltage is 3.3v

  //we need an actual voltage to figure out the temp
  float voltage = (float)val / 4095 * 3.3; //volts

  //formula for voltage --> TempC
  // (voltage - 0.5) / 0.01        0.5 v subtract   and then divide by 0.01 v (10 mV)
  tempC = (voltage - 0.5) / 0.01; //temperature in C

  tempF = tempC * (9.0 / 5) + 32; //temp in F

  Serial.println("TMP36 tempC " + String(tempC));
  Serial.println("TMP36 tempF: " + String(tempF));

  //pubish (EVENT NAME, EVENT VALUE)
  Particle.publish("initial_state_20211_temperature", String(tempF), PRIVATE);
  Particle.publish("initial_state_20211_temperature", String(humidity), PRIVATE);
  delay(2000);
}
