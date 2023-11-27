const int MOTION_PIN = D2;
const int LED_PIN = D7;

unsigned long prevMillis = 0;
unsigned long holdTime = 5000;
/*
  red goes to VUSB
  white goes to GND
  black goes to D2
  10k res goes from D2 to VUSB

*/

/*
  how to implement a hold
  -
  if there's movement, reset out millis timer and turn on light
  else no movement
    if miilis timer is up, turn off light
*/
void setup() {
    Serial.begin(9600);
    pinMode(MOTION_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    // give the sensor time to warm up/read the room
    delay(2000);  // not millis, but actually delay
}

void loop() {
    int movement = digitalRead(MOTION_PIN);

    //advanced / hold version
    unsigned long curMillis = millis();

    if(movement == LOW) { //movement detected
      digitalWrite(LED_PIN, HIGH);
      Serial.println("Movement detected");
      prevMillis = curMillis;
    }
    else { //movement has stopped
      if (curMillis - prevMillis > holdTime) { // movement stopped AND hold time expired
        Serial.println("Alarm off");
        digitalWrite(LED_PIN, LOW);
      }
      else {                                  //movement stopped BUT still holding alarm notice
        Serial.println("Movement stopped, but still holding");
      }
    }

//  Simple version
    // if (movement == LOW) {
    //     Serial.println("Movement detected!");
    //     digitalWrite(LED_PIN, HIGH);
    // } else {
    //     Serial.println("\tMovement stopped");
    //     digitalWrite(LED_PIN, LOW);
    // }
}
