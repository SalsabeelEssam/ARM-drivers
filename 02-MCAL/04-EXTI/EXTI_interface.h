/***************************************************************************************************
 *  File Name        : EXTI_interface.h
 *  Module           : EXTI  INTERFACE
 *  Description      : to interface EXTI
 *  Created on       : JUL 9, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
/*Need line Number and Mode*/
void EXTI_voidInit(void);
void EXTI_voidEnableExternalInterrupt(u8 Copy_u8LineNumber);
void EXTI_voidDisableExternalInterrupt(u8 Copy_u8LineNumber);
void EXTI_voidSWTriggerExternalInterrupt(u8 Copy_u8LineNumber);
void EXTI_voidSetSignalLatchExternalInterrupt(u8 Copy_u8LineNumber,u8 Copy_u8ModeType);

void EXIT_voidSetCallBack(void (*ptr) (void));
#endif