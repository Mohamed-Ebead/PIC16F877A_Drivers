
// shared libraries
#include <xc.h>
#include "MCU_Config.h"
#include "std_types.h"

//MCAL
#include "_7_Segment_int.h"

//HAL
#include "DIO_Interface.h"
#include "ADC_int.h"


#define _XTAL_FREQ 8000000

#define ADC_CHANNEL 2


void main(void) 
{
    u16 u16_ADC_Read ; 
    u16 u16_Voltage ; 
    u8 u8_Temp ; 

    
    DIO_SetPinDirection(PORTA_DIO,ADC_CHANNEL,INPUT) ;
    ADC_Init();
    vid_7_Segment_Init() ; 
    
    
    while (1) 
    {
       u16_ADC_Read = ADC_Read(ADC_CHANNEL);
       
    
       u16_Voltage = ((u16_ADC_Read * 5000UL) /1024UL ) ;
       u8_Temp = (u8) (u16_Voltage / 10 ); 
              
       
       vid_7_Segment_Display_2Digits(u8_Temp) ;
      // __delay_ms(1000) ;
        
    }
    
    return;
}
