/***************************************************************************************************
 *  File Name        : SYSTICK_program.C
 *  Module           : SYSTICK  PROGRAM
 *  Description      : public function
 *  Created on       : JUL 11, 2021
 *  version          : v 02
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

#if SYSTICK_INTERRUPT_SELECTION ==  SYSTICK_INTERRUPT_ENABLE
static void (* CallBackFunction)(void) = NULL;
#endif

static u8 SYSTICK_u8TimerMode = 0;

void SYSTICK_voidInit(void){
	#if CLOCK_SOURSE_SELECTION == CLOCK_AHB_DIV_BY_8
		CLR_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL,2);
	#elif CLOCK_SOURSE_SELECTION == PROCESSOR_CLOCK
		SET_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL,2);
	//#else #error"Wrong Clock"
	#endif
	/*Disable SYSTICK  Interrupt */
	CLR_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL,1);
	/*Disable SYSTICK*/
	CLR_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL,0);
}

void SYSTICK_voidSetBusyWait(u32 Copy_u32Ticks){
	/* Reload Value */
	SYSTICK_ACCESS_REGISTERS -> STK_LOAD = Copy_u32Ticks;
	/* Enable SYSTICK*/
	SET_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL,0);
	/* Polling To end Counting flag == 0*/
	while(!GET_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL , 16));
    /* Stop Timer */
	CLR_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL, 0);
	SYSTICK_ACCESS_REGISTERS -> STK_LOAD = 0;
	SYSTICK_ACCESS_REGISTERS -> STK_VAL  = 0;
}

void SYSTICK_voidSetTimer(u32 Copy_u32Ticks ,u8 Copy_u8SystickReap){

	SYSTICK_u8TimerMode = Copy_u8SystickReap;
	/* Reload Value */
	SYSTICK_ACCESS_REGISTERS -> STK_LOAD = Copy_u32Ticks;

	/* Enable SYSTICK*/
	SET_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL,0);
	
	/*Enable Interrupt */
	SET_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL,1);
	
}

void SYSTICK_voidStopInterval(void){
	/*Disable SYSTICK Interrupt */
	CLR_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL,1);
	/*Disable SYSTICK*/
	CLR_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL,0);
    SYSTICK_ACCESS_REGISTERS -> STK_LOAD = 0;
	SYSTICK_ACCESS_REGISTERS -> STK_VAL  = 0;
}

u32 SYSTICK_u32GetElapsedTime(void){
	u32 Local_u32LoadSubValue;
	Local_u32LoadSubValue = (SYSTICK_ACCESS_REGISTERS -> STK_LOAD) -(SYSTICK_ACCESS_REGISTERS -> STK_VAL);
	return Local_u32LoadSubValue;
}
u32 SYSTICK_u32GetRemainingTime(void){
	return  (SYSTICK_ACCESS_REGISTERS -> STK_VAL);
}

#if SYSTICK_INTERRUPT_SELECTION ==  SYSTICK_INTERRUPT_ENABLE

void SYSTICK_voidSetCallBack( void (*Copy_ptr)(void)){
	CallBackFunction =  Copy_ptr;
}

void SysTick_Handler(void){
	u8 Local_u8ClearFlag = 0;
	if(SYSTICK_u8TimerMode == SINGLE){
		 /* Stop Timer */
		 CLR_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL, 0);
		 SYSTICK_ACCESS_REGISTERS -> STK_LOAD = 0;
		 SYSTICK_ACCESS_REGISTERS -> STK_VAL  = 0;
		 /*Disable Interrupt */
		 CLR_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL, 1);
	}
	if(CallBackFunction != NULL){
		CallBackFunction();
	}
	/* Clear interrupt flag */
	//Local_u8ClearFlag = GET_BIT(SYSTICK_ACCESS_REGISTERS -> STK_CTRL,16);
}
#endif
