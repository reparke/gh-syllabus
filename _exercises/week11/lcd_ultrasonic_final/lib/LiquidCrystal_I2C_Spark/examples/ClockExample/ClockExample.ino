/*
8-Feb-2015
Jim Brower
bulldoglowell@gmail.com
*/

#include "LiquidCrystal_I2C_Spark.h"

LiquidCrystal_I2C *lcd;

int lastSecond = 0;

void setup(void)
{
  Serial.begin(9600);
  lcd = new LiquidCrystal_I2C(0x27, 16, 2);
  lcd->init();
  lcd->backlight();
  lcd->clear();
  lcd->print("***Spark Time***");
}

void loop(void)
{
  if (Time.second() != lastSecond)
  {
    Serial.print(Time.timeStr());
    lcd->setCursor(0,1);
    lcd->print(Time.hour() < 10? "   0" : "    ");
    lcd->print(Time.hour());
    lcd->print(Time.minute() < 10? ":0": ":");
    lcd->print(Time.minute());
    lcd->print(Time.second() < 10? ":0": ":");
    lcd->print(Time.second());
    lastSecond = Time.second();
  }
}
