const int PIN_LED = D2;
const int PIN_ONBOARD_LED = D7;
const int PIN_BUTTON = D3;

//track the state of the button
int stateButtonLast = HIGH;
int stateButtonCurrent = HIGH;
bool isLEDOn = false;

void setup()
{
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_ONBOARD_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT); //button is DIGITAL INPUT
  Serial.begin(9600);         //always what you type   -- starts the serial object that allows us to print to the screen
}

void loop()
{
  int stateButtonCurrent = digitalRead(PIN_BUTTON);
  Serial.println("Button: " + String(stateButtonCurrent));

  //we want to change the led when--current is low, and last was high
  if (stateButtonCurrent == LOW && stateButtonLast == HIGH) {
    if (isLEDOn == true) {
      isLEDOn = false;
    }
    else {
      isLEDOn = true;
    }

    // //shortcut
    // isLEDOn = !isLEDOn;   //! means not
  }

  if( isLEDOn == true) {
    //turn led1 HIGH
    //turn LED 2 low
  }
  else {
    //reverse
  }
  
  // digitalWrite(PIN_LED, isLEDOn);
  // digitalWrite(PIN_ONBOARD_LED, !isLEDOn);

  //update the state
  stateButtonLast = stateButtonCurrent;


  // if (buttonValue == HIGH) {
  //   digitalWrite(PIN_ONBOARD_LED, LOW);
  //   digitalWrite(PIN_LED, LOW);
  // }
  // else {
  //   digitalWrite(PIN_ONBOARD_LED, HIGH);
  //   digitalWrite(PIN_LED, HIGH);
  // }

  //just we don't get an error, we need to slow the loop
  delay(250);
}
