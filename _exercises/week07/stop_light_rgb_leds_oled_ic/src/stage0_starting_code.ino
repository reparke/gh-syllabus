// cf: http://siever.info/cse132/weeks/3/studio/
// this code is adapted from Bill Siever
// North-South traffic stoplight and East-West pedestrian walk light

// it uses a timing approach based on cur and prevMillis
#include "SparkFunMicroOLED.h"   // Include MicroOLED library
MicroOLED oled(MODE_I2C, 9, 1);  // Example I2C declaration RST=D7, DC=LOW

const int PIN_RED = D2;
const int PIN_GREEN = D3;
const int PIN_BLUE = D4;

const int LONG_LIGHT_DURATION = 5000;   // time for green, red, walk, don't walk
const int SHORT_LIGHT_DURATION = 2000;  // time for yellow
const int BLINK_RATE = 500;             // time for blinking don't walk light

// TODO:  Create enum State for stoplight states
// we could use some kind of int const
// enum State { TrafficGo, TrafficSlow, TrafficStop };
enum State { TrafficGo, TrafficSlow, PedWalk, PedDontWalk };

// TODO: create enum Color for signal light colors
enum Color { Red, Yellow, Green, Black };

// TODO: Create variables for state change and state length
State currentState;
unsigned long prevMillisState = 0;
unsigned long currentStateDuration =
    0;  // either 2s or 5s based on which state we currently in

void setup() {
    Serial.begin(9600);
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);

    oled.begin();      // Initialize the OLED
    oled.clear(ALL);   // Clear the display's internal memory
    oled.display();    // Display what's in the buffer (splashscreen)
    delay(1000);       // Delay 1000 ms
    oled.clear(PAGE);  // Clear the display's internal memory
    oled.display();
}

/* ======= FUNCTIONS =========== */

// TODO: COMPLETE updateNextState
void updateNextState() {
    // we are here implementing the logic from our state diagram / table
    //  you could use an if if you wanted
    // enum State {TrafficGo, TrafficSlow, TrafficStop};
    switch (currentState) {
        case TrafficGo:  // same as saying if (currentState == TrafficGo)
            currentState = TrafficSlow;
            // we also need to update duration
            currentStateDuration = SHORT_LIGHT_DURATION;
            break;
        case TrafficSlow:  // same as else if (currentState == TrafficSlow)
            // currentState = TrafficStop;
            currentState = PedWalk;
            currentStateDuration = LONG_LIGHT_DURATION;
            break;
        // case TrafficStop:
        case PedWalk:
            currentState = PedDontWalk;
            currentStateDuration = SHORT_LIGHT_DURATION;
            break;
        case PedDontWalk:
            currentState = TrafficGo;
            currentStateDuration = LONG_LIGHT_DURATION;
            break;
    }
}

// TODO: COMPLETE setColor
void setColor(Color c) {
    switch (c) {
        case Red:
            digitalWrite(PIN_RED, HIGH);
            digitalWrite(PIN_GREEN, LOW);
            digitalWrite(PIN_BLUE, LOW);
            break;
        case Green:
            digitalWrite(PIN_RED, LOW);
            digitalWrite(PIN_GREEN, HIGH);
            digitalWrite(PIN_BLUE, LOW);
            break;
        case Yellow:
            digitalWrite(PIN_RED, HIGH);
            digitalWrite(PIN_GREEN, HIGH);
            digitalWrite(PIN_BLUE, LOW);
            break;
        case Black:
            digitalWrite(PIN_RED, LOW);
            digitalWrite(PIN_GREEN, LOW);
            digitalWrite(PIN_BLUE, LOW);
            break;
    }
}
// TODO: COMPLETE updateNextStateDuration
void updateOutputs() {
    // eventually we add outputs for OLED
    // standard oled
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.setFontType(0);

    switch (currentState) {
        case TrafficGo:
            setColor(Green);
            oled.println("Don't Walk");
            break;
        case TrafficSlow:
            setColor(Yellow);
            oled.println("Don't Walk");
            break;
        // case TrafficStop:
        case PedWalk:
            setColor(Red);
            oled.println("Walk");
            break;
        case PedDontWalk:
            setColor(Red);
            oled.println("Don't Walk");
            break;
    }
    oled.display();
}
void loop() {
    // TODO: comment out this function after verifying OLED and RGB LED work
    // testLightandOLED();

    unsigned long curMillis = millis();
    if (curMillis - prevMillisState > currentStateDuration) {
        prevMillisState = curMillis;
        // ok, timer has gone of so we need to update state
        // so what do we do?
        // check the current and change based on that
        // change the current state duration
        // change the outputs (RGB and eventually OLED)
        updateNextState();
        updateOutputs();
    }
}

/* ======= FUNCTIONS FOR DEBUGGING LED WIRING ========= */
// functions used for testing only
void testLightandOLED() {
    // test R, G, B LEDs individually; then white
    int lights[] = {PIN_RED, PIN_GREEN, PIN_BLUE};

    // turn off LED
    for (int i = 0; i < arraySize(lights); i++) {
        digitalWrite(lights[i], LOW);
    }

    // test R G B
    for (int i = 0; i < arraySize(lights); i++) {
        digitalWrite(lights[i], HIGH);
        delay(1000);
        digitalWrite(lights[i], LOW);
        delay(500);
    }

    // show white
    for (int i = 0; i < arraySize(lights); i++) {
        digitalWrite(lights[i], HIGH);
    }

    //-----------------------

    // test OLED screen
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.setFontType(0);
    oled.println("Testing OLED");
    oled.display();

    oled.setFontType(0);  // 7-segment font
    for (int i = 0; i < 20; i++) {
        oled.print(".");
        oled.display();
        delay(10);
    }
    oled.clear(PAGE);  // Clear the display
    oled.display();
}
