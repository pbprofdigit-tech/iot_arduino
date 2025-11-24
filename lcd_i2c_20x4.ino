#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup(){
  // Inizializza il display
  lcd.init();
  // Abilita la retroilluminazione
  lcd.backlight();
  // Cancella il display
  lcd.clear();

  // Imposta la posizione di partenza del testo: colonna,riga
  lcd.setCursor(0, 0);
  lcd.print("  HELLO WORLD!!!");
  lcd.setCursor(0, 1);
  lcd.print("  Dimostrazione di");
  lcd.setCursor(0, 2);
  lcd.print("     scrittura    ");  
  lcd.setCursor(0, 3);
  lcd.print("    su display  ");  
}

void loop(){
}