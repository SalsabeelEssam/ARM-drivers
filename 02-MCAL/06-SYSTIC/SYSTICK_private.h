/***************************************************************************************************
 *  File Name        : SYSTICK_private.h
 *  Module           : SYSTICK  PRIVATE
 *  Description      : save register and private function
 *  Created on       : JUL 11, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define SYSTICK_BASE_ADDRESS       0xE000E010

typedef struct{
	u32 STK_CTRL;
	u32 STK_LOAD;
	u32 STK_VAL;
	u32 STK_CALIB;
}SYSTICK_REGISTER;

#define SYSTICK_ACCESS_REGISTERS    ((volatile SYSTICK_REGISTER *)(SYSTICK_BASE_ADDRESS))

#define CLOCK_AHB_DIV_BY_8  				  0
#define PROCESSOR_CLOCK      				  1

#define	SYSTICK_INTERRUPT_ENABLE 			  0
#define	SYSTICK_INTERRUPT_DISABLE			  1

#endif