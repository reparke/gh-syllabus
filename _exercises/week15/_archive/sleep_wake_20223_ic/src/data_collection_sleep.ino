const int PIN_BUTTON = D8;

void setup() {
    Serial.begin(9600);
    pinMode(PIN_BUTTON, INPUT);
}

void loop() {
    Serial.println("About to go to sleep");

    SystemSleepConfiguration config;  // object to set sleep modes
    config.mode(SystemSleepMode::ULTRA_LOW_POWER)
        .duration(20s).gpio(PIN_BUTTON, FALLING);  // will wake after 20s OR a button press
    System.sleep(config);

    Serial.println("We just woke");

    delay(120000);  // we adding this just for the in class demo so the device
                    // will be awake long enough to flash
}
