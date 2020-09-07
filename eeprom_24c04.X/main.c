/*
 * File:   main.c
 * Author: Mohamed  Ebead
 *
 * Created on July 6, 2020, 3:58 PM
 */

//shared libraries 
#include "Std_Types.h"
#include "Typdefs.h"
#include "MCU_Config.h"
#include <xc.h>

// MCAL 
#include "EEPROM_I2c.h"
#include "DIO_Interface.h"

// HAL 
#include "I2c.h"


//#define _XTAL_FREQ 4000000
//#define EEPROM_ADDRESS 0b10100000   // address as picsimlab ,last bit = 0 to write 


void main(void) {
    
  // DIO_SetPortDirection(PORTD_DIO ,0x00);
  //  DIO_SetPortValue(PORTD_DIO ,0x00 ) ;
    I2C_init() ;
     __delay_ms(500);
     
     u8 arr[2] = {4,4} ;
    
//    u8 data  ; 
        
    while(1)
    {        
        EEPROM_Write(0x72) ;
         __delay_ms(1000);

/*
          data = EEPROM_ReadFromEEPROM();
         DIO_SetPortValue(PORTD_DIO ,data ) ;
          __delay_ms(1000);
          */
         
    }
    
    return;
}
