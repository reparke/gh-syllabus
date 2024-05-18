unsigned long WAKE_DURATION = 120000;
unsigned long SLEEP_DURATION = 20000;
unsigned long prevMillis = 0;

int prevButtonVal = HIGH;
int currButtonVal = HIGH;

// phase 1: have device sleep for 20s, then stay awake for 2 min
void lowPowerWakeTime() {
    unsigned long curMillis = millis();
    if (curMillis - prevMillis > WAKE_DURATION) {
        Serial.println("about to sleep");

        SystemSleepConfiguration config;
        config.mode(SystemSleepMode::ULTRA_LOW_POWER).duration(SLEEP_DURATION);
        System.sleep(config);

        Serial.println("waking up!");

        prevMillis = curMillis;
    }

}

//phase 2: a button will cause device to sleep, and button will cause device to wake
// for a button to WAKE device, you must connect button to pin D8 (is also WKP)
void lowPowerWakeButton() {
    //latch to put device to sleep
    currButtonVal = digitalRead(WKP);
    if (currButtonVal == HIGH && prevButtonVal == LOW) {
        Serial.println("sleep on button press");
        SystemSleepConfiguration config;
        config.mode(SystemSleepMode::ULTRA_LOW_POWER).gpio(WKP, FALLING); //wakeup argon on PRESS
        System.sleep(config);
        Serial.println("wake on button press");
    }

    prevButtonVal = currButtonVal;
}

void setup() {
    Serial.begin(9600);
    pinMode(WKP, INPUT);        //WKP is another label for pin D8
}

void loop() {
    lowPowerWakeTime();
    // lowPowerWakeButton();
}