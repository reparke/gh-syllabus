const int PIN_TMP = A5;
// use millis
unsigned long prevMillisPublish = 0;  // time of last publish
const unsigned long PUBLISH_INTERVAL = 10000;

void setup() {
    Serial.begin(9600);
    pinMode(PIN_TMP, INPUT);
}

void loop() {
    int adcVal = analogRead(PIN_TMP);

    float voltage = adcVal * 3.3 / 4095;  // ensures that we get a float

    // 0.5 volt offset, and 10 mV / C is the slope
    float tempC = (voltage - 0.5) / 0.01;  // voltage / 10mv

    /* Generate a random temperature just for testing purposes */
    tempC = random(21, 32);  // uncomment to generate random Celsius temp

    float tempF = tempC * (9.0 / 5) + 32;


    unsigned long currMillis = millis();
    if (currMillis - prevMillisPublish > PUBLISH_INTERVAL) {
        // publish
        // publish(EVENT_NAME, EVENT_VALUE)
        tempC = random(21, 32);
        Serial.println("The temp in Celsius is " + String(tempC));

        Particle.publish("week5", String(tempC));

        prevMillisPublish = currMillis;
        // always need to update prevMillis INSIDE THIS IF
    }
}