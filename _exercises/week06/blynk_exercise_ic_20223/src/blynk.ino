/*
    - install blynk library
    - paste #define
*/
#define BLYNK_TEMPLATE_ID "TMPLRSs66Yj0"
#define BLYNK_DEVICE_NAME "Week 6"
#define BLYNK_AUTH_TOKEN "W6fBjFZSrx5575a70HUfW5hDxNWyD7dV"

//where did this come from? looking examples and documentation
#include <blynk.h>
#define BLYNK_PRINT Serial
#define BLYNK_IP IPAddress(64, 225, 16, 22) //use this number exactly

//blynk timer
unsigned long intervalBlynk = 10000;
unsigned long prevBlynkMillis = 0;

const int PIN_LED = D7;

void setup() {
    pinMode(PIN_LED, OUTPUT);
    Serial.begin(9600);

    //configure blynk
    Blynk.begin(BLYNK_AUTH_TOKEN, BLYNK_IP);
}

void loop() {
    /* be careful
    We can't send data to blynk too fast
    AND
    we can't use delay
    */
    Blynk.run();
    unsigned long currMillis = millis();
    if (currMillis - prevBlynkMillis > intervalBlynk) {
        //send a rand number FROM argon TO blynk
        int randonNum = random(0, 256);
        // Blynk.virtualWrite(V0, randonNum); // for you
        Blynk.virtualWrite(V6, randonNum);
        prevBlynkMillis = currMillis;
    }
}