//may be glitching because not using debouncing

// first version

// const int PIN_BUTTON = D2;
// const int PIN_LED1 = D3;
// const int PIN_LED2 = D4;

// void setup() {
//   pinMode(PIN_BUTTON, INPUT);
//   pinMode(PIN_LED1, OUTPUT);
//   pinMode(PIN_LED2, OUTPUT);
//   Serial.begin(9600);
// }

// void loop() {
//   int read = digitalRead(PIN_BUTTON);
//   Serial.println("Read: " + String(read));
//   if (read == HIGH) {
//     digitalWrite(PIN_LED1, HIGH);
//   }
//   else{
//     digitalWrite(PIN_LED1, LOW);
//   }
// }



//v2 - latch

const int PIN_BUTTON = D2;
const int PIN_LED1 = D3;
const int PIN_LED2 = D4;

int LED1_STATE = LOW;
int lastButtonState = HIGH;
int currentButtonState = LOW;

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int currentButtonState = digitalRead(PIN_BUTTON);
  Serial.println("currentButtonState: " + String(currentButtonState) +
                 "; lastButtonState: " + String(lastButtonState) + "; LEDstate: " + String(LEDstate));

  if (currentButtonState == HIGH && lastButtonState == LOW) {
    LED1_STATE = !LED1_STATE;
  }

  if (LED1_STATE == HIGH) {
    digitalWrite(PIN_LED1, HIGH);
  }
  else{
    digitalWrite(PIN_LEDq, LOW);
  }

    lastButtonState = currentButtonState;
}