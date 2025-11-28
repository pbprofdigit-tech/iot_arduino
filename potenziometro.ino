#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup(){
  lcd.init();
  lcd.backlight();

  pinMode(A0,INPUT);
  // potenziometro tra A0 e massa
  lcd.clear();
  lcd.setCursor(0, 0);

  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("    Paolo Bruni");
  lcd.setCursor(0, 1);
  lcd.print("     PRESENTA");
  lcd.setCursor(0, 2);
  lcd.print("  Dimostrazione di");

}

void loop(){
  int n;
  n=analogRead(A0);
  lcd.setCursor(0, 3);
  lcd.print("  "+String(n)+"   ");
  delay(200);

}
