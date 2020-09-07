/*
 * File:   main.c
 * Author: Mohamed  Ebead
 *
 * Created on July 10, 2020, 12:31 PM
 */

// shared libraries 
#include <xc.h>
#include "std_types.h"
#include "Bit_Logic.h"
#include "MCU_Config.h"

// MCAL
#include "Timer1_int.h"
#include "DIO_int.h"
#include "DIO_Interface.h"

u16 x =0 ;

void main(void) {
    
    DIO_SetPinDirection(PORTC_DIO , 0 , OUTPUT) ;
    DIO_SetPinValue(PORTC_DIO , 0 , LOW) ;
    
    Timer1_Init_Comp() ;
    
    while (1)
    {
        
    }
    
    return;
}
