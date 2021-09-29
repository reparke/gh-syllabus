#include <blynk.h>

#define BLYNK_TEMPLATE_ID "TMPLRSs66Yj0"
#define BLYNK_DEVICE_NAME "Week 6"
#define BLYNK_AUTH_TOKEN "W6fBjFZSrx5575a70HUfW5hDxNWyD7dV";

#define BLYNK_PRINT Serial
#define BLYNK_IP IPAddress(64, 225, 16, 22)  // https://ny3.blynk.cloud/ – New York
char auth[] = "W6fBjFZSrx5575a70HUfW5hDxNWyD7dV";

const int PIN_LED = D7;
const int PIN_RED = D3;
const int PIN_GREEN = D4;
const int PIN_BLUE = D5;
const int PIN_SWITCH = D2;

void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_SWITCH, INPUT);
    Serial.begin(9600);

    delay(5000);
    Blynk.begin(auth, BLYNK_IP);
}

void loop() { 
    Blynk.run(); 
}
