/*
 * File:   EEPROM_Prog.c
 * Author: Mohamed  Ebead
 *
 * Created on July 7, 2020, 10:46 AM
 */

// shared libraries
#include "Std_Types.h"
#include "Bit_Logic.h"
#include <XC.h>

// MCAL

// HAL
#include "I2C_interface.h"
#include "I2C_Register.h"

//#define _XTAL_FREQ 20000000

#define EEPROM_ADDRESS 0xA0   // address as picsimlab ,last bit = 0 to write 


/*----------------------------------------------------------------------------*/

void EEPROM_WriteToEEPROM (u8 u8_Data) 
{
    I2CBegin() ;
    
    I2C_Write(EEPROM_ADDRESS) ;
    I2C_Write(0x00);
    I2C_Write(u8_Data);    
    I2C_End() ;
}

/*----------------------------------------------------------------------------*/

u8 EEPROM_ReadFromEEPROM (void) 
{
     u8 Data ; 
    
    I2CBegin() ;
    I2C_Write(EEPROM_ADDRESS);

    I2C_Write((u8)0x00);
    I2C_RepeatedStart();
    
    I2C_Write((EEPROM_ADDRESS)+1);

    Data = I2C_Read(0) ;
    
   I2C_End() ;
    
   return Data ;
}
