void setup() {
    Serial.begin(9600);
    pinMode(D8, OUTPUT);
}

void loop() {

    ulpWakeOnTime();
    delay(120000);

}

// go into ultra low power, and wake after a certain lenght of time
void ulpWakeOnTime() {
    Serial.println("About to go to sleep");
    SystemSleepConfiguration config;
    config.mode(SystemSleepMode::ULTRA_LOW_POWER).duration(20s);    //go to ULP and wake in 20s
    System.sleep(config);
    Serial.println("Just woke up!");
}

// go into ultra low power, and wake after a certain lenght of time
void ulpWakeOnTimeOrButton() {
    Serial.println("About to go to sleep");
    SystemSleepConfiguration config;
    config.mode(SystemSleepMode::ULTRA_LOW_POWER).duration(20s).gpio(D8, FALLING);  
    System.sleep(config);
    Serial.println("Just woke up!");
}