const int PIN_LED_RED = D2;
const int PIN_LED_GREEN = D3;
const int PIN_LED_BLUE = D4;
const int PIN_BUTTON = D5;

// state
int stateButtonPrevious = HIGH;
int stateButtonCurrent = HIGH;

// Serial
// 1. in setup, Serial.begin
// 2. in loop, call Serial.println
// 3. Start the Serial monitor

void setup() {
    Serial.begin(9600);
    pinMode(PIN_LED_RED, OUTPUT);
    pinMode(PIN_LED_GREEN, OUTPUT);
    pinMode(PIN_LED_BLUE, OUTPUT);
    pinMode(PIN_BUTTON, INPUT);
}

void loop() {
    // create light pattern
    // Red, Blue, White, Magenta/Purple

    // //RED
    // digitalWrite(PIN_LED_RED, HIGH);
    // digitalWrite(PIN_LED_GREEN, LOW);
    // digitalWrite(PIN_LED_BLUE, LOW);
    // delay(500);
    // // Blue
    // digitalWrite(PIN_LED_RED, LOW);
    // digitalWrite(PIN_LED_GREEN, LOW);
    // digitalWrite(PIN_LED_BLUE, HIGH);
    // delay(500);
    // // WHITE
    // digitalWrite(PIN_LED_RED, HIGH);
    // digitalWrite(PIN_LED_GREEN, HIGH);
    // digitalWrite(PIN_LED_BLUE, HIGH);
    // delay(500);
    // // Magenta
    // digitalWrite(PIN_LED_RED, HIGH);
    // digitalWrite(PIN_LED_GREEN, LOW);
    // digitalWrite(PIN_LED_BLUE, HIGH);
    // delay(500);

    // // orange -- orange has only partial green so we need ANALOGWRITE
    // analogWrite(PIN_LED_RED, 255);
    // analogWrite(PIN_LED_GREEN, 120);
    // analogWrite(PIN_LED_BLUE, 0);

    // read new value
    stateButtonCurrent = digitalRead(PIN_BUTTON);
    if (stateButtonCurrent == LOW && stateButtonPrevious == HIGH) {
        displayRandomColor();
    }
    stateButtonPrevious = stateButtonCurrent;
}

// write a function that displays a random color
// random(startNum, endUPTOBUTINCLUDING)

// returnType functionName(inputParam)
void displayRandomColor() {
    // generate three random nums between 0-255
    // put into RGBs
    int randR = random(0, 256);  // generate from start to end-1
    int randG = random(0, 256);
    int randB = random(0, 256);

    analogWrite(PIN_LED_RED, randR);
    analogWrite(PIN_LED_GREEN, randG);
    analogWrite(PIN_LED_BLUE, randB);
}