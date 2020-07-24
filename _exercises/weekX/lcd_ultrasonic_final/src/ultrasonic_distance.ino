

// This #include statement was automatically added by the Particle IDE.
#include "LiquidCrystal_I2C_Spark.h"
double SPEED_SOUND_CM_ROOM_TEMP_FAHR = 0.03444;
double CONV_FACTOR_CM_TO_IN = 0.3437;
int MAX_RANGE_CM = 78;
int MIN_RANGE_CM = 0;

const int PIN_BUTTON = D2;
const int PIN_TRIGGER = D3;
const int PIN_ECHO = D4;

bool unitInCm = true;  // true is CM, false is IN
double distanceCm;

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("Setup");

  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Test");
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dist to object:");

  // start trigger
  digitalWrite(PIN_TRIGGER, LOW);  // prepare
  delayMicroseconds(2);
  digitalWrite(PIN_TRIGGER, HIGH);  // prepare
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER, LOW);  // prepare

  int timeRoundTrip = pulseIn(PIN_ECHO, HIGH);  // wait for round trip time
  distanceCm = timeRoundTrip * SPEED_SOUND_CM_ROOM_TEMP_FAHR / 2;

  Serial.print("Button value: ");
  Serial.println(digitalRead(PIN_BUTTON));
  if (digitalRead(PIN_BUTTON) == HIGH) {
    Serial.println("button pressed");
    delay(50);             // crude way to address debouncing
    unitInCm = !unitInCm;  // toggle units if button pressed
  }

  if (distanceCm >= MAX_RANGE_CM ||
      distanceCm <= MIN_RANGE_CM) {  // these units can be CM only because that
                                     // is what the sensor reports
    lcd.setCursor(0, 1);
    lcd.print("out of range");

    Serial.println("out of range");
  } else {
    if (unitInCm == true) {  // cm
      lcd.setCursor(0, 1);
      lcd.print(distanceCm);
      lcd.print(" cm");
    } else {  // in
      double distanceIn = distanceCm * CONV_FACTOR_CM_TO_IN;
      lcd.setCursor(0, 1);
      lcd.print(distanceIn);
      lcd.print(" in");
    }
  }
  // debug
  Serial.print("Round trip time: ");
  Serial.println(timeRoundTrip);
  Serial.print("Distance in cm: ");
  Serial.println(distanceCm);
  delay(500);
}
