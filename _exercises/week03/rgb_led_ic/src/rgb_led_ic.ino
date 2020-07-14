const int PIN_RED = D3;
const int PIN_GREEN = D4;
const int PIN_BLUE = D5;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  // for a better approx of a truly number
  randomSeed(analogRead(A0));  // optional
}

void loop() {
  // displayRandomColor();
  displayColor(127, 255, 0);
  delay(500);
}

void displayRandomColor() {
  analogWrite(PIN_RED, random(0, 255));
  analogWrite(PIN_GREEN, random(0, 255));
  analogWrite(PIN_BLUE, random(0, 255));
}

void displayColor(int r, int g, int b) {
  analogWrite(PIN_RED, r);
  analogWrite(PIN_GREEN, g);
  analogWrite(PIN_BLUE, b);
}
// const int PIN_BUTTON = D2;

// int prevState = LOW;
// int currState = HIGH;  // button open unpressed
// int ledState = LOW;    // off

// // setup() runs once, when the device is first turned on.
// void setup() {
//   // Put initialization like pinMode and begin functions here.
//   pinMode(PIN_BUTTON, INPUT);
//   pinMode(PIN_, OUTPUT);

//   Serial.begin(9600);
// }

// // loop() runs over and over again, as quickly as it can execute.
// void loop() {
//   // The core of your code will likely live here.
//   int currState = digitalRead(PIN_BUTTON);

//   Serial.println("InputRead: " + String(currState));

//   // if (currState == HIGH && prevState == LOW && ledState == LOW) {
//   //   digitalWrite(PIN_LED, HIGH);
//   // } else if (currState == HIGH && prevState == LOW && ledState == HIGH) {
//   //   digitalWrite(PIN_LED, LOW);
//   // }

//   if (currState == HIGH && prevState == LOW ) {
//     ledState = !ledState;
//   }
//   digitalWrite(PIN_LED, ledState);
//   prevState = currState;
// }