#ifndef LCD_H
#define LCD_H
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <avr/io.h>
#include "util/delay.h"


void lcd_init(void);
void lcd_data(uint8_t data);
void lcd_cmd(uint8_t cmd);
void lcd_gotoxy(uint8_t x, uint8_t y);
void lcd_clr(void);
void lcd_str(char *string);
#endif