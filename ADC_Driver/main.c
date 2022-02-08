/*
 * main.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Mariam
 */
#include "std_types.h"
#include "Bit_calc.h"
//#include <util/delay.h>
#include"DIO_interface.h"
#include"ADC_interface.h"
#include"LCD_interface.h"



void Seperate_Result (u32 u32Result, u8 * u8array_Result)
{

	u8array_Result[0]= ((u32Result / 10000) % 10) + 48;//48 is the zero character is ASCII
	u8array_Result[1]= ((u32Result / 1000 ) % 10) + 48;
	u8array_Result[2]= ((u32Result / 100  ) % 10) + 48;
	u8array_Result[3]= ((u32Result / 10   ) % 10) + 48;
	u8array_Result[4]=  (u32Result % 10   ) + 48;

}

void main (void)
{	u8 Local_iterator;
	u8 result;
	u32 mv_temp;
	u32 temp_value;
	u8 	u8array_Result[5]={0};
    u8 arr[]="my_temp=";
    
    
	DIO_vidSetPortDirection(PORTB,OUTPUT);
	DIO_vidSetPortDirection(PORTD,OUTPUT);
	DIO_vidSetPinDirection(PORTA,PIN0,INPUT);

	ADC_vidIntitalization();
	LCD_vidIntitalize();
	LCD_vidWriteString3(arr);

	while(1)
	{
		ADC_GetAdcBlocking(0,&result);
		mv_temp=(u32)((u32)(result)*(5000UL))/(256UL);
		temp_value=(u32)(mv_temp/10UL);

		Seperate_Result(mv_temp,u8array_Result);

		GoToXY(8,0);
		for(Local_iterator=0;Local_iterator<5;Local_iterator++)
		{
			LCD_vidWriteData(u8array_Result[Local_iterator]);
		}

		//LCD_vidWriteString2(u8array_Result);

		//_delay_ms(1000);
        for(int i=0; i< 100000; i++);

}

}


/*if((temp_value>=0)&&(temp_value<25))
		{
			DIO_vidSetPinValue(PORTD,PIN0,HIGH);
			DIO_vidSetPinValue(PORTD,PIN1,LOW);
			DIO_vidSetPinValue(PORTD,PIN2,LOW);
		}
		else if((temp_value>=25)&&(result<30))
		{
			DIO_vidSetPinValue(PORTD,PIN0,LOW);
			DIO_vidSetPinValue(PORTD,PIN1,HIGH);
			DIO_vidSetPinValue(PORTD,PIN2,LOW);
		}
		else if((temp_value>=30)&&(result<40))
				{
					DIO_vidSetPinValue(PORTD,PIN0,LOW);
					DIO_vidSetPinValue(PORTD,PIN1,LOW);
					DIO_vidSetPinValue(PORTD,PIN2,HIGH);
				}

	}*/
