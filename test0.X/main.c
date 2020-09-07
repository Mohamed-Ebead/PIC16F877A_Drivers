/*
 * File:   main.c
 * Author: Mohamed  Ebead
 *
 * Created on June 29, 2020, 9:43 AM
 */


#include "config.h"
#include<pic16f877a.h>
#include<xc.h>
#include "std_types.h"
#include"EXT_INT_RB0_Interface.h"
#include "DIO_Interface.h"

#define _XTAL_FREQ 4000000 


void main(void) {
    
    

    EXT_INT_Init ();
    DIO_SetPinDirection (PORTA_DIO , PIN0, OUTPUT) ;
    DIO_SetPinValue(PORTA_DIO , PIN0, LOW) ;
 DIO_SetPortDirection (PORTC_DIO , 0X00);
   // TRISAbits.TRISA7 = 0;

            
    while (1)
    {
        
       // DIO_SetPinValue(PORTA_DIO , PIN0, HIGH) ; 
       DIO_SetPortValue (PORTC_DIO , 0XFF);
                __delay_ms(1000) ;
                 DIO_SetPortValue (PORTC_DIO , 0X00);
          // DIO_SetPinValue(PORTA_DIO , PIN0, LOW) ; 
                                __delay_ms(1000) ;


        /*
        PORTAbits.RA0 = 1 ;
        __delay_ms(1000) ;
        PORTAbits.RA0 = 0 ;
        __delay_ms(1000) ;
        */
    }
    return;
}

