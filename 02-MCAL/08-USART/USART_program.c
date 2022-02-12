/***************************************************************************************************
 *  File Name        : USART_program.C
 *  Module           : USART  PROGRAM
 *  Description      : public function
 *  Created on       : JUL 18, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void MUSART_voidInit(void){
	/* baud rate = 9600 by equation = fck/ 16 * bautrate = number in BRR*/
	USART_ACCESS_REGISTERS -> USART_BRR = 0x341;
SET_BIT(USART_ACCESS_REGISTERS -> USART_CR1,2);
SET_BIT(USART_ACCESS_REGISTERS -> USART_CR1,3);
SET_BIT(USART_ACCESS_REGISTERS -> USART_CR1,13);
/* CLEAR status registers */
USART_ACCESS_REGISTERS -> USART_SR = 0;

}
void MUSART_voidTransmit(u8 Copy_String[]){
	
	while( *Copy_String != '\0'){
		USART_ACCESS_REGISTERS -> USART_DR = (*Copy_String);
		/*POLLING UNTILE ALL DATA SEND and clear flag*/
		while(!GET_BIT(USART_ACCESS_REGISTERS -> USART_SR,6));
		Copy_String++;
	}
}
void MUSART_voidReceive(u8 *Copy_DataReturn){
	u16 Local_u16TimeOut = 0;
	u8  Local_u8TimeOut  = 0;
	/*to not wait for ever*/
	while(!GET_BIT(USART_ACCESS_REGISTERS -> USART_SR,5)){
		Local_u16TimeOut++;
		if(Local_u16TimeOut == 10000){
			Local_u8TimeOut = 255;
			break;
		}
	}
	if(Local_u8TimeOut == 0){
	  *Copy_DataReturn  = (u8)USART_ACCESS_REGISTERS -> USART_DR ;
	}else{
		*Copy_DataReturn = 255;
	}
}

