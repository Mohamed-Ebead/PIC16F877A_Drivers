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

// MCAL
#include "_7_Segment_int.h"

// HAL
#include "DIO_Interface.h"

#define _XTAL_FREQ 4000000 

extern u8 ON_OFF_Status ; 
extern u8 SET_Mode_Status ; 
extern u8 u8_Temp  ;
extern u8 ON_OFF_Flag ;
extern u8 Set_Temp_Flag ;
extern u8 TempChange_Status ; 


/*----------------------------------------------------------------------------*/

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
            __delay_ms(100) ;
            
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
        
    }
}
else
    {
        
    }
}

/*----------------------------------------------------------------------------*/

u8 Check_ON_OFF_Flag (void) 
{
    if (ON_OFF_Flag == _SET )
    {
    if (ON_OFF_Status == OFF_STATE)
        {
            ON_OFF_Status = OFF_STATE ;          
        }
        else if (ON_OFF_Status == ON_STATE)
        {
           ON_OFF_Status = ON_STATE ; 
        }
        else
        {
            // invalid state 
        }
    }
    else
    {
        ON_OFF_Flag = _RESET ;
    }
     
    
    return ON_OFF_Flag ;
}

/*----------------------------------------------------------------------------*/

u8 Check_SetTempMode_Flag (void) 
{
    if (Set_Temp_Flag == _SET)
    {
        SET_Mode_Status = _SET ;
    }
    else
    {
        SET_Mode_Status = _RESET ;
    }
    
    return  SET_Mode_Status ;
}
