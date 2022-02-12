/***************************************************************************************************
 *  File Name        : AFIO_program.C
 *  Module           : AFIO  PROGRAM
 *  Description      : public function
 *  Created on       : JUL 9, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void AFIO_voidSetEXTIConfiguration(u8 Copy_u8LineNumber,u8 Copy_u8PortMapPin){
	/* define number of line in which register like line 9 then 9/4 = 2 this in register 2*/
	u8 Local_u8RegisterIndex = Copy_u8LineNumber / 4;
	/* (Copy_u8LineNumber % 4) to define number of block we have in each register 4 block for 4 line in lower bit so which block 9%4 = 1*/
	AFIO_ACCESS_REGISTERS -> AFIO_EXTICR[Local_u8RegisterIndex] &= ~((0b1111) << ((Copy_u8LineNumber % 4) * 4));
	AFIO_ACCESS_REGISTERS -> AFIO_EXTICR[Local_u8RegisterIndex] |= ((Copy_u8PortMapPin) << ((Copy_u8LineNumber % 4) * 4));
}