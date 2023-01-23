
// create a global constant to represent each pin in our our project
const int PIN_POT = A0;
const int PIN_ONBOARD_LED = D7;
const int PIN_LED = D2;

// this happens JUST ONCE
// configure serial monitor, setup pin modes
void setup() {
    Serial.begin(9600);
    pinMode(PIN_POT, INPUT);
    pinMode(PIN_ONBOARD_LED, OUTPUT);
    pinMode(PIN_LED, OUTPUT);
    Serial.println("This message is in setup and shows only once");
}

// infinite loop
void loop() {
    Serial.println("Now we're are in loop()");
    int potVal = analogRead(PIN_POT);

    float voltage = potVal / 4095.0 * 3.3;
    //  float voltage = float(potVal) / 4095 * 3.3;
    // print out the digital value AND the analog voltage associated with it
    // 0-3.3v analog
    // 0-4095 digital
    Serial.println("The potentiometer value is " + String(potVal) +
                   " and the voltage is " +
                   String(voltage, 2));  // convert int -> str

    // delay(500); //500 ms
  analogWrite(PIN_LED, 0); //off
  delay(500);
  analogWrite(PIN_LED, 127);  //half bright
  delay(500);
  analogWrite(PIN_LED, 255); //full bright
  delay(500);

}