
const int PIN_PHOTORESISTOR = A5;
const int PIN_RGB_RED = D2;
const int PIN_RGB_GREEN = D3;
const int PIN_RGB_BLUE = D4;

const int THRESHOLD_DARK = 1200;     // 0-1200 dark
const int THRESHOLD_AMBIENT = 2500;  // 1200-2500
// 2000-4095 is bright

int lightReading = 0;
String lightLevel;

void setup() {
    Serial.begin(9600);
    pinMode(PIN_PHOTORESISTOR, INPUT);
    pinMode(PIN_RGB_RED, OUTPUT);
    pinMode(PIN_RGB_GREEN, OUTPUT);
    pinMode(PIN_RGB_BLUE, OUTPUT);
}

void loop() {
    //variable is global
    lightReading = analogRead(PIN_PHOTORESISTOR);

    if (0 < lightReading && lightReading < THRESHOLD_DARK) {  // 0-1200
        // analogWrite(PIN_RGB_RED, 0);
        // analogWrite(PIN_RGB_GREEN, 0);
        // analogWrite(PIN_RGB_BLUE, 0);
        // displayColor(0,0,0);
        displayColorString("black");
        lightLevel = "dark";
    } else if (THRESHOLD_DARK <= lightReading && lightReading < THRESHOLD_AMBIENT) {  // 1200-2500
        // analogWrite(PIN_RGB_RED, 255);
        // analogWrite(PIN_RGB_GREEN, 0);
        // analogWrite(PIN_RGB_BLUE, 0);
        // displayColor(255, 0, 0);
        displayColorString("red");
        lightLevel = "ambient";
    } else {
        // analogWrite(PIN_RGB_RED, 0);
        // analogWrite(PIN_RGB_GREEN, 0);
        // analogWrite(PIN_RGB_BLUE, 255);
        // displayColor(0,0,255);
        displayColorString("blue");
        lightLevel = "bright";
    }
    Serial.println("Photoresitor value = " + String(lightReading));

    Particle.publish("Light Reading", String(lightReading));
    Particle.publish("Light Level", lightLevel);
    
    //two messages: light value (ADC), and what is the state of your room light (Dark, ambient, bright)
    delay(5000); //5 sec
}
void displayColor(int r, int g, int b) {
    analogWrite(PIN_RGB_RED, r);
    analogWrite(PIN_RGB_GREEN, g);
    analogWrite(PIN_RGB_BLUE, b);
}
void displayColorString(String color) {
  if (color == "black") {
    displayColor(0,0,0);
  }
  else if (color == "red") {
    displayColor(255,0,0);
  }
  else if (color == "blue") {
    displayColor(0,0,255);
  }
  else {
    displayColor(255,255,255);
  }
}