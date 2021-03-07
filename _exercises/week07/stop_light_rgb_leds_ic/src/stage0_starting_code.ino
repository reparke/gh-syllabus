// cf: http://siever.info/cse132/weeks/3/studio/
// this code is adapted from Bill Siever
// two lane stoplight and pedestrian walk light

// it uses a timing approach based on cur and prevMillis

const int PIN_NS_RED = D2;
const int PIN_NS_GREEN = D3;
const int PIN_NS_BLUE = D4;
const int PIN_WE_RED = A5;
const int PIN_WE_GREEN = A4;
const int PIN_WE_BLUE = A3;
const int PIN_DONT_WALK = D5;
const int PIN_WALK = D6;

const int LONG_LIGHT_DURATION = 5000;   // time for green, red, walk, don't walk
const int SHORT_LIGHT_DURATION = 2000;  // time for yellow
const int BLINK_RATE = 500;             // time for blinking don't walk light

// stage 1: NS state changes
unsigned long prevMillisState = 0;
unsigned long stateLength = 0;

unsigned long prevMillisBlink =0;
bool isDWOn = true;
// Create enum State for stoplight states
// enum State { stateNSR, stateNSY, stateNSG };
enum State { statePED, statePEDDW, stateNSY, stateNSG };

// create enum Color for signal light colors
enum Color { Red, Green, Yellow, Black };

// create num Light for distinguishing north-south light and west-east light
enum Stoplight { lightNS, lightWE };

State currentState = stateNSG;

// for testing purposes only
int lights[] = {PIN_NS_RED,   PIN_NS_GREEN, PIN_NS_BLUE, PIN_WE_RED,
                PIN_WE_GREEN, PIN_WE_BLUE,  PIN_WALK,    PIN_DONT_WALK};

void setup() {
    Serial.begin(9600);
    pinMode(PIN_NS_RED, OUTPUT);
    pinMode(PIN_NS_GREEN, OUTPUT);
    pinMode(PIN_NS_BLUE, OUTPUT);
    pinMode(PIN_WE_RED, OUTPUT);
    pinMode(PIN_WE_GREEN, OUTPUT);
    pinMode(PIN_WE_BLUE, OUTPUT);
    pinMode(PIN_WALK, OUTPUT);
    pinMode(PIN_DONT_WALK, OUTPUT);
}

/* ======= FUNCTIONS =========== */

// TODO: COMPLETE updateNextState
void updateNextState() {
    switch (currentState) {
        case stateNSG:
            currentState = stateNSY;
            break;
        case stateNSY:
            currentState = statePED;
            break;
        case statePED:
            currentState = statePEDDW;
            break;
        case statePEDDW:
            currentState = stateNSG;
            break;
    }
}

// TODO: COMPLETE updateNextStateDuration
void updateNextStateDuration() {
    switch (currentState) {
        case stateNSG:
            stateLength = LONG_LIGHT_DURATION;
            break;
        case stateNSY:
            stateLength = SHORT_LIGHT_DURATION;
            break;
        case statePED:
            stateLength = LONG_LIGHT_DURATION;
            break;
        case statePEDDW:
            stateLength = SHORT_LIGHT_DURATION;
            break;
    }
}

// TODO: COMPLETE setColor
// this simply takes one stoplight and a color, and sets the color
void setColor(Stoplight stoplight, Color color) {
    // figure out what are the pins for the RGB
    int r, g, b;  // placeholders for the pins for the LED
    switch (stoplight) {
        case lightNS:
            r = PIN_NS_RED;
            g = PIN_NS_GREEN;
            b = PIN_NS_BLUE;
            break;
    }
    // we dont care which light we are turning on...just set the color
    switch (color) {
        case Red:
            analogWrite(r, 255);
            analogWrite(g, 0);
            analogWrite(b, 0);
            break;
        case Green:
            analogWrite(r, 0);
            analogWrite(g, 255);
            analogWrite(b, 0);
            break;
        case Yellow:
            analogWrite(r, 255);
            analogWrite(g, 255);
            analogWrite(b, 0);
            break;
        case Black:
            analogWrite(r, 0);
            analogWrite(g, 0);
            analogWrite(b, 0);
            break;
    }
}

// TODO: COMPLETE updateLights
void updateLights() {
    // reset all lights
    // change light based on current state
    setColor(lightNS, Black);
    digitalWrite(PIN_WALK, LOW);
    digitalWrite(PIN_DONT_WALK, LOW);
    switch (currentState) {
        case stateNSG:
            setColor(lightNS, Green);
            digitalWrite(PIN_DONT_WALK, HIGH);
            digitalWrite(PIN_WALK, LOW);
            break;
        case statePED:
            setColor(lightNS, Red);
            digitalWrite(PIN_DONT_WALK, LOW);
            digitalWrite(PIN_WALK, HIGH);
            break;
        case statePEDDW:
            setColor(lightNS, Red);
            digitalWrite(PIN_DONT_WALK, HIGH);
            digitalWrite(PIN_WALK, LOW);
            break;
        case stateNSY:
            setColor(lightNS, Yellow);
            digitalWrite(PIN_DONT_WALK, HIGH);
            digitalWrite(PIN_WALK, LOW);
            break;
    }
}

// LOOP
void loop() {
    unsigned long curMillis = millis();

    if (curMillis - prevMillisState > stateLength) {
        prevMillisState = curMillis;
        updateNextState();          // switch to new state
        updateNextStateDuration();  // update new state length
        updateLights();
    }
    
    // if (curMillis - prevMillisBlink > BLINK_RATE && currentState != statePED) {
    //     prevMillisBlink = curMillis;
    //     //light show change, but not sure on or off

    //     if (isDWOn == true ) {
    //         isDWOn = false;
    //         digitalWrite(PIN_DONT_WALK, LOW);
    //     }    
    //     else {
    //         isDWOn= true;
    //         digitalWrite(PIN_DONT_WALK, HIGH);
    //     }
    // }
    // test all lights -- delete once wiring is verified
    // turnAllLightsOn();
    // delay(2000);
    // turnAllLightsOff();
    // cycleLights(500);
}

/* ======= FUNCTIONS FOR DEBUGGING LED WIRING ========= */
// functions used for testing only
void cycleLights(int delayMS) {
    for (int i = 0; i < arraySize(lights); i++) {
        digitalWrite(lights[i], HIGH);
        delay(delayMS);
        digitalWrite(lights[i], LOW);
    }
}

void turnAllLightsOn() {
    for (int i = 0; i < arraySize(lights); i++) {
        digitalWrite(lights[i], HIGH);
    }
}

void turnAllLightsOff() {
    for (int i = 0; i < arraySize(lights); i++) {
        digitalWrite(lights[i], LOW);
    }
}