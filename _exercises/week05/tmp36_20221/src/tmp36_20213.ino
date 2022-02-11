
const int PIN_TMP = A5;

const int PIN_ARRAY[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
const int DIE_ARR_VAL1[] = {0, 0, 0, 0, 1, 0, 0, 0, 0};

const int rollVariation[6][9] = {{1}, {1}, {1}, {1}, {1}, {1}};

void setup() {
    Serial.begin(9600);
    pinMode(PIN_TMP, INPUT);
}

void loop() {
    int val = analogRead(PIN_TMP);  // 4095 ADC
    float voltage = (float)val / 4095 * 3.3;
    // Voltage - 0.5)/0.01
    float tempC = (voltage - 0.5) / 0.01;
    float tempF = tempC * (9.0 / 5) + 32;
    Serial.println("TempF" + String(tempF) + "Temp C" + String(tempC));

    //change the number of decimals
    //publish syntax: eventName, eventData
    Particle.publish("temperature", String(tempF, 1) );
    delay(5000);
}