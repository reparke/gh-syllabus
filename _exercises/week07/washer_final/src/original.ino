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
const int LED_RED_PIN = D3;    //red
const int LED_GREEN_PIN = D4;  //green
const int LED_BLUE_PIN = D5;  //blue

const int SHORT_CYCLE = 2000;
const int LONG_CYCLE = 4000;

unsigned long prevMillisState = 0;
unsigned long stateDuration = 0;

enum State {
    Idle,
    Hot,
    Cold,
    ExtraDry,
    RegularDry
};

enum Cycle {
    Economy,
    Deluxe,
    SuperDeluxe
};

State currentState = Idle;

// function for debugging only
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

// function for debugging only
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


Cycle getCyclePosition() {
    int value = analogRead(POT_PIN);
    if (value < 1365 && value >= 0)
        return Economy;
    else if (value >= 1365 && value < 2730)
        return Deluxe;
    else
        return SuperDeluxe;
}

void nextState() {
    State next;

    switch (currentState) {
        case Idle:
            if (digitalRead(BUTTON_PIN) == 1) {
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
void nextDuration() {
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
void setOutputs() {
    switch (currentState) {
        case Idle:
            analogWrite(LED_RED_PIN, 255);
            analogWrite(LED_GREEN_PIN, 255);
            analogWrite(LED_BLUE_PIN, 255);
            break;

        case Hot:  //red
            analogWrite(LED_RED_PIN, 255);
            analogWrite(LED_GREEN_PIN, 0);
            analogWrite(LED_BLUE_PIN, 0);
            break;

        case Cold:  //blue
            analogWrite(LED_RED_PIN, 0);
            analogWrite(LED_GREEN_PIN, 0);
            analogWrite(LED_BLUE_PIN, 255);
            break;

        case RegularDry:  //orange
            analogWrite(LED_RED_PIN, 255);
            analogWrite(LED_GREEN_PIN, 165);
            analogWrite(LED_BLUE_PIN, 0);
            break;

        case ExtraDry:  //orange
            analogWrite(LED_RED_PIN, 255);
            analogWrite(LED_GREEN_PIN, 165);
            analogWrite(LED_BLUE_PIN, 0);
            break;
    }
}

void loop() {
    unsigned long currMillis = millis();
    if (currMillis - prevMillisState > stateDuration) {
        prevMillisState = currMillis;
        nextState();
        nextDuration();
        setOutputs();
        // if (currentState != 0) {
        //     Serial.print(displayCycle(getCyclePosition()));
        //     Serial.println(", Next state " + displayState(currentState) + " for " + String(stateDuration));
        // }
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
