/***************************************************************************************************
 *  File Name      : BIT_MATH.h
 *  Module         : Common - Macros
 *  Description    : Commonly used Macros 
 *  Created on     : JUL 4, 2020
 *  version          : v 01
 *  Author         : Salsabeel_Essam
 ***************************************************************************************************/



#ifndef  BIT_MATH_H
#define  BIT_MATH_H

#define   SET_BIT(VAR,BIT)      ((VAR) |=  (1<<(BIT)))
#define   CLR_BIT(VAR,BIT)      ((VAR) &= ~(1<<(BIT)))
#define   TOG_BIT(VAR,BIT)      ((VAR) ^=  (1<<(BIT)))
#define   GET_BIT(VAR,BIT)      (((VAR) >> (BIT)) & 1)


#endif