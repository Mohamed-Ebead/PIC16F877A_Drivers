/*
 * File:   EXT_INT_Prog.c
 * Author: Mohamed  Ebead
 *
 * Created on June 29, 2020, 10:06 PM
 */

//shared libraries 

#include "APP_config.h"
#include "Std_Types.h"
#include "Bit_Logic.h"

#include "APP_Interface.h"

// MCAL
#include "Interrupt_Config.h"
#include "_7_Segment_int.h"

// HAL
#include "DIO_Interface.h"
#include "INT_Reg.h"
#include "DIO_Reg.h"




void (*GptrToFun_RB0) (void) ;
void (*GptrToFun_RB4) (void) ;
void (*GptrToFun_RB5) (void) ;






void RB0_SetCallBack (void (*pFun) (void)) 
{
    GptrToFun_RB0 = pFun ; 
}


void RB4_SetCallBack (void (*pFun) (void)) 
{
    GptrToFun_RB4 = pFun ; 
}


void RB5_SetCallBack (void (*pFun) (void)) 
{
    GptrToFun_RB5 = pFun ; 
}




extern u8 State ;
extern u8 u8_Temp_Set ;
extern u8 ON_OFF_Flag ;
extern u8 ON_OFF_Status ; 
extern u8 Set_Temp_Flag ;
extern u8 TempChange_Status ; 



void EXT_INT_Init (void) 
{
    DIO_SetPinDirection ( PORTB_DIO , ON_OFF_BUTTON , INPUT ) ; // set RB0 as input pin for ON/OFF button
    DIO_SetPinDirection ( PORTB_DIO , up_BUTTON , INPUT ) ;     // set RB4 as input pin for UP     button
    DIO_SetPinDirection ( PORTB_DIO , DOWN_BUTTON , INPUT ) ;   // set RB5 as input pin for Down   button
    
    CLR_BIT (OPTION_REGISTER , OPTION_RBPU ) ;       // connect PORTB to pull up resistors
    
    CLR_BIT (OPTION_REGISTER , OPTION_INTEDG ) ;       // Falling edge 
    SET_BIT (INTCON_REGISTER , INTCON_INTE ) ;         // RB0 int enable 
    SET_BIT (INTCON_REGISTER , INTCON_RBIE ) ;         // RB PORT change interrupt enable 
    SET_BIT (INTCON_REGISTER , INTCON_GIE ) ;          // global int enable 
}



void __interrupt () ISR (void) 
{   
   
    if (GET_BIT(INTCON_REGISTER,INTCON_INTF))      // ON/OFF button ( RB0 )
    {        
       GptrToFun_RB0 ();
       CLR_BIT(INTCON_REGISTER,INTCON_INTF) ; 

    }
    else if ( GET_BIT(INTCON_REGISTER,INTCON_RBIF) ) // UP or DOWN button ( RB4 , RB5 )
    {
        // UP button is pressed 
        if ( ! DIO_GetPinValue(PORTB_DIO,up_BUTTON) )
        {
            GptrToFun_RB4 () ;
        }
        // DOWN button is pressed 
        else if ( ! DIO_GetPinValue(PORTB_DIO,DOWN_BUTTON) )
        {
            GptrToFun_RB5 () ;
            
        }
        else
        {
            // pressed wrong button 
        }
        CLR_BIT(INTCON_REGISTER,INTCON_RBIF) ;  // clear PORT change  interrupt flag
        
    }
    else
    {
       // other interrupt flag
    }
}