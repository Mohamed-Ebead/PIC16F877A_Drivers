/*
 * File:   7_Segment_prog.c
 * Author: Mohamed  Ebead
 *
 * Created on July 3, 2020, 4:07 PM
 */


// shared libraries 
//#include "config.h"
#include <pic.h>

#include "Std_Types.h"

// MCAL
#include "_7_segment_private.h"
// HAL
#include "DIO_Interface.h"

#define _XTAL_FREQ 8000000 

/*----------------------------------------------------------------------------*/

#define L_CTRL PIN4
#define R_CTRL PIN5


void vid_7_Segment_Init (void) 
{
    DIO_SetPinDirection(PORTA_DIO , L_CTRL , OUTPUT) ; // control signal for left 7-segment
    DIO_SetPinDirection(PORTA_DIO , R_CTRL , OUTPUT) ; // control signal for right 7-segment
    
    DIO_SetPortDirection(PORTD_DIO , 0x00) ; // SET PORTD output for 7-segment 
    
    // Initialization 
    DIO_SetPinValue(PORTA_DIO , L_CTRL , LOW) ; 
    DIO_SetPinValue(PORTA_DIO , R_CTRL , LOW) ; 
    
  //  DIO_SetPortValue(PORTA_DIO , 0x00) ;
    
}

/*----------------------------------------------------------------------------*/

void vid_7_Segment_DeInit (void) 
{
    DIO_SetPinValue(PORTA_DIO , L_CTRL , LOW) ; 
    DIO_SetPinValue(PORTA_DIO , R_CTRL , LOW) ; 
    
}
/*----------------------------------------------------------------------------*/

void vid_Left_7_Segment_DisplayNumber (u8 u8_Number ) 
{
    DIO_SetPinValue(PORTA_DIO , R_CTRL , LOW) ;   // disable right 7-segment
    DIO_SetPinValue(PORTA_DIO , L_CTRL , HIGH) ;  // enable left 7-segment
    
    DIO_SetPortValue(PORTD_DIO,u8_Left_7Segment[u8_Number]) ;
    
}


/*----------------------------------------------------------------------------*/

void vid_Right_7_Segment_DisplayNumber (u8 u8_Number ) 
{
    DIO_SetPinValue(PORTA_DIO , L_CTRL , LOW) ;  // disable left 7-segment
    DIO_SetPinValue(PORTA_DIO , R_CTRL , HIGH) ; // enable right 7-segment
    DIO_SetPortValue(PORTD_DIO,u8_Right_7Segment[u8_Number]) ;
    
}

/*----------------------------------------------------------------------------*/

void vid_7_Segment_Display_2Digits (u8 u8_Num ) 
{
    u8 Stability ;
    u8 Ones = u8_Num % 10 ;
    u8 Tens = u8_Num / 10 ;
    
    // display for one second
    for ( Stability =0 ; Stability<50;Stability++)
    {    
        vid_Right_7_Segment_DisplayNumber (Ones) ;
        __delay_ms(10);
        vid_Left_7_Segment_DisplayNumber  (Tens) ;
        __delay_ms(10);
    }
    
    DIO_SetPinValue(PORTA_DIO , L_CTRL , LOW) ; 
    
    
    
    
}