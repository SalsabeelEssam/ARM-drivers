/***************************************************************************************************
 *  File Name        : SPI_config.h
 *  Module           : SPI CONFIG
 *  Description      : to config SPI
 *  Created on       : JUL 14, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H
/*Write it in a pair port,pin*/
#define SPI1_SLAVE_PIN    GPIOA,0

/* OPTIEN : WRITE_THEN_READ 
            READ_THEN_WRITE */
#define CLOCK_PHASE_SELECT     WRITE_THEN_READ
/*OPTIEN :
          IDEAL_STATE_AT_1 
          IDEAL_STATE_AT_0 */ 
#define CLOCK_POLARITY_SELECT  IDEAL_STATE_AT_1

/*OPTIEN :
           MASTER_CONFIGURATION
           SLAVE_CONFIGURATION
		  */ 
#define MASTER_SELECTION    MASTER_CONFIGURATION

/* OPTIN 
fPCLK_DIV_2   
fPCLK_DIV_4   
fPCLK_DIV_8  
fPCLK_DIV_16  
fPCLK_DIV_32  
fPCLK_DIV_64  
fPCLK_DIV_128 
fPCLK_DIV_256 
*/
#define PRESCALLER_CONTROL   fPCLK_DIV_2

/* OPTIECION 
SPI_ENABLE
SPI_DISABLE
*/
#define SPI1_ENABLE   SPI_ENABLE
/* OPTIECION 
MSB_TRANSMITTED_FIRST
LSB_TRANSMITTED_FIRST
*/
#define SET_DATA_ORDER   MSB_TRANSMITTED_FIRST

/* OPTIECION 
SSM_HW
SSM_SW
*/
#define SOFTWARE_SLAVE_MANAGEMENT   SSM_SW
/* OPTIECION 
SSM_SW_SLAVE 
SSM_SW_MASTER
*/
#define INTERNAL_SLAVE_SELECT  SSM_SW_MASTER

/* OPTIECION 
SEND_8BIT_DATA 
SEND_16BIT_DATA
*/
#define DATA_FRAME_FORMAT  SEND_8BIT_DATA



#endif