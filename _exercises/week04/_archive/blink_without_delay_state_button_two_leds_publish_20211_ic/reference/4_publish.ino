// second version
// millis for LED1; button output to serial monitor
const int PIN_BUTTON = D2;
const int PIN_LED1 = D3;
const int PIN_LED2 = D4;

int led1State = LOW;
int currentButtonState = LOW;

//latch
int prevButttonState = HIGH;
int led2State = LOW;

//track millis
unsigned long prevMillisLed1Blink = 0; // start at 0
unsigned long intervalLed1 = 300;      // ms between blink

//publish
unsigned long prevMillisPublish = 0;  // start at 0
unsigned long intervalPublish = 1000; // ms between blink
int buttonPresses = 0;
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
      led1State = LOW;
    }
    else
    {
      led1State = HIGH;
      digitalWrite(PIN_LED1, HIGH);
    }
    prevMillisLed1Blink = curMillis;
  }

  if ((curMillis - prevMillisPublish) > intervalPublish)
  {
    Particle.publish("Button Presses", String(buttonPresses));
    prevMillisPublish = curMillis;
  }

  if (currentButtonState == HIGH && prevButttonState == LOW) //rising edge
  {
    buttonPresses++;
    //change LED 2 state
    // led2State = !led2State;
    // digitalWrite(PIN_LED2, led2State);
    if (led2State == HIGH)
    {
      digitalWrite(PIN_LED2, LOW);
      led2State = LOW;
    }
    else
    {
      led2State = HIGH;
      digitalWrite(PIN_LED2, HIGH);
    }
  }
  prevButttonState = currentButtonState;
}
