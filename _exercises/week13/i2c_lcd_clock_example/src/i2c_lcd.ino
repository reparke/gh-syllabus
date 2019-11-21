/*
8-Feb-2015
Jim Brower
bulldoglowell@gmail.com
*/

#include "LiquidCrystal_I2C_Spark.h"

LiquidCrystal_I2C *lcd;

int lastSecond = 0;

void setup(void) {
  Serial.begin(9600);
  lcd = new LiquidCrystal_I2C(0x27, 16, 4);
  lcd->init();
  lcd->backlight();
  lcd->clear();
  lcd->print("***Spark Time***");
}

void loop(void) {
  if (Time.second() != lastSecond) {
    Serial.print(Time.timeStr());
    lcd->setCursor(0, 1);
    lcd->print(Time.hour() < 10 ? " 0" : " ");
    lcd->print(Time.hour());
    lcd->print(Time.minute() < 10 ? ":0" : ":");
    lcd->print(Time.minute());
    lcd->print(Time.second() < 10 ? ":0" : ":");
    lcd->print(Time.second());
    lastSecond = Time.second();
  }
}
/*
- install LiquidCrystal_I2C_Spark
- include LiquidCrystal_I2C_Spark.h
- create lcd Object
*/

// #include "LiquidCrystal_I2C_Spark.h"

// LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

// void setup() {
//   Serial.begin(9600);
//   Serial.println("Setup");

//   lcd.init();
//   lcd.backlight();
//   lcd.clear();
//   lcd.print("Test");
// }

// // loop() runs over and over again, as quickly as it can execute.
// void loop() {
//   Serial.println("Loop");

//   // lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("Dist to object:");

// }