// cf: http://siever.info/cse132/weeks/3/studio/
// this code is adapted from Bill Siever
// two lane stoplight and pedestrian walk light

// it uses a timing approach based on cur and prevMillis
#include "SparkFunMicroOLED.h"   // Include MicroOLED library
MicroOLED oled(MODE_I2C, 9, 1);  // Example I2C declaration RST=D7, DC=LOW

const int PIN_NS_RED = D2;
const int PIN_NS_GREEN = D3;
const int PIN_NS_BLUE = D4;

const int LONG_LIGHT_DURATION = 5000;   // time for green, red, walk, don't walk
const int SHORT_LIGHT_DURATION = 2000;  // time for yellow
const int BLINK_RATE = 500;             // time for blinking don't walk light

// stage 1: NS state changes
unsigned long prevMillisState = 0;
unsigned long stateLength = 0;

// enum State { stateNSG, stateNSY, stateNSR }; //stage 2: add pedestrians
enum State { stateNSG, stateNSY, statePED, statePEDDW };  //

State currentState = stateNSG;

enum Color { Red, Yellow, Green, Black };
void updateOLED() {
    String output = "";
    switch (currentState) {  // stage 1: add switch statement
        case stateNSY:
        case statePEDDW:
        case stateNSG:
            output = "Don't\nWalk";
            break;
        // case NSR:                    //stage 2
        case statePED:
            output = "Walk";
            break;
    }
    oled.clear(PAGE);      // Clear the display
    oled.setCursor(0, 0);  // Set cursor to top-left
    oled.setFontType(1);   // 7-segment font
    oled.print(output);    // Print "A0"
    oled.display();

    Serial.println(output);
}
unsigned long prevMillisBlink = 0;  // stage 3: blinking
bool isDWLedOn = true;              // controls LED blinking for don't walk

void setup() {
    Serial.begin(9600);
    pinMode(PIN_NS_RED, OUTPUT);
    pinMode(PIN_NS_GREEN, OUTPUT);
    pinMode(PIN_NS_BLUE, OUTPUT);

    oled.begin();      // Initialize the OLED
    oled.clear(ALL);   // Clear the display's internal memory
    oled.display();    // Display what's in the buffer (splashscreen)
    delay(1000);       // Delay 1000 ms
    oled.clear(PAGE);  // Clear the display
    oled.display();
    /* === DEBUGGING ONLY ====== */
    //     turnAllLightsOn();
    //     delay(2000);
    //     turnAllLightsOff();
    //     cycleLights(500);
}
void setColor(Color c) {
    switch (c) {
        case Red:
            digitalWrite(PIN_NS_RED, HIGH);
            digitalWrite(PIN_NS_GREEN, LOW);
            digitalWrite(PIN_NS_BLUE, LOW);
            break;
        case Yellow:
            digitalWrite(PIN_NS_RED, HIGH);
            digitalWrite(PIN_NS_GREEN, HIGH);
            digitalWrite(PIN_NS_BLUE, LOW);
            break;
        case Green:
            digitalWrite(PIN_NS_RED, LOW);
            digitalWrite(PIN_NS_GREEN, HIGH);
            digitalWrite(PIN_NS_BLUE, LOW);
            break;
        case Black:
            digitalWrite(PIN_NS_RED, LOW);
            digitalWrite(PIN_NS_GREEN, LOW);
            digitalWrite(PIN_NS_BLUE, LOW);
            break;
    }
}
// stage 1:  add
void updateLights() {
    setColor(Black);

    switch (currentState) {  // stage 1: add switch statement
        case stateNSY:
            setColor(Yellow);
            break;
        // case NSR:                    //stage 2
        case statePED:
            setColor(Red);
            break;
        case statePEDDW:
            setColor(Red);
            break;
        case stateNSG:
            setColor(Green);
            break;
    }
}
/* ======== FUNCTIONS =========== */
// stage 1: create function with NSY NSR NSG
void updateNextStateDuration() {
    switch (currentState) {
        case stateNSY:
        case statePEDDW:
            stateLength = SHORT_LIGHT_DURATION;
            break;
        default:
            stateLength = LONG_LIGHT_DURATION;
    }
}
void updateNextState() {
    switch (currentState) {
        case stateNSY:
            // currentState = stateNSR; //stage 2
            currentState = statePED;
            // currentState = stateWEG;
            break;
        // case stateNSR:  //stage 2
        case statePED:  // stage 2
            // Reset the blink rate when changing OUT of PED
            // isDWLedOn = true;        //commented out--why was this here?
            currentState = statePEDDW;
            break;
        case statePEDDW:
            currentState = stateNSG;
            break;
        case stateNSG:
            currentState = stateNSY;
            break;
    }
}
void loop() {
    // stage 1: NS state changes

    unsigned long curMillis = millis();  // current time

    if ((curMillis - prevMillisState) > stateLength) {
        prevMillisState = curMillis;
        // Serial.print("Changing State: " + String(currentState));
        updateNextState();
        updateNextStateDuration();
        updateLights();
        updateOLED();

        // Serial.println(" --> " + String(currentState));
    }

    // stage 3:
    if ((curMillis - prevMillisBlink) > BLINK_RATE &&
        currentState == statePEDDW) {
        prevMillisBlink = curMillis;

        isDWLedOn = !isDWLedOn;
        if (isDWLedOn == false) {
            oled.clear(PAGE);  // Clear the display
            oled.display();
        } else {
            updateOLED();
        }
        // digitalWrite(PIN_DONT_WALK, isDWLedOn);
    }
}

/* ======= FUNCTIONS FOR DEBUGGING LED WIRING ========= */
// functions used for testing only
void testLightandOLED() {
    // test R, G, B LEDs individually
    int lights[] = {PIN_NS_RED, PIN_NS_GREEN, PIN_NS_BLUE};

    for (int i = 0; i < arraySize(lights); i++) {
        digitalWrite(lights[i], HIGH);
        delay(1000);
        digitalWrite(lights[i], LOW);
        delay(500);
    }

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
