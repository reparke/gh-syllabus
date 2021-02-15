
const int PIN_BUTTON = D2;
const int PIN_LED1 = D3;
const int PIN_LED2 = D4;

//Track button state
int curButtonState = LOW;
int prevButtonState = LOW;

//version with millis
unsigned long prevMillisLED1 = 0; //always start at 0
unsigned long intervalLED1 = 300; //milliseconds, what the lab asks

//we also need to track the state of the LED
int led1state = LOW;
int led2state = LOW;

//publish timer
int buttonPresses = 0;
unsigned long prevMillisPublish = 0;
unsigned long intervalPublish = 1000;

void setup()
{
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //need to get current time- don't need it to be a global variable
  unsigned long curMillis = millis();
  curButtonState = digitalRead(PIN_BUTTON);

  // check if time elapsed >= interval window
  if (curMillis - prevMillisLED1 >= intervalLED1)
  {
    prevMillisLED1 = curMillis;
    if (led1state == LOW)
    {
      digitalWrite(PIN_LED1, HIGH);
      led1state = HIGH;
    }
    else
    {
      digitalWrite(PIN_LED1, LOW);
      led1state = LOW;
    }
  }

  if (curMillis - prevMillisPublish >= intervalPublish)
  {
    Particle.publish("Button Press", String(buttonPresses), PRIVATE);
    prevMillisPublish = curMillis;
  }

  //rising edge= low to high
  //toggle button for LED2
  if (prevButtonState == LOW && curButtonState == HIGH)
  {
    Serial.println("Button Pressed: " + String(buttonPresses));
    buttonPresses++;
    if (led2state == LOW)
    {
      digitalWrite(PIN_LED2, HIGH);
      led2state = HIGH;
    }
    else
    {
      digitalWrite(PIN_LED2, LOW);
      led2state = LOW;
    }
  }
  prevButtonState = curButtonState; //do not want to update this inside of a if loop
}
