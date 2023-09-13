#include "rgb-controls.h"
using namespace RGBControls;

Led led(D2, D3, D4);        //R G B pins of our RGB LED
Color red(255, 0, 0);
Color blue(0, 0, 255);


const int PIN_PHOTORESISTOR = A5;
const int PIN_RGB_RED = D2;
const int PIN_RGB_GREEN = D3;
const int PIN_RGB_BLUE = D4;

int brightnessLevel = 0;

// constants for your thresholds
const int THRESHOLD_DARK = 1200;
const int THRESHOLD_AMBIENT = 2500;

// FUNCTIONS
// input and output to function
// Step 1: define your function (outside of loop or setup)
// step 2: use / call your function (inside of loop or setup)
// input idea: string like red,
//              int r, g, b
// input: int values for the red, the green, and the blue LED values
// return:  none ()
void changeLedColor(int r, int g, int b) {
    // theoretical "recipe" or algorithm using these input
    analogWrite(PIN_RGB_RED, r);
    analogWrite(PIN_RGB_GREEN, g);
    analogWrite(PIN_RGB_BLUE, b);
}

void setup() {
    Serial.begin(9600);
    pinMode(PIN_PHOTORESISTOR, INPUT);
    pinMode(PIN_RGB_RED, OUTPUT);
    pinMode(PIN_RGB_GREEN, OUTPUT);
    pinMode(PIN_RGB_BLUE, OUTPUT);
}

/*
    convert 0-4095 ADC value to a 0-255 PWM
    map()
    input --> new scale
*/

void loop() {
    // led.fade(red, blue, 1000);



    //    brightnessLevel = analogRead(PIN_PHOTORESISTOR); //0-4095
    // float voltage = float(brightnessLevel) * 3.3 / 4095;

    // part 1
    // if (brightnessLevel > 0 && brightnessLevel <= THRESHOLD_DARK) {
    //     Serial.println("dark");
    //     changeLedColor(0, 0, 0);
    // } else if (brightnessLevel > THRESHOLD_DARK &&
    //            brightnessLevel <= THRESHOLD_AMBIENT) {
    //     Serial.println("ambient");
    //     changeLedColor(255, 255, 0);
    // } else {
    //     Serial.println("bright");
    //     changeLedColor(255, 255, 255);
    // }

    // Serial.println(brightnessLevel);
    // // part 2
    // int pwmValue = map(brightnessLevel, 100, 900, 0, 255);
    // changeLedColor(pwmValue, 0, pwmValue);

    // part 3
    
    if (brightnessLevel > 0 && brightnessLevel <= THRESHOLD_DARK) {
        Serial.println("dark");
        int pwmValue = map(brightnessLevel, 100, 900, 0, 255);
        changeLedColor(pwmValue, 0, pwmValue);
        
        Particle.publish("Light Status", "Dark");
        Particle.publish("Light Value", String(brightnessLevel));
    } else if (brightnessLevel > THRESHOLD_DARK &&
               brightnessLevel <= THRESHOLD_AMBIENT) {
        Serial.println("ambient");
        int pwmValue = map(brightnessLevel, 100, 900, 0, 255);
        changeLedColor(pwmValue, 0, pwmValue);

        Particle.publish("Light Status", "Ambient");
        Particle.publish("Light Value", String(brightnessLevel));
    } else {
        Serial.println("bright");
        int pwmValue = map(brightnessLevel, 100, 900, 0, 255);
        changeLedColor(pwmValue, 0, pwmValue);

        Particle.publish("Light Status", "Bright");
        Particle.publish("Light Value", String(brightnessLevel));
    }

    delay(10000); // set a long delay for particle messages
    
}
