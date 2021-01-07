const int PIN_MOTION = D2;
const int PIN_LED = D7;


void setup()
{
    pinMode(PIN_MOTION, INPUT);
    pinMode(PIN_LED, OUTPUT);
    Serial.begin(9600);

    delay(2000);    //need to a "baseline" of the room
}

void loop(){
    int motion = digitalRead(PIN_MOTION);
    //if motion is LOW, then movement was detected; if HIGH, no motion

    if(motion == HIGH) {
        digitalWrite(PIN_LED, LOW);
        Serial.println("movement stopped");
    }
    else {
        digitalWrite(PIN_LED, HIGH);
        Serial.println("movement detected");
    }
    delay(1000);
}

void part2AlarmHold() {
    unsigned long curMillis = millis();
    int proximity = digitalRead(MOTION_PIN);
    // Serial.println("Motion pin: " + String(proximity));
    if (proximity == LOW)  // If the sensor's output goes low, motion is detected
    {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Motion detected!");
        prevAlarmMillis = curMillis;
    } else if ((curMillis - prevAlarmMillis) > timeAfterAlarm) {
        // } else  {
        digitalWrite(LED_PIN, LOW);
        Serial.println("Motion stopped!");
    }

}