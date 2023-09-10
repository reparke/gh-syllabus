/*
First thing when opening projects
 - configure for device
 - setup pinmodes
 - serial.beging
 - make pin labels (globacl constants)
*/

const int PIN_BUTTON = D5;
const int PIN_RGB_R = D2;
const int PIN_RGB_G = D3;
const int PIN_RGB_B = D4;
const int PIN_ONBOARD_LED = D7;  // this is always D7

int previousButtonVal = LOW;  // this is our "memory" of last loop()
int counter = 0;

bool ledOn = false;

// define a function
// step 1: define the function -- what it will do
// step 2: later we call / use function (probably happens in loop)

void displayRgbColor(int r, int g, int b) {
    analogWrite(PIN_RGB_R, r);
    analogWrite(PIN_RGB_G, g);
    analogWrite(PIN_RGB_B, b);
}

void setup() {
    Serial.begin(9600);
    pinMode(PIN_BUTTON, INPUT);
    pinMode(PIN_RGB_R, OUTPUT);
    pinMode(PIN_RGB_G, OUTPUT);
    pinMode(PIN_RGB_B, OUTPUT);
    pinMode(PIN_ONBOARD_LED, OUTPUT);
}

void loop() {
    // button review
    //  int buttonVal = digitalRead(PIN_BUTTON);
    //  Serial.println("The button value is " + String(buttonVal));
    //  delay(100);

    // if (buttonVal == HIGH) {
    //   digitalWrite(PIN_ONBOARD_LED, LOW);
    // }
    // else { //buttonVal is low
    //   digitalWrite(PIN_ONBOARD_LED, HIGH);
    // }

    // int buttonVal = digitalRead(PIN_BUTTON);
    // if (buttonVal == HIGH) {
    //     digitalWrite(PIN_ONBOARD_LED, LOW);
    // }
    // else {
    //     digitalWrite(PIN_ONBOARD_LED, HIGH);
    // }
    // make the RGB LED turn white when the button pressed, and then off
    // otherwise

    // int buttonVal = digitalRead(PIN_BUTTON);
    // if (buttonVal == LOW) {         //pressed
    //     // analogWrite(PIN_RGB_R, 255);
    //     // analogWrite(PIN_RGB_G, 0);
    //     // analogWrite(PIN_RGB_B, 0);
    //     displayRgbColor(255, 0, 0);
    //     delay(500);

    //     // analogWrite(PIN_RGB_G, 255);
    //     // analogWrite(PIN_RGB_B, 0);
    //     displayRgbColor(0,0,255);
    //     delay(500);

    //     // analogWrite(PIN_RGB_R, 255);
    //     // analogWrite(PIN_RGB_G, 109);
    //     // analogWrite(PIN_RGB_B, 0);
    //     displayRgbColor(255, 109, 0);
    //     delay(500);

    // } else {
    //     // analogWrite(PIN_RGB_R, 0);
    //     // analogWrite(PIN_RGB_G, 0);
    //     // analogWrite(PIN_RGB_B, 0);
    //   displayRgbColor(0,0,0);
    // }

    // to make latch
    // we need two variables--current and prev button
    // if we want "falling edge" (aka press button)
    //    prev was high, and current is low
    int currentButtonVal = digitalRead(PIN_BUTTON);
    if (currentButtonVal == LOW && previousButtonVal == HIGH) {
        // here we know the button was pressed just once!
        counter = counter + 1;
        Serial.println("Counter = " + String(counter));
        if (ledOn == false) {
            displayRgbColor(0, 0, 0);
            ledOn = true;
        } else {
            displayRgbColor(255, 255, 255);
            ledOn = false;
        }
    }

    // at the very end of loop, we need to update prev
    previousButtonVal = currentButtonVal;
}