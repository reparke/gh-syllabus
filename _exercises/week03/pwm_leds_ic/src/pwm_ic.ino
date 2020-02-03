
const int PIN_LED = D2;
int brightness = 0;
int changeValue = 1;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);  // configure the serial monitor
}

// version 3
void loop() {
  analogWrite(PIN_LED, brightness);
  delay(5);
  Serial.println("Brightness: " + String(brightness) +
                 ", changeVal: " + String(changeValue));
  brightness = brightness + changeValue;

  if (brightness == 255 || brightness == 0) {
    changeValue = changeValue * -1;
  }
}

// 0-100% duty cyle
// 0-255 PWM value
// version 2
// void loop() {
//   // delay with no while
//   int brightness = 0;
//   while (brightness < 255) {
//     brightness++;  // add 1
//     analogWrite(PIN_LED, brightness);
//     delay(5);
//   }
//   while (brightness > 0) {
//     brightness--;  // decrease by 1
//     analogWrite(PIN_LED, brightness);
//     delay(5);
//   }
// void loop() {
// version 1
// analogWrite(PIN_LED, 63);
// delay(1000);
// analogWrite(PIN_LED, 127);
// delay(1000);
// analogWrite(PIN_LED, 197);
// delay(1000);
// analogWrite(PIN_LED, 255);
// delay(1000);
// }
// }