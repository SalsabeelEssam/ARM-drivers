/***************************************************************************************************
 *  File Name        : EXTI_program.C
 *  Module           : EXTI  PROGRAM
 *  Description      : public function
 *  Created on       : JUL 9, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
/* array of ptr to function take void and return void*/
//static void (* EXTI0_CallBackFunction[16]) (void) = NULL;
static void (* EXTI0_CallBackFunction) (void) = NULL;

void EXTI_voidInit(void){
	/*Disable Interrupt at first */
	 CLR_BIT(EXTI_ACCESS_REGISTERS -> EXTI_IMR , EXTI_LINE);
	 /* Inti External Interrupt for mode and line in config file*/
	#if  EXTI_MODE == RISING_EDGE
		SET_BIT(EXTI_ACCESS_REGISTERS -> EXTI_RTSR , EXTI_LINE);
	#elif  EXTI_MODE == FALLING_EDGE
		SET_BIT(EXTI_ACCESS_REGISTERS -> EXTI_FTSR , EXTI_LINE);
	#elif  EXTI_MODE == ON_CHANGE
		SET_BIT(EXTI_ACCESS_REGISTERS -> EXTI_RTSR , EXTI_LINE);
		SET_BIT(EXTI_ACCESS_REGISTERS -> EXTI_FTSR , EXTI_LINE);
	#else
			#error"Wrong Mode or Line Choice"
	#endif
	/*Enable Interrupt at the end of function */
	SET_BIT(EXTI_ACCESS_REGISTERS -> EXTI_IMR , EXTI_LINE);
}
void EXTI_voidEnableExternalInterrupt(u8 Copy_u8LineNumber){
   /* Enable Line */
   SET_BIT(EXTI_ACCESS_REGISTERS -> EXTI_IMR , Copy_u8LineNumber);
}
void EXTI_voidDisableExternalInterrupt(u8 Copy_u8LineNumber){
	/* Disable Line */
   CLR_BIT(EXTI_ACCESS_REGISTERS -> EXTI_IMR , Copy_u8LineNumber);
}
void EXTI_voidSWTriggerExternalInterrupt(u8 Copy_u8LineNumber){
	/* fire interrupt by software even if the is no hardware interrupt eccure*/
	SET_BIT(EXTI_ACCESS_REGISTERS -> EXTI_SWIER , Copy_u8LineNumber);
}
void EXTI_voidSetSignalLatchExternalInterrupt(u8 Copy_u8LineNumber,u8 Copy_u8ModeType){
	/* to change mode and number of line in run time*/
	switch(Copy_u8ModeType){
		case RISING_EDGE:  
			SET_BIT(EXTI_ACCESS_REGISTERS -> EXTI_RTSR , Copy_u8LineNumber);
			break;
		case FALLING_EDGE: 
			SET_BIT(EXTI_ACCESS_REGISTERS -> EXTI_FTSR , Copy_u8LineNumber);
		    break;
		case ON_CHANGE: 
			SET_BIT(EXTI_ACCESS_REGISTERS -> EXTI_RTSR , Copy_u8LineNumber);
			SET_BIT(EXTI_ACCESS_REGISTERS -> EXTI_FTSR , Copy_u8LineNumber);
			break;
		default: /* return Error*/ break;
	}
	/*Enable Interrupt  */
	SET_BIT(EXTI_ACCESS_REGISTERS -> EXTI_IMR , Copy_u8LineNumber);

}

/* */
void EXIT_voidSetCallBack(void (*ptr) (void)){
	CallBackFunction = ptr ;
}
/* ISR for Interrupt EXTI0 */
void EXTI0_IRQHander(void){
	/* clear pending bit */
	SET_BIT(EXTI_ACCESS_REGISTERS -> EXTI_PR , 0);
	/* call Back Function Execute*/
	EXIT_voidSetCallBack();
	
}