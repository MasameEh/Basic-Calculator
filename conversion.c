/*
 * conversion.c
 *
 * Created: 2/23/2023 2:00:06 PM
 *  Author: Mohamed Sameh
 */ 
#include "conversion.h"

int64_t toInt(char string[]){
	int64_t num = 0;
	int8_t sign = 1, i = -1;
	
	if(string[0] == '-' )
	{
		sign = -1;
		i = 0;
	}
	
	while(string[++i] != '\0')
	{
		num = (num * 10) + (string[i] - '0');
	}
	num *= sign;
	return num;
}

void toString(char string[], int64_t num)
{
	int64_t x1, x2, reminder;
	int8_t i , length = 0;
	
	x2 = num;
	//finding the length
	while(x2 != 0)
	{
		length++;
		x2 /= 10;
	}
	
	for (i = 0; i < length; i++)
	{
		reminder = num % 10;
		num /= 10;
		string[length - (i+1)] = reminder + '0'; 
	}
	
	x1 = num;
	if(x1 < 0)
	{
		string[0] = '-';
	}
	
	string[length] = '\0';
	
}
