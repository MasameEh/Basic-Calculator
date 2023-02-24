/*
 * Calc.c
 *
 * Created: 2/22/2023 12:57:41 PM
 * Author : Mohamed Sameh
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "keypad.h"
#include "calc.h"


int main(void)
{
	 label:LCD_init();
	keypad_init();
	
	
    while (1) 
    {
		
		char num1[8], num2[8], operator = 0;
		uint8_t i = 0;
		
		do 
		{
			num1[i] = keypad_get_pressed_key();
		} while (num1[i] == NO_PRESS_VAL);
		
		LCD_send_char(num1[i]);

		i++;

		while (1)
		{
			do
			{
				num1[i] = keypad_get_pressed_key();
			} while (num1[i] == NO_PRESS_VAL);
			
			if(num1[i] == 'A'){
				LCD_clearscreen();
			}else{
				LCD_send_char(num1[i]);
			}
			
			if(num1[i] == '+')
			{
				operator = '+';
				num1[i] = '\0';
				break;
			}
			else if(num1[i] == '-')
			{
				operator = '-';
				num1[i] = '\0';
				break;
			}
			else if(num1[i] == '/')
			{
				operator = '/';
				num1[i] = '\0';
				break;
			}
			else if(num1[i] == '*')
			{
				operator = '*';
				num1[i] = '\0';
				break;
			}else if (num1[i] == '=')
			{
				LCD_move_curser(3,0);
				LCD_send_char(num1[i-1]);
				do 
				{
					num1[i+1] = keypad_get_pressed_key();
				} while (num1[i+1] == NO_PRESS_VAL);
				if(num1[i+1] == 'A' || num1[i+1] == '0'|| num1[i+1] == '+'|| num1[i+1] == '-'|| num1[i+1] == '*'|| num1[i+1] == '/'|| num1[i+1] == '1'|| num1[i+1] == '2'|| num1[i+1] == '3'|| num1[i+1] == '4'|| num1[i+1] == '5'|| num1[i+1] == '6'|| num1[i+1] == '7'|| num1[i+1] == '8'|| num1[i+1] == '9'|| num1[i+1] == '=')
				goto label;
			}
			
			i++;
			
		}
		i = 0;
		do
		{
			num2[i] = keypad_get_pressed_key();
		} while (num2[i] == NO_PRESS_VAL);
		if(num2[i]== '+' || num2[i]== '-'|| num2[i]== '/' || num2[i]== '*'|| num2[i]== '=')
		{
			char warning[] = "wrong value"; 
			LCD_clearscreen();
			LCD_move_curser(3,0);
			LCD_send_string(warning);
			_delay_ms(100);
			LCD_clearscreen();
			goto label;
		}else if (num2[i]== 'A')
		{
			LCD_clearscreen();
		}else{
			LCD_send_char(num2[i]); 
		}
		i++;
		while(1)
		{
			do
			{
				num2[i] = keypad_get_pressed_key();
			} while (num2[i] == NO_PRESS_VAL);
			 
			if (num2[i] == '=')
			{
				LCD_send_char(num2[i]);
				num2[i] = '\0';
				break;
			}else if (num2[i]== '+' || num2[i]== '-'|| num2[i]== '/' || num2[i]== '*')
			{
				char warning[] = "two numbers";
				LCD_move_curser(3,0);
				LCD_clearscreen();
				LCD_send_string(warning);
				_delay_ms(100);
				LCD_clearscreen();
				goto label;
			}else if (num2[i]== 'A')
			{
				LCD_clearscreen();
				goto label;
			}else
			{
				LCD_send_char(num2[i]);
			}
			i++;
		}
		
		calculate(num1,num2,operator);
		
		char key;
		do 
		{
			key = keypad_get_pressed_key();
		} while (key == NO_PRESS_VAL);
		if(key == 'A' || key == '0'|| key == '+'|| key == '-'|| key == '*'|| key == '/'|| key == '1'|| key == '2'|| key == '3'|| key == '4'|| key == '5'|| key == '6'|| key == '7'|| key == '8'|| key == '9'|| key == '=')
				{
					LCD_clearscreen();
				}
				
	}
}

