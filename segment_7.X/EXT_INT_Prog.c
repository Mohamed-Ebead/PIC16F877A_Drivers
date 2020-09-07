/*
 * File:   EXT_INT_Prog.c
 * Author: Mohamed  Ebead
 *
 * Created on June 29, 2020, 10:06 PM
 */

#include "std_types.h"
#include "Bit_Logic.h"

#include "DIO_Interface.h"
#include "INT_Reg.h"
#include "DIO_Reg.h"

void EXT_INT_Init (void) 
{
    DIO_SetPinDirection ( PORTB_DIO , PIN0 , INPUT ) ; // set RB0 as input pin 
    SET_BIT (OPTION_REGISTER , OPTION_INTEDG ) ;       // rising edge 
    SET_BIT (INTCON_REGISTER , INTCON_INTE ) ;         // ext int enable 
    SET_BIT (INTCON_REGISTER , INTCON_GIE ) ;          // global int enable 
}



void __interrupt () ISR (void) 
{
    if (GET_BIT(INTCON_REGISTER,INTCON_INTF))
    {
     TOG_BIT(PORTA_Register,0) ; 
     CLR_BIT(INTCON_REGISTER,INTCON_INTF) ; 
    }
}