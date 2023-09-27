const int PIN_BUTTON = D2;

// stage 1: constant 10 sec timer
unsigned long prevMillis = 0;
unsigned long currMillis = 0;
const unsigned long INTERVAL_TIMER = 5000;

// stage 2: timer starts ON and will go forever, but presing the button will
// stop the timer
bool timerActive = true;  // this means timer starts ON
int prevButtonState = HIGH;
int currButtonState = HIGH;

// stage 3: let the button reset the alarm back ON

void setup() {
    pinMode(PIN_BUTTON, INPUT);
    Serial.begin(9600);
}

void loop() {
    currMillis = millis();

    // check for button press
    currButtonState = digitalRead(PIN_BUTTON);
    if (currButtonState == LOW && prevButtonState == HIGH) {
        // this is button press
        // turning alarm off simply means

        if (timerActive == true) {  // timer is ON, let's now turn OFF
            timerActive = false;
            Serial.println("A button stopped the timer");
        }
        else{ //timer is OFF, let's now turn it on
            //how do we track the timer?
            //what variable are related to timer? prevMillis and timerActive
            timerActive = true;
            prevMillis = millis();      //resetting the timer
            Serial.println("A button restarted the timer");
        }
    }
    prevButtonState = currButtonState;

    if (timerActive == true && currMillis - prevMillis > INTERVAL_TIMER) {
        prevMillis = currMillis;
        Serial.println("Timer went off!");
    }
}