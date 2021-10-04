#include <blynk.h>  //library (need to import it in your own project)

char auth[] = "ENTER_YOUR_BLYNK_TOKEN";  // array of characters with your token

unsigned long blynkDelay = 1000;  // delay between sending ARGON to APP
unsigned long prevMillis = 0;

/* template for RECEIVING APP to ARGON */
/*
BLYNK_WRITE(V0) {

}
*/

void setup() {
    // 1. Require initial Blynk delay
    delay(5000);
    // 2. connect to blynk
    Blynk.begin(auth);
}

void loop() {
    Blynk.run();  // 3. start Blynk -- do NOT put in millis timer
    unsigned long currMillis = millis();
    if (currMillis - prevMillis > blynkDelay) {
        prevMillis = currMillis;

        /* template for SENDING ARGON to APP*/
        /*
            Blynk.virtualWrite(V0, 0);
        */
    }
}