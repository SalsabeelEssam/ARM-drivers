/***************************************************************************************************
 *  File Name        : SPI_private.h
 *  Module           : SPI  PRIVATE
 *  Description      : save register and private function
 *  Created on       : JUL 14, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SPI_BASE_ADDRESS  0x40013000

typedef struct{
	volatile u32 SPI_CR1;
	volatile u32 SPI_CR2;
	volatile u32 SPI_SR;
	volatile u32 SPI_DR;
	volatile u32 SPI_CRCPR;
	volatile u32 SPI_RXCRCR;
	volatile u32 SPI_TXCRCR;
	volatile u32 SPI_I2SCFGR;
	volatile u32 SPI_I2SPR;
	
} SPI_REGISTERS;

#define SPI_ACCESS_REGISTERS   ((volatile SPI_REGISTERS *)SPI_BASE_ADDRESS)


#define READ_THEN_WRITE     1
#define WRITE_THEN_READ     0


#define IDEAL_STATE_AT_1     1
#define IDEAL_STATE_AT_0     0


#define SLAVE_CONFIGURATION      0
#define MASTER_CONFIGURATION     1

#define 	fPCLK_DIV_2        0
#define 	fPCLK_DIV_4        1    
#define 	fPCLK_DIV_8        2
#define 	fPCLK_DIV_16       3
#define 	fPCLK_DIV_32       4
#define 	fPCLK_DIV_64       5
#define 	fPCLK_DIV_128      6
#define 	fPCLK_DIV_256      7

#define	SPI_ENABLE  		 1
#define	SPI_DISABLE 		 0

#define	MSB_TRANSMITTED_FIRST   0
#define	LSB_TRANSMITTED_FIRST   1

#define	SSM_HW    0
#define	SSM_SW    1

#define	SSM_SW_SLAVE    0
#define	SSM_SW_MASTER   1

#define	SEND_8BIT_DATA    0
#define	SEND_16BIT_DATA   1

#endif