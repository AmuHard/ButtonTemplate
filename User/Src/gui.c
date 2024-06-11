
#include<stdio.h>
#include "gui.h"

void GuiInit(void){
  LCD_DisplayStringLine(Line1,(unsigned char *)"    Hello World!    ");
  uint8_t str[24];
  sprintf((char*)str,"      Num1:%03d         ",0);
  LCD_DisplayStringLine(Line2,str);
  sprintf((char*)str,"      Num2:%03d         ",0);
  LCD_DisplayStringLine(Line3,str); 
  sprintf((char*)str,"      Num3:%03d         ",0);
  LCD_DisplayStringLine(Line4,str);
  sprintf((char*)str,"      Num4:%03d         ",0);
  LCD_DisplayStringLine(Line5,str);
}

void GuiShowNum(uint8_t* num){
  static uint8_t str[24];
  sprintf((char*)str,"      Num1:%03d         ", num[0]);
  LCD_DisplayStringLine(Line2,str);
  sprintf((char*)str,"      Num2:%03d         ", num[1]);
  LCD_DisplayStringLine(Line3,str); 
  sprintf((char*)str,"      Num3:%03d         ", num[2]);
  LCD_DisplayStringLine(Line4,str);
  sprintf((char*)str,"      Num4:%03d         ", num[3]);
  LCD_DisplayStringLine(Line5,str); 
}
