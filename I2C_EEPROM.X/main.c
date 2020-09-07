/*
 * File:   main.c
 * Author: Mohamed  Ebead
 *
 * Created on July 6, 2020, 3:58 PM
 */

//shared libraries 
#include "Std_Types.h"
#include "MCU_Config.h"
#include <xc.h>

// MCAL 
#include "EEPROM_int.h"
#include "DIO_Interface.h"

// HAL 
#include "I2C_interface.h"


#define _XTAL_FREQ 400000
//#define EEPROM_ADDRESS 0b10100000   // address as picsimlab ,last bit = 0 to write 


void main(void) {
    
  // DIO_SetPortDirection(PORTD_DIO ,0x00);
  //  DIO_SetPortValue(PORTD_DIO ,0x00 ) ;
    I2C_Init() ;
     __delay_ms(500);
     
     u8 arr[2] = {100,90} ;
    
//    u8 data  ; 
        
    while(1)
    {        
        EEPROM_WriteToEEPROM(0xFF) ;
         __delay_ms(1000);

/*
          data = EEPROM_ReadFromEEPROM();
         DIO_SetPortValue(PORTD_DIO ,data ) ;
          __delay_ms(1000);
          */
         
    }
    
    return;
}
