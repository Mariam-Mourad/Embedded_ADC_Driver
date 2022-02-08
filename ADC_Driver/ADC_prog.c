/*
 * ADC_prog.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Mariam
 */
#include"std_types.h"
//#include"DIO_interface.h"// dah mayenfa3sh a3meloh include 3ashan ADC is a periferal in the MCAL
#include"Bit_calc.h"
#include"ADC_interface.h"

void ADC_vidIntitalization(void)
{//enebaling the periferal
	//in register ADC_ADCSRA
	SetBit(ADC_ADCSRA,7);
	//Prescaler configuration
		SetBit(ADC_ADCSRA,0);
		SetBit(ADC_ADCSRA,1);
		SetBit(ADC_ADCSRA,2);
//set ADC_ADMUX
//set ADLAR
	//ADC_ADMUX=0x60;
	//reference voltage is ACC(internal)
	ClrBit(ADC_ADMUX,7);
	SetBit(ADC_ADMUX,6);
	//data left adjustment
	SetBit(ADC_ADMUX,5);



}

u8 ADC_GetAdcBlocking(u8 Copy_Channel_Num, u8* Copy_Data )
{//el bernameg hena me3ala2 3ala el flag le7ad ma el flag yetrefe3(lama a5od eraya)
u8 Local_ErrorState=STD_u8_ERROR_OK;
if((Copy_Channel_Num>=0)&&(Copy_Channel_Num<8))
{
ADC_ADMUX=(((ADC_ADMUX)&(0b11100000))|(Copy_Channel_Num));
//start conversion
SetBit(ADC_ADCSRA,6);
//wait on flag(tol ma howa b zero el 2eraya mesh gahza)
while(GetBit(ADC_ADCSRA,4)==0);
//ADC Flag Clear
SetBit(ADC_ADCSRA,4);
//read value
(*Copy_Data)=ADC_ADCH;
}
return Local_ErrorState;
}
/**********************************************************************/
