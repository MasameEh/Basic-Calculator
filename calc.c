/*
 * calc.c
 *
 * Created: 2/22/2023 1:24:40 PM
 *  Author: Mohamed Sameh
 */ 
#include <avr/io.h>
#include "calc.h"

void calculate(char num1[] , char num2[], char op)
{
	
	int64_t  operand1, operand2, result=0;
	
	operand1 = toInt(num1);
	operand2 = toInt(num2);
	
	switch(op)
	{
		case '+':
		result = operand1 + operand2;
		break;
		case '-':
		result = operand1 - operand2;
		break;
		case '/':
		result = operand1 / operand2;
		break;
		case '*':
		result = operand1 * operand2;
		break;
	}
	if (result == 0)
	{
		LCD_move_curser(1,1);
		LCD_send_char(48);
	}else{
	LCD_move_curser(1,1);
	LCD_send_int(result);
	}
}