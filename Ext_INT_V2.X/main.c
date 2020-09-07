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
#include "System_Vars.h"
#include "APP_Interface.h"

//MCAL
#include"EXT_INT_int.h"
#include "_7_Segment_int.h"



//#define _XTAL_FREQ 4000000 



void main(void) {
    
    SystemVars_Init () ;
    EXT_INT_Init ();  
    vid_7_Segment_Init() ;
    SetCallBacks ();
    OFF_Mode();
    
    
            
    while (1)
    {
        
        if (ON_OFF_Status == ON_STATE)
        {
            ON_Mode() ;
        }
        else if (ON_OFF_Status == OFF_STATE)
        {
            OFF_Mode() ;
        }
        else
        {
            
        }
        
        
        
        SetTemp_Mode() ;
        
        /*
       if ( ( Check_SetTempMode_Flag () ) == _SET ) 
       {
           SetTemp_Mode () ;
       }
       else
       {
           
       }*/

    }
    return;
}

