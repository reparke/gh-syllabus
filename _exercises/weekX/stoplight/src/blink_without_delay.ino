//referencing: https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all



/* =================== Leave this part unchanged ============================== */

const int WALK_PIN = D2;
const int DONT_WALK_PIN = D3;
const int intervalWalkOn = 1000;
const int intervalWalkOff = 100;
const int intervalDontWalkOn = 350;
const int intervalDontWalkOff = 35;



void setup() {
  pinMode(WALK_PIN, OUTPUT);
  pinMode(DONT_WALK_PIN, OUTPUT);
}

/* ================== versions are below =============================== */


// // V1 - simple delay - build this, and then ask how to get the second LED to
// blink at 350ms
// //clearly this approach isn't going to work
// void loop() {
//   digitalWrite(WALK_PIN, HIGH);
//   delay(invervalWalkOn);
//   digitalWrite(WALK_PIN, LOW);
//   delay(invervalWalkOff);

//   //added after
//   digitalWrite(DONT_WALK_PIN, HIGH);
//   delay(interviewDontWalkOn);
//   digitalWrite(DONT_WALK_PIN, LOW);
//   delay(interviewDontWalkOff);
// }

/* ================================================= */

// v2 - ignore second LED for the moment and just consider one light with different times -- include this code on slides
// unsigned long previousMillis = 0;
// int walkLedState = LOW;
// void loop() {
//   unsigned long currentMillis = millis();                 //current time
//   if (currentMillis - previousMillis >= intervalWalkOn) {   //check if (now - previous) is more than our interval
//     previousMillis = currentMillis;                       //if YES, update previous
//     if (walkLedState == LOW) {                            //switch state
//       walkLedState = HIGH;                                
//     } else {
//       walkLedState = LOW;
//     }
//     digitalWrite(WALK_PIN, walkLedState);
//   }
// }
/* ================================================= */


// //v3 - set different on / off times
// /*
//   Diagram:
// if walkstate = LOW AND time off is over
//   walkState = HIGH; update time, turn on LED
// if walkState = HIGH AND time on is over
//   walkState = LOW; update time, turn off LED

// */
// unsigned long previousMillis = 0;
// int walkLedState = LOW;
// void loop()
// {
//   // check to see if it's time to change the state of the LED
//   unsigned long currentMillis = millis();
 
//   if((walkLedState == HIGH) && (currentMillis - previousMillis >= intervalWalkOn))
//   {
//     walkLedState = LOW;  // Turn it off
//     previousMillis = currentMillis;  // Remember the time
//     digitalWrite(WALK_PIN, walkLedState);  // Update the actual LED
//   }
//   else if ((walkLedState == LOW) && (currentMillis - previousMillis >= intervalWalkOff))
//   {
//     walkLedState = HIGH;  // turn it on
//     previousMillis = currentMillis;   // Remember the time
//     digitalWrite(WALK_PIN, walkLedState);	  // Update the actual LED
//   }
// }

/* ================================================= */


//v4 - set different on / off times
/*
  Diagram:
    if walkstate = LOW AND time off is over
      walkState = HIGH; update time, turn on LED
    if walkState = HIGH AND time on is over
      walkState = LOW; update time, turn off LED

*/
//notice the change here
// unsigned long previousMillis = 0;
unsigned long previousMillisWalk = 0;
unsigned long previousMillisDontWalk = 0;
int walkLedState = LOW;
int dontWalkLedState = LOW;
void loop()
{
  // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();
 
  if((walkLedState == HIGH) && (currentMillis - previousMillisWalk >= intervalWalkOn))
  {
    walkLedState = LOW;  // Turn it off
    previousMillisWalk = currentMillis;  // Remember the time
    digitalWrite(WALK_PIN, walkLedState);  // Update the actual LED
  }
  else if ((walkLedState == LOW) && (currentMillis - previousMillisWalk >= intervalWalkOff))
  {
    walkLedState = HIGH;  // turn it on
    previousMillisWalk = currentMillis;   // Remember the time
    digitalWrite(WALK_PIN, walkLedState);	  // Update the actual LED
  }
  if((dontWalkLedState == HIGH) && (currentMillis - previousMillisDontWalk >= intervalDontWalkOn))
  {
    dontWalkLedState = LOW;  // Turn it off
    previousMillisDontWalk = currentMillis;  // Remember the time
    digitalWrite(DONT_WALK_PIN, dontWalkLedState);  // Update the actual LED
  }
  else if ((dontWalkLedState == LOW) && (currentMillis - previousMillisDontWalk >= intervalDontWalkOff))
  {
    dontWalkLedState = HIGH;  // turn it on
    previousMillisDontWalk = currentMillis;   // Remember the time
    digitalWrite(DONT_WALK_PIN, dontWalkLedState);	  // Update the actual LED
  }
}