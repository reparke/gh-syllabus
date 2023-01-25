const int PIN_LED1 = D3;
const int PIN_LED2 = D4;
const int PIN_BUTTON = D2;

//millis() or time will be in unsigned long
//what was the LAST time we checked
unsigned long prevMillisLed1 = 0;
unsigned long prevMillisLed2 = 0;

//any intervals we want to track
unsigned long intervalOnLed1 = 2000; // 2 sec
unsigned long intervalOnLed2 = 1200; // 2 sec

//what state are with in
//we need to know if LED is on or it is off
bool state_LED1 = false; //LED 1 starts off
bool state_LED2 = false; //LED 2 starts off

void setup() {
  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  Serial.begin(9600);

}

//ver 2
void loop() {
  //get current time
  unsigned long currMillis = millis();

  //is the elapsed time since we LAST changed the LED GREATER than our interval time
  //    if yes, then switch light (on->off or off->on)
  //    if no,  do nothing
  int val = digitalRead(PIN_BUTTON);
  Serial.println("Button: " + String(val));

  //LED 1 code
  if ((currMillis - prevMillisLed1) > intervalOnLed1) {
    //update the prevMillis
    prevMillisLed1 = currMillis;

    //switch the light
    if (state_LED1 == false) {    //means light is off
      //change state
      state_LED1 = true;

      //turn on light
      digitalWrite(PIN_LED1, HIGH);
    }
    else {  //light is on now
      //change state
      state_LED1 = false;

      //turn off
      digitalWrite(PIN_LED1, LOW);
    }
  }
  //LED 2 code
  if ((currMillis - prevMillisLed2) > intervalOnLed2) {
    //update the prevMillis
    prevMillisLed2 = currMillis;

    //switch the light
    if (state_LED2 == false) {    //means light is off
      //change state
      state_LED2 = true;

      //turn on light
      digitalWrite(PIN_LED2, HIGH);
    }
    else {  //light is on now
      //change state
      state_LED2 = false;

      //turn off
      digitalWrite(PIN_LED2, LOW);
    }
  }

}


//LED blink at 5sec
//register button presses
// void loop() {
  // //delay is blocking -- v1
  // digitalWrite(PIN_LED1, HIGH);
  // delay(5000);
  // digitalWrite(PIN_LED2, LOW);
  // delay(5000);
  // int val = digitalRead(PIN_BUTTON);
  // Serial.println("Button press: " + String(val));





// }