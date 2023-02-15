
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

void loop() {
    brightnessLevel = analogRead(PIN_PHOTORESISTOR);

    if (brightnessLevel > 0 && brightnessLevel <= THRESHOLD_DARK) {
        Serial.println("dark");
        Particle.publish("Light quality", "dark");
        changeLedColor(0, 0, 0);
    } else if (brightnessLevel > THRESHOLD_DARK &&
               brightnessLevel <= THRESHOLD_AMBIENT) {
        Serial.println("ambient");
        Particle.publish("Light quality", "ambient");
        changeLedColor(255, 255, 0);
    } else {
        Serial.println("bright");
        Particle.publish("Light quality", "bright");
        changeLedColor(255,255,255);
    }

    //something important!
    //we have a free account with the particle cloud
    // we CAN  send one message per sec

    //whenever we use publish, we need to slow how often messages are sent
    delay(10000);
}
