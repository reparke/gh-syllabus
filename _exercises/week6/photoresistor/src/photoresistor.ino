//v2 is using a 1k R

//empirically derived: 
/*
ambient: 2790
dark: > 3000
bright: < 1500
*/

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.

  pinMode(A0, INPUT);
  Serial.begin(9600);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  int val = analogRead(A0);
  Serial.println("Analog val: " + String(val));
  delay(1000);
}

// //v1 is using a potentiometer to precisely identify the "ambient calibration"
// //trying to match the R of the photoresistor at ambient light

// // setup() runs once, when the device is first turned on.
// void setup() {
//   // Put initialization like pinMode and begin functions here.

//   pinMode(A0, INPUT);
//   Serial.begin(9600);
// }

// // loop() runs over and over again, as quickly as it can execute.
// void loop() {
//   // The core of your code will likely live here.
//   int val = analogRead(A0);
//   Serial.println("Analog val: " + String(val));
//   delay(1000);
// }