/*
 * File:   main.c
 * Author: Mohamed  Ebead
 *
 * Created on June 29, 2020, 9:43 AM
 */

// shared libraries 
#include "config.h"
#include "APP_config.h"
#include "std_types.h"
#include "Bit_Logic.h"

// APP
#include "APP_Interface.h"

//MCAL
#include"EXT_INT_int.h"
#include "_7_Segment_int.h"



//#define _XTAL_FREQ 4000000 

u8 ON_OFF_Status ; 
u8 SET_Mode_Status ; 
u8 u8_Temp  ;
u8 ON_OFF_Flag ;
u8 Set_Temp_Flag ;
u8 TempChange_Status ;

void main(void) {
    
    SystemVars_Init () ;
    EXT_INT_Init ();  
    vid_7_Segment_Init() ;
    OFF_Mode();
    
    
            
    while (1)
    {
        /*
       if ( (ON_OFF_Flag == _SET ) && (ON_OFF_Status == OFF_STATE) )
       {
           ON_Mode();
           ON_OFF_Flag = _RESET ;
       }
       else
       {
            OFF_Mode();
            ON_OFF_Flag = _RESET ;
       }*/
       
       if ( ( Check_SetTempMode_Flag () ) == _SET ) 
       {
           SetTemp_Mode () ;
       }
       else
       {
           
       }

    }
    return;
}

