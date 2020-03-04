/* Wiring guide
  NorthSouth Red LED      -   D2
  NorthSouth Yellow LED   -   D3
  NorthSouth Green LED    -   D4
  WestEast Red LED        -   A0
  WestEast Yellow LED     -   A1
  WestEast Green LED      -   D5

  Walk White LED          -   D6
  Don't Walk Red LED      -   D7
*/

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

// for testing purposes only
int lights[] = {NSRed, NSYel, NSGrn, WERed, WEYel, WEGrn, WALK, DONTWALK};

// stage 1: NS lights only (vertical)
/* NSG, NSY, NSR
 */

enum State { NSG, NSY, NSR };
State currentState = NSG;  // start in NS green
int stateLength = 0;

// make a state transition function
State getNextState(State c) {
  // swithch or ifs
  switch (c) {
    case NSG:
      return NSY;
    case NSY:
      return NSR;
    case NSR:
      return NSG;
  }
}

int getStateDuration(State c) {
  switch (c) {
    case NSG:
    case NSR:
      return GO_TIME;
    case NSY:
      return TRANSITION_TIME;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(NSRed, OUTPUT);
  pinMode(NSYel, OUTPUT);
  pinMode(NSGrn, OUTPUT);
  pinMode(WERed, OUTPUT);
  pinMode(WEYel, OUTPUT);
  pinMode(WEGrn, OUTPUT);
  pinMode(WALK, OUTPUT);
  pinMode(DONTWALK, OUTPUT);
}

/* ======= FUNCTIONS =========== */
// TODO: COMPLETE
void setLight(State c) {
  digitalWrite(NSRed, LOW);
  digitalWrite(NSYel, LOW);
  digitalWrite(NSGrn, LOW);
  digitalWrite(WERed, LOW);
  digitalWrite(WEYel, LOW);
  digitalWrite(WEGrn, LOW);
  digitalWrite(WALK, LOW);
  digitalWrite(DONTWALK, LOW);

  switch (c) {
    case NSY:
      digitalWrite(NSYel, HIGH);
      break;
    // case NSR:                    //stage 2
    case NSR:
      digitalWrite(NSRed, HIGH);
      break;
    case NSG:
      digitalWrite(NSGrn, HIGH);
      break;
  }
}
/*
  check what state and change the state
  get the duration
  implement the state -- turn on lights
*/
void loop() {
  currentState = getNextState(currentState);
  stateLength = getStateDuration(currentState);
  setLight(currentState);
  delay(stateLength);
}

// TODO: COMPLETE getNextState

// TODO: COMPLETE getNextStateDuration

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