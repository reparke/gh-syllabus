

const int PIN_BUTTON = D2;
int buttonVal;

// buton val
int prevButtonState = HIGH;
int currButtonState = HIGH;

// millis
bool timerActive = true;
unsigned long prevTimerMillis = 0;
unsigned long currTimerMillis = 0;
const unsigned long INTERVAL_TIMER = 5000;

void setup() { pinMode(PIN_BUTTON, INPUT); }

// example 1: continual 10 sec timer constant
//  void loop() {
//      currTimerMillis = millis();
//      if (currTimerMillis - prevTimerMillis > INTERVAL_TIMER) {
//          Serial.println("Timer went off!");
//          prevTimerMillis = currTimerMillis;
//      }
//  }

/* example 2: timer is going infinitely but button turns it off permanently
add global variable for alarm state = true
need to add button latch
add timerActive == true to millis IF
  */
// void loop() {
//     currTimerMillis = millis();
//     currButtonState = digitalRead(PIN_BUTTON);
//     if (currButtonState == LOW && prevButtonState == HIGH) {
//         timerActive = false;
//         Serial.println("Timer now stopped");
//     }
//     prevButtonState = currButtonState;

//     if (currTimerMillis - prevTimerMillis > INTERVAL_TIMER &&
//         timerActive == true) {
//         Serial.println("Timer went off!");
//         prevTimerMillis = currTimerMillis;
//     }
// }

/* example 3: timer is going infinitely but button toggles off and on
need to add button latch
add timerActive == true to millis IF
  */
void loop() {
    currTimerMillis = millis();

    currButtonState = digitalRead(PIN_BUTTON);
    if (currButtonState == LOW && prevButtonState == HIGH) {
        if (timerActive == true) {
            timerActive = false;
            Serial.println("Timer now stopped");
        } else {  // timer is off...how do we turn it back on? how do we track
                  // "timer on"?
            timerActive = true;
            prevTimerMillis = currTimerMillis;
            Serial.println("Timer now restarted");
        }
    }
    prevButtonState = currButtonState;

    if (currTimerMillis - prevTimerMillis > INTERVAL_TIMER &&
        timerActive == true) {
        Serial.println("Timer went off!");
        prevTimerMillis = currTimerMillis;
    }
}