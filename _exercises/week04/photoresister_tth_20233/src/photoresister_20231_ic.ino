
const int PIN_RGB_RED = D2;
const int PIN_RGB_GREEN = D3;
const int PIN_RGB_BLUE = D4;
const int PIN_PHOTORESISTOR = A5;

const int THRESHOLD_DARK = 2000;  // dark will be 0-2000
const int THRESHOLD_AMBIENT = 3200;

void changeRgbColor(int r, int g, int b) {
    analogWrite(PIN_RGB_RED, r);
    analogWrite(PIN_RGB_GREEN, g);
    analogWrite(PIN_RGB_BLUE, b);
}

void setup() {
    Serial.begin(9600);
    pinMode(PIN_RGB_RED, OUTPUT);
    pinMode(PIN_RGB_GREEN, OUTPUT);
    pinMode(PIN_RGB_BLUE, OUTPUT);
    pinMode(PIN_PHOTORESISTOR, INPUT);
}

//part 1
// void loop() {
//     // photoresistor is analog input... ADC 0-4095
//     int photoReading = analogRead(PIN_PHOTORESISTOR);

//     /*
//     if we get a reading of 3000, what does that mean? --> is meaningless
//         PR is measuring relative change of light levels
//         however, if we calibrate the PR and we check for changes, then we can
//                 make sense of a reading

//     */
//     if (photoReading >= 0 && photoReading < THRESHOLD_DARK) {
//         Serial.println("Dark " + String(photoReading));
//         changeRgbColor(0, 0, 0);
//     } else if (photoReading >= THRESHOLD_DARK &&
//                photoReading < THRESHOLD_AMBIENT) {
//         Serial.println("Ambient " + String(photoReading));
//         changeRgbColor(0, 0, 255);
//     } else {
//         Serial.println("Bright " + String(photoReading));
//         changeRgbColor(255, 255, 255);
//     }
//     // Serial.println("PR = " + String(photoReading));
//     delay(200);
// }

// part 2
void loop() {
    // photoresistor is analog input... ADC 0-4095
    int photoReading = analogRead(PIN_PHOTORESISTOR);

    /*
    if we get a reading of 3000, what does that mean? --> is meaningless
        PR is measuring relative change of light levels
        however, if we calibrate the PR and we check for changes, then we can
                make sense of a reading

    */
   //map the ADC light levels (0-4095) to PWM values (0-255)
    /*
        OUTPUT_VALUE =
                    map(INPUT_VALUE,
                        INPUT_RANGE_MIN,
                        INPUT_RANGE_MAX,
                        OUTPUT_RANGE_MIN,
                        OUTPUT_RANGE_MAX)
    */
    int pwmValue = map(photoReading, 0, 4095, 0, 255);
    changeRgbColor(pwmValue, 0, pwmValue); // choosing "magenta" and adjust brightness

    if (photoReading >= 0 && photoReading < THRESHOLD_DARK) {
        Serial.println("Dark " + String(photoReading));

        // Particle.publish("lightLevel", "dark");
        // Particle.publish("lightReading", String(photoReading));
        // changeRgbColor(0, 0, 0);
    } else if (photoReading >= THRESHOLD_DARK &&
               photoReading < THRESHOLD_AMBIENT) {
        Serial.println("Ambient " + String(photoReading));

        // Particle.publish("lightLevel", "ambient");
        // Particle.publish("lightReading", String(photoReading));
        // changeRgbColor(0, 0, 255);
    } else {
        Serial.println("Bright " + String(photoReading));

        // Particle.publish("lightLevel", "bright");
        // Particle.publish("lightReading", String(photoReading));
        // changeRgbColor(255, 255, 255);
    }
    // Serial.println("PR = " + String(photoReading));
    delay(5000);
}