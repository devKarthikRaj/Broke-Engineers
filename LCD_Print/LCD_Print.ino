/* [Test code - Do not release to participants]
 *  
 * What?
 * > Display something on LCD via I2C
 * cd
 * Pre requiste - Download the LiquidCrystal I2C library from the Arduino library manager
 */

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Escendo 2022");
}

void loop() {
  lcd.setCursor(0,1);
  lcd.print("29.5");
}
