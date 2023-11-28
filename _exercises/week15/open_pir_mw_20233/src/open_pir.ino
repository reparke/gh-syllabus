const int PIN_MOVEMENT = D2;
const int PIN_LED = D7;

void setup() {
    Serial.begin(9600);
    pinMode(PIN_MOVEMENT, INPUT);
    pinMode(PIN_LED, OUTPUT);
}

void loop() {
    // to detect movement, we do digital read on the sensor
    int alarm = digitalRead(PIN_MOVEMENT);

    if (alarm == HIGH) {
        digitalWrite(PIN_LED, HIGH);
        Serial.println("Motion detected");
    } else {
        digitalWrite(PIN_LED, LOW);
        Serial.println("Motion stopped");
    }
}