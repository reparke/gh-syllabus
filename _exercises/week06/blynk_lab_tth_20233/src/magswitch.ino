/*
    1) Use ZeRGBa to control RGB LED on pins V0 V1 V2 (app –> argon)
    2) Use a display to show if magnetic switch is open or closed on pin V3
   (argon –> app)

   3) Use a button on V4 to trigger the RGB LED to display a color randomly
   chosen from white, yellow, magenta, red (app –> argon)
   4 When one of the four
   random colors is displayed on the RGB LED, send a string representing that
   color to the app on pin V7 (argon –> app)


*/

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


#include "Particle.h"
SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_WARN);

#define BLYNK_TEMPLATE_ID "TMPL8pRjLGSG"
#define BLYNK_TEMPLATE_NAME "Week 6 Lab"
#define BLYNK_AUTH_TOKEN "CXGdYkgREo9JvRwFIZ4d8y9WCZ83Zr2b"

#include <blynk.h>  //library (need to import it in your own project)

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
    Blynk.begin(BLYNK_AUTH_TOKEN);
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