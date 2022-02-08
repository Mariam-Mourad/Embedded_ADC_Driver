/*
 * DIO_regs.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Mariam
 */

#ifndef DIO_REGS_H_
#define DIO_REGS_H_
/*Port A adresses*/
#define DDRA_Register  *((volatile u8*)(0x3A))//casted 3ashan yefham en dah address mesh integer number
#define PORTA_Register *((volatile u8*)(0x3B))
#define PINA_Register  *((volatile u8*)(0x39))

/*Port B adresses*/
#define DDRB_Register  *((volatile u8*)(0x37))/*Direction Register, Decide whether this pin is output or input*/
#define PORTB_Register *((volatile u8*)(0x38))/*Register that saves the wanted output to the pins*/
#define PINB_Register  *((volatile u8*)(0x36))/*Register that reads the inputs on the pins*/

/*Port C adresses*/
#define DDRC_Register  *((volatile u8*)(0x34))
#define PORTC_Register *((volatile u8*)(0x35))
#define PINC_Register  *((volatile u8*)(0x33))


/*Port D adresses*/
#define DDRD_Register  *((volatile u8*)(0x31))
#define PORTD_Register *((volatile u8*)(0x32))
#define PIND_Register  *((volatile u8*)(0x30))



#endif /* DIO_REGS_H_ */
