/***************************************************************************************************
 *  File Name        : SPI_interface.h
 *  Module           : SPI  INTERFACE
 *  Description      : to interface SPI
 *  Created on       : JUL 11, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI1_voidInit(void);
void SPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmite, u8 *Copy_DataToReceive);
void SPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmite, void (*callBack)(u8));