/***************************************************************************************************
 *  File Name        : AFIO_private.h
 *  Module           : AFIO  PRIVATE
 *  Description      : save register and private function
 *  Created on       : JUL 9, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

#define AFIO_BASE_ADDRESS       0x40010000

typedef struct{
	u32 AFIO_EVCR;
	u32 AFIO_MAPR;
	u32 AFIO_EXTICR[4];
	u32 AFIO_MAPR2;
}AFIO_REGISTERS;

#define AFIO_ACCESS_REGISTERS ((volatile AFIO_REGISTERS *)AFIO_BASE_ADDRESS)

#endif