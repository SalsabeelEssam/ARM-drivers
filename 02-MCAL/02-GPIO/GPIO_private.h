/***************************************************************************************************
 *  File Name        : GPIO_private.h
 *  Module           : GPIO  PRIVATE
 *  Description      : save register and private function
 *  Created on       : JUL 6, 2021
 *  version          : v 01
 *  Author           : Salsabeel_Essam
 ***************************************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#define  GPIO_PORTA            0x40010800 
#define  GPIO_PORTB            0x40010C00 
#define  GPIO_PORTC            0x40011000

 /* REGISTER ADDRESSES FOR PORTA */
#define  GPIOA_CRL             (*((u32*)(GPIO_PORTA + 0x00))) 
#define  GPIOA_CRH             (*((u32*)(GPIO_PORTA + 0x04))) 
#define  GPIOA_IDR             (*((u32*)(GPIO_PORTA + 0x08)))
#define  GPIOA_ODR             (*((u32*)(GPIO_PORTA + 0x0C))) 
#define  GPIOA_BSRR            (*((u32*)(GPIO_PORTA + 0x10))) 
#define  GPIOA_BRR             (*((u32*)(GPIO_PORTA + 0x14)))
#define  GPIOA_LCKR            (*((u32*)(GPIO_PORTA + 0x18)))

 /* REGISTER ADDRESSES FOR PORTB */
#define  GPIOB_CRL             (*((u32*)(GPIO_PORTB + 0x00))) 
#define  GPIOB_CRH             (*((u32*)(GPIO_PORTB + 0x04))) 
#define  GPIOB_IDR             (*((u32*)(GPIO_PORTB + 0x08)))
#define  GPIOB_ODR             (*((u32*)(GPIO_PORTB + 0x0C))) 
#define  GPIOB_BSRR            (*((u32*)(GPIO_PORTB + 0x10))) 
#define  GPIOB_BRR             (*((u32*)(GPIO_PORTB + 0x14)))
#define  GPIOB_LCKR            (*((u32*)(GPIO_PORTB + 0x18)))

 /* REGISTER ADDRESSES FOR PORTC */
#define  GPIOC_CRL             (*((u32*)(GPIO_PORTC + 0x00))) 
#define  GPIOC_CRH             (*((u32*)(GPIO_PORTC + 0x04))) 
#define  GPIOC_IDR             (*((u32*)(GPIO_PORTC + 0x08)))
#define  GPIOC_ODR             (*((u32*)(GPIO_PORTC + 0x0C))) 
#define  GPIOC_BSRR            (*((u32*)(GPIO_PORTC + 0x10))) 
#define  GPIOC_BRR             (*((u32*)(GPIO_PORTC + 0x14)))
#define  GPIOC_LCKR            (*((u32*)(GPIO_PORTC + 0x18)))

#endif