/*
    Econ
        Cold 2 min
        RegularDry 2 min
        Idle
    Deluxe
        Hot 4 min
        RegularDry 2 min
        Idle
    Super
        Hot 4 min
        ExtraDry 4 min
        Idle
    Consider pressing button to go back to idle
    Consider using switch to be either lock (extra), or replace the button

Colors:
    Idle,       white
    Hot,        red
    Cold,       blue
    ExtraDry,    yellow
    RegularDry    yellow
*/

const int POT_PIN = A3;
const int BUTTON_PIN = D2;
const int LED_RED_PIN = D3;    // red
const int LED_GREEN_PIN = D4;  // green
const int LED_BLUE_PIN = D5;   // blue

const int SHORT_CYCLE = 2000;
const int LONG_CYCLE = 4000;

unsigned long prevMillisState = 0;

// create enum State for states

// create enum Cycle for cycles

// create enum Color for light colors

/* DEBUGGING FUNCTIONS ONLY - uncomment if you need to use them
   ========================
*/
/*
String displayState(State s) {
    switch (s) {
        case Idle:
            return "idle";
        case Hot:
            return "hot";
        case ExtraDry:
            return "longdry";
        case Cold:
            return "cold";
        case RegularDry:
            return "shortdry";
    }
}

String displayCycle(Cycle c) {
    switch (c) {
        case Economy:
            return "economy";
        case Deluxe:
            return "deluxe";
        case SuperDeluxe:
            return "superdeluxe";
    }
}
*/

/* ===== FUNCTIONS ====== */
// TODO: create getCyclePotion
// reads potentiometer and returns current Cycle

// TODO: create updateNextState
// uses button inputs and current state to update global state variable

// TODO: create updateNextDuration
// update global state duration variable based on the current state

// TODO: create updateOutputs
// updates LEDs based on upcoming state

// LOOP
void loop() {
    
}

void setup() {
    Serial.begin(9600);
    pinMode(BUTTON_PIN, INPUT);
    pinMode(POT_PIN, INPUT);
    pinMode(LED_RED_PIN, OUTPUT);
    pinMode(LED_BLUE_PIN, OUTPUT);
    pinMode(LED_GREEN_PIN, OUTPUT);
}
