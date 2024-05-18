/*
    This function will put the device to sleep for 30 s
*/

unsigned long prevMillis = 0;
unsigned long WAKE_DURATION = 120000;  // 2 min

/* to wake device with button, we need to use the WKP pin (this is actually D8)

    we need a latch
*/
const int PIN_BUTTON = D8;
int prevButtonVal = HIGH;
int currButtonVal = HIGH;

void lowPowerWakeButton() {
    currButtonVal = digitalRead(PIN_BUTTON);
    if (currButtonVal == LOW && prevButtonVal == HIGH) {
        Serial.println("About to go to low power");
        SystemSleepConfiguration config;
        config.mode(SystemSleepMode::ULTRA_LOW_POWER).gpio(WKP, FALLING);
        System.sleep(config);
        Serial.println("Waking up!");
    }
    // this means we should sleep
    prevButtonVal = currButtonVal;
}

void lowPowerWakeTime() {
    Serial.println("About to go to sleep");
    SystemSleepConfiguration config;
    config.mode(SystemSleepMode::ULTRA_LOW_POWER)
        .duration(30s);  // go to low power mode, and wake up after 30s
    System.sleep(config);
    Serial.println("Just woke up!");
}

void setup() {
    Serial.begin(9600);
    // set up WKP pin as input
    pinMode(WKP, INPUT);
}

void loop() {
    // unsigned long curMillis = millis();
    // if (curMillis - prevMillis > WAKE_DURATION) {
    //     lowPowerWakeTime();
    //     prevMillis = curMillis;
    // }
    lowPowerWakeButton();
}