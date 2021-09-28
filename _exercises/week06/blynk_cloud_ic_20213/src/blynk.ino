// 1. include blynk
#include <blynk.h>

// virtual pins
// V5 is push button (app --> argon)
// V6 is the display and LED (argon --> app)
const int PIN_LED = D7;
const int PIN_RED = D3;
const int PIN_GREEN = D4;
const int PIN_BLUE = D5;
const int PIN_SWITCH = D2;

unsigned long blynkDelay = 1000;    //enforce that we dont send data too fast
unsigned long prevMillis = 0;

BLYNK_WRITE(V0) {  // RED
    // event handler for when the user moves the sliders on the app
    // we have a slider that send an integer value from 0-255
    // lets read the value on the slider
    int sliderValue = param.asInt();  // represents slider value
    analogWrite(PIN_RED, sliderValue);
    Serial.println("Red: " + String(sliderValue));
}
BLYNK_WRITE(V1) {  // RED
    // event handler for when the user moves the sliders on the app
    // we have a slider that send an integer value from 0-255
    // lets read the value on the slider
    int sliderValue = param.asInt();  // represents slider value
    analogWrite(PIN_GREEN, sliderValue);
    Serial.println("Red: " + String(sliderValue));
}
BLYNK_WRITE(V2) {  // RED
    // event handler for when the user moves the sliders on the app
    // we have a slider that send an integer value from 0-255
    // lets read the value on the slider
    int sliderValue = param.asInt();  // represents slider value
    analogWrite(PIN_BLUE, sliderValue);
    Serial.println("Red: " + String(sliderValue));
}
//above setup
//send data FROM APP TO ARGON
BLYNK_WRITE(V5) {                   //button
    //receive and store button
    //use button val to control on board LED
    int buttonValue = param.asInt();        //0 is low, 1 is high
    digitalWrite(PIN_LED, buttonValue);
    Serial.println("Button press: " + String(buttonValue));
}

void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_SWITCH, INPUT);
    Serial.begin(9600);

    // 2. have a 5 sec delay to allow Argon to finish settling
    delay(5000);
    // 3. setup blynk
    Blynk.begin("_Ce745Lvb6anFEDvGggMSYvZCwIF8b6i");

    // //this is just for a local Blynk - Rob only
    // Blynk.begin("_Ce745Lvb6anFEDvGggMSYvZCwIF8b6i", IPAddress(192, 168, 0, 131),
    //             8080);
}

void loop() {
    // 4. start Blynk
    Blynk.run();

    //do NOT put blynk.run() within millis
    unsigned long curMillis = millis();
    if (curMillis-prevMillis > blynkDelay) {
        //send data FROM ARGON TO APP
        int randNum = random(0, 256);   //PWM is 0-255
        Blynk.virtualWrite(V6, randNum);
        Serial.println("Random #: " + String(randNum));

        prevMillis = curMillis;
    }
}