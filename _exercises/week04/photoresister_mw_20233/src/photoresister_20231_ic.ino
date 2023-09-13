const int PIN_PHOTORESISTOR = A5;
const int PIN_RGB_RED = D2;
const int PIN_RGB_GREEN = D3;
const int PIN_RGB_BLUE = D4;

const int THRESHOLD_DARK = 1200;     // specific to rob's location
const int THRESHOLD_AMBIENT = 3200;  // unique to rob

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

void loop() {
    /*
        range of values for reading a photoresistor:
         0-4095 - ADC

         what is PR measuring?
            3000 -- meaningless BUT
             if we calibrate the device
             and then we look change in PR value,


    */

    int lightReading = analogRead(PIN_PHOTORESISTOR);
    float voltage = float(lightReading) * 3.3 / 4095;
    /**
     * 0-1200  = dark
     *      all blue
     * 1201-3200 = ambient
     * 3201-4095 = bright
     *
     */

    // part 2 : how do we use the lightreading to directly control
    //    the LED color
    // convert 0-4095 ADC  --> -0-255 PWM

    // if (lightReading >= 0 && lightReading <= THRESHOLD_DARK) {  // dark
    //     Serial.println("Dark");

    //     Particle.publish("lightReading", String(lightReading));
    //     Particle.publish("lightDescription", "Dark");
    //     // changeRgbColor(0,0,0);
    // } else if (lightReading > THRESHOLD_DARK &&
    //            lightReading <= THRESHOLD_AMBIENT) {  // ambient
    //     Serial.println("Ambient");

    //     Particle.publish("lightReading", String(lightReading));
    //     Particle.publish("lightDescription", "Ambient");
    //     // changeRgbColor(0, 0, 255);
    // } else {
    //     Serial.println("Bright");

    //     Particle.publish("lightReading", String(lightReading));
    //     Particle.publish("lightDescription", "Bright");
    //     // changeRgbColor(255,255, 255);
    // }

    // // map()   converts one input range of values to a new output range of
    // // values
    // // int pwmValue = map(lightReading, 0, 4095, 0, 255); //theoreticals
    // int pwmValue = map(lightReading, 500, 3600, 50, 255);  // reality

    // changeRgbColor(pwmValue, pwmValue, pwmValue);

    Serial.println(lightReading);
    // just for today, we are using a long delay
    delay(5000);
}