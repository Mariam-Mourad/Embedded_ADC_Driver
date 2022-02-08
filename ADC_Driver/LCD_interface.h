/*
 * LCD_interface.h
 *
 *  Created on: Aug 24, 2019
 *      Author: Mariam
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_vidWriteCommand (u8 Copy_u8PortValue);
void LCD_vidIntitalize(void);
void LCD_vidWriteData (u8 Copy_u8PortData);
void LCD_vidWriteString (u8* Copy_u8PortString,u8 u8Index);
/*iteration a2al men el index*/
void LCD_vidWriteString2 (u8* Copy_u8PortString);
/*while not null '\0'*/
void LCD_vidWriteString3 (u8* Copy_u8PortString);
void GoToXY(u8 x, u8 y);//tary2teen;
void LCD_vidClearScreen(void);
void LCD_vidWriteExtraChar(u8 Y, u8 X);


#endif /* LCD_INTERFACE_H_ */
