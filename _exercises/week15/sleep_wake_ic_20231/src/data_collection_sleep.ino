const int PIN_BUTTON = D3;  //smart watch button

void setup() {
    Serial.begin(9600);
    pinMode(PIN_BUTTON, INPUT); //button
    pinMode(D8, OUTPUT);


}
void loop() {
    Serial.println("About to go sleep....");

    // SystemSleepConfiguration config;
    // // config.mode(SystemSleepMode::ULTRA_LOW_POWER).duration(20s);
    // config.mode(SystemSleepMode::ULTRA_LOW_POWER).gpio(PIN_BUTTON, FALLING); //button press HIGH to LOW
    // System.sleep(config);
    // delay(10000);


}