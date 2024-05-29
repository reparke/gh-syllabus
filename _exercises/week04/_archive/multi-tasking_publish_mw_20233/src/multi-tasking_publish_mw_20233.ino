// pin labels
const int PIN_LED1 = D3;
const int PIN_LED2 = D4;
const int PIN_BUTTON = D2;

/* Goasl
- Blink LED1 every 300 milliseconds

- Create a toggle button (latch) to turn LED2 on at rising edge and off again at
the rising edge
- Track the number of times the button is pressed

- Publish the number of button presses to the Particle cloud every 5000
milliseconds

*/

/* Multitasking variables
 */
unsigned long prevMillisLed1 =
    0;  // track the last time our timer went off (aka the LED turned on/off)
const unsigned long INTERVAL_LED1 =
    300;              // how long is the "timer" we are tracking
int led1State = LOW;  // internal state to track if LED1 is on or off

unsigned long prevMillisPublish = 0;  // last time we published
unsigned long INTERVAL_PUBLISH = 5000;
// don't need state variable

/* latch variables */
int counter = 0;
int prevButtonState = HIGH;
int currButtonState = HIGH;
int led2State = LOW;

void setup() {
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    pinMode(PIN_BUTTON, INPUT);
    Serial.begin(9600);
}

void loop() {
    unsigned long currMillis =
        millis();  // tells us current relative time in ms

    // LED 1 blinking block
    // question: have 300 ms elapsed since we last turn the LED on or off
    if (currMillis - prevMillisLed1 > INTERVAL_LED1) {
        // we know that we have passed the amount of time of our internal
        //  since LED1 turned on or off last
        // ALWAYS! make sure to update the time
        prevMillisLed1 = currMillis;
        if (led1State == HIGH) {
            led1State = LOW;
        } else {  // led1state == LOW
            led1State = HIGH;
        }
        digitalWrite(PIN_LED1, led1State);
    }

    // publish code
    if (currMillis - prevMillisPublish > INTERVAL_PUBLISH) {
        prevMillisPublish = currMillis;
        Particle.publish("Counter", String(counter));
    }

    // led 2
    currButtonState = digitalRead(PIN_BUTTON);
    if (currButtonState == HIGH && prevButtonState == LOW) {  // rising edge
        if (led2State == HIGH) {
            led2State = LOW;
        } else {
            led2State = HIGH;
        }
        digitalWrite(PIN_LED2, led2State);
        counter = counter + 1;
        Serial.println("Counter pressed: " + String(counter));
    }
    prevButtonState = currButtonState;
}
