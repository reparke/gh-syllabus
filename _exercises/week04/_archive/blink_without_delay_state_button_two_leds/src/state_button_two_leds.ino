// // first version
// // illustrate delay blocking
// const int PIN_BUTTON = D2;
// const int PIN_LED1 = D3;
// const int PIN_LED2 = D4;

// int LED1_STATE = LOW;
// int lastButtonState = HIGH;
// int currentButtonState = LOW;

// void setup() {
//   pinMode(PIN_BUTTON, INPUT);
//   pinMode(PIN_LED1, OUTPUT);
//   pinMode(PIN_LED2, OUTPUT);
//   Serial.begin(9600);
// }

// void loop() {
//   int currentButtonState = digitalRead(PIN_BUTTON);
//   Serial.println("Read: " + String(currentButtonState));

//   if (currentButtonState == HIGH && lastButtonState == LOW) {
//     LED1_STATE = !LED1_STATE;
//   }

//     //run code with out these blocks first
//     //then add these lines to see how delay is blocking
//     digitalWrite(PIN_LED2, HIGH);
//     delay(1000);
//     digitalWrite(PIN_LED2, LOW);
//     delay(1000);
//     digitalWrite(PIN_LED2, HIGH);
//     delay(1000);
//     digitalWrite(PIN_LED2, LOW);
//     delay(1000);
//     digitalWrite(PIN_LED2, HIGH);

//   if (LED1_STATE == HIGH) {
//     digitalWrite(PIN_LED1, HIGH);
//   }
//   else{
//     digitalWrite(PIN_LED1, LOW);
//   }

//     lastButtonState = currentButtonState;
// }

// // version 2 - millis
// // illustrate delay blocking
// const int PIN_BUTTON = D2;
// const int PIN_LED1 = D3;
// const int PIN_LED2 = D4;

// int LED1_STATE = LOW;
// int lastButtonState = HIGH;
// int currentButtonState = LOW;

// // track time
// unsigned long prevMillisLed2Blink = 0;  // start at 0
// int LED2_STATE = LOW;
// unsigned long intervalLed2 = 1000;  // ms between blink

// void setup() {
//   pinMode(PIN_BUTTON, INPUT);
//   pinMode(PIN_LED1, OUTPUT);
//   pinMode(PIN_LED2, OUTPUT);
//   Serial.begin(9600);
// }

// /*
//   if LED IS ON AND the interval since we last changed the state has elapsed
//       then we turn the light off AND update the time
//   if LED is OFF and the interval has elapsed
//       then we turn ON the light and update the time
// */
// void loop() {
//   int currentButtonState = digitalRead(PIN_BUTTON);
//   Serial.println("Read: " + String(currentButtonState));

//   unsigned long curMillis = millis();

//   if ((curMillis - prevMillisLed2Blink) > intervalLed2) {
//     LED2_STATE = !LED2_STATE;
//     digitalWrite(PIN_LED2, LED2_STATE);
//     prevMillisLed2Blink = curMillis;
//   }

//   if (currentButtonState == HIGH && lastButtonState == LOW) {
//     LED1_STATE = !LED1_STATE;
//   }

//   //   //run code with out these blocks first
//   //   //then add these lines to see how delay is blocking
//   //   digitalWrite(PIN_LED2, HIGH);
//   //   delay(1000);
//   //   digitalWrite(PIN_LED2, LOW);
//   //   delay(1000);
//   //   digitalWrite(PIN_LED2, HIGH);
//   //   delay(1000);
//   //   digitalWrite(PIN_LED2, LOW);
//   //   delay(1000);
//   //   digitalWrite(PIN_LED2, HIGH);

//   if (LED1_STATE == HIGH) {
//     digitalWrite(PIN_LED1, HIGH);
//   } else {
//     digitalWrite(PIN_LED1, LOW);
//   }

//   lastButtonState = currentButtonState;
// }

// version 3 - two timers
const int PIN_BUTTON = D2;
const int PIN_LED1 = D3;
const int PIN_LED2 = D4;

int LED1_STATE = LOW;
int lastButtonState = HIGH;
int currentButtonState = LOW;

// track time
unsigned long prevMillisLed2Blink = 0;  // start at 0
unsigned long prevMillisLed1Blink = 0;  // start at 0
int LED2_STATE = LOW;
unsigned long intervalLed2 = 1000;  // ms between blink
unsigned long intervalLed1 = 300;   // ms between blink

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  Serial.begin(9600);
}

/*
  if LED IS ON AND the interval since we last changed the state has elapsed
      then we turn the light off AND update the time
  if LED is OFF and the interval has elapsed
      then we turn ON the light and update the time
*/
void loop() {
  int currentButtonState = digitalRead(PIN_BUTTON);
  Serial.println("Read: " + String(currentButtonState));

  unsigned long curMillis = millis();

  if ((curMillis - prevMillisLed2Blink) > intervalLed2) {
    LED2_STATE = !LED2_STATE;
    digitalWrite(PIN_LED2, LED2_STATE);
    prevMillisLed2Blink = curMillis;
  }

  if ((curMillis - prevMillisLed1Blink) > intervalLed1) {
    LED1_STATE = !LED1_STATE;
    digitalWrite(PIN_LED1, LED1_STATE);
    prevMillisLed1Blink = curMillis;
  }

  // disable latching and do two different rates
  // if (currentButtonState == HIGH && lastButtonState == LOW) {
  //   LED1_STATE = !LED1_STATE;
  // }

  // if (LED1_STATE == HIGH) {
  //   digitalWrite(PIN_LED1, HIGH);
  // } else {
  //   digitalWrite(PIN_LED1, LOW);
  // }

  // lastButtonState = currentButtonState;
}