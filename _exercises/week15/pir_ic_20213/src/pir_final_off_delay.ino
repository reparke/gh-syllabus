const int PIN_ALARM = D2;
const int PIN_LED = D7;

unsigned long alarmHold = 5000;
unsigned long prevMillis = 0;

void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_ALARM, INPUT);
    Serial.begin(9600);

    // you need a 1-2 sec DELAY
    delay(1000);
}

void loop() {
    int motion = digitalRead(PIN_ALARM);

    unsigned long curMillis = millis();
    // if (motion == HIGH) {
    //     Serial.println("Motion NOT detected");
    //     digitalWrite(PIN_LED, LOW);
    // } else {
    //     Serial.println("Motion detected");
    //     digitalWrite(PIN_LED, HIGH);
    // }
    if (motion == LOW) {
      digitalWrite(PIN_LED, HIGH);
      //reset timer
      prevMillis = curMillis;
      Serial.println("Motion detec");

    }
    else if (curMillis - prevMillis > alarmHold) {
      digitalWrite(PIN_LED, LOW);
      Serial.println("Motion stopped");
    }

  /*
    alarm ON: reset our timer, turn on light
    alarm OFF:
      if we've exceeed our hold time, turn off light
  */

}


// when there motion, light stays on for 5 sec
// when there's motion for 5 sec, light turns off
// don't use delay