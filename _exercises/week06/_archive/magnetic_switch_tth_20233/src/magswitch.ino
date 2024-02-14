/*Note: This corresponds to locally installed project "Week 6", tab "Demo"
  Features
    - Button to control onboard LED on V5 (app --> argon)
    - display for random number on V6 (argon --> app)
    - virtual LED represents random value on V6 (argon --> app)
*/

/*
    the process to code data FROM APP TO ARGON and FROM ARGON TO APP are
   different!

   The process for data FROM APP TO ARGON is a little different

   EVENT DRIVEN PROGRAMMING
        we write a function that we DONT CALL
        the argon will call the function FOR US when then event happens (for
   example a button is pressed)

*/

#define BLYNK_TEMPLATE_ID "TMPL2gt5c5Lp6"
#define BLYNK_TEMPLATE_NAME "Week 6 TTh"
#define BLYNK_AUTH_TOKEN "VP83B4uRuidrNNUlUCM4UJ7TqAdXPLaT"

#define BLYNK_PRINT Serial
#define BLYNK_IP IPAddress(64, 225, 16, 22)
#include <blynk.h>

const int PIN_LED = D7;
const int PIN_RED = D3;
const int PIN_GREEN = D4;
const int PIN_BLUE = D5;
const int PIN_SWITCH = D2;

int prevDoorState = HIGH;
int currDoorState = HIGH;

unsigned long prevMillis = 0;
unsigned long currMillis = 0;
const unsigned long INTERVAL_BLYNK = 1000;

void changeLedColor(int r, int g, int b) {
    // theoretical "recipe" or algorithm using these input
    analogWrite(PIN_RED, r);
    analogWrite(PIN_GREEN, g);
    analogWrite(PIN_BLUE, b);
}

// "event handler" for virtual button presses on V5
BLYNK_WRITE(V5) {
    // param is a special variable from Blynk which contains the data being from
    // Blynk
    int virtualButtonValue =
        param.asInt();  // convert the value sent from Blynk to be a int

    digitalWrite(PIN_LED, virtualButtonValue);
    Serial.println("Virtual button press: " + String(virtualButtonValue));\
}

void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_SWITCH, INPUT);
    Serial.begin(9600);

    delay(5000);
    Blynk.begin(BLYNK_AUTH_TOKEN, BLYNK_IP);
}

/*
    data FROM ARGON TO APP
        - it is important that we don't slow down Blynk.run()
        - we don't want to send too many messages to Blynk too fast
        ---> when sending messages in loop() to Blynk, we should use a millis
   timer
*/

void loop() {
    Blynk.run();  // this SHOULD NOT be in the millis timer

    currMillis = millis();
    if (currMillis - prevMillis > INTERVAL_BLYNK) {
        prevMillis = currMillis;

        // to send data from argon to app, we use Blynk.virtualWrite
        int randNum = random(0, 256);
        Blynk.virtualWrite(V6, randNum);  // send randNum on virtual pin v6
        Serial.println("Random num: " + String(randNum));
    }

    // currDoorState = digitalRead(PIN_SWITCH);
    // // Serial.println(currDoorState);
    // if (currDoorState == LOW && prevDoorState == HIGH) {
    //     Serial.println("Door was closed");
    //     Particle.publish("Door state", "Door was closed");
    //     changeLedColor(255, 0, 0);
    // } else if (currDoorState == HIGH && prevDoorState == LOW) {
    //     Serial.println("Door was opened");
    //     Particle.publish("Door State", "Door was opened");
    //     changeLedColor(255, 255, 255);
    // }
    // prevDoorState = currDoorState;
}
