// SYSTEM_MODE(MANUAL);

const int PIN_BUTTON = D2;
const int PIN_LED1 = D3;
const int PIN_LED2 = D4;

// create timing variables
const unsigned long INTERVAL_LED1_ON = 300;  // 300 ms

unsigned long prevMillisLed1 = 0;

int stateButtonPrev = HIGH;

//led state variable
int led1State = LOW;
int led2State = LOW;  

void setup() {
    pinMode(PIN_BUTTON, INPUT);
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    unsigned long curMillis = millis();  // current time

    // check led time
    if (curMillis - prevMillisLed1 >
        INTERVAL_LED1_ON) {  // time to update our LED
        // update your "prev" time
        prevMillisLed1 = curMillis;

        //DO WHATEVER YOU WANT HAPPEN ON THE TIMER
        if (led1State == HIGH) {
          led1State = LOW;    
        }
        else {
          led1State = HIGH;
        }
        digitalWrite(PIN_LED1, led1State);
    }

  //latch code
  int stateButtonCurrent = digitalRead(PIN_BUTTON);
  if (stateButtonPrev == LOW && stateButtonCurrent == HIGH) {
    if (led2State == HIGH) {
      led2State = LOW;
    }
    else {
      led2State = HIGH;
    }
    Serial.println("button pressed");
    digitalWrite(PIN_LED2, led2State);

  }
  //update button state ALWAYS
  stateButtonPrev = stateButtonCurrent;


}

/* version 1
void loop() {
    digitalWrite(PIN_LED1, HIGH);
    delay(300);
    digitalWrite(PIN_LED1, LOW);
    delay(300);
    digitalWrite(PIN_LED1, HIGH);
    delay(300);
    digitalWrite(PIN_LED1, LOW);
    delay(300);
    int buttonVal = digitalRead(PIN_BUTTON);
    if (buttonVal == LOW) {
      Serial.println("Button was pressed");
    }
}

*/
