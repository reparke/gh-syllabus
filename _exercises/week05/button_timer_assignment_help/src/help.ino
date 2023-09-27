//phase 1: 10 sec timer
const unsigned long INTERVAL_TIMER = 4000;
unsigned long prevMillis = 0;
unsigned long currMillis = 0;

//phase 2: timer starts ON and goes forever, but button press will stop timer forever
int prevButtonState = HIGH;
int currButtonState = HIGH;
bool alarmOn = true; //alarm "state" whether on (true) or off (false)

//phase 3: timer starts ON and goes forever, 
//button press once starts timer
//button press again resets timer back on 

const int PIN_BUTTON = D2;

void setup() {
    pinMode(PIN_BUTTON, INPUT);
    Serial.begin(9600);
}

void loop() {
    currMillis = millis();

    //set up a latch
    currButtonState = digitalRead(PIN_BUTTON);
    if (currButtonState == LOW && prevButtonState == HIGH) {
        //falling edge
        if (alarmOn == true) { //alarm is ON
            alarmOn = false;    //turn off alarm
            Serial.println("Timar stopped");
        }
        else {//alarm is currently OFF
            alarmOn = true;
            prevMillis = currMillis;   //resets the timer
        }
    }
    prevButtonState = currButtonState;

    if (alarmOn == true && currMillis - prevMillis > INTERVAL_TIMER) {
        prevMillis = currMillis;
        Serial.println("Timer just went off");
    }
}