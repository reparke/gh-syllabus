// second version
// millis for LED1; button output to serial monitor
const int PIN_BUTTON = D2;
const int PIN_LED1 = D3;
const int PIN_LED2 = D4;

int currentButtonState = LOW;
int led1State = LOW;

//track millis
unsigned long prevMillisLed1Blink = 0; // start at 0
unsigned long intervalLed1 = 300;      // ms between blink
/*
  if LED IS ON AND the interval since we last changed the state has elapsed
      then we turn the light off AND update the time
  if LED is OFF and the interval has elapsed
      then we turn ON the light and update the time
*/
void setup()
{
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  unsigned long curMillis = millis();
  currentButtonState = digitalRead(PIN_BUTTON);

  if ((curMillis - prevMillisLed1Blink) > intervalLed1)
  {
    if (led1State == HIGH)
    {
      digitalWrite(PIN_LED1, LOW);
    }
    else
    {
      digitalWrite(PIN_LED1, HIGH);
    }
    prevMillisLed1Blink = curMillis;
  }

  if (currentButtonState == LOW)
  {
    Serial.println("Button pressed: " + String(currentButtonState));
  }
}
