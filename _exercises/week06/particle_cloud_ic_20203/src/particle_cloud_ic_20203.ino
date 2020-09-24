const int PIN_LED = D7;

const int PIN_SWITCH = D2;
int switchRead;  //magnetic switch

bool isDoorOpen = false;

void setup() {
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_SWITCH, INPUT);
    Serial.begin(9600);

    Particle.variable("isDoorOpen", isDoorOpen);  //particle variables need to be GLOBAL
    Particle.function("blinkLed", blinkLed);
}

void loop() {
    switchRead = digitalRead(PIN_SWITCH);

    if (switchRead == HIGH) {  // just read that switch is open
        if (isDoorOpen == false) {
            isDoorOpen = true;
            Particle.publish("ITP348/Door/REP", "closed --> open");
        }
    } else {  // just read that switch is closed
        if (isDoorOpen == true) {
            isDoorOpen = false;
            Particle.publish("ITP348/Door/REP", "open --> closed");
        }
    }
}

int blinkLed(String cmd) {
    Serial.println("IFTTT function input: " + cmd);
    if (cmd.equalsIgnoreCase("twice")) {
        digitalWrite(PIN_LED, HIGH);
        delay(1000);
        digitalWrite(PIN_LED, LOW);
        delay(1000);
    }
    digitalWrite(PIN_LED, HIGH);
    delay(1000);
    digitalWrite(PIN_LED, LOW);
    delay(1000);
}