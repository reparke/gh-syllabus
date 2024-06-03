#define BLYNK_TEMPLATE_ID "TMPL8pRjLGSG"
#define BLYNK_TEMPLATE_NAME "Week 6 Lab"
#define BLYNK_AUTH_TOKEN "CXGdYkgREo9JvRwFIZ4d8y9WCZ83Zr2b"

// #define BLYNK_TEMPLATE_ID "TMPL21_bpJDKa"
// #define BLYNK_TEMPLATE_NAME "Week 6"
// #define BLYNK_AUTH_TOKEN "Glbz5sDT1gaudxya5-c_OL6kZR0JMQTV"


#include <blynk.h>

const int PIN_LED = D7;
const int PIN_RED = A2;
const int PIN_GREEN = A5;
const int PIN_BLUE = D15; // aka MOSI pin
const int PIN_SWITCH = D2;

/* blynk needs a constant stable connection to work between app and argon
    Blynk also gets angry if we update too fast

    WHEN we want to send message FROM ARGON TO APP, if we are doing in LOOP, we
   need a millis timer
*/
unsigned long blynkUpdateInterval = 1000;
unsigned long prevBlynkMillis = 0;

/*
    EVENT-DRIVEN PROGRAMMING

     DATA FROM APP TO ARGON
     we write a function, and the ARGON calls the function FOR US
     so we NEVER CALL THIS FUNCTION
*/
BLYNK_WRITE(V5) {
    int buttonVal = param.asInt();  // this is virtual pin V5  which a button

    digitalWrite(D7, buttonVal);
}

void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_SWITCH, INPUT);
    Serial.begin(9600);

    delay(5000);
    Blynk.begin(BLYNK_AUTH_TOKEN);  // initial setup
}

void loop() {
    Blynk.run();  // refreshes Blynk app every constantly
    // Blynk.run DOES NOT GO IN A MILLIS TIMER

    // however, we put message from ARGON TO APP within millis timer
    unsigned long curMillis = millis();
    if (curMillis - prevBlynkMillis > blynkUpdateInterval) {
        // here is where we sent data to blynk

        // FROM ARGON TO APP
        Blynk.virtualWrite(V6, random(0, 256));
        prevBlynkMillis = curMillis;
    }
}