/***************************************************************************************************
 *  File Name        : NVIC_interface.h
 *  Module           : NVIC  INTERFACE
 *  Description      : to interface NVIC
 *  Created on       : JUL 7, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void NVIC_voidInit(void);

void NVIC_voidEnableInterrupt(u8 Copy_u8PositionNummber);
void NVIC_voidDisableInterrupt(u8 Copy_u8PositionNummber);

void NVIC_voidSetPendingFlag(u8 Copy_u8PositionNummber);
void NVIC_voidClearPendingFlag(u8 Copy_u8PositionNummber);

u8 NVIC_u8GetActiveFlag(u8 Copy_u8PositionNummber);

void NVIC_voidSetPriority(s8 Copy_s8PositionNummber, u8 Copy_u8GroupPeriorty, u8 Copy_u8SubPeriorty, u32 Copy_u32GroupID);

#endif