#include <LiquidCrystal.h>

int seconds = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //RS, E, D4, D5, D6, D7

void setup(){
  lcd.begin(16,2);//number of Columns, number of Rows
  lcd.print("Hello, world!");
}

void loop(){
  lcd.setCursor(0,1);//col, row
  lcd.print(seconds);
  delay(1000);
  seconds += 1;
}
