const int PIN_PIR = D2;
const int PIN_LED = D7;

unsigned long prevAlarm = 0;
unsigned long holdTime = 3000;  // 3s = 3000ms

void setup() {
    pinMode(PIN_PIR, INPUT);
    pinMode(PIN_LED, OUTPUT);
    Serial.begin(9600);

    // many PIR sensors recommend a short delay here
    delay(2000);
}

/*
  alarm disabled / enabled
  connect to webservice to track time
  trip alarm, and it stays on
  only trigger alarm AT MOST every X milliseconds
*/
void loop() {
    int reading = digitalRead(PIN_PIR);
    // low = movement, high = no movement

    unsigned long curMillis = millis();
    if (reading == LOW) {
        digitalWrite(PIN_LED, HIGH);
        Serial.println("Motion detected!");
        prevAlarm = curMillis;
    } else {  // no movment detected
        if (curMillis - prevAlarm > holdTime) {
            digitalWrite(PIN_LED, LOW);
            Serial.println("Motion stopped!");
        }
    }
}