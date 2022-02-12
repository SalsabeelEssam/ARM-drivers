/***************************************************************************************************
 *  File Name        : SPI_program.C
 *  Module           : SPI  PROGRAM
 *  Description      : public function
 *  Created on       : JUL 14, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void (*CallBack)(u8);

void SPI1_voidInit(void){
	//SPI_ACCESS_REGISTERS ->SPI_CR1=0x0347;
	
	#if CLOCK_PHASE_SELECT == WRITE_THEN_READ
	SET_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,0);
	#elif CLOCK_PHASE_SELECT == READ_THEN_WRITE
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,0);
	#endif
	
	#if CLOCK_POLARITY_SELECT == IDEAL_STATE_AT_1
	SET_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,1);
	#elif CLOCK_POLARITY_SELECT == IDEAL_STATE_AT_0
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,1);
	#endif
	
	#if MASTER_SELECTION == MASTER_CONFIGURATION
	SET_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,1);
	#elif MASTER_SELECTION == SLAVE_CONFIGURATION
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,2);
	#endif
	
	#if PRESCALLER_CONTROL  == fPCLK_DIV_2
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,3);
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,4);
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,5);
	#elif PRESCALLER_CONTROL  == fPCLK_DIV_4
	SET_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,3);
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,4);
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,5);
	#elif PRESCALLER_CONTROL  == fPCLK_DIV_8
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,3);
	SET_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,4);
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,5);
	#endif
	
	#if SET_DATA_ORDER  == MSB_TRANSMITTED_FIRST
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,7);
	#elif SET_DATA_ORDER == LSB_TRANSMITTED_FIRST
	SET_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,7);
	#endif
	
	#if  SOFTWARE_SLAVE_MANAGEMENT  == SSM_SW
	SET_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,9);
	#if   INTERNAL_SLAVE_SELECT == SSM_SW_MASTER
	SET_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,8);
	#elif  INTERNAL_SLAVE_SELECT == SSM_SW_SLAVE
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,8);
	#endif
	#elif SOFTWARE_SLAVE_MANAGEMENT  == SSM_HW
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,9);
	#endif
	
	
	#if   DATA_FRAME_FORMAT == SEND_8BIT_DATA
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,11);
	#elif  DATA_FRAME_FORMAT == SEND_16BIT_DATA
	SET_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,11);
	#endif
	
	#if   SPI1_ENABLE == SPI_ENABLE
	SET_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,6);
	#elif  SPI1_ENABLE == SPI_DISABLE
	CLR_BIT(SPI_ACCESS_REGISTERS ->SPI_CR1,6);
	#endif
}


SPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmite, u8 *Copy_DataToReceive){
	/* Clear for Slave Select Pin*/
	MGPIO_VidSetPinValue(SPI1_SLAVE_PIN,LOW);
	
	/* send data*/
	SPI_ACCESS_REGISTERS -> SPI_DR = Copy_u8DataToTransmite;
	
	/* wait busy flag to finish*/
	while(GET_BIT((SPI_ACCESS_REGISTERS -> SPI_SR),7) ==1);
	
	/* return the receive data */
	*Copy_DataToReceive = SPI_ACCESS_REGISTERS -> SPI_DR;
	
	/*set slave select pin*/
	MGPIO_VidSetPinValue(SPI1_SLAVE_PIN,HIGH);
}
void SPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmite, void (*callBack)(u8)){
	
    CallBack =callBack;	
	/* Clear for Slave Select Pin*/
	MGPIO_VidSetPinValue(SPI1_SLAVE_PIN,LOW);
	
	/* send data*/
	SPI_ACCESS_REGISTERS -> SPI_DR = Copy_u8DataToTransmite;
	
}
void SPI1_IRQHandler(void){
	CallBack(SPI_ACCESS_REGISTERS -> SPI_DR);
	/*set slave select pin*/
	MGPIO_VidSetPinValue(SPI1_SLAVE_PIN,HIGH);
}