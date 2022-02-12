/***************************************************************************************************
 *  File Name        : USART_interface.h
 *  Module           : USART  INTERFACE
 *  Description      : to interface USART
 *  Created on       : JUL 18, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void MUSART_voidInit(void);
void MUSART_voidTransmit(u8 arr[]);
void MUSART_voidReceive(u8 *Copy_DataReturn);

#endif