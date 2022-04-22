
boolean shouldSleep = true;  // set to false, but gets inverted in setup()
int count = 0;
const int MAX_SIZE = 2;
int data[MAX_SIZE];

SYSTEM_MODE(SEMI_AUTOMATIC);    //when argon turns on, it does NOT connect to cloud (no wifi)

void setup() {
    Serial.begin(9600);
    pinMode(WKP, INPUT);  // not strictly necessary
}

void loop() { dataCollection(); }

void dataCollection() {
    if (count < MAX_SIZE) {
        data[count] = random(60, 120);
        Serial.println(String(count) + ": " + String(data[count]));
        count += 1;
    }
    if (count == MAX_SIZE) {
        Particle.connect();
        String msg = "";
        for (int i = 0; i < MAX_SIZE; i++) {
            msg += String(data[i]) + ",";
        }
        Particle.publish(msg);
        Serial.println(msg);
        count = 0;
    }
    Serial.println("About to ULTRA_LOW_POWER! on time");
    SystemSleepConfiguration config;
    config.mode(SystemSleepMode::ULTRA_LOW_POWER).duration(10s);
    System.sleep(config);
}
