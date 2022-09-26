const int PIN_TMP = A5;

const unsigned long INTERVAL_PUBLISH = 10000;
unsigned long prevMillis = 0;

void setup() {
    Serial.begin(9600);
    pinMode(PIN_TMP, INPUT);
}

void loop() {
    int adcVal = analogRead(PIN_TMP);

    float voltage = adcVal * 3.3 / 4095;  // ensures that we get a float

    // 0.5 volt offset, and 10 mV / C is the slope
    float tempC = (voltage - 0.5) / 0.01;  // voltage / 10mv

    float tempF = tempC * (9.0 / 5) + 32;

    Serial.println("The temp in Fahrenheit is " + String(tempF));

    unsigned long currMillis = millis();
    if (currMillis - prevMillis > INTERVAL_PUBLISH) {
        //              EVENT, DATA
        Particle.publish("tempF", String(tempF));

        //want to see another value
        int humidity = random(40, 70);  // for demonstration
        Particle.publish("humidity", String(humidity));
        prevMillis = currMillis;
    }
}

// read temp  ---> use serial monitor
// publish temperature to particle
// particle send temp to initial state via webhook
