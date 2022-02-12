/***************************************************************************************************
 *  File Name        : DMA_private.h
 *  Module           : DMA  PRIVATE
 *  Description      : save register and private function
 *  Created on       : JUL 29, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

#define DMA_BASE_ADDRESS  0x40020000

typedef struct{
	volatile u32 DMA_CCR;
	volatile u32 DMA_CNDTR;
	volatile u32 DMA_CPAR;
	volatile u32 DMA_CMAR;
	volatile u32 DMA_RESERVED;	
} DMA_CHANNEL;
typedef struct{
	volatile u32 DMA_ISR;
	volatile u32 DMA_IFCR;
	DMA_CHANNEL Channel[7];
} DMA_REGISTERS;

#define DMA_ACCESS_REGISTERS   ((volatile DMA_REGISTERS *)DMA_BASE_ADDRESS)



#endif