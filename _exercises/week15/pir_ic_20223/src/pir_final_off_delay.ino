const int LED_PIN = D7;
const int MOTION_PIN = D2;
unsigned long holdTime = 5000;
unsigned long prevMillis = 0;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    // pinMode(MOTION_PIN, INPUT); //PIR requires a 10k pullup resistor
    pinMode(MOTION_PIN, INPUT_PULLUP);  // using an internal pull up resistor

    // pir needs about 10-15 sec with no motion to "read the room"
    delay(10000);
}

void loop() {
    // int motion = digitalRead(MOTION_PIN);

    // if (motion == LOW) {  // if LOW, then motion was detected
    //     digitalWrite(LED_PIN, HIGH);
    //     Serial.println("Motion detected");
    // } else {  // no motion detected
    //     digitalWrite(LED_PIN, LOW);
    //     Serial.println("No motion detected");
    // }

    int motion = digitalRead(MOTION_PIN);
    unsigned long curMillis= millis();

    if (motion == LOW) {  // if LOW, then motion was detected so lets start/restart timer
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Motion detected");
        prevMillis = curMillis; //restart the 5s timer
    } else if(curMillis - prevMillis > holdTime) {  // no motion detected but AND we are past the hold time
        digitalWrite(LED_PIN, LOW);
        Serial.println("No motion detected and no longer holding alarm");
    }
    else { //no motion detected BUT we are within the 5s from the last alarm
        //keep LED on!
        Serial.println("No motion detected but holding for 5s");
    }
}