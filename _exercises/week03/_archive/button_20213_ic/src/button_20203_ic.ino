const int PIN_BUTTON = D2;
const int PIN_LED_1 = D3;
const int PIN_LED_2 = D4;

// global variables
// state variable--what is happening in my code
int stateButtonCurrent = HIGH;  // unpressed
int stateButtonPrevious = HIGH;

bool isLedOn = false;  // have we turned the light on or off

void setup() {
    Serial.begin(9600);  // "Baud" -- bits per second
    // set pin mode
    pinMode(PIN_BUTTON, INPUT);
    pinMode(PIN_LED_1, OUTPUT);
    pinMode(PIN_LED_2, OUTPUT);
}

void loop() {
    stateButtonCurrent =
        digitalRead(PIN_BUTTON);  // what is happening with button NOW

    // we know a button press means: now button is low, prev button was high
    if (stateButtonCurrent == LOW && stateButtonPrevious == HIGH) {
        if (isLedOn == true) {
            isLedOn = false;
            digitalWrite(PIN_LED_1, LOW);
            digitalWrite(PIN_LED_2, LOW);
        } else {
            isLedOn = true;
            digitalWrite(PIN_LED_1, HIGH);
            digitalWrite(PIN_LED_2, HIGH);
        }
    }

    stateButtonPrevious = stateButtonCurrent;

    // read the digital input
    // int buttonVal = digitalRead(PIN_BUTTON);

    // Serial.println("Button value: " + String(buttonVal));

    // Version 1: LED follows button
    // if (buttonVal == LOW) {  // button is LOW, aka closed pressed
    //     digitalWrite(PIN_LED_1, HIGH);
    //     digitalWrite(PIN_LED_2, HIGH);
    // } else {  // button is HIGH aka open, unpressed
    //     digitalWrite(PIN_LED_1, LOW);
    //     digitalWrite(PIN_LED_2, LOW);
    // }
}