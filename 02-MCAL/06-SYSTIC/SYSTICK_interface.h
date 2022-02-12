/***************************************************************************************************
 *  File Name        : SYSTICK_interface.h
 *  Module           : SYSTICK  INTERFACE
 *  Description      : to interface SYSTICK
 *  Created on       : JUL 11, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

#define SINGLE     0
#define PERIODIC   1

void SYSTICK_voidInit(void);
void SYSTICK_voidSetBusyWait(u32 Copy_u32Ticks);
/*
Copy_u8SystickReap =  SINGLE OR PERIODIC
*/
void SYSTICK_voidSetTimer(u32 Copy_u32Ticks ,u8 Copy_u8SystickReap);
void SYSTICK_voidStopInterval(void);
u32 SYSTICK_u32GetElapsedTime(void);
u32 SYSTICK_u32GetRemainingTime(void);
void SYSTICK_voidSetCallBack( void (*Copy_ptr)(void));

#endif