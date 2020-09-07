/*
 * File:   Program.c
 * Author: Mohamed  Ebead
 *
 * Created on July 5, 2020, 9:51 AM
 */

//shared libraries 
#include <xc.h>
#include "Std_Types.h"
#include "Bit_Logic.h"

//APP
#include "CallBacks.h"
#include "APP_config.h"


// MCAL
#include "_7_Segment_int.h"
#include "Program_Config.h"
#include "EEPROM_int.h"

// HAL
#include "DIO_Interface.h"
#include "ADC_int.h"
#include "APP_Interface.h"

#define _XTAL_FREQ 8000000 

extern u8 ON_OFF_Status ; 
extern u8 SET_Mode_Status ; 
extern u8 u8_Temp_Set  ;
extern u8 u8_Water_Temp ; 
extern u8 ON_OFF_Flag ;
extern u8 Set_Temp_Flag ;
extern u8 TempChange_Status ; 
extern u16 u16_ADC_Read ; 
extern u16 u16_Voltage ; 
extern u8 u8_Counter  ;
extern u8 u8_arr_Temp[10]  ;
/*----------------------------------------------------------------------------*/

void SetCallBacks (void)
{
    Timer1_SetCallBack  (&Temp_ControlWaterTemp) ;
    RB0_SetCallBack     (&RB0_Handler) ;
    RB4_SetCallBack     (&RB4_Handler) ;
    RB5_SetCallBack     (&RB5_Handler) ;
    
     
}

/*----------------------------------------------------------------------------*/

void SystemVars_Init (void) 
{
    if ( (EEPROM_ReadFromEEPROM() < 75 ) && (EEPROM_ReadFromEEPROM() >35 ) )
    {
        // do not change value 
    }
    else
    {
        EEPROM_WriteToEEPROM(TEMP_INIT) ;
    }
    
    u8_Temp_Set = EEPROM_ReadFromEEPROM() ;
     ON_OFF_Status = OFF_STATE ; 
     ON_OFF_Flag = _RESET ;
     Set_Temp_Flag = _RESET ;
     TempChange_Status = _RESET ; 
}

/*----------------------------------------------------------------------------*/

void System_Power (void)
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
}

/*----------------------------------------------------------------------------*/

void ON_Mode (void) 
{     
    ON_OFF_Status = ON_STATE ; 
    
    vid_7_Segment_Display_2Digits(u8_Water_Temp) ;
        
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
            vid_7_Segment_Display_2Digits(u8_Temp_Set) ;
            vid_7_Segment_DeInit() ;
            __delay_ms(1000) ;
            
            if (TempChange_Status == _SET)
            {
                count = 0 ; 
                TempChange_Status = _RESET ; 
            }
        }
        Set_Temp_Flag = _RESET  ; 
        
        EEPROM_WriteToEEPROM(u8_Temp_Set) ;
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

/*----------------------------------------------------------------------------*/

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
                if ( u8_Temp_Set <75 )
                {
                    u8_Temp_Set += 5 ;
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
            
            SetTemp_Mode();
            
}

/*----------------------------------------------------------------------------*/

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
                if (u8_Temp_Set > 35 )
                {
                   u8_Temp_Set -= 5 ;
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
    SetTemp_Mode();
}

/******************************* Fan Module ***********************************/
/*----------------------------------------------------------------------------*/

void Cooler_Init (void) 
{
    DIO_SetPinDirection ( PORTC_DIO , FAN , OUTPUT ) ;
    DIO_SetPinValue     ( PORTC_DIO , FAN , LOW ) ;

}

/*----------------------------------------------------------------------------*/
void Cooler_TurnOn  (void) 
{
    DIO_SetPinValue ( PORTC_DIO , FAN , HIGH ) ;
}

/*----------------------------------------------------------------------------*/

void Cooler_TurnOff (void) 
{
    DIO_SetPinValue     ( PORTC_DIO , FAN , LOW ) ;
}

/*----------------------------------------------------------------------------*/
/******************************************************************************/

/******************************* Heater Module ********************************/
/*----------------------------------------------------------------------------*/

void Heater_Init (void) 
{
    DIO_SetPinDirection ( PORTC_DIO , HEATER , OUTPUT ) ;
    DIO_SetPinValue     ( PORTC_DIO , HEATER , LOW ) ;

}

/*----------------------------------------------------------------------------*/
void Heater_TurnOn  (void) 
{
    DIO_SetPinValue ( PORTC_DIO , HEATER , HIGH ) ;
}

/*----------------------------------------------------------------------------*/

void Heater_TurnOff (void) 
{
    DIO_SetPinValue     ( PORTC_DIO , HEATER , LOW ) ;
}

/*----------------------------------------------------------------------------*/
/******************************************************************************/

/********************************* ADC Module *********************************/

void TempSensor_Init (void) 
{
    DIO_SetPinDirection(PORTA_DIO , 2 , INPUT );
    ADC_Init() ;    
}

/*----------------------------------------------------------------------------*/

void Temp_ControlWaterTemp (void) 
{
    
    u8 iterator = 0 ;
    u8 u8_Temp_Avg = 0 ; 
    
    if (ON_OFF_Status == ON_STATE)
    {
        
    u16_ADC_Read = ADC_Read(LM35);
    u16_Voltage = ((u16_ADC_Read * 5000UL) /1024UL ) ;
    u8_Water_Temp = (u8) (u16_Voltage / 10 ); 
    
    vid_7_Segment_Display_2Digits(u8_Water_Temp) ;

           
    u8_arr_Temp[u8_Counter] = u8_Water_Temp ;
    u8_Counter ++ ; 
    
    if (u8_Counter == 10 )
    {
        u8_Counter = 0 ;
        // get the average of the last 10 measurements
        for ( iterator = 0 ; iterator < 10 ; iterator ++  )
        {
            // add all the elements of the temperature array 
            u8_Temp_Avg = u8_Temp_Avg + u8_arr_Temp[iterator] ;
        }
        // devide the summation by 10 to get the average temp 
        u8_Temp_Avg = u8_Temp_Avg / 10 ; 
        
        // control the heater and the cooler based on the average temp
        if ( (u8_Temp_Avg - u8_Temp_Set ) >= 5)
        {
             Cooler_TurnOn() ;
             Heater_TurnOff() ;
        }
        else if ( ( u8_Temp_Set - u8_Temp_Avg) >=5 )
        {
             Heater_TurnOn() ;
             Cooler_TurnOff() ;
        }
        else          // (u8_Water_Temp == u8_Temp_Set)
        {
             Cooler_TurnOff() ;
             Heater_TurnOff() ; 
        } 
    }
    else
    {
        // wait until 10th measure 
    }
    
    

            vid_7_Segment_Display_2Digits(u8_Water_Temp) ;
    }
    else
    {
        // off state do not do anything 
    }
}

/******************************************************************************/
