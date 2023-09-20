


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

/* multitasking variables */
unsigned long prevMillisLed1 = 0; //last time our timer went off (aka LED on or off)
unsigned long currMillis = 0; //last time our timer went off (aka LED on or off)
const unsigned long INTERVAL_LED1 = 300; // how long is our LED1 timer
int led1State = LOW;

unsigned long prevMillisPublish = 0; //last time our publishing timer went off
const unsigned long INTERVAL_PUBLISH = 5000;


/* latch variables*/
int prevButtonState = HIGH;
int currButtonState = HIGH;
int led2State = LOW;
int counter = 0;


void setup() {
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    pinMode(PIN_BUTTON, INPUT);
    Serial.begin(9600);
}

void loop() {
    //get current relative time
    currMillis = millis();    //time since Argon turned on in ms

    // button latch block
    currButtonState = digitalRead(PIN_BUTTON);
    //rising edge: button is released
    if (currButtonState == HIGH && prevButtonState == LOW) {
        counter = counter + 1;
        Serial.println("Counter = " + String(counter));
        if(led2State == HIGH) {
            led2State = LOW;
        }
        else { 
            led2State = HIGH;
        }
        digitalWrite(PIN_LED2, led2State);
    }
    prevButtonState = currButtonState;


    // LED1 blinking block
    //question: has 300 ms elapsed since we last turned the LED on or off?
    if (currMillis - prevMillisLed1 >= INTERVAL_LED1) {
        // inside here we know timer has gone off
        prevMillisLed1 = currMillis;        //updates our timer for next time

        //this is updating the "internal" state of the LED, not the actualLED we see
        if (led1State == HIGH) {
            led1State = LOW;
        }
        else {
            led1State = HIGH;
        }
        digitalWrite(PIN_LED1, led1State);  //THIS update the actual LED we see
    }

    // publishing block
    if (currMillis - prevMillisPublish >= INTERVAL_PUBLISH) {
        // in here we know the publish timer went off
        prevMillisPublish = currMillis;
        Particle.publish("Counter", String(counter));
    }
}
