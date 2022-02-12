/***************************************************************************************************
 *  File Name        : AFIO_interface.h
 *  Module           : AFIO  INTERFACE
 *  Description      : to interface AFIO
 *  Created on       : JUL 9, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

#define PORT_MAP_PINA       0b0000  /*AFIO output PIN IN PORTA*/
#define PORT_MAP_PINB       0b0001  /*AFIO output PIN IN PORTB*/
#define PORT_MAP_PINC       0b0010  /*AFIO output PIN IN PORTC*/


void AFIO_voidSetEXTIConfiguration(u8 Copy_u8LineNumber,u8 Copy_u8PortMapPin);

#endif