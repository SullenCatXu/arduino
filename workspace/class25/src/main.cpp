#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
//参考资料I2C LCD与Arduino接口https://zhuanlan.zhihu.com/p/349791145
//Arduino 通过 I2C 驱动 LCD1602 液晶屏https://arduino.nxez.com/2020/10/08/arduino-drives-lcd1602-screen-through-i2c.html

LiquidCrystal_I2C lcd(0X27,16,2);

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("LCD1602 I2C test");
  lcd.setCursor(0,1);
  lcd.print("  arduino  ");
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}