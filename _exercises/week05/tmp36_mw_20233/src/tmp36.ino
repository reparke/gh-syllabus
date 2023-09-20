//set up millis timer for a 3 sec delay before publishing
unsigned long currMillis = 0;
unsigned long prevMillis = 0;
const unsigned long INTERVAL_PUBLISH = 3000;

const int PIN_TMP = A5;

void setup() {
    Serial.begin(9600);
    pinMode(PIN_TMP, INPUT);
}


// with analogRead, we get 0-4095
// we need voltage then wee need temperature
void loop() {
    int adcValue = analogRead(PIN_TMP);

    //convert ADC to voltage
    float voltage = adcValue * 3.3 / 4095;

    // float voltage = float (adcValue) / 4095 * 3.3;  // will this work?
    // float voltage = adcValue / 4095.0 * 3.3;  // will this work?

    //we could use map with the following caveat
    // map will convert int -> int and float -> float
    // 0.0 to 4095.0 --> 0.0 to 3.3

    // 0.5 v offset, 10 mV for 1 deg C
    float tempC = (voltage - 0.5) / 0.01;
    float tempF = tempC * (9.0 / 5) + 32;

    // Serial.println("TempC: " + String(tempC) + ", TempF: " + String(tempF,1));

    //what considerations should we make when sending data to Particle Cloud (Particle.publish() )?
    // we have limitations in the free tier -- 
    // we can't send more than 1 message per sec

    //get current time
    currMillis = millis();
    //check if timer has expired
    if (currMillis - prevMillis > INTERVAL_PUBLISH) {
        prevMillis = currMillis;

        Serial.println("TempC: " + String(tempC) +
                       ", TempF: " + String(tempF, 1));
        // the publish event name needs to match our webhook integration
        Particle.publish("week5_temp", String(tempF,2));        //only send two decimals
    }

}