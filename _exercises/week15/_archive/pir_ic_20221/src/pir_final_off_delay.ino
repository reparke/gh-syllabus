const int PIN_LED = D7;
const int PIN_MOTION = D2;
unsigned long prevAlarmMillis = 0;

void setup()
{
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_MOTION, INPUT);
    Serial.begin(9600);
    delay(10000);
}

 void loop()
{
    int movement = digitalRead(PIN_MOTION);
    unsigned long curMillis = millis();

    if (movement == LOW) { //motion detected
        digitalWrite(PIN_LED, HIGH);
        Serial.println("Motion detected!");
        prevAlarmMillis = curMillis; //reset the last alarm time
    }
    else if (curMillis - prevAlarmMillis < 5000 ) { //motion stop, but hold alarm for 5 sec
        digitalWrite(PIN_LED, HIGH);
        Serial.println("Motion stopped, but holding alarm!");
    }
    else {                              // motion stopped greater than 5 sec ago
        digitalWrite(PIN_LED, LOW);
        Serial.println("Motion stopped; alarm off");
    }
    delay(1000);
}