const int MOTION_PIN = D2;
const int LED_PIN = D7;

void setup() {
  pinMode(MOTION_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);

  delay(2000);  // 1-2 s
}

void loop() {
  int reading = digitalRead(MOTION_PIN);

  if (reading == LOW) {  // motion detected
    digitalWrite(LED_PIN, HIGH);
  } else {  // no motion
    digitalWrite(LED_PIN, LOW);
  }

}