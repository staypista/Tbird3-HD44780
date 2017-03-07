/*
 * Tbird3-HD44780.c
 *
 * Created: 2017. 03. 07. 20:47:32
 * Author : Nagy Zsolt
 * Board type: Tbird-Exp.
 */ 

#include <avr/io.h>
#include "LCD.h"


int main(void)
{
    uint8_t i;
	lcd_init();
	for(i=0;i<4;i++) {
		lcd_gotoxy(i,0);
		lcd_str("0123456789ABCDEF");
	}	
    while (1) 
    {		
    }
}

