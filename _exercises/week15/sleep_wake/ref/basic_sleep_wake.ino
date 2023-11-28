
boolean shouldSleep = true;  // set to false, but gets inverted in setup()
void setup() {
    Serial.begin(9600);
    pinMode(WKP, INPUT);  // D8()
}
int prevButtonVal = HIGH;
int currButtonVal = HIGH;
void loop() {
    // use these two
    ulpAndWakeTime();
    // ulpAndWakeButtonPress();

    // stopAndWakeGpio();
    // ulpAndWakeGpio();
    // hibernateAndWakeGpio();
}

// use this one
void ulpAndWakeButtonPress() {
    currButtonVal = digitalRead(D8);

    if (prevButtonVal == HIGH && currButtonVal == LOW) {
        // if (shouldSleep == true) {
        Serial.println("About to ULTRA_LOW_POWER!");
        SystemSleepConfiguration config;
        config.mode(SystemSleepMode::ULTRA_LOW_POWER).gpio(WKP, FALLING);
        System.sleep(config);
        // }
        // if (shouldSleep == true) {
        //     Serial.println("shouldSleep is true so function paused");
        // }
        // // Serial.print("This should execute after ULTRA_LOW_POWER");
        // shouldSleep = false;
    }
    prevButtonVal = currButtonVal;
}

/* Stop, and Wake up on FALLING 0->1 on pin D8 (WKP)
  Connect button to pin D8 (WKP), use 10K pull up resistor
  No need to
*/
void stopAndWakeGpio() {
    if (shouldSleep == true) {
        Serial.println("About to sleep!");
        SystemSleepConfiguration config;
        config.mode(SystemSleepMode::STOP).gpio(WKP, FALLING);
        System.sleep(config);
    }
    if (shouldSleep == true) {
        Serial.println("shouldSleep is true so function paused");
    }
    shouldSleep = false;
}
/* Ultra Low Power, and Wake up on FALLING 0->1 on pin D8 (WKP)
  Connect button to pin D8 (WKP), use 10K pull up resistor
*/
void ulpAndWakeGpio() {
    if (shouldSleep == true) {
        Serial.println("About to ULTRA_LOW_POWER!");
        SystemSleepConfiguration config;
        config.mode(SystemSleepMode::ULTRA_LOW_POWER).gpio(WKP, FALLING);
        System.sleep(config);
    }
    if (shouldSleep == true) {
        Serial.println("shouldSleep is true so function paused");
    }
    // Serial.print("This should execute after ULTRA_LOW_POWER");
    shouldSleep = false;
}

/* Hibernate, and Wake up on FALLING 0->1 on pin D8 (WKP)
  Connect button to pin D8 (WKP), use 10K pull up resistor
  NOTE: This function doesn't work as configured because device is reset
    on wake, running setup() again
*/
void hibernateAndWakeGpio() {
    if (shouldSleep == true) {
        Serial.println("About to hibernate!");
        SystemSleepConfiguration config;
        config.mode(SystemSleepMode::HIBERNATE).gpio(WKP, FALLING);
        System.sleep(config);
    }
    if (shouldSleep == true) {
        Serial.println("shouldSleep is true so function paused");
    }
    // shouldSleep = false;
}

// use this one
/* Ultra Low Power, and Wake up one minute
 */
void ulpAndWakeTime() {
    int sleepTime = Time.now();
    // if (shouldSleep == true) {
    Serial.println("About to ULTRA_LOW_POWER! on time");
    SystemSleepConfiguration config;
    config.mode(SystemSleepMode::ULTRA_LOW_POWER).duration(30s);
    System.sleep(config);
    int diff = Time.now() - sleepTime;
    Serial.print("Time between sleep and wake: " + String(diff));
    // }
    // Serial.print("This should execute after ULTRA_LOW_POWER");
    // shouldSleep = false;
}