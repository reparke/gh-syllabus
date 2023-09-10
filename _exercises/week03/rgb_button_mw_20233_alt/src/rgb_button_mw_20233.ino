const int PIN_BUTTON = D5;

int buttonPresses = 0;
int counter = 0;

void setup() {
    pinMode(PIN_BUTTON, INPUT);
    Serial.begin(9600);
}

void loop() {
    int buttonVal = digitalRead(PIN_BUTTON);  // this is doing to be 0 or 1

    // Serial.println("Button val = " + String(buttonVal));
    if (buttonVal == LOW) {  // pressed
        counter = counter + 1;
    }
    Serial.println("Counter = " + String(counter));
}