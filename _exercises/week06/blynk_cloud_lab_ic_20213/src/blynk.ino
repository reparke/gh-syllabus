#include <blynk.h>

#define BLYNK_TEMPLATE_ID "TMPLRSs66Yj0"
#define BLYNK_DEVICE_NAME "Week 6"
#define BLYNK_AUTH_TOKEN "W6fBjFZSrx5575a70HUfW5hDxNWyD7dV";

#define BLYNK_PRINT Serial
#define BLYNK_IP \
    IPAddress(64, 225, 16, 22)  // https://ny3.blynk.cloud/ – New York
char auth[] = "W6fBjFZSrx5575a70HUfW5hDxNWyD7dV";

const int PIN_LED = D7;
const int PIN_RED = D3;
const int PIN_GREEN = D4;
const int PIN_BLUE = D5;
const int PIN_SWITCH = D2;

unsigned long prevMillis = 0;
unsigned long blynkInterval = 1000;  // 1 sec delay--the minimum Blynk
                                     // recommends

// create the function (event handler) that will be triggered when the
// APP wants to send data FROM APP to ARGON
BLYNK_WRITE(V5) {
    // this function will get called when v5 has new data
    // the app will also send data so we should retrieve it
    int buttonVal = param.asInt();

    // at this point....pretend that buttonVal represents a physical button
    // on your argon
    digitalWrite(PIN_LED, buttonVal);
}

void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_SWITCH, INPUT);
    Serial.begin(9600);

    delay(5000);  // Blynk recommendation
    Blynk.begin(auth, BLYNK_IP);
}

// we DO NOT USE DELAY in the loop
// you definitely have to use MILLIS
void loop() {
    Blynk.run();

    unsigned long currMillis = millis();
    if (currMillis - prevMillis >
        blynkInterval) {  // we are sending data FROM ARGON to APP
        prevMillis = currMillis;
        int randNum = random(0, 256);  // generate random num 0-255

        // to send data from ARGON to APP
        // Blynk.virtualWrite(PIN, data)
        Blynk.virtualWrite(V6, randNum);
    }
}