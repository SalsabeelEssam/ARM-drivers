/***************************************************************************************************
 *  File Name        : FPES_private.h
 *  Module           : FPES  PRIVATE
 *  Description      : save register and private function
 *  Created on       : JUL 24, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef FPES_PRIVATE_H
#define FPES_PRIVATE_H

#define FPES_BASE_ADDRESS  0x40022000

typedef struct{
	volatile u32 FLASH_ACR;
	volatile u32 FLASH_KEYR;
	volatile u32 FLASH_OPTKEYR;
	volatile u32 FLASH_SR;
	volatile u32 FLASH_CR;
	volatile u32 FLASH_AR;
	volatile u32 FLASH_RESEVED;
	volatile u32 FLASH_OBR;
	volatile u32 FLASH_WRPR;
	
} FPES_REGISTERS;

#define FPES_ACCESS_REGISTERS   ((volatile FPES_REGISTERS *)FPES_BASE_ADDRESS)



#endif