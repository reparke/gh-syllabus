
void setup() {
  Serial.begin(9600);   //9600
  Serial.println("In setup");
  pinMode(D7, OUTPUT);
}
void loop() {
  digitalWrite(D7, HIGH);
  delay(500);

}