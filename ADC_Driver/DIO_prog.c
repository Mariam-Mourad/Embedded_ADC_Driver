/*
 * DIO_prog.c

 *
 *  Created on: Aug 17, 2019
 *      Author: Mariam
 */
#include"../std_types.h"
#include"../Bit_calc.h"

#include"DIO_interface.h"
#include"DIO_regs.h"
/*Author*/
/*date:17/8/2019*/
/*Description: dio driver for avr atmega32*/


/*Description:Setting the wanted I/O pin either to be input or output*/
/*inputs:Port name(PORTA->PORTD),Pin Num(PIN0->PIN7),direction(OUTPUT,INPUT)*/
/*outputs:Logic 1 on the pin to be Output,Logic 0 on the pin to be INput */

void DIO_vidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction)
{/*The first thing to do in any function is parameter checking */
	/*parameters checked that it less than port d and less than pin 7*/
	if((Copy_u8PortId <= PORTD) && (Copy_u8PinId <= PIN7))

	{/*Checking the direction whether -> Output*/
		if(Copy_u8Direction== OUTPUT)


		{	switch (Copy_u8PortId)
			{/*checking which port is selected to set the logic of that bit to 1, Output*/
		case PORTA: SetBit(DDRA_Register, Copy_u8PinId);break;/*setting the selected pin in portA direction register to logic 1*/
		case PORTB: SetBit(DDRB_Register, Copy_u8PinId);break;/*same as before*/
		case PORTC: SetBit(DDRC_Register, Copy_u8PinId);break;/*same as before*/
		case PORTD: SetBit(DDRD_Register, Copy_u8PinId);break;/*same as before*/
			}
		}
		else if(Copy_u8Direction==INPUT)
			/*checking which port is selected to set the logic of that bit to 0, Input*/
		{
			switch (Copy_u8PortId)
						{
					case PORTA: ClrBit(DDRA_Register, Copy_u8PinId);break;/*setting the selected pin in portA direction register to logic 0,clear it*/
					case PORTB: ClrBit(DDRB_Register, Copy_u8PinId);break;/*same as before*/
					case PORTC: ClrBit(DDRC_Register, Copy_u8PinId);break;/*same as before*/
					case PORTD: ClrBit(DDRD_Register, Copy_u8PinId);break;/*same as before*/
						}
		}

	}
	else
	{/*error*/

	}
}
/******************************************************************************************/

/*Description: Setting wanted output on pins using the PORT register which is the logical memory(RAM) that the wanted logic(1,0) is to be outputted */
/*used to write certain data(1,0) on the avr pins*/
/*Inputs:Port name(PORTA->PORTD),Pin Num(PIN0->PIN7),PinValue(HIGH,LOW)*/
/*outputs:Logic 1 on the pin to be HIGH,Logic 0 on the pin to be LOW */
void DIO_vidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
	if((Copy_u8PortId <= PORTD) && (Copy_u8PinId <= PIN7))
	{/*parameters checked that it less than port d and less than pin 7*/

		if(Copy_u8Value == HIGH)
		{/*checking the value that is wanted to be written->if high*/
			switch (Copy_u8PortId)
			/*checking which port do i want to write on*/
		{
		case PORTA: SetBit(PORTA_Register, Copy_u8PinId);break;/*setting the selected pin to logic 1 on register PortA which holds the outputs of the pins*/
		case PORTB: SetBit(PORTB_Register, Copy_u8PinId);break;/*the same*/
		case PORTC: SetBit(PORTC_Register, Copy_u8PinId);break;/*the same*/
		case PORTD: SetBit(PORTD_Register, Copy_u8PinId);break;/*the same*/
		}
		}
		else if(Copy_u8Value == LOW)
		{/*checking the value that is wanted to be written->if low*/
			switch (Copy_u8PortId)
						{
					case PORTA: ClrBit(PORTA_Register, Copy_u8PinId);break;/*Clearing\setting the selected pin to logic 0 on register PortA which holds the outputs of the pins*/
					case PORTB: ClrBit(PORTB_Register, Copy_u8PinId);break;/*the same*/
					case PORTC: ClrBit(PORTC_Register, Copy_u8PinId);break;/*the same*/
					case PORTD: ClrBit(PORTD_Register, Copy_u8PinId);break;/*the same*/
						}
		}

	}
	else
	{/*error*/

	}
}
/********************************************************************************************************/

/*Description:It is used when the setted pin is input and i want to read some data from it*/
/*it reads the data from register called PIN where the inputed data is saved(memory/RAM for the inputs)*/
/*Inputs:Inputs:Port name(PORTA->PORTD),Pin Num(PIN0->PIN7)*/
/*outputs:Logic1,0 saved in local variable Local_Result then returned as the return of the function in variable u8 */
u8   DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{  u8 Local_Result;
		/*parameter checking and returning in the error statmen in the default of the switch case if the selected port is not the same as what is wanted*/
		switch (Copy_u8PortId)
		{
		case PORTA: Local_Result=GetBit(PINA_Register, Copy_u8PinId);break;/*reading the bit and returning it in local variable*/
		case PORTB: Local_Result=GetBit(PINB_Register, Copy_u8PinId);break;/*the same as before*/
		case PORTC: Local_Result=GetBit(PINC_Register, Copy_u8PinId);break;/*the same as before*/
		case PORTD: Local_Result=GetBit(PIND_Register, Copy_u8PinId);break;/*the same as before*/
		default: Local_Result=0xFF;/*the error statement*/
		}
return Local_Result;
	}
/**************************************************************************************************************/

/*Description:Setting the direction of a port as a whole*/
/*Inputs:Port name(A->D) , PortDirection (the state of the port): (INPUT,OUTPUT)*/
/*Outputs:Void*/
void DIO_vidSetPortDirection(u8 Copy_u8PortId,u8 Copy_u8PortDirection)
{
	if(Copy_u8PortId <= PORTD)
{/*Parameters checking:Port <D*/
	if(Copy_u8PortDirection==OUTPUT)
	{
		switch (Copy_u8PortId)

				{
			case PORTA: DDRA_Register= 0xFF;break;
			case PORTB: DDRB_Register= 0xFF;break;
			case PORTC: DDRC_Register= 0xFF;break;
			case PORTD: DDRD_Register= 0xFF;break;
				}
	}
	else if(Copy_u8PortDirection==INPUT)
		{
		switch (Copy_u8PortId)
					{
				case PORTA: DDRA_Register= 0x00;break;
				case PORTB: DDRB_Register= 0x00;break;
				case PORTC: DDRC_Register= 0x00;break;
				case PORTD: DDRD_Register= 0x00;break;
					}
	}
	else
	{
		/*error*/
	}
}
else
{
/*error*/

}

}
/****************************************************************************************/
/*Description:setting the value of a hole port , it writes in Port register*/
/*Inputs:Port name(A->D), PortValue (data written in the hole register)*/
/*OUtputs:Void*/
void DIO_vidSetPortValue(u8 Copy_u8PortId,u8 Copy_u8PortValue)
{
	if(Copy_u8PortId <= PORTD)
		{
	switch (Copy_u8PortId)
				{
			case PORTA: PORTA_Register= Copy_u8PortValue;break;
			case PORTB: PORTB_Register= Copy_u8PortValue;break;
			case PORTC: PORTC_Register= Copy_u8PortValue;break;
			case PORTD: PORTD_Register= Copy_u8PortValue;break;
				}
		}

	}
