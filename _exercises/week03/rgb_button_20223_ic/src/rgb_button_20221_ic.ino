const int PIN_RED = D2;
const int PIN_GREEN = D3;
const int PIN_BLUE = D4;
const int PIN_BUTTON = D5;
const int PIN_ONBOARD_LED = D7;

int counter = 0;
int prevButtonVal = HIGH;       //track the last time loop() ran, what was the value

void setup() {
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_BUTTON, INPUT);
    pinMode(PIN_ONBOARD_LED, OUTPUT);

    //step 1: serial
    Serial.begin(9600); //always happens in setup()
}
void loop() {
    //step 2: serial
    //use Serial.println() as needed

    //step 3: serial
    // launch serial monitor

    //press the button and make the onboard light turn on
    //Button: when NOT pressed, what voltage will be on pin D5? HIGH
    //          when pressed, the voltage will be LOW

    // //V1 - read button
    // int buttonVal = digitalRead(PIN_BUTTON);
    // if (buttonVal == LOW) {
    //     digitalWrite(PIN_ONBOARD_LED, HIGH);
    //     Serial.println("Button is being pressed");
    // }
    // else {  //buttonVal == HIGH (unpressed)
    //     digitalWrite(PIN_ONBOARD_LED, LOW);
    // }

    // V2 - color sequence button
    // int buttonVal = digitalRead(PIN_BUTTON);
    // if (buttonVal == LOW) {
    //     Serial.println("Button is being pressed");
    //     //white
    //     digitalWrite(PIN_RED, HIGH);
    //     digitalWrite(PIN_GREEN, HIGH);
    //     digitalWrite(PIN_BLUE, HIGH);
    //     delay(1000);
    //     //red
    //     digitalWrite(PIN_RED, HIGH);
    //     digitalWrite(PIN_GREEN, LOW);
    //     digitalWrite(PIN_BLUE, LOW);
    //     delay(500);
    //     //green
    //     digitalWrite(PIN_RED, LOW);
    //     digitalWrite(PIN_GREEN, HIGH);
    //     digitalWrite(PIN_BLUE, LOW);
    //     delay(500);
    //     //blue
    //     digitalWrite(PIN_RED, LOW);
    //     digitalWrite(PIN_GREEN, LOW);
    //     digitalWrite(PIN_BLUE, HIGH);
    //     delay(500);
    //     //orange
    //     analogWrite(PIN_RED, 255);
    //     analogWrite(PIN_GREEN, 123);
    //     analogWrite(PIN_BLUE, 0);
    //     delay(500);
    //     //off
    //     digitalWrite(PIN_RED, LOW);
    //     digitalWrite(PIN_GREEN, LOW);
    //     digitalWrite(PIN_BLUE, LOW);

    // } else {  // buttonVal == HIGH (unpressed)
    // }

    //v3 - LATCH or TOGGLE
    int currButtonVal = digitalRead(PIN_BUTTON);
    //do some stuff
    //what counts as a press? we went HIGH to LOW
    if (currButtonVal == LOW && prevButtonVal == HIGH) {
        counter = counter + 1;
        Serial.println(counter);
        // digitalWrite(PIN_ONBOARD_LED, HIGH);
    }

    //before I leave loop(), we need to store the CURR val in the PREV val
    prevButtonVal = currButtonVal;
}