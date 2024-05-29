const int PIN_LED1 = D3;
const int PIN_LED2 = D4;
const int PIN_BUTTON = D2;

int counter = 0;

int prevButtonVal = 0;

void setup() {
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    pinMode(PIN_BUTTON, INPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(D7, HIGH);
    delay(1000);

    int currButtonVal = digitalRead(PIN_BUTTON);
    if (currButtonVal == LOW && prevButtonVal == HIGH) {
        counter = counter + 1;
        Serial.println("Current counter = " + String(counter));
        prevButtonVal = currButtonVal;
    }

    digitalWrite(D7, LOW);
    delay(1000);
}
