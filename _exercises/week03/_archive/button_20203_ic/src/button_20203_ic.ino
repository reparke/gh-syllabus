

const int PIN_BUTTON = D2;
const int PIN_LED = D7;

int curButton;  //global
int prevButton;   //the digitalRead value the last time through the loop
bool isLedOn = false; //start with LED off

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  delay(100);
  curButton = digitalRead(PIN_BUTTON);

  Serial.println("InputRead: " + String(curButton));

  /*
  if curButton is HIGH and prevButton is low, that means the button was released
  */

  if (curButton == HIGH && prevButton == LOW) { 
    //if led was on before, then turn off
    //if lef was off before, then turn on
    if (isLedOn == true) {
      isLedOn = false;
    }
    else {
      isLedOn = true;
    }
    //alterate way: isLedOn = !isLedOn;
  }

  if (isLedOn == true) {
    digitalWrite(PIN_LED, HIGH);
  }
  else {
    digitalWrite(PIN_LED, LOW);
  }

  prevButton = curButton; //update the state with time

  // if (curButton == HIGH) {    
  //   digitalWrite(PIN_LED, LOW);  //button HIGH means open, which means LED should be off
  // }
  // else {                         //button LOW means closed, ,which means LED is on
  //   digitalWrite(PIN_LED, HIGH);
  // }
}