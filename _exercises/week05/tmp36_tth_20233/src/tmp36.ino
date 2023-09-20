const int PIN_TMP = A5;

// milllis timer variables
unsigned long currMillis = 0;
unsigned long prevMillis = 0;
const unsigned long INTERVAL_PUBLISH = 4000;

void setup() {
    Serial.begin(9600);
    pinMode(PIN_TMP, INPUT);
}

// with analogRead, we get 0-4095
// we need voltage then wee need temperature
void loop() {
    /*
        read ADC value
        covert ADC to voltage
        make sensor adjustment
        convert to fahr
    */

    int tmpValue = analogRead(PIN_TMP);       // 0-4095
    float voltage = tmpValue / 4095.0 * 3.3;  // 0-3.3v
    //    float voltage = float(tmpValue) / 4095 * 3.3;

    /*
        map() will convert int to int, or float to float
        float voltage = map(tmpValue, 0.0, 4095.0, 0.0, 3.3);
    */

    // 0.5 V offset, 10 mV per 1 deg C
    float tempC = (voltage - 0.5) / 0.01;  // temp in Cel
    // if missing tmp36
    // float tempC = random(20, 24);
    float tempF = tempC * (9.0 / 5) + 32;

    // Serial.println("Cel: " + String(tempC) + "; Fahr: " + String(tempF, 1));

    // Particle.publish() -- alwasys use a millis timer
    // publish limitations
    //  monthly quota -- don't sedn too much data
    //  only send strings
    //  1 publish / sec

    currMillis = millis();  // get current time
    if (currMillis - prevMillis > INTERVAL_PUBLISH) {
        prevMillis = currMillis;

        Serial.println("Cel: " + String(tempC) + "; Fahr: " + String(tempF, 1));
        // in publish, the first param EVENT_NAME is what is going to trigger a
        // webhook
        Particle.publish("week5_temp", String(tempC,1));
    }
}