const int PIN_PIR = D2;
const int PIN_LED = D7;

const int PIN_PIR_A = A0;
unsigned long lastPrint = 0;

void setup() {
    // Serial.begin(9600);
    Serial.begin(115200);     // faster serial rate to see analog outputs
    pinMode(PIN_PIR, INPUT);  // digital if using OUT pin
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_PIR_A, INPUT);
}

void printAnalogValue() {
    if ((lastPrint + 100) < millis()) {
        lastPrint = millis();
        // Read in analog value:
        unsigned int analogPIR = analogRead(PIN_PIR_A);
        // Convert 10-bit analog value to a voltage
        // (Assume high voltage is 5.0V.)
        float voltage = (float)analogPIR / 4096.0 * 3.3;
        // Print the reading from the digital pin.
        // Mutliply by 5 to maintain scale with AOUT.
        Serial.print(3.3 * digitalRead(PIN_PIR));
        Serial.print(',');      // Print a comma
        Serial.print(2.5);      // Print the upper limit
        Serial.print(',');      // Print a comma
        Serial.print(1.7);      // Print the lower limit
        Serial.print(',');      // Print a comma
        Serial.print(voltage);  // Print voltage
        Serial.println();
    }
}
// latch version
int prevAlarm = LOW;
void loop() {
    // to detect movement, we do a reading on the sensor
    int alarm = digitalRead(PIN_PIR);

    if (alarm == HIGH && prevAlarm == LOW) {
        Serial.println("Movement detected");
        digitalWrite(PIN_LED, HIGH);
    } else if (alarm == LOW && prevAlarm == HIGH) {
        Serial.println("Movement stopped");
        digitalWrite(PIN_LED, LOW);
    }
    prevAlarm = alarm;
}



// void loop(){
//     //to detect movement, we do a reading on the sensor
//     int alarm = digitalRead(PIN_PIR);

//     if (alarm == HIGH) {
//         Serial.println("Movement detected");
//         digitalWrite(PIN_LED, HIGH);
//     }
//     else {
//         Serial.println("Movement stopped");
//         digitalWrite(PIN_LED, LOW);
//     }

// }