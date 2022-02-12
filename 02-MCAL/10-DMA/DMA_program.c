/***************************************************************************************************
 *  File Name        : DMA_program.C
 *  Module           : DMA  PROGRAM
 *  Description      : public function
 *  Created on       : JUL 29, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


void DMA_viodChannelInit(void){
	/* 1- memory to memeory 
	   2- periorty leverl Very highvideo
	   3- Source Size & desination size  =32bit
	   4- MINK And PINC acticated
	   5- no circular
	   6- transferr interrupt enable interrrupt 
	   7- direction sourse or destination
	    
    */
	#if CHANNEL_ID == 1
	DMA_ACCESS_REGISTERS -> Channel[0].DMA_CCR =
	#endif
}

void DMA_viodChannelStart(u32 *Copy_SourseAddress,u32 *Copy_DistinationAddress,u16 Copy_BlockSize)<
{
	/*make sure channel is disable */
	CLR_BIT(DMA_ACCESS_REGISTERS -> Channel[CHANNEL_ID -1].CRR,0);
	/*Write Address*/
	DMA_ACCESS_REGISTERS -> Channel[CHANNEL_ID -1].CPAR = Copy_SourseAddress;
	DMA_ACCESS_REGISTERS -> Channel[CHANNEL_ID -1].CMAR = Copy_DistinationAddress;
	/*Block Lenght */
	DMA_ACCESS_REGISTERS -> Channel[CHANNEL_ID -1].CNDTR = Copy_BlockSize;
	/*ENABLE */
	SET_BIT(DMA_ACCESS_REGISTERS -> Channel[CHANNEL_ID -1].CRR,0);
	
}