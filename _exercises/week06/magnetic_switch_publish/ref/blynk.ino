/*Note: This corresponds to locally installed project "Week 6", tab "Demo"
  Features
    - Button to control onboard LED on V5 (app --> argon)
    - display for random number on V6 (argon --> app)
    - virtual LED represents random value on V6 (argon --> app)
*/

#include <blynk.h>                                 //library
char auth[] = "_Ce745Lvb6anFEDvGggMSYvZCwIF8b6i";  // this is a array of
                                                   // characters with our token

// if you're sending values to from ARGON to APP (push), we MUST use millis()
// limit is 10 values per sec
// in loop(), we MUST NOT use delay
unsigned long blynkDelay = 1000;
unsigned long prevMillis = 0;

const int PIN_LED = D7;
const int PIN_RED = D3;
const int PIN_GREEN = D4;
const int PIN_BLUE = D5;
const int PIN_SWITCH = D2;

// virtual pin headers
// // const int VPIN_RED = V0;
// // const int VPIN_GREEN = V1;
// // const int VPIN_BLUE = V2;
// const int VPIN_SWITCH = V3;
// // const int VPIN_TEXT = V4;
// const int VPIN_LED = V5;

// you do NOT need to set PINMODE for these virtual pins

// retrieve from app
// app ==> argon
//  create a special function called BLYNK_WRITE(<<PIN>>)
BLYNK_WRITE(V5) {
    // event handler for when the user moves the sliders on the app
    // we have a slider that send an integer value from 0-255
    // lets read the value on the slider
    int buttonVal = param.asInt();  // represents slider value
    digitalWrite(PIN_LED, buttonVal);
    Serial.println("On board LED: " + String(buttonVal));
}

void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_SWITCH, INPUT);
    Serial.begin(9600);

    // 1. have delay
    delay(5000);  // needs to be delay, not millis

    // 2. connect to blynk
    // Blynk.begin(auth);
    Blynk.begin(auth, IPAddress(192, 168, 0, 131), 8080);
    Serial.println("in setup");
}

void loop() {
    Blynk.run();  // do NOT put in millis timer
    unsigned long currMillis = millis();
    if (currMillis - prevMillis > blynkDelay) {
        prevMillis = currMillis;

        // NOW we send value
        // Blynk.virtualWrite(<<PIN>>, <<VALUE>>)
        int randNum = random(0, 255);
        Serial.println("sending random number: " + String(randNum));
        Blynk.virtualWrite(V6,
                           randNum);  // send data from argon ===> app
    }
}
