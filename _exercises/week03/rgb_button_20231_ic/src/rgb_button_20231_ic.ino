const int PIN_RED = D2;
const int PIN_GREEN = D3;
const int PIN_BLUE = D4;
const int PIN_BUTTON = D5;

// global variables
//  store the current and prev button values
int curButtonVal = HIGH;
int prevButtonVal = HIGH;

// our counter needs to be a global variable
int butttonCounter = 0;
bool redOn = false;

int lightSequence = 0;  // 0 is white, 1 is red, and 2 is blue

void displayRandomColor() {
    int r = random(0, 256);
    int b = random(0, 256);
    int g = random(0, 256);
    analogWrite(PIN_RED, r);
    analogWrite(PIN_GREEN, g);
    analogWrite(PIN_BLUE, b);
}
void displayColor(int r, int g, int b) {
    analogWrite(PIN_RED, r);
    analogWrite(PIN_GREEN, g);
    analogWrite(PIN_BLUE, b);
}

void setup() {
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_BUTTON, INPUT);
    Serial.begin(9600);
}

// we are NOT directly controlling the LED
void loop() {
    // //version 1
    // //read button
    // int buttonVal = digitalRead(PIN_BUTTON);
    // if (buttonVal == HIGH) {
    //     digitalWrite(PIN_RED, LOW);
    // }
    // else {
    //     digitalWrite(PIN_RED, HIGH);
    // }

    // // version 2 -- toggle or latch
    // // read button
    // curButtonVal = digitalRead(PIN_BUTTON);
    // //looking for falling edge--press down
    // if (prevButtonVal == HIGH && curButtonVal == LOW) { //button was just
    // pressed
    //     //we need to know if light is on or off
    //     butttonCounter = butttonCounter + 1;  // butttonCounter++;
    //     Serial.println("button presses " + String(butttonCounter));

    //     if (redOn == true) {  // red light is currently on
    //         redOn = false;  //change state
    //         digitalWrite(PIN_RED, LOW);
    //     }
    //     else {// red light is currently off
    //         redOn = true;
    //         digitalWrite(PIN_RED, HIGH);
    //     }
    // }

    // version 3 -- toggle or latch to show random color
    //     curButtonVal = digitalRead(PIN_BUTTON);
    //     // looking for falling edge--press down
    //     if (prevButtonVal == HIGH &&
    //         curButtonVal == LOW) {  // button was just pressed

    //         displayRandomColor();
    //     }
    //     prevButtonVal = curButtonVal;
    // }

    // version 4 - cycle through white, red, and blue
    curButtonVal = digitalRead(PIN_BUTTON);
    // looking for falling edge--press down
    if (prevButtonVal == HIGH &&
        curButtonVal == LOW) {  // button was just pressed

lightSequence = (lightSequence + 1) % 3;
/*
    Why this works
    --------------
    lightSequence  |  lightSequence + 1 | (lightSequence + 1) % 3
            0                    1                     1
            1                    2                     2
            2                    3                     0
*/

if (lightSequence == 0) {
    displayColor(255, 255, 255);
} else if (lightSequence == 1) {
    displayColor(255, 0, 0);
} else if (lightSequence == 2) {
    displayColor(0, 0, 255);
}
    }
    prevButtonVal = curButtonVal;
}

/*
    int a = 5;
    a++; // always means add 1
    a--; // means subtract 1
*/