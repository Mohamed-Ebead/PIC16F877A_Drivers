/*
 * File:   Program.c
 * Author: Mohamed  Ebead
 *
 * Created on July 5, 2020, 9:51 AM
 */

//shared libraries 
#include <pic.h>

#include "std_types.h"
#include "Bit_Logic.h"

//APP
#include"APP_config.h"
#include "CallBacks.h"

// MCAL
#include "_7_Segment_int.h"

// HAL
#include "DIO_Interface.h"

#define _XTAL_FREQ 8000000 

extern u8 ON_OFF_Status ; 
extern u8 SET_Mode_Status ; 
extern u8 u8_Temp  ;
extern u8 ON_OFF_Flag ;
extern u8 Set_Temp_Flag ;
extern u8 TempChange_Status ; 


/*----------------------------------------------------------------------------*/

void SetCallBacks (void)
{
    RB0_SetCallBack (&RB0_Handler) ;
    RB4_SetCallBack (&RB4_Handler) ;
    RB5_SetCallBack (&RB5_Handler) ;
     
}


void SystemVars_Init (void) 
{
     ON_OFF_Status = OFF_STATE ; 
     u8_Temp = TEMP_INIT ;
     ON_OFF_Flag = _RESET ;
     Set_Temp_Flag = _RESET ;
     TempChange_Status = _RESET ; 
}

/*----------------------------------------------------------------------------*/

void ON_Mode (void) 
{     
    ON_OFF_Status = ON_STATE ; 
    
    vid_7_Segment_Display_2Digits(u8_Temp) ;
    
    
}

/*----------------------------------------------------------------------------*/

void OFF_Mode (void) 
{
    ON_OFF_Status = OFF_STATE ;
    vid_7_Segment_DeInit () ;
   
}

/*----------------------------------------------------------------------------*/

void SetTemp_Mode (void) 
{
    u8 count = 0 ;

 if (ON_OFF_Status == ON_STATE)
 {
     if (Set_Temp_Flag == _SET)
     {

        for (count=0;count<5;count++)
        {
            vid_7_Segment_Display_2Digits(u8_Temp) ;
            vid_7_Segment_DeInit() ;
            __delay_ms(1000) ;
            
            if (TempChange_Status == _SET)
            {
                count = 0 ; 
                TempChange_Status = _RESET ; 
            }
        }
        Set_Temp_Flag = _RESET  ; 
    }
    else
    {
         // Set_Temp_Flag == _RESET
    }
 }
 else
    {
        // ON_OFF_Status == OFF_STATE
    }
}

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


/*******************************/

void RB0_Handler (void)
{
    if ( ON_OFF_Status == ON_STATE )
    {
        OFF_Mode();
    }
    else
    {
       ON_Mode();
    }
}

void RB4_Handler (void)
{
   
            if (Set_Temp_Flag == _RESET)
            {
                Set_Temp_Flag = _SET ;
            }
            else 
            {
                if (ON_OFF_Status == ON_STATE)
                {
                if ( u8_Temp <75 )
                {
                    u8_Temp += 5 ;
                    TempChange_Status = _SET ; 
                }
                else 
                {
                     // temp cannot be more than 75 
                }
                }
                else
                {
                    // off state 
                }
                
            }
}

void RB5_Handler (void)
{
    if (Set_Temp_Flag == _RESET)
            {
                Set_Temp_Flag = _SET ;
            }
            else 
            {
                if (ON_OFF_Status == ON_STATE)
                {
                if (u8_Temp > 35 )
                {
                   u8_Temp -= 5 ;
                   TempChange_Status = _SET ; 
                
                }
                else 
                {
                     // temp cannot be less than 35 
                }
                }
                else
                {
                    // off state 
                }
            }
}