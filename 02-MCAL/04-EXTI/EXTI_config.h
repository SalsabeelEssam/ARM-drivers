/***************************************************************************************************
 *  File Name        : EXTI_config.h
 *  Module           : EXTI CONFIG
 *  Description      : to config EXTI
 *  Created on       : JUL 9, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/* can choose from 0 up to 15 line just change number 0 to 1 or any nuber*/
#define EXTI_LINE     LINE0
/* Options :
            RISING_EDGE
            FALLING_EDGE		
			ON_CHANGE */
#define EXTI_MODE     RISING_EDGE

#endif