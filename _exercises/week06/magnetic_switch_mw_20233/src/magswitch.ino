#define BLYNK_TEMPLATE_ID "TMPL2AtGMJRHD"
#define BLYNK_TEMPLATE_NAME "Week 6 MW"
#define BLYNK_AUTH_TOKEN "QBtBuJMmrWRH8TdznsnSVB1s4rzCrMpR"

// add these
// #define BLYNK_PRINT Serial

// add header for library
#include <blynk.h>

/*Note: This corresponds to locally installed project "Week 6", tab "Demo"
  Features
    - Button to control onboard LED on V5 (app --> argon)
    - display for random number on V6 (argon --> app)
    - virtual LED represents random value on V6 (argon --> app)
*/
const int PIN_LED = D7;
const int PIN_RED = D3;
const int PIN_GREEN = D4;
const int PIN_BLUE = D5;
const int PIN_SWITCH = D2;

/*
    EVENT DRIVEN PROGRAMMING
        DATA from APP to ARGON
        we write a function, and the ARgon calls the function when the event
   happens FOR US we NEVER calls this function
*/
unsigned long prevMillis = 0;
const unsigned long INTERVAL_BLYNK = 1000;

// we want the on-board LED to turn on when the "virtual button" in app is
// pressed we build a "function" (event handler) to be called when the specific
// action happens virtual pin V5 corresponds to a button in Blynk
BLYNK_WRITE(V5) {
    Serial.println("Virtual button V6 was pressed!");

    // we can access the "value" of the virtual button (or datastream)
    int buttonVal = param.asInt();  // this the is the equivalent digitalRead
                                    // for physical button

    digitalWrite(PIN_LED, buttonVal);
}

void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_SWITCH, INPUT);
    Serial.begin(9600);

    // add these to setup
    Blynk.begin(BLYNK_AUTH_TOKEN);
    delay(5000);  // Blynk needs to in setup
}
void loop() {
    // add this for blynk in loop()
    Blynk.run();
    // everything else that might contact blynk needs to be in a milli block
    /*
        the process for data FROM ARGON TO APP is different than the opposite
        to send data argon --> app, we Blynk.virtualWrite()
        BUT this function can't get called to often so we need a millis timer
       for IMPORTANT: blynk.run() should NOT be in the millis block
    */

    unsigned long currMillis = millis();
    if (currMillis - prevMillis > INTERVAL_BLYNK) {
        // now we can send data to app
        prevMillis = currMillis;
        Blynk.virtualWrite(V6, random(0, 256));
    }
}