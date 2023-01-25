const int PIN_RGB_RED = D2;
const int PIN_RGB_GREEN = D3;
const int PIN_RGB_BLUE = D4;
const int PIN_BUTTON = D5;

int stateButtonCurrent = HIGH;
int stateButtonLast = HIGH;

void setup()
{
  pinMode(PIN_RGB_RED, OUTPUT);
  pinMode(PIN_RGB_GREEN, OUTPUT);
  pinMode(PIN_RGB_BLUE, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);

  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  // The core of your code will likely live here.

  //useful trick
  //turn on red light, delay for 1 sec, turn on green light, delay, turn on blue, delay
  // digitalWrite(PIN_RGB_RED, HIGH);
  // digitalWrite(PIN_RGB_GREEN, LOW);
  // digitalWrite(PIN_RGB_BLUE, LOW);
  // delay(1000);
  // digitalWrite(PIN_RGB_RED, LOW);
  // digitalWrite(PIN_RGB_GREEN, HIGH);
  // digitalWrite(PIN_RGB_BLUE, LOW);
  // delay(1000);
  // digitalWrite(PIN_RGB_RED, LOW);
  // digitalWrite(PIN_RGB_GREEN, LOW);
  // digitalWrite(PIN_RGB_BLUE, HIGH);
  // delay(1000);

  // int x = random(0, 256);   //0 - 255

  //1) random generates a color and delays for 1 sec
  //2) when you press the button, it will randomly display a new color

  // int red = random(0, 256); //0-255 (don't include the endpoint)
  // int green = random(0, 256);
  // int blue = random(0, 256);

  // analogWrite(PIN_RGB_RED, red);
  // analogWrite(PIN_RGB_GREEN, green);
  // analogWrite(PIN_RGB_BLUE, blue);
  // delay(250);

  // stateButtonCurrent = digitalRead(PIN_BUTTON);
  // if (stateButtonCurrent == LOW && stateButtonLast == HIGH) {
  //   int red = random(0, 256); //0-255 (don't include the endpoint)
  //   int green = random(0, 256);
  //   int blue = random(0, 256);

  //   analogWrite(PIN_RGB_RED, red);
  //   analogWrite(PIN_RGB_GREEN, green);
  //   analogWrite(PIN_RGB_BLUE, blue);
  // }
  // stateButtonLast = stateButtonCurrent;
  //orange  241, 145, 16
    analogWrite(PIN_RGB_RED, 241);
    analogWrite(PIN_RGB_GREEN, 145);
    analogWrite(PIN_RGB_BLUE, 16);
}
