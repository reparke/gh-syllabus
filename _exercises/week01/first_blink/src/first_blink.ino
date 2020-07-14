/*
Initial test of blink
- start by including blinking on-board D7
- add one LED and resistor
- then blink both LEDs
 */

// v1
void setup() { 
  pinMode(D7, OUTPUT);

}
void loop() { digitalWrite(D7, HIGH); }

//===============

//v2
// void setup() { 
//   pinMode(D7, OUTPUT);
//   pinMode(D3, OUTPUT);
//   
// }
// void loop() {
//   digitalWrite(D7, HIGH)
//   digitalWrite(D3, HIGH)
// }

//===============

// v3
// void setup() {
//   pinMode(D7, OUTPUT);
//   pinMode(D3, OUTPUT);
//
// }
// void loop() {
//   digitalWrite(D7, HIGH)
//   digitalWrite(D3, HIGH)
//   delay(3000);
//   digitalWrite(D7, LOW)
//   digitalWrite(D3, LOW)
//   delay(3000);
//   digitalWrite(D7, HIGH)
//   digitalWrite(D3, HIGH  )
//   delay(3000);
// }