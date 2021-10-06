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
// enum State { TrafficGo, TrafficSlow, TrafficStop };
enum State { TrafficGo, TrafficSlow, PedWalk, PedDontWalk };

// TODO: create enum Color for signal light colors
enum Color { Red, Green, Yellow };

// TODO: Create variables for state change and state length
State currentState = TrafficGo;
int currentStateDuration = 0;
unsigned long prevMillisState = 0;

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
    // here is our state transition logic
    // Go --> Slow --> Stop

    unsigned long curMillis = millis();
    switch (currentState) {  // if (currentState == ...)
        case TrafficGo:      // if (currentState == TrafficGo)
            if (curMillis - prevMillisState >
                currentStateDuration) {  // now we change states
                // change LED color
                // update the OLED

                // update prevMillis
                // update state
                // update the stateduration
                currentState = TrafficSlow;
                prevMillisState = curMillis;
                updateNextStateDuration();
                updateOLED();
                updateLights();
            }
            break;
        case TrafficSlow:
            if (curMillis - prevMillisState >
                currentStateDuration) {  // now we change states
                // currentState = TrafficStop;
                currentState = PedWalk;
                prevMillisState = curMillis;
                updateNextStateDuration();
                updateOLED();
                updateLights();
            }
            break;
        // case TrafficStop:
        case PedWalk:
            if (curMillis - prevMillisState >
                currentStateDuration) {  // now we change states
                currentState = PedDontWalk;
                prevMillisState = curMillis;
                updateNextStateDuration();
                updateOLED();
                updateLights();
            }
            break;
        case PedDontWalk:
            if (curMillis - prevMillisState >
                currentStateDuration) {  // now we change states
                currentState = TrafficGo;
                prevMillisState = curMillis;
                updateNextStateDuration();
                updateOLED();
                updateLights();
            }
            break;
    }
}

// TODO: COMPLETE updateNextStateDuration
void updateNextStateDuration() {
    switch (currentState) {
        case TrafficGo:
            currentStateDuration = LONG_LIGHT_DURATION;
            break;
        case TrafficSlow:
            currentStateDuration = SHORT_LIGHT_DURATION;
            break;
        // case TrafficStop:
        case PedWalk:
            currentStateDuration = LONG_LIGHT_DURATION;
            break;
        case PedDontWalk:
            currentStateDuration = SHORT_LIGHT_DURATION;
            break;
        default:
            break;
    }
}

// TODO: COMPLETE setColor
void setColor(Color c) {
    switch (c) {
        case Red:
            analogWrite(PIN_RED, 255);
            analogWrite(PIN_GREEN, 0);
            analogWrite(PIN_BLUE, 0);
            break;
        case Green:
            analogWrite(PIN_RED, 0);
            analogWrite(PIN_GREEN, 255);
            analogWrite(PIN_BLUE, 0);
            break;
        case Yellow:
            analogWrite(PIN_RED, 255);
            analogWrite(PIN_GREEN, 255);
            analogWrite(PIN_BLUE, 0);
            break;
    }
}

// TODO: COMPLETE updateLights
void updateLights() {
    switch (currentState) {
        // case TrafficStop:
        case PedWalk:
            setColor(Red);
            break;
        case PedDontWalk:
            setColor(Red);
            break;
        case TrafficSlow:
            setColor(Yellow);
            break;
        case TrafficGo:
            setColor(Green);
            break;
    }
}

// TODO: COMPLETE updateOLED
void updateOLED() {
    switch (currentState) {
        case PedWalk:
            Serial.println("Walk");
            break;
        default:  // everythign else
            Serial.println("Don't Walk");
            break;
    }
}

void loop() {
    // TODO: comment out this function after verifying OLED and RGB LED work
    // testLightandOLED();
    updateNextState();  // this function determines IF we should go to a new
                        // state if so, then which state do we go
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
