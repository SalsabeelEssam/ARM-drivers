/***************************************************************************************************
 *  File Name        : NVIC_private.h
 *  Module           : NVIC  PRIVATE
 *  Description      : save register and private function
 *  Created on       : JUL 7, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/*Base Address of Core Pheriheral NVIC */
#define NVIC_BASE_ADDRESS     0xE000E100
#define SCB_BASE_ADDRESS      0xE000ED00

#define NVIC_ISER0   (*((u32*)(NVIC_BASE_ADDRESS + 0x00))) /* Set Enable external interrupt from 0 to 31 periheral*/
#define NVIC_ISER1   (*((u32*)(NVIC_BASE_ADDRESS + 0x04))) /* Set Enable external interrupt from 32 to 63 periheral*/

#define NVIC_ICER0   (*((u32*)(NVIC_BASE_ADDRESS + 0x80))) /* clear Enable external interrupt from 0 to 31 periheral*/
#define NVIC_ICER1   (*((u32*)(NVIC_BASE_ADDRESS + 0x84))) /* clear Enable external interrupt from 32 to 63 periheral*/

#define NVIC_ISPR0   (*((u32*)(NVIC_BASE_ADDRESS + 0x100)))/* Set Pending external interrupt from 0 to 31 periheral*/
#define NVIC_ISPR1   (*((u32*)(NVIC_BASE_ADDRESS + 0x104)))/* Set Pending external interrupt from 32 to 63 periheral*/

#define NVIC_ICPR0   (*((u32*)(NVIC_BASE_ADDRESS + 0x180)))/* Clear Pending external interrupt from 0 to 31 periheral*/
#define NVIC_ICPR1   (*((u32*)(NVIC_BASE_ADDRESS + 0x184)))/* Clear Pending external interrupt from 32 to 63 periheral*/

#define NVIC_IABR0   (*((volatile u32*)(NVIC_BASE_ADDRESS + 0x200)))/* Get Active Flag external interrupt from 0 to 31 periheral*/
#define NVIC_IABR1   (*((volatile u32*)(NVIC_BASE_ADDRESS + 0x204)))/* Get Active Flag external interrupt from 32 to 63 periheral*/

/* (ptr to u8) will use substractor for siple than derfrance */
#define NVIC_IPR     ((volatile u8*)(NVIC_BASE_ADDRESS + 0x300)) /* Set Interrupt Priorty  external interrupt from 0 to 59 periheral*/
/* this adress not in this place*/
#define SCB_AIRCR    (*(volatile u32*)(SCB_BASE_ADDRESS + 0x0C)) /* Set group Priorty and Sub Priorty  Number for external interrupt */
 
#define NVIC_GROUP_4_SUB_0       0x05FA0300  /* 4 bit for group IPR ==> group*/
#define NVIC_GROUP_3_SUB_1       0x05FA0400  /* 3 bit for group && 1 bit For sub periorty IPR ==> 3group + 1sub*/
#define NVIC_GROUP_2_SUB_2       0x05FA0500  /* 2 bit for group && 2 bit For sub periorty IPR ==> 2group + 2sub*/
#define NVIC_GROUP_1_SUB_3       0x05FA0600  /* 1 bit for group && 3 bit For sub periorty IPR ==> 1group + 3sub*/
#define NVIC_GROUP_0_SUB_4       0x05FA0700  /* 0 bit for group && 4 bit For sub periorty IPR ==> 0group + 4sub*/

 
#endif 