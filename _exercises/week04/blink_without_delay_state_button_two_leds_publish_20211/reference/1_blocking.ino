// first version
// illustrate delay blocking
const int PIN_BUTTON = D2;
const int PIN_LED1 = D3;
const int PIN_LED2 = D4;

int currentButtonState = LOW;

void setup()
{
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  currentButtonState = digitalRead(PIN_BUTTON);

  digitalWrite(PIN_LED1, HIGH);
  delay(300);
  digitalWrite(PIN_LED1, LOW);
  delay(300);
  digitalWrite(PIN_LED1, HIGH);
  delay(300);
  digitalWrite(PIN_LED1, LOW);
  delay(300);

  if (currentButtonState == LOW)
  {
    Serial.println("Button pressed: " + String(currentButtonState));
  }
}
