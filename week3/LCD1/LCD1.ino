#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int count = 0;
void setup() {
  //  lcd.init();
  lcd.init();
  lcd.backlight();
  //  lcd.setCursor(2, 1);
  //  lcd.print("Ywrobot Arduino!");
  //  lcd.setCursor(0, 2);
  //  lcd.print("Arduino LCM IIC 2004");
  //  lcd.setCursor(2, 3);
  //  lcd.print("Power By Ec-yuan!");
}
void loop() {
  lcd.setCursor(0, 0);
  lcd.print(count*0.01);
  lcd.print(" BTC");
  delay(1000);
  count++;
}
