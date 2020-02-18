
const int PIN_BUTTON = D2;

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(PIN_BUTTON, INPUT);

  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  int inputRead = digitalRead(PIN_BUTTON);

  Serial.println("InputRead: " + String(inputRead));
  delay(400);
}
