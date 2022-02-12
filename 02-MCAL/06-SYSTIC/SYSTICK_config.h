/***************************************************************************************************
 *  File Name        : SYSTIC_config.h
 *  Module           : SYSTIC CONFIG
 *  Description      : to config SYSTIC
 *  Created on       : JUL 11, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef SYSTIC_CONFIG_H
#define SYSTIC_CONFIG_H

/*  Options :
             CLOCK_AHB_DIV_BY_8
			 PROCESSOR_CLOCK */
#define CLOCK_SOURSE_SELECTION   PROCESSOR_CLOCK 


/*  Options :
             SYSTICK_INTERRUPT_ENABLE
			 SYSTICK_INTERRUPT_DISABLE */
#define SYSTICK_INTERRUPT_SELECTION   SYSTICK_INTERRUPT_ENABLE

#endif