/***************************************************************************************************
 *  File Name        : DMA_interface.h
 *  Module           : DMA  INTERFACE
 *  Description      : to interface DMA
 *  Created on       : JUL 29, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

void DMA_viodChannelInit(void);

void DMA_viodChannelStart(u32 *Copy_SourseAddress,u32 *Copy_DistinationAddress,u16 Copy_BlockSize);

#endif