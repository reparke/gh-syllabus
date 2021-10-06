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

const int POT_PIN = A5;
const int SWITCH_PIN = D5;
const int LED_RED_PIN = D2;    // red
const int LED_GREEN_PIN = D3;  // green
const int LED_BLUE_PIN = D4;   // blue

const int SHORT_CYCLE = 2000;
const int LONG_CYCLE = 4000;

unsigned long prevMillisState = 0;
unsigned long stateDuration = 0;

// create enum State for states
enum State { Idle, Hot, Cold, ExtraDry, RegularDry };

// create enum Cycle for cycles
enum Cycle { Economy, Deluxe, SuperDeluxe };

enum Color { Red, Blue, Orange, White, Black };

State currentState = Idle;
Cycle currentCycle = Economy;

int counter = 0;  // debugging only

/* DEBUGGING FUNCTIONS ONLY
   ========================
*/
String getStateString() {
    String output = "";

    switch (currentState) {
        case Idle:
            output = "idle";
            break;
        case Hot:
            output = "hot";
            break;

        case ExtraDry:
            output = "longdry";
            break;

        case Cold:
            output = "cold";
            break;

        case RegularDry:
            output = "shortdry";
            break;
    }
    return output;
}
/* DEBUGGING FUNCTIONS ONLY
   ========================
*/
String getCycleString() {
    String output = "";
    switch (currentCycle) {
        case Economy:
            output = "economy";
            break;

        case Deluxe:
            output = "deluxe";
            break;

        case SuperDeluxe:
            output = "superdeluxe";
            break;
    }
    return output;
}

/* ===== FUNCTIONS ====== */
// TODO: create getCyclePotion
// reads potentiometer and returns current Cycle
Cycle getCyclePosition() {
    int value = analogRead(POT_PIN);
    if (value < 1365 && value >= 0)
        return Economy;
    else if (value >= 1365 && value < 2730)
        return Deluxe;
    else
        return SuperDeluxe;
}

// Alternate version of getCyclePotion that uses map
// reads potentiometer and returns current Cycle
// Cycle getCyclePosition() {
//     int rawValue = analogRead(POT_PIN);
//     int mappedVal = map(rawValue, 0, 4095, 0, 2);
//     Cycle c = (Cycle)mappedVal;
//     return c;
// }

// TODO: create updateNextState
// uses button inputs and current state to update global state variable
void updateNextState() {
    unsigned long currMillis = millis();

    switch (currentState) {
        case Idle:
            if (digitalRead(SWITCH_PIN) == 1) {
                currentState = Idle;
            } else {
                counter++;
                currentCycle = getCyclePosition();
                switch (currentCycle) {
                    case Economy:
                        currentState = Cold;
                        break;
                    case Deluxe:
                        currentState = Hot;
                        break;
                    case SuperDeluxe:
                        currentState = Hot;
                        break;
                }
                updateNextDuration();
                displayAllStateInfo();
            }
            break;
        case Hot:
            if (currMillis - prevMillisState > stateDuration) {
                prevMillisState = currMillis;
                counter++;
                currentCycle = getCyclePosition();

                if (currentCycle == Deluxe) {
                    currentState = RegularDry;
                } else if (currentCycle == SuperDeluxe) {
                    currentState = ExtraDry;
                }
                updateNextDuration();

                displayAllStateInfo();
            }
            break;
        case Cold:
            if (currMillis - prevMillisState > stateDuration) {
                prevMillisState = currMillis;
                counter++;

                currentState = RegularDry;
                updateNextDuration();

                displayAllStateInfo();
            }
            break;

        case RegularDry:
            if (currMillis - prevMillisState > stateDuration) {
                prevMillisState = currMillis;
                counter++;

                currentState = Idle;
                updateNextDuration();

                displayAllStateInfo();
            }
            break;

        case ExtraDry:
            if (currMillis - prevMillisState > stateDuration) {
                prevMillisState = currMillis;
                counter++;

                currentState = Idle;
                updateNextDuration();

                displayAllStateInfo();
            }
            break;
    }
}

// TODO: create updateNextDuration
// update global state duration variable based on the current state
void updateNextDuration() {
    switch (currentState) {
        case Idle:
            stateDuration = 0;
            break;
        case Hot:
            stateDuration = LONG_CYCLE;
            break;
        case Cold:
            stateDuration = SHORT_CYCLE;
            break;
        case RegularDry:
            stateDuration = SHORT_CYCLE;
            break;
        case ExtraDry:
            stateDuration = LONG_CYCLE;
            break;
    }
}

void setColor(Color c) {
    switch (c) {
        case Red:
            digitalWrite(LED_RED_PIN, HIGH);
            digitalWrite(LED_GREEN_PIN, LOW);
            digitalWrite(LED_BLUE_PIN, LOW);
            break;
        case White:
            digitalWrite(LED_RED_PIN, HIGH);
            digitalWrite(LED_GREEN_PIN, HIGH);
            digitalWrite(LED_BLUE_PIN, HIGH);
            break;
        case Blue:
            digitalWrite(LED_RED_PIN, LOW);
            digitalWrite(LED_GREEN_PIN, LOW);
            digitalWrite(LED_BLUE_PIN, HIGH);
            break;
        case Orange:
            analogWrite(LED_RED_PIN, 255);
            analogWrite(LED_GREEN_PIN, 165);
            digitalWrite(LED_BLUE_PIN, LOW);
            break;
        case Black:
            digitalWrite(LED_RED_PIN, LOW);
            digitalWrite(LED_GREEN_PIN, LOW);
            digitalWrite(LED_BLUE_PIN, LOW);
            break;
    }
}

// TODO: create updateOutputs
// updates LEDs based on upcoming state
void updateOutputs() {
    switch (currentState) {
        case Idle:
            setColor(White);
            break;

        case Hot:  // red
            setColor(Red);
            break;

        case Cold:  // blue
            setColor(Blue);
            break;

        case RegularDry:  // orange
            setColor(Orange);
            break;

        case ExtraDry:  // orange
            setColor(Orange);
            break;
    }
}

// LOOP
void loop() {
    testInitialSetup();
    // updateNextState();
}

void setup() {
    Serial.begin(9600);
    pinMode(SWITCH_PIN, INPUT);
    pinMode(POT_PIN, INPUT);
    pinMode(LED_RED_PIN, OUTPUT);
    pinMode(LED_BLUE_PIN, OUTPUT);
    pinMode(LED_GREEN_PIN, OUTPUT);
}

/*
 DEBUGGING FUNCTIONS (not for class)
=================================================
*/
void displayAllStateInfo() {
    int valPot = analogRead(POT_PIN);
    String stateString = getStateString();
    String cycleString = getCycleString();

    String output =
        "%d: %s; Cycle = %s; Duration = %d, Pot = %d, EnumState = %d, "
        "EnumCycle = %d";
    Serial.printlnf(output, counter, stateString.c_str(), cycleString.c_str(),
                    stateDuration, valPot, currentState, currentCycle);
}

// functions used for testing only
void testInitialSetup() {
    // test R, G, B LEDs individually; then white
    int lights[] = {LED_RED_PIN, LED_GREEN_PIN, LED_BLUE_PIN};

    // test R G B
    for (int i = 0; i < arraySize(lights); i++) {
        testInputs();
        digitalWrite(lights[i], HIGH);
        delay(1000);
        testInputs();

        digitalWrite(lights[i], LOW);
        delay(500);
    }

    // show white
    for (int i = 0; i < arraySize(lights); i++) {
        testInputs();

        digitalWrite(lights[i], HIGH);
    }
    delay(1000);
    // show black
    for (int i = 0; i < arraySize(lights); i++) {
        testInputs();

        digitalWrite(lights[i], LOW);
    }
    delay(500);

    //-----------------------
}
void testInputs() {
    String valSwitchString = digitalRead(SWITCH_PIN) ? "open" : "closed";
    int valPot = analogRead(POT_PIN);
    Serial.printlnf("Switch: %s, Pot: %d", valSwitchString.c_str(), valPot);
}