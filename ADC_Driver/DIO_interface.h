/*
 * DIO_interface.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Mariam
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*ports*/

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/*Pins*/
#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

#define HIGH	1
#define LOW		0

#define OUTPUT 1
#define INPUT  0

/*prototypes*/

void DIO_vidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction);
void DIO_vidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value);
u8   DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);
void DIO_vidSetPortDirection(u8 Copy_u8PortId,u8 Copy_u8PortDirection);
void DIO_vidSetPortValue(u8 Copy_u8PortId,u8 Copy_u8PortValue);



#endif /* DIO_INTERFACE_H_ */
