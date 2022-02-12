/***************************************************************************************************
 *  File Name        : GPIO_program.C
 *  Module           : GPIO  PROGRAM
 *  Description      : public function
 *  Created on       : JUL 6, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode){
	switch(Copy_u8PORT){
		case GPIOA:
				if(Copy_u8PIN < 8){
					GPIOA_CRL &= ~((0b1111)      << (4 * Copy_u8PIN));
					GPIOA_CRL |=  ((Copy_u8Mode) << (4 * Copy_u8PIN));
				}else{
					Copy_u8PIN -= 8;
					GPIOA_CRH &= ~((0b1111)      << (4 * Copy_u8PIN));
					GPIOA_CRH |=  ((Copy_u8Mode) << (4 * Copy_u8PIN));
				}
			break;
		case GPIOB:
		        if(Copy_u8PIN < 8){
					GPIOB_CRL &= ~((0b1111)      << (4 * Copy_u8PIN));
					GPIOB_CRL |=  ((Copy_u8Mode) << (4 * Copy_u8PIN));
				}else{
					Copy_u8PIN -= 8;
					GPIOB_CRH &= ~((0b1111)      << (4 * Copy_u8PIN));
					GPIOB_CRH |=  ((Copy_u8Mode) << (4 * Copy_u8PIN));
				}
			break;
		case GPIOC:
		        if(Copy_u8PIN < 8){
					GPIOC_CRL &= ~((0b1111)      << (4 * Copy_u8PIN));
					GPIOC_CRL |=  ((Copy_u8Mode) << (4 * Copy_u8PIN));
				}else{
					Copy_u8PIN -= 8;
					GPIOC_CRH &= ~((0b1111)      << (4 * Copy_u8PIN));
					GPIOC_CRH |=  ((Copy_u8Mode) << (4 * Copy_u8PIN));
				}
			break;
		default : /* return Error*/ break;
	}
}

void GPIO_voidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value){
	switch(Copy_u8PORT){
		case GPIOA:
			if(Copy_u8Value == GPIO_HIGH){
				SET_BIT(GPIOA_ODR,Copy_u8PIN);
			}else if(Copy_u8Value == GPIO_LOW){
				CLR_BIT(GPIOA_ODR,Copy_u8PIN);
			}
			break;
		case GPIOB:
			if(Copy_u8Value == GPIO_HIGH){
				SET_BIT(GPIOB_ODR,Copy_u8PIN);
			}else if(Copy_u8Value == GPIO_LOW){
				CLR_BIT(GPIOB_ODR,Copy_u8PIN);
			}
			break;
		case GPIOC:
			if(Copy_u8Value == GPIO_HIGH){
				SET_BIT(GPIOC_ODR,Copy_u8PIN);
			}else if(Copy_u8Value == GPIO_LOW){
				CLR_BIT(GPIOC_ODR,Copy_u8PIN);
			}
			break;
		default : /* return error*/ break;
	}
}

u8 GPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN){
	u8 Local_u8Resert = 0; 
		switch(Copy_u8PORT){
		case GPIOA:
			Local_u8Resert = GET_BIT(GPIOA_IDR,Copy_u8PIN);
			break;
		case GPIOB:
			Local_u8Resert = GET_BIT(GPIOA_IDR,Copy_u8PIN);
			break;
		case GPIOC:
			Local_u8Resert = GET_BIT(GPIOA_IDR,Copy_u8PIN);
			break;
		default : /* return error*/ break;
	}
	return Local_u8Resert ;
}

