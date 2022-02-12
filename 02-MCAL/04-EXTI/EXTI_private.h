/***************************************************************************************************
 *  File Name        : EXTI_private.h
 *  Module           : EXTI  PRIVATE
 *  Description      : save register and private function
 *  Created on       : JUL 9, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define EXTI_BASE_ADDRESS  0x40010400

typedef struct{
	volatile u32 EXTI_IMR;
	volatile u32 EXTI_EMR;
	volatile u32 EXTI_RTSR;
	volatile u32 EXTI_FTSR;
	volatile u32 EXTI_SWIER;
	volatile u32 EXTI_PR;
	
} EXTI_REGISTERS;

#define EXTI_ACCESS_REGISTERS   ((volatile EXTI_REGISTERS *)EXTI_BASE_ADDRESS)

/* NUMBER OF INTERRUPT LINE*/
#define LINE0   0
#define LINE1   1
#define LINE2   2
#define LINE3   3
#define LINE4   4

/* TYPE OF  INTERRUPT MODE*/
#define RISING_EDGE    0
#define FALLING_EDGE   1 	
#define ON_CHANGE      2
#endif