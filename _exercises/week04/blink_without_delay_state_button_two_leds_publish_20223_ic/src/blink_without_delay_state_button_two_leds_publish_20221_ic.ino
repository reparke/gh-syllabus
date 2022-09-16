const int PIN_LED1 = D3;
const int PIN_LED2 = D4;
const int PIN_BUTTON = D2;

// interveral for led 1 to blink
const unsigned long INTERVAL_LED1 = 300;
unsigned long prevMillisLed1 = 0;  // updated everytime we take action on LED1

const unsigned long INTERVAL_PUBLISH = 1000;
unsigned long prevMillisPublish = 0;

// track if LED1 is on or off (this could int OR bool)
int led1_state = LOW;  // led is off
int led2_state = LOW;

// for toggle
int prevButtonState = HIGH;

int buttonPresses = 0;

void setup() {
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    pinMode(PIN_BUTTON, INPUT);
    Serial.begin(9600);
}

void loop() {
    // what is current time
    unsigned long currMillis = millis();
    // LED 1 block
    // question: has 1 second passed since we last turned on / off the LED?
    if (currMillis - prevMillisLed1 > INTERVAL_LED1) {
        // We know that we have passed the amount of time of our interval
        // since we last changed LED 1

        // if LED 1 was on, turn off. if led 1 was off, turn on
        if (led1_state == LOW) {
            led1_state = HIGH;  // change the state
            digitalWrite(PIN_LED1, HIGH);
        } else {  // led1 was on
            led1_state = LOW;
            digitalWrite(PIN_LED1, LOW);
        }
        prevMillisLed1 = currMillis;
    }

    // toggle code
    int currButtonState = digitalRead(PIN_BUTTON);
    if (currButtonState == LOW && prevButtonState == HIGH) {  // rising edge
        
        buttonPresses = buttonPresses + 1;
        // buttonPresses++; //increments buttonpreses by 1

        if (led2_state == LOW) {
            led2_state = HIGH;
        } else {
            led2_state = LOW;
        }
        digitalWrite(PIN_LED2, led2_state);  // same as above, but shorter
    }
    prevButtonState = currButtonState;

    //publishing code
    if (currMillis - prevMillisPublish > INTERVAL_PUBLISH) {
        prevMillisPublish = currMillis; //always remember to update time
        Particle.publish("Current Button Presses", String(buttonPresses));

    }

}

// version 1 with delay
//  digitalWrite(PIN_LED1, HIGH);
//  delay(300);
//  digitalWrite(PIN_LED1, LOW);
//  delay(300);
//  digitalWrite(PIN_LED1, HIGH);
//  delay(300);
//  digitalWrite(PIN_LED1, LOW);
//  delay(300);
//  int buttonVal = digitalRead(PIN_BUTTON);
//  if (buttonVal == LOW) {
//      Serial.println("Button was pressed");
//  }