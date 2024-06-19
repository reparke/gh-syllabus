
/*
    Econ
        ColdWash 2 min
        RegularDry 2 min
        Idle
    Deluxe
        HotWash 2 min
        RegularDry 2 min
        Idle
    Super
        HotWash 4 min
        ExtraDry 4 min
        Idle


Colors:
    Idle        white
    HotWash         red
    ColdWash        blue
    RegularDry  orange
    ExtraDry    yellow

*/

const int POT_PIN = A1;
const int SWITCH_PIN = D5;
const int LED_RED_PIN = A2;    // red
const int LED_GREEN_PIN = A5;  // green
const int LED_BLUE_PIN = D15;   // aka MOSI pin, blue

const int SHORT_CYCLE = 2000;
const int LONG_CYCLE = 4000;

unsigned long prevMillisState = 0;

// create enum State for states
enum State { Idle, HotWash, ColdWash, ExtraDry, RegularDry };

// create enum Cycle for cycles
enum Cycle { Economy, Deluxe, SuperDeluxe };

enum Color { Red, Blue, Orange, Yellow, White, Black };

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
            output = "Idle";
            break;
        case HotWash:
            output = "Hot Wash";
            break;

        case ExtraDry:
            output = "Extra Dry";
            break;

        case ColdWash:
            output = "Cold Wash";
            break;

        case RegularDry:
            output = "Regular Dry";
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
            output = "Economy";
            break;

        case Deluxe:
            output = "Deluxe";
            break;

        case SuperDeluxe:
            output = "Super Deluxe";
            break;
    }
    return output;
}

/* ===== FUNCTIONS ====== */
// TODO: create getCyclePotion
// reads potentiometer and updates current Cycle

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
        case Yellow:
            analogWrite(LED_RED_PIN, 0);
            analogWrite(LED_GREEN_PIN, 255);
            digitalWrite(LED_BLUE_PIN, LOW);
            break;
        case Black:
            digitalWrite(LED_RED_PIN, LOW);
            digitalWrite(LED_GREEN_PIN, LOW);
            digitalWrite(LED_BLUE_PIN, LOW);
            break;
    }
}

// void getCyclePosition() {
//     int value = analogRead(POT_PIN);
//     if (value < 1365 && value >= 0)
//         currentCycle = Economy;
//     else if (value >= 1365 && value < 2730)
//         currentCycle = Deluxe;
//     else
//         currentCycle = SuperDeluxe;
// }

// Alternate version of getCyclePotion that uses map
// reads potentiometer and returns current Cycle
void getCyclePosition() {
    int rawValue = analogRead(POT_PIN);
    int mappedVal = map(rawValue, 0, 4095, 0, 2);
    currentCycle = (Cycle)mappedVal;
}

// TODO: create updateNextState
// uses button inputs and current state to update global state variable
void updateNextState() {
    unsigned long currMillis = millis();
    getCyclePosition();

    switch (currentState) {
        case Idle:
            if (digitalRead(SWITCH_PIN) == 0) {
                // currentState = Idle;
                // } else {
                counter++;
                switch (currentCycle) {
                    case Economy:
                        currentState = ColdWash;
                        break;
                    case Deluxe:
                        currentState = HotWash;
                        break;
                    case SuperDeluxe:
                        currentState = HotWash;
                        break;
                }
                prevMillisState = currMillis;
                setColor(White);

                displayAllStateInfo();
            }
            break;
        case HotWash:
            if (currMillis - prevMillisState > SHORT_CYCLE) {
                prevMillisState = currMillis;
                counter++;

                if (currentCycle == Deluxe) {
                    currentState = RegularDry;
                } else if (currentCycle == SuperDeluxe) {
                    currentState = ExtraDry;
                }
                setColor(Red);

                displayAllStateInfo();
            }
            break;
        case ColdWash:
            if (currMillis - prevMillisState > SHORT_CYCLE) {
                prevMillisState = currMillis;
                counter++;

                currentState = RegularDry;
                setColor(Blue);

                displayAllStateInfo();
            }
            break;

        case RegularDry:
            if (currMillis - prevMillisState > SHORT_CYCLE) {
                prevMillisState = currMillis;
                counter++;

                currentState = Idle;
                setColor(Orange);

                displayAllStateInfo();
            }
            break;

        case ExtraDry:
            if (currMillis - prevMillisState > LONG_CYCLE) {
                prevMillisState = currMillis;
                counter++;

                currentState = Idle;
                setColor(Yellow);

                displayAllStateInfo();
            }
            break;
    }
}

// LOOP
void loop() {
    // testInitialSetup();
    updateNextState();
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
        "%d: %s; Cycle = %s; Pot = %d, EnumState = %d, "
        "EnumCycle = %d";
    Serial.printlnf(output, counter, stateString.c_str(), cycleString.c_str(),
                    valPot, currentState, currentCycle);
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