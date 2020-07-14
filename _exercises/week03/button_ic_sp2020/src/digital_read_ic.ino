
// const int PIN_BUTTON = D2;

// // setup() runs once, when the device is first turned on.
// void setup() {
//   // Put initialization like pinMode and begin functions here.
//   pinMode(PIN_BUTTON, INPUT);

//   Serial.begin(9600);
// }

// // loop() runs over and over again, as quickly as it can execute.
// void loop() {
//   // The core of your code will likely live here.
//   int inputRead = digitalRead(PIN_BUTTON);

//   Serial.println("InputRead: " + String(inputRead));
//   delay(400);
// }

const int PIN_BUTTON = D2;
const int PIN_LED = D8;
int prevState = LOW;
int currState = HIGH;  // button open unpressed
int ledState = LOW;    // off

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED, OUTPUT);

  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  int currState = digitalRead(PIN_BUTTON);

  Serial.println("InputRead: " + String(currState));

  // if (currState == HIGH && prevState == LOW && ledState == LOW) {
  //   digitalWrite(PIN_LED, HIGH);
  // } else if (currState == HIGH && prevState == LOW && ledState == HIGH) {
  //   digitalWrite(PIN_LED, LOW);
  // }

  if (currState == HIGH && prevState == LOW ) {
    ledState = !ledState;
  }
  digitalWrite(PIN_LED, ledState);
  prevState = currState;
}
//analog write
//int num = random(0, 255);