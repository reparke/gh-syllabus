/*
  Led 1 is on for 2000ms, off for 1000ms
  led 2 is on for 300 ms, and off for 300ms
*/

unsigned long prevMillis = 0;  // the last time we took specific action ON LED 1
unsigned long prevMillis2 = 0;

// state of our program
int ledState1 = LOW;  // status of our first led
int ledState2 = LOW;
unsigned long interval1 =
    2000;  // interval is a LONG because we will need to compare it to time
unsigned long interval2 = 1000;  // off time
unsigned long interval3 = 300;

// pin
const int LED1_PIN = D2;
const int LED2_PIN = D3;
const int SPEAKER_PIN = D4;

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
}

/*
  if LED IS ON AND the interval since we last changed the state has elapsed
      then we turn the light off AND update the time
  if LED is OFF and the interval has elapsed
      then we turn ON the light and update the time
*/

void loop() {
  // we are keeping time--> what is the current time
  unsigned long curMillis =
      millis();  // current time (in ms) since argon turned on
  tone(SPEAKER_PIN, 1000, 500);

  if (ledState1 == HIGH && (curMillis - prevMillis) >= interval1) {
    ledState1 = LOW;         // change the state so the light is low
    prevMillis = curMillis;  // update the last time we did soemthing
                             // interesting

  } else if (ledState1 == LOW && (curMillis - prevMillis) >= interval2) {
    ledState1 = HIGH;
    prevMillis = curMillis;
  }

  else if (ledState2 == HIGH && (curMillis - prevMillis2) >= interval3) {
    ledState2 = LOW;  // change the state so the light is low
    prevMillis2 =
        curMillis;  // update the last time we did soemthing interesting
  } else if (ledState2 == LOW && (curMillis - prevMillis2) >= interval3) {
    ledState2 = HIGH;
    prevMillis2 = curMillis;
  }
  digitalWrite(LED1_PIN, ledState1);
  digitalWrite(LED2_PIN, ledState2);
}