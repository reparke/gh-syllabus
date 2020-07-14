
// simple latching button code
// glithcing because no debouncing is used
const int PIN_BUTTON = D2;
const int PIN_LED = D3;

int LEDstate = LOW;
int lastButtonState = HIGH;
int currentButtonState = LOW;

void setup() {
  pinMode(PIN_BUTTON, INPUT);  // button
  pinMode(PIN_LED, OUTPUT);    // LED
  Serial.begin(9600);
}

void loop() {
  currentButtonState = digitalRead(PIN_BUTTON);
  Serial.println("currentButtonState: " + String(currentButtonState) +
                 "; lastButtonState: " + String(lastButtonState) + "; LEDstate: " + String(LEDstate));

  if (currentButtonState == HIGH && lastButtonState == LOW) {
    LEDstate = !LEDstate;
  }
  digitalWrite(PIN_LED, LEDstate);

  lastButtonState = currentButtonState;
}

// basic button
// const int PIN_BUTTON = D2;
// const int PIN_LED = D3;

// void setup() {
//   pinMode(PIN_BUTTON, INPUT); //button
//   pinMode(PIN_LED, OUTPUT);  //LED
//   Serial.begin(9600);
// }

// void loop() {
//   int buttonRead = digitalRead(PIN_BUTTON);
//   Serial.println("ButtonRead: " + String(buttonRead));

//   if (buttonRead == HIGH) {
//     digitalWrite(PIN_LED, LOW);  //button HIGH means open, which means LED
//     should be off
//   }
//   else {      //button LOW means closed, ,which means LED is on
//     digitalWrite(PIN_LED, HIGH);
//   }
// }