/***************************************************************************************************
 *  File Name        : FPES_interface.h
 *  Module           : FPES  INTERFACE
 *  Description      : to interface FPES
 *  Created on       : JUL 24, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef FPES_INTERFACE_H
#define FPES_INTERFACE_H

void FPEC_voidEraseAppArea(void);
	
void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber);

void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length);

#endif