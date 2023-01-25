
const int PIN_PHOTORESISTOR = A5;
const int PIN_RGB_RED = D2;
const int PIN_RGB_GREEN = D3;
const int PIN_RGB_BLUE = D4;

int brightnessLevel = 0;
String roomLevel;

//constants for your thresholds
const int THRESHOLD_DARK = 1200; 
const int THRESHOLD_AMBIENT = 2500;

void changeLedColor(int r, int g, int b) {
  analogWrite(PIN_RGB_RED, r);
  analogWrite(PIN_RGB_GREEN, g);
  analogWrite(PIN_RGB_BLUE, b);
}

void setup() {
    Serial.begin(9600);
    pinMode(PIN_PHOTORESISTOR, INPUT);
    pinMode(PIN_RGB_RED, OUTPUT);
    pinMode(PIN_RGB_GREEN, OUTPUT);
    pinMode(PIN_RGB_BLUE, OUTPUT);

    //set LED color
    changeLedColor(255,0,255);
}

// void loop() {
//   brightnessLevel = analogRead(PIN_PHOTORESISTOR);
//   //map()
//   // int pwmValue = map(brightnessLevel, 0, 4095, 0, 255);
//   int pwmValue = map(brightnessLevel, 1000, 3000, 15, 255);
//   changeLedColor(pwmValue, 0, pwmValue);
  

//   //map input from photoresistor (0-4095)
//   // output of LED 0-255
// }

void loop() {
    brightnessLevel = analogRead(PIN_PHOTORESISTOR);

  if (brightnessLevel > 0 && brightnessLevel <= THRESHOLD_DARK) {
    roomLevel = "dark";
    Serial.println(roomLevel);
    changeLedColor(0,0,0);
  }
  else if (brightnessLevel > THRESHOLD_DARK && brightnessLevel <= THRESHOLD_AMBIENT) {
      roomLevel = "ambient";
      Serial.println(roomLevel);
      changeLedColor(255, 0, 255);
  }
  else {
    roomLevel = "bright";
    Serial.println(roomLevel);
    changeLedColor(255, 255, 255);
  }
  Particle.publish("Brightness", String(brightnessLevel));
  Particle.publish("Room Level", roomLevel);

  //IMPORTANT!
  // you can only 1 publish / sec

  // we all have a limited free publishing per month
  delay(10000);
}

