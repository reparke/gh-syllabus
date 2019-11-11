
const int PIN_LED = D7;
const String LIGHT_STRING_VALUES[] = {"dark", "ambient", "bright"};

double f;
String lightLevel;

int publishDelayMS = 2000;
unsigned long prevTime = 0;


void setup() {
  Serial.begin(9600);

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

//we will send TEMP:LIGHT
void publishEvents() { Particle.publish("reading", String(f, 2) + ":" + lightLevel); }