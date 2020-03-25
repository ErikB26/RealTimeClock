#include <LiquidCrystal_I2C.h>

const int LCD_PORT = 0x27;
const int LCD_ROW_LENGTH = 16;

LiquidCrystal_I2C lcd(0x27, 20, 4);

/**
 * Initialize the display, turn on the backlight and clear it.
 */
void lcdSetup() {
  lcd.init();                
  lcd.backlight();   
  lcd.clear();
}

/**
 * Display given text on the display.
 * 
 * @param String regel1 The text to be displayed on the first row.
 * @param String regel2 The text to be displayed on the second row.
 */
void lcdPrint(String row1, String row2) {
  lcd.setCursor(calcPosition(row1), 0); 
  lcd.print(row1);
  lcd.setCursor(calcPosition(row2), 1);
  lcd.print(row2); 
}

/**
 * Calculate the cursor position so the text will be displayed in the center of a row.
 * 
 * @param String text The text to be displayed.
 * @return integer
 */
int calcPosition(String text) {
  return (LCD_ROW_LENGTH - text.length()) / 2;
}
