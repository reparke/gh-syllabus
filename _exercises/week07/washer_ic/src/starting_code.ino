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
enum State { Idle, Hot, Cold, ExtraDry, RegularDry };

// create enum Cycle for cycles
enum Cycle { Economy, Deluxe, SuperDeluxe };

// create enum Color for light colors
enum Color { Red, Blue, Orange, White, Black };

// to manage state
State currentState = Idle;  // starting state
Cycle currentCycle = Economy;
unsigned long stateDuration = 0;  // how long am I in the current state

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
void getCyclePosition() {
    int pos = analogRead(
        POT_PIN);  // 0 4095---> 0-1364 Eco, 1365-2729 Del, rest is SuperDel
    if (pos >= 0 && pos < 1365) {
        currentCycle = Economy;
    } else if (pos >= 1365 && pos < 2730) {
        currentCycle = Deluxe;
    } else {
        currentCycle = SuperDeluxe;
    }

    // //fun alt
    // int value = map(analogRead(POT_PIN, 0, 4095, 0, 2));
    // currentCycle = (Cycle) value;
}

// TODO: create updateNextState
// uses button inputs and current state to update global state variable
void updateNextState() {
    switch (currentState) {
        case Idle:
            if (digitalRead(BUTTON_PIN) == 0) {  // mag switch closed
                getCyclePosition();
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
            }
            break;
        case Cold:
            currentState = RegularDry;
            break;
        case Hot:
            if (currentCycle == Deluxe) {
                currentState = RegularDry;
            } else {
                currentState = ExtraDry;
            }
            break;
        case RegularDry:
            currentState = Idle;
            break;
        case ExtraDry:
            currentState = Idle;
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
            if (currentCycle == Deluxe) {
                stateDuration = SHORT_CYCLE;
            } else {
                stateDuration = LONG_CYCLE;
            }
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
        case Cold:
            setColor(Blue);
            break;
        case Hot:
            setColor(Red);
            break;
        case ExtraDry:
            setColor(Orange);
            break;
        case RegularDry:
            setColor(Orange);
            break;
    }
}
// LOOP
void loop() {
    // check timer
    // check cycle
    // check if switch is closed
    // update state

    unsigned long curMillis = millis();
    if (curMillis - prevMillisState >
        stateDuration) {              // the timer is up....this could be ANY
        prevMillisState = curMillis;  // update
        updateNextState();     // 1. determine the next state we should go to
        updateNextDuration();  // 2. change to new timer
        updateOutputs();       // 3. change any LEDS etc. based the new state
    }
}

void setup() {
    Serial.begin(9600);
    pinMode(BUTTON_PIN, INPUT);
    pinMode(POT_PIN, INPUT);
    pinMode(LED_RED_PIN, OUTPUT);
    pinMode(LED_BLUE_PIN, OUTPUT);
    pinMode(LED_GREEN_PIN, OUTPUT);
}
