

/*
Do NOT ever use while loops


*/

// const int PIN_LED1 = D3;
// const int PIN_LED2 = D4;
// const int PIN_BUTTON = D2;

// // array
// int delayLengths[4] = {100, 1000, 500, 2000};  // in milliseconds

// int pinArray[4] = {D2, D3, D6, D5};
// int someLedState[3] = {HIGH, HIGH, LOW};

// void setup() {
//     pinMode(PIN_LED1, OUTPUT);
//     pinMode(PIN_LED2, OUTPUT);
//     pinMode(PIN_BUTTON, INPUT);
//     Serial.begin(9600);
// }

// void loop() {
//     // for (int index = 0; index < 4; index++) {
//     for (int index = 0; index < arraySize(delayLengths) < 4;
//          index++) {  // arraySize is specific to Argon
//         Serial.println("Delay " + String(delayLengths[index]));
//         digitalWrite(PIN_LED1, HIGH);
//         delay(delayLengths[index]);
//         digitalWrite(PIN_LED1, LOW);
//         delay(delayLengths[index]);
//     }
// }

const int PIN_LED1 = D3;
const int PIN_LED2 = D4;
const int PIN_BUTTON = D2;
/*
    build latch
        track prevbutton val
        read cur button val
        if prev High and cur Low, this is press
            do what ever code you want here

        where do we update prevButton? OUTSIDE the if
*/
int prevButtonVal = HIGH;
int currButtonVal = HIGH;
int buttonPresses = 0;

/*
Multitasking variables
*/
unsigned long prevLed1Millis =
    0;  // last "relative" that our led1 timer went off
const unsigned long led1IntervalOn = 300;   // how long is the "led1" timer
const unsigned long led1IntervalOff = 700;  // how long is the "led1" timer
int led1State = LOW;

void setup() {
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    pinMode(PIN_BUTTON, INPUT);
    Serial.begin(9600);
}

/*
 - enable the button to turn on / off LED 2 when pressed
 - publish a message to the particle cloud every 10 sec
 - challenge: led1 to be on for 300 ms, be off for 700 ms
*/

void loop() {
    // //multitasking code
    // unsigned long currMillis = millis();  //the current "relative" time
    // //question: has 300 ms passed since led1 last changed state?
    // if (currMillis - prevLed1Millis > led1Interval) { //if true, then timer
    // has gone off
    //     //do the code that happens when interval goes off
    //     //if led1 was on, then turn off (vice versa)
    //     if (led1State == LOW) {
    //         led1State = HIGH;
    //         digitalWrite(PIN_LED1, HIGH);
    //     }
    //     else {
    //         led1State = LOW;
    //         digitalWrite(PIN_LED1, LOW);
    //     }
    //     //ONLY WHEN THE TIMER GOES OFF, do we update prevMillis
    //     prevLed1Millis = currMillis; //update the timer so we are ready for
    //     the next interval
    // }
    // multitasking code
    unsigned long currMillis = millis();  // the current "relative" time
    // question: has 300 ms passed since led1 last changed state?
    if (led1State == LOW) {
        if (currMillis - prevLed1Millis > led1IntervalOff ) {
            // if true, then timer has gone off
            // do the code that happens when interval goes off
            // if led1 was on, then turn off (vice versa)
            led1State = HIGH;
            digitalWrite(PIN_LED1, HIGH);

            // ONLY WHEN THE TIMER GOES OFF, do we update prevMillis
            prevLed1Millis = currMillis;  // update the timer so we are ready
        }                                 // for the next interval
    } else { //led1 is HIGH
        if (currMillis - prevLed1Millis > led1IntervalOn) {
            // if true, then timer has gone off
            // do the code that happens when interval goes off
            // if led1 was on, then turn off (vice versa)
            led1State = LOW;
            digitalWrite(PIN_LED1, LOW);

            // ONLY WHEN THE TIMER GOES OFF, do we update prevMillis
            prevLed1Millis = currMillis;  // update the timer so we are
                                          // ready for the next interval
        }
    }

    // button latch code
    currButtonVal = digitalRead(PIN_BUTTON);
    if (currButtonVal == LOW &&
        prevButtonVal == HIGH) {  // button pressed, falling edge
        buttonPresses++;
        Serial.println("Button pressed: " + String(buttonPresses));
    }
    // update the prevButton OUTSIDE this if because it needs to update
    // EVERY loop()
    prevButtonVal = currButtonVal;
}