
// //version 1 - read button input
// int buttonState = 0;  //global variable state
// void setup() {
//   pinMode(2, INPUT);  //configure
//   Serial.begin(9600);
// }

// void loop() {
// //read button state
//   buttonState = digitalRead(2); 
//   if (buttonState == HIGH) {
//     Serial.write("HIGH");
//   }
//   else {
//     Serial.write("LOW");

//   }
// }

//version 2 - read button and trigger LEd
// int buttonState = 0;  //global variable state
// void setup() {
//   pinMode(2, INPUT);  //configure
//   pinMode(8, OUTPUT);  //configure
//   Serial.begin(9600);
//   // digitalWrite(8, HIGH);

// }

// void loop() {
// //read button state
//   buttonState = digitalRead(2); 
//   if (buttonState == HIGH) {
//     Serial.println("HIGH");
//      digitalWrite(8, HIGH);
//   }
//   else {
//     Serial.println("LOW");
//       digitalWrite(8, LOW);

//   }
// }

// //version 3 latch

// int LEDstate = LOW;
// int lastButtonState = LOW;
// int currentButtonState = HIGH;

// void setup() {
//   pinMode(2, INPUT);  // button
//   pinMode(8, OUTPUT);    // LED
//   Serial.begin(9600);
// }

// void loop() {
//   currentButtonState = digitalRead(2);
//   Serial.println("currentButtonState: " + String(currentButtonState) +
//                  "; lastButtonState: " + String(lastButtonState) + "; LEDstate: " + String(LEDstate));

//   if (currentButtonState == HIGH && lastButtonState == LOW) {
//     LEDstate = !LEDstate;
//   }
//   digitalWrite(8, LEDstate);

//   lastButtonState = currentButtonState;
// }

//version 3 latch pull down

// int LEDstate = LOW;
// int lastButtonState = LOW;
// int currentButtonState = HIGH;

// void setup() {
//   pinMode(2, INPUT);  // button
//   pinMode(8, OUTPUT);    // LED
//   Serial.begin(9600);
// }

// void loop() {
//   currentButtonState = digitalRead(2);
//   Serial.println("currentButtonState: " + String(currentButtonState) +
//                  "; lastButtonState: " + String(lastButtonState) + "; LEDstate: " + String(LEDstate));

//   if (currentButtonState == LOW && lastButtonState == HIGH) {
//     LEDstate = !LEDstate;
//   }
//   digitalWrite(8, LEDstate);

//   lastButtonState = currentButtonState;
// }


// // version 4 - pull down simple button - very noisy
// int buttonState = 0;  //global variable state
// void setup() {
//   pinMode(2, INPUT);  //configure
//   pinMode(8, OUTPUT);  //configure
//   Serial.begin(9600);
//   // digitalWrite(8, HIGH);

// }

// void loop() {
//   // read the state of the pushbutton value:
//   buttonState = digitalRead(2);
//   Serial.println("buttonstate: " + String(buttonState));

//   // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//   if (buttonState == HIGH) {
//     // turn LED on:
//     digitalWrite(8, HIGH);
//   } else {
//     // turn LED off:
//     digitalWrite(8, LOW);
//   }
// }


// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 8;      // the number of the LED pin
// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);
  Serial.println("buttonState: " + String(buttonState) +
                 "; lastButtonState: " + String(lastButtonState) + "; ledState: " + String(ledState));

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  // set the LED:
  digitalWrite(ledPin, ledState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}