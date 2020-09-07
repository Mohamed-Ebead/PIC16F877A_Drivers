/*
 * File:   main.c
 * Author: Mohamed  Ebead
 *
 * Created on June 29, 2020, 9:43 AM
 */

// shared libraries 
#include <xc.h>
#include "MCU_Config.h"
#include "APP_config.h"
#include "Std_Types.h"
#include "Bit_Logic.h"

// APP
#include "APP_Interface.h"
#include "System_Vars.h"

//MCAL
#include "_7_Segment_int.h"
#include "DIO_Interface.h"

#include "ADC_int.h"
#include "EXT_INT_int.h"
#include "I2C_interface.h"
#include "EEPROM_int.h"
#include "Timer1_int.h"


#define _XTAL_FREQ 8000000 



void main(void) {
    
    
      Heater_Init() ;
  Cooler_Init();
     TempSensor_Init () ;
I2C_Init() ;
  EXT_INT_Init ();  
    vid_7_Segment_Init() ;
    SetCallBacks ();
  OFF_Mode();
  SystemVars_Init () ;
  Timer1_Init_Comp() ;


    while (1)
    {
        
    
 System_Power () ;
        
        
SetTemp_Mode() ;
      
  Temp_ControlWaterTemp();
 //vid_7_Segment_Display_2Digits(u8_Water_Temp) ;

        
        
    }
    return;
}


