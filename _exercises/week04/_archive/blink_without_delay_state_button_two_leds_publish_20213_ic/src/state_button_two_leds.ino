const int PIN_BUTTON = D2;
const int PIN_LED1 = D3;
const int PIN_LED2 = D4;

// state variables
int stateButtonCurrent = HIGH;
int stateLed1 = LOW;  // what is the LED 1 doing right now
int stateButtonPrev = HIGH;   // need for latch
int buttonPresses = 0;

// millis tracking / time tracking
// these are ALWAYS unsigned long (really big int)
unsigned long prevMillisLed1 = 0;   // always start your PREV millis at 0
unsigned long intervalLed1 = 1000;  // how long between blinks (or state
                                    // changes)

unsigned long prevMillisPublish = 0;
unsigned long intervalPublish = 2500;

void setup() {
    pinMode(PIN_BUTTON, INPUT);
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // version 2: use millis
    unsigned long curMillis = millis();  // what is time is it NOW
    // check has enough elapsed since the light last blinked (change state)
    if (curMillis - prevMillisLed1 >= intervalLed1) {
        prevMillisLed1 = curMillis;  // update the prevMillis counter
        if (stateLed1 == HIGH) {     // light IS currently on
            digitalWrite(PIN_LED1, LOW);
            stateLed1 = LOW;
        } else {
            digitalWrite(PIN_LED1, HIGH);
            stateLed1 = HIGH;
        }
    }

    //button latch
    stateButtonCurrent  = digitalRead(PIN_BUTTON);
    if (stateButtonCurrent == HIGH && stateButtonPrev == LOW) {//RISING edge
        Serial.println("button pressed");
        // buttonPresses = buttonPresses + 1;
        buttonPresses++;
    }
    stateButtonPrev = stateButtonCurrent;   //update


    // if (stateButtonCurrent == LOW) {
    //   Serial.println("button pressed");
    //   // buttonPresses = buttonPresses + 1;
    //   buttonPresses++;
    // } 
    //now track publish
    if (curMillis - prevMillisPublish >= intervalPublish) {
      Particle.publish("Button presses", String(buttonPresses));
      prevMillisPublish = curMillis;
    }

    // stage 3: track the number button presses, and publish the result to Particle cloud every 2.5 s
    // stage 4: change the button track to be a latch--only register button presses on RISING edges

    // version 1
    // digitalWrite(PIN_LED1, HIGH);
    // delay(300);
    // digitalWrite(PIN_LED1, LOW);
    // delay(300);
    // digitalWrite(PIN_LED1, HIGH);
    // delay(300);
    // digitalWrite(PIN_LED1, LOW);
    // delay(300);

    // stateButtonCurrent = digitalRead(PIN_BUTTON);
    // if (stateButtonCurrent == LOW) { //button pressed
    //   Serial.println("Button Pressed!");
    // }
}
