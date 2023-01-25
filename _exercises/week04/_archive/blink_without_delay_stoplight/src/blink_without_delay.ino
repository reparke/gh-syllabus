// //referencing:
// https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all


unsigned long prevMillis = 0;  // last time we checked time
int ledState = LOW;            // initial state
unsigned long interval1 = 1000;

const int WHITE_LED_PIN = D2;
const int RED_LED_PIN = D3;
const int SPEAKER_PIN = D4;

void setup() {
  pinMode(WHITE_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);


}

// /* ================================================= */


// // V1 - single light blinking
// void loop() {
//   unsigned long curMillis = millis();  // current time
//   // check if (now - previous) is more than our interval
//   if (curMillis - prevMillis >= interval1) {
//     prevMillis = curMillis;  // if YES, update previous
//     if (ledState == LOW) {   // if LED ON, now it is OFF
//       ledState = HIGH;
//     } else {  // if LED ON, now it is OFF
//       ledState = LOW;
//     }
//     digitalWrite(WHITE_LED_PIN, ledState);
//   }
// }

// /* ================================================= */

// unsigned long interval2 = 350;

// V2 - one light with different on / off times
// void loop() {
//   // check to see if it's time to change the state of the LED
//   unsigned long curMillis = millis();

//   if ((ledState == HIGH) && (curMillis - prevMillis >= interval1)) {
//     ledState = LOW;                         // Turn it off
//     prevMillis = curMillis;                 // Remember the time
//     digitalWrite(WHITE_LED_PIN, ledState);  // Update the actual LED
//   } else if ((ledState == LOW) && (curMillis - prevMillis >= interval1 / 2)) {
//     ledState = HIGH;                        // turn it on
//     prevMillis = curMillis;                 // Remember the time
//     digitalWrite(WHITE_LED_PIN, ledState);  // Update the actualLED
//   }
// }
// /* ================================================= */

// unsigned long interval2 = 350;

// V3 two lights each eith different delays
void loop() {
}




// /* =================== Leave this part unchanged
// ============================== */

// /* ================== versions are below =============================== */

// // // V1 - simple delay - build this, and then ask how to get the second
// LED to
// // blink at 350ms
// // //clearly this approach isn't going to work
// // void loop() {
// //   digitalWrite(WALK_PIN, HIGH);
// //   delay(invervalWalkOn);
// //   digitalWrite(WALK_PIN, LOW);
// //   delay(invervalWalkOff);

// //   //added after
// //   digitalWrite(DONT_WALK_PIN, HIGH);
// //   delay(interviewDontWalkOn);
// //   digitalWrite(DONT_WALK_PIN, LOW);
// //   delay(interviewDontWalkOff);
// // }



// /* ================================================= */

// //v4 - set different on / off times
// /*
//   Diagram:
//     if walkstate = LOW AND time off is over
//       walkState = HIGH; update time, turn on LED
//     if walkState = HIGH AND time on is over
//       walkState = LOW; update time, turn off LED

// */
// //notice the change here
// // unsigned long previousMillis = 0;
// unsigned long previousMillisWalk = 0;
// unsigned long previousMillisDontWalk = 0;
// int walkLedState = LOW;
// int dontWalkLedState = LOW;
// void loop()
// {
//   // check to see if it's time to change the state of the LED
//   unsigned long currentMillis = millis();

//   if((walkLedState == HIGH) && (currentMillis - previousMillisWalk >=
//   intervalWalkOn))
//   {
//     walkLedState = LOW;  // Turn it off
//     previousMillisWalk = currentMillis;  // Remember the time
//     digitalWrite(WALK_PIN, walkLedState);  // Update the actual LED
//   }
//   else if ((walkLedState == LOW) && (currentMillis - previousMillisWalk >=
//   intervalWalkOff))
//   {
//     walkLedState = HIGH;  // turn it on
//     previousMillisWalk = currentMillis;   // Remember the time
//     digitalWrite(WALK_PIN, walkLedState);	  // Update the actual LED
//   }
//   if((dontWalkLedState == HIGH) && (currentMillis - previousMillisDontWalk
//   >= intervalDontWalkOn))
//   {
//     dontWalkLedState = LOW;  // Turn it off
//     previousMillisDontWalk = currentMillis;  // Remember the time
//     digitalWrite(DONT_WALK_PIN, dontWalkLedState);  // Update the actual
//     LED
//   }
//   else if ((dontWalkLedState == LOW) && (currentMillis -
//   previousMillisDontWalk >= intervalDontWalkOff))
//   {
//     dontWalkLedState = HIGH;  // turn it on
//     previousMillisDontWalk = currentMillis;   // Remember the time
//     digitalWrite(DONT_WALK_PIN, dontWalkLedState);	  // Update the actual
//     LED
//   }
// }