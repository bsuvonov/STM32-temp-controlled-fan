/************************************************************************
* lcd1602.h
*Header file for the LCD Driver
*for LAB3
*DB0~DB7
*PA0~PA7= LCD_PORT
************************************************************************/ 
#ifndef  lcd1602_H
#define  lcd1602_H #include "stm32f1xx_hal.h"


#define LCD_PORT GPIOA->ODR
typedef unsigned char uchar;

/* Function prototypes */

void LCD_init(void);	//LCD Initialization
void LCD_Clear(void);	// LCD Clear Display

void LCD_Write_Command(uchar Com); //LCD Write Function
void LCD_Write_Data(uchar dat); //LCD Read Function

uchar LCD_Read_State(void); //LCD Read State

void LCD_Set_Position(uchar x,uchar y); //LCD Write Date

void LCD_Display_Char(uchar Char,uchar x,uchar y); //LCD Display one char 
void LCD_Display_String(uchar x,uchar y,uchar *str); //LCD a string
#endif
/*****************end of LCD.h**********************/
