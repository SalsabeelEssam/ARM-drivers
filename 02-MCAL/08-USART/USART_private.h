/***************************************************************************************************
 *  File Name        : USART_private.h
 *  Module           : USART  PRIVATE
 *  Description      : save register and private function
 *  Created on       : JUL 18, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

#define USART_BASE_ADDRESS  0x40013800

typedef struct{
	volatile u32 USART_SR;
	volatile u32 USART_DR;
	volatile u32 USART_BRR;
	volatile u32 USART_CR1;
	volatile u32 USART_CR2;
	volatile u32 USART_CR3;
	volatile u32 USART_GTPR;
	
} USART_REGISTERS;

#define USART_ACCESS_REGISTERS   ((volatile USART_REGISTERS *)USART_BASE_ADDRESS)



#endif