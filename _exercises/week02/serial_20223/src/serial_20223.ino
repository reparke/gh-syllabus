//any data that needs to persist through each time loop runs MUST 
// be a global

// int counter = 0;  //global

//step 1
const int PIN_POT = A0;
const int PIN_LED = A1;

void setup() {
  //this is where we always start our serial monitor
  Serial.begin(9600);
  Serial.println("Hello world!");
  Serial.println("We should only see this code once");

  //step 2 - pinmode
  pinMode(PIN_POT, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // Serial.println("Now we are in loop so we'll see this a lot");
  delay(50); // 100 ms

  // counter = counter + 1;
  // Serial.println("The counter is now " + String(counter));

  // how to read an analog sensor
  int potValue = analogRead(PIN_POT);
  // range from 0 - 4095 (estimation of voltage 0-3.3)

  int pwmValue = potValue / 4095.0 * 255;   
  // division with integers results in an INTEGER

  analogWrite(PIN_LED, pwmValue);


  Serial.println("POT: "  + String(potValue)  + ", PWM: " + String(pwmValue));

}