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

/* DEBUGGING FUNCTIONS ONLY
   ========================
*/
String getStateString(State s) {
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
/* DEBUGGING FUNCTIONS ONLY
   ========================
*/
String getCycleString(Cycle c) {
    switch (c) {
        case Economy:
            return "economy";
        case Deluxe:
            return "deluxe";
        case SuperDeluxe:
            return "superdeluxe";
    }
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
    State next;

    switch (currentState) {
        case Idle:
            if (digitalRead(SWITCH_PIN) == 1) {
                next = Idle;
            } else {
                Cycle cycle = getCyclePosition();
                switch (cycle) {
                    case Economy:
                        next = Cold;
                        break;
                    case Deluxe:
                        next = Hot;
                        break;
                    case SuperDeluxe:
                        next = Hot;
                        break;
                }
            }
            break;
        case Hot:
            if (getCyclePosition() == Deluxe) {
                next = RegularDry;
            } else if (getCyclePosition() == SuperDeluxe) {
                next = ExtraDry;
            }
            break;
            next = ExtraDry;
            break;
        case Cold:
            next = RegularDry;
            break;

        case RegularDry:
            next = Idle;
            break;

        case ExtraDry:
            next = Idle;
            break;
    }

    currentState = next;
}

// TODO: create updateNextDuration
// update global state duration variable based on the current state
void updateNextDuration() {
    int next;

    switch (currentState) {
        case Idle:
            next = 0;
            break;
        case Hot:
            next = LONG_CYCLE;
            break;
        case Cold:
            next = SHORT_CYCLE;
            break;
        case RegularDry:
            next = SHORT_CYCLE;
            break;
        case ExtraDry:
            next = LONG_CYCLE;
            break;
    }

    stateDuration = next;
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
    unsigned long currMillis = millis();
    if (currMillis - prevMillisState > stateDuration) {
        prevMillisState = currMillis;
        updateNextState();
        updateNextDuration();
        updateOutputs();
        // if (currentState != 0) {
        //     Serial.print(getCycleString(getCyclePosition()));
        //     Serial.println(", Next state " + getStateString(currentState) + "
        //     for " + String(stateDuration));
        // }
    }
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