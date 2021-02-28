/*
    STATE TRANSITIONS
    =================
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

    STATE COLORS
    ============
    Idle,       white
    Hot,        red
    Cold,       blue
    ExtraDry,    yellow
    RegularDry    yellow
*/

const int POT_PIN = A3;
const int BUTTON_PIN = D2;
const int LED_RED_PIN = D3;
const int LED_GREEN_PIN = D4;
const int LED_BLUE_PIN = D5;

const int SHORT_CYCLE = 2000;  //instead of 2 min, we use 2 sec
const int LONG_CYCLE = 4000;   //instead of 4 min, we use 4 sec

unsigned long prevMillisState = 0;

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
