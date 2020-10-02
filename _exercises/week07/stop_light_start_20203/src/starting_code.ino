
const int NSRed = D2;
const int NSYel = D3;
const int NSGrn = D4;
const int WERed = A0;
const int WEYel = A1;
const int WEGrn = D5;
const int WALK = D6;
const int DONTWALK = D7;

const int GO_TIME = 5000;          // time for green, red, walk, don't walk
const int TRANSITION_TIME = 1000;  // time for yellow
const int BLINK_RATE = 500;        // time for blinking don't walk light

// for testing purposes onle
int lights[] = {NSRed, NSYel, NSGrn, WERed, WEYel, WEGrn, WALK, DONTWALK};

//stage 1: NS lights
/*
  green -> yellow -> red -> green ( STATES)
  how do we go from stateGreen to stateYellow? what causes that?
    -- timer millis INPUT
  when we get to a state, what do we have to do? OUTPUTS
    -- current light goes on, previous  light goes off

stage 2:
  green -> yellow -> red/PEDwalk -> PEDdon't walk

stage 3:
    another timer that tracks whether to blink or not


*/



//states
//enum is a type in C++ just int
//"State" is a word we just chose
// enum State { NSG,
//              NSY,
//              NSR };        //just north south light state
enum State { NSG, NSY, PEDW, PEDDW };  //just north south light state
//PEDDW is a shrt lngth

State currentState = NSG;  //state we start in

unsigned long prevStateMillis = 0;
unsigned long stateLength = 0;  //how long should we stay in the current state

unsigned long prevBlinkMillis = 0;
bool isWalkOn = false;

void setup() {
    Serial.begin(9600);
    // put your setup code here, to run once:
    pinMode(NSRed, OUTPUT);
    pinMode(NSYel, OUTPUT);
    pinMode(NSGrn, OUTPUT);
    pinMode(WERed, OUTPUT);
    pinMode(WEYel, OUTPUT);
    pinMode(WEGrn, OUTPUT);
    pinMode(WALK, OUTPUT);
    pinMode(DONTWALK, OUTPUT);
}
void loop() {
    // test all lights -- delete once wiring is verified
    // turnAllLightsOn();
    // delay(2000);
    // turnAllLightsOff();
    // cycleLights(500);

    //get the time
    //IF the curtime - prevTime > state length
    //update our time
    //change our state
    //update our state length
    //change our lights
    unsigned long currMillis = millis();

    if ((currMillis - prevStateMillis) > stateLength) {
        prevStateMillis = currMillis;  //update time
        Serial.println("Changing state...");
        updateState();
        updateStateDuration();
        setLights();
    }
    //control blink
    if ((currMillis - prevBlinkMillis) > BLINK_RATE && currentState == PEDW) {
        prevBlinkMillis = currMillis;
        //turn off if it was on
        //turn on if it was off
        if (isWalkOn == true) {
            isWalkOn = false;
            digitalWrite(WALK, LOW);
        }
        else {
            isWalkOn = true;
            digitalWrite(WALK, HIGH);
        }

    }
}

/* ======= FUNCTIONS =========== */
// TODO: COMPLETE
void setLights() {
    digitalWrite(NSRed, LOW);
    digitalWrite(NSYel, LOW);
    digitalWrite(NSGrn, LOW);
    digitalWrite(WERed, LOW);
    digitalWrite(WEYel, LOW);
    digitalWrite(WEGrn, LOW);
    digitalWrite(WALK, LOW);
    digitalWrite(DONTWALK, LOW);

    //figure out lights to turn on
    switch (currentState) {
        case NSG:             //green light + don't walk
            digitalWrite(NSGrn, HIGH);
            digitalWrite(DONTWALK, HIGH);
            break;
        case NSY:             //yellow + don't walk
            digitalWrite(NSYel, HIGH);
            digitalWrite(DONTWALK, HIGH);
            break;
        case PEDW:          //red + walk
            digitalWrite(NSRed, HIGH);
            digitalWrite(WALK, HIGH);
            break;
        case PEDDW: //red + don't walk
            digitalWrite(NSRed, HIGH);
            digitalWrite(DONTWALK, HIGH);
            break;
    }
}

// TODO: COMPLETE updateNextState
// looks at currentState global var
//and determines next state
void updateState() {
    switch (currentState) {
        case NSG:
            currentState = NSY;
            break;
        case NSY:
            currentState = PEDW;
            break;
        case PEDW:
            currentState = PEDDW;
            break;
        case PEDDW:
            currentState = NSG;
            //no need for default
    }
}

// TODO: COMPLETE updateNextStateDuration
// determine how long we stay in the length state
// yellow is shorter (TRANSITION); green and red are longer (GO)
void updateStateDuration() {
    switch (currentState) {
        case PEDDW:
            stateLength = TRANSITION_TIME;
            break;
        case NSY:
            stateLength = TRANSITION_TIME;
            break;
        default:  //else
            stateLength = GO_TIME;
    }
}

/* ======= FUNCTIONS FOR DEBUGGING LED WIRING ========= */
// functions used for testing only
void cycleLights(int delayMS) {
    for (int i = 0; i < arraySize(lights); i++) {
        digitalWrite(lights[i], HIGH);
        delay(delayMS);
        digitalWrite(lights[i], LOW);
    }
}

void turnAllLightsOn() {
    for (int i = 0; i < arraySize(lights); i++) {
        digitalWrite(lights[i], HIGH);
    }
}

void turnAllLightsOff() {
    for (int i = 0; i < arraySize(lights); i++) {
        digitalWrite(lights[i], LOW);
    }
}