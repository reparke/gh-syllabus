/*
 * Project losant_temperature_demo
 * Description:
 * Author:
 * Date:
 */

const int PIN_LED = D7;
const String LIGHT_STRING_VALUES[] = {"dark", "ambient", "bright"};

double f;
String lightLevel;

unsigned long publishDelayMS = 2000;
unsigned long prevTime = 0;

boolean isLedOn = false;

int statusLedValue = 0;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Particle.function("ledChange", ledChange);
  Serial.begin(9600);
  Serial.println("Starting up!");

  Particle.variable("tempFahr", f);
  Particle.variable("isLedOn", isLedOn);

}

void loop() {
  unsigned long curTime = millis();
  if (curTime - prevTime > publishDelayMS) {
    prevTime = curTime;
    f = random(720, 760) / 10.0;  // random temp as double from 72.0 - 76.0
    lightLevel = LIGHT_STRING_VALUES[random(0, 2)];

    publishEvents();
  }

}

/* ======== Particle Functions ======*/

// fn: ledChange
// particle fn: ledStatus
// input: string command: on, off, blink
// output: 0 for valid commands; -1 for invalid
int ledChange(String command) {
  if (command == "on") {
    digitalWrite(PIN_LED, HIGH);
    isLedOn = true;
    return 0;
  } else if (command == "off") {
    digitalWrite(PIN_LED, LOW);
    isLedOn = false;
    return 0;
  } else if (command == "blink") {
    bool startLedState = isLedOn;
    // turn off light to state (may already be off)
    digitalWrite(PIN_LED, LOW);
    isLedOn = false;

    for (int i = 0; i < 10; i++) {
      digitalWrite(PIN_LED, HIGH);

      isLedOn = true;
      delay(250);
      analogWrite(PIN_LED, 0);

      isLedOn = false;
      delay(250);
    }
    // if light was originally on, make sure to turn it back on
    if (startLedState == true) {
      digitalWrite(PIN_LED, HIGH);

      isLedOn = true;
    }
    return 0;
  } else {
    return -1;  // error
  }
}

/* ======== Functions ======*/

void publishEvents() {
  // publish messages to Particle are max 4 per 1 sec so add a delay
  // Particle.publish("tempFahr", String(f, 1));
  // Particle.publish("lightLevel", String(lightLevel));
  // Particle.publish("isLedOn", String(isLedOn));
  // Particle.publish("tempFahr", "tempFahr=" + String(f, 1));

  Particle.publish("readings", String(f, 1) + ":" + lightLevel);

  Serial.print("tempFahr: " + String(f));
  Serial.println("; lightLevel: " + lightLevel);
}

