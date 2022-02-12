/***************************************************************************************************
 *  File Name        : GPIO_interface.h
 *  Module           : GPIO  INTERFACE
 *  Description      : to interface GPIO
 *  Created on       : JUL 6, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIOA    0
#define GPIOB    1
#define GPIOC    2

#define GPIO_HIGH    1
#define GPIO_LOW     0


typedef enum {
	PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7,
	PIN8, PIN9, PIN10, PIN11, PIN12, PIN13, PIN14, PIN15
} PIN_NUM;

#define INPUT_ANALOG               0b0000  /*Input Analog pin*/
#define INPUT_FLOATING             0b0100  /*Input Floating pin*/
#define INPUT_PULLUP_PULLDOWN      0b1000  /*Input Pull up or Pull down pin*/


#define OUTPUT_SPEED_10MHZ_PP      0b0001  /*output General Purpose Push Pull with 10 MHZ*/
#define OUTPUT_SPEED_10MHZ_OD      0b0101  /*output General Purpose open drain with 10 MHZ*/
#define OUTPUT_SPEED_10MHZ_AFPP    0b1001  /*output Alternative function Push Pull with 10 MHZ*/
#define OUTPUT_SPEED_10MHZ_AFOD    0b1101  /*output Alternative function Open drain with 10 MHZ*/

#define OUTPUT_SPEED_2MHZ_PP       0b0010  /*output General Purpose Push Pull with 2 MHZ*/
#define OUTPUT_SPEED_2MHZ_OD       0b0110  /*output General Purpose open drain with 2 MHZ*/
#define OUTPUT_SPEED_2MHZ_AFPP     0b1010  /*output Alternative function Push Pull with 2 MHZ*/
#define OUTPUT_SPEED_2MHZ_AFOD     0b1110  /*output Alternative function Open drain with 2 MHZ*/

#define OUTPUT_SPEED_50MHZ_PP      0b0011  /*output General Purpose Push Pull with 50 MHZ*/
#define OUTPUT_SPEED_50MHZ_OD      0b0111  /*output General Purpose open drain with 50 MHZ*/
#define OUTPUT_SPEED_50MHZ_AFPP    0b1011  /*output Alternative function Push Pull with 50 MHZ*/
#define OUTPUT_SPEED_50MHZ_AFOD    0b1111  /*output Alternative function Open drain with 50 MHZ*/


void GPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode);

void GPIO_voidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value);

u8 GPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN);

#endif