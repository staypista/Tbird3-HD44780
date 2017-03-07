#include <avr/io.h>
#define F_CPU 8000000UL
#include "util/delay.h"
#include "LCD.h"

#define ENABLE {_delay_ms(1); PORTF|=0b00001000;_delay_ms(1);PORTF&=0b11110111;}
	
/*This function send a data byte to lcd.*/
void lcd_data(uint8_t data){
	PORTF|=0x02;
	PORTE=data&0xF0;
	ENABLE
	data=(data<<4);
	PORTE=data&0xF0;
	ENABLE
}

/*This function send a command byte to lcd.*/
void lcd_cmd(uint8_t cmd){
	PORTF&=0xfd;
	PORTE=cmd&0xF0;
	ENABLE
	cmd=(cmd<<4);
	PORTE=cmd&0xF0;
	ENABLE
}

/**
 *	This function sets the cursor's xy position. 
 *	lcd_gotoxy(uint8_t y, uint8_t x)
 *	y position Range: 0-3
 *	x position Range: 0-15
 */
void lcd_gotoxy(uint8_t y, uint8_t x){
	uint8_t temp=0;
	switch(y){
		case 0: temp = 0x80+x; break;
		case 1:	temp = 0xC0+x; break;
		case 2:	temp = 0x90+x; break;
		case 3: temp = 0xD0+x; break;
		default: temp = 0x80+x;
	}
	lcd_cmd(temp);
}

/*This function delete any character from the lcd.*/
void lcd_clr(void){
	lcd_cmd(0x01);
	lcd_gotoxy(0,0);	
}

/*This function send a string to lcd.*/
void lcd_str(char *string){
	uint8_t i;
	for(i=1;*string;i++){
		lcd_data(*string);
		string++;
		if(i==16) lcd_gotoxy(1,0);
		if(i==32) lcd_gotoxy(2,0);
		if(i==48) lcd_gotoxy(3,0);
	}	
}

/*This function initializing the lcd.*/ 
void lcd_init(void){
	DDRF|=0x0E;
	DDRE|=0xF0;
	lcd_cmd(0x30);
	_delay_ms(20);
	lcd_cmd(0x30);
	_delay_ms(20);
	lcd_cmd(0x30);
	_delay_ms(20);
	lcd_cmd(0x0E);
	lcd_cmd(0x02);
	lcd_cmd(0x06);
	lcd_cmd(0x01);
	lcd_cmd(0x0C);
}