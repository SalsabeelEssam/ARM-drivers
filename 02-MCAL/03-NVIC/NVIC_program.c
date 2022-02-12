/***************************************************************************************************
 *  File Name        : NVIC_program.C
 *  Module           : NVIC  PROGRAM
 *  Description      : public function
 *  Created on       : JUL 7, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_config.h"
#include "NVIC_private.h"


void NVIC_voidInit(void){
	
	SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION;
}
void NVIC_voidEnableInterrupt(u8 Copy_u8PositionNummber){
	if( Copy_u8PositionNummber <= 31){
		NVIC_ISER0 = (1 << Copy_u8PositionNummber);
	}else if( Copy_u8PositionNummber <= 59){/* max number of pheripheral i can enable to interrupt*/
		Copy_u8PositionNummber -= 32;
		NVIC_ISER1 = (1 << Copy_u8PositionNummber);
	}else {
		/*Return Error*/
	}
}


void NVIC_voidDisableInterrupt(u8 Copy_u8PositionNummber){
	if( Copy_u8PositionNummber <= 31){
		NVIC_ICER0 = (1 << Copy_u8PositionNummber);
	}else if( Copy_u8PositionNummber <= 59){
		Copy_u8PositionNummber -= 32;
		NVIC_ICER1 = (1 << Copy_u8PositionNummber);
	}else {
		/*Return Error*/
	}
}


void NVIC_voidSetPendingFlag(u8 Copy_u8PositionNummber){
		if( Copy_u8PositionNummber <= 31){
		NVIC_ISPR0 = (1 << Copy_u8PositionNummber);
	}else if( Copy_u8PositionNummber <= 59){
		Copy_u8PositionNummber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8PositionNummber);
	}else {
		/*Return Error*/
	}
}

void NVIC_voidClearPendingFlag(u8 Copy_u8PositionNummber){
		if( Copy_u8PositionNummber <= 31){
		NVIC_ICPR0 = (1 << Copy_u8PositionNummber);
	}else if( Copy_u8PositionNummber <= 59){
		Copy_u8PositionNummber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8PositionNummber);
	}else {
		/*Return Error*/
	}
}


u8 NVIC_u8GetActiveFlag(u8 Copy_u8PositionNummber){
	u8 Local_u8Result =0;
	if( Copy_u8PositionNummber <= 31){
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8PositionNummber);
	}else if( Copy_u8PositionNummber <= 59){
		Copy_u8PositionNummber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8PositionNummber);
	}else {
		/*Return Error*/
	}
	return Local_u8Result;
}

void NVIC_voidSetPriority(s8 Copy_s8PositionNummber, u8 Copy_u8GroupPeriorty, u8 Copy_u8SubPeriorty, u32 Copy_u32GroupID){
	/* (Copy_u32GroupID - GROUP3) /256 TO GET Priorty  p = 0 or 1,2,3,4 in table like 3 or 4 number of group and sub bit   */
	u8 Local_u8Priorty = Copy_u8SubPeriorty |(Copy_u8GroupPeriorty << ((Copy_u32GroupID - GROUP3) /256));
	/* For Core Peripheral */
	
	
	/* For External Peripheral*/
	if(Copy_s8PositionNummber >= 0){
		/* give position Number of pheriheral ID of group and ID of sub and save in msb */
		NVIC_IPR[Copy_s8PositionNummber] = Local_u8Priorty << 4;
	}
	/* to tell System Clock Block Which  Priority grouping I use  */
	/* seperated to may be 3 bit for group and 1 bit for sub and so on*/
	SCB_AIRCR = Copy_u32GroupID;
}