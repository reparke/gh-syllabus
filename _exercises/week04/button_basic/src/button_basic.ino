
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
int buttonState = 0;  //global variable state
void setup() {
  pinMode(2, INPUT);  //configure
  pinMode(8, OUTPUT);  //configure
  Serial.begin(9600);
  // digitalWrite(8, HIGH);

}

void loop() {
//read button state
  buttonState = digitalRead(2); 
  if (buttonState == HIGH) {
    Serial.println("HIGH");
     digitalWrite(8, HIGH);
  }
  else {
    Serial.println("LOW");
      digitalWrite(8, LOW);

  }
}
