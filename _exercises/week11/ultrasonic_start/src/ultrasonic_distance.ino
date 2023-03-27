

const int PIN_RED = D2;
const int PIN_GREEN = D3;
const int PIN_BLUE = D4;

const int PIN_TRIGGER = D6;
const int PIN_ECHO = D5;

double distanceCm;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop() {}
