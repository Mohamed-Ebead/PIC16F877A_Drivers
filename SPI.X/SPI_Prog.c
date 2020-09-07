/* 
 * File:   UART_Reg.h
 * Author: Mohamed  Ebead
 *
 * Created on July 20, 2020, 10:25 AM
 */

// shared libraries
#include "Std_Types.h"
#include "Bit_Logic.h"


// HAL
#include "SPI_Reg.h"
#include "DIO_Interface.h"

extern u8 u8_DataRead ; 


void SPI_MasterInit  (void) 
{
    //Set The SPI Mode (to Master), and Set the desired Clock Rate
    // Set Spi Mode To Master + Set SCK Rate To Fosc/64
    CLR_BIT (SSPCON1_REGISTER , SSPCON1_SSPM0_BIT) ; 
    CLR_BIT (SSPCON1_REGISTER , SSPCON1_SSPM1_BIT) ; 
    CLR_BIT (SSPCON1_REGISTER , SSPCON1_SSPM2_BIT) ; 
    CLR_BIT (SSPCON1_REGISTER , SSPCON1_SSPM3_BIT) ; 

    // Enable The Synchronous Serial Port
    SET_BIT (SSPCON1_REGISTER , SSPCON1_SSPEN_BIT) ;
    
   //Configure the Serial Clock Polarity & Phase         
    CLR_BIT (SSPSTAT_REGISTER , SSPSTAT_CKE_BIT) ;       
    CLR_BIT (SSPCON1_REGISTER , SSPCON1_CKP_BIT) ; 
    
   // Configure when the input data is sampled    
    CLR_BIT(SSPSTAT_REGISTER,SSPSTAT_SMP_BIT) ;
    
    // Configure the IO pins For SPI Master Mode
    DIO_SetPinDirection(PORTC_DIO,PIN5,OUTPUT) ;  // SDO -> Output
    DIO_SetPinDirection(PORTC_DIO,PIN4,INPUT)  ;  // SDI -> Input
    DIO_SetPinDirection(PORTC_DIO,PIN3,OUTPUT) ;  // SCK -> Output
    
    // Enable SPI Transmission Interrupts (if needed)
    SET_BIT(PIE1_REGISTER , PIE1_SSPIE_BIT) ;
    SET_BIT(INTCON_REGISTER , INTCON_PEIE_BIT) ;  // Peripherals Interrupt Enable Bit
    SET_BIT(INTCON_REGISTER , INTCON_GIE_BIT)  ;  // Global Interrupt Enable Bit
    
}

/*----------------------------------------------------------------------------*/

void SPI_SlaveInit   (void) 
{
    //Set The SPI Mode (to Slave + SS Enabled)
    // // Set SPI Mode To Slave + SS Enabled 
    CLR_BIT (SSPCON1_REGISTER , SSPCON1_SSPM0_BIT) ; 
    CLR_BIT (SSPCON1_REGISTER , SSPCON1_SSPM1_BIT) ; 
    SET_BIT (SSPCON1_REGISTER , SSPCON1_SSPM2_BIT) ; 
    CLR_BIT (SSPCON1_REGISTER , SSPCON1_SSPM3_BIT) ; 

    // Enable The Synchronous Serial Port
    SET_BIT (SSPCON1_REGISTER , SSPCON1_SSPEN_BIT) ;
    
   //Configure the Serial Clock Polarity & Phase         
    CLR_BIT (SSPSTAT_REGISTER , SSPSTAT_CKE_BIT) ;       
    CLR_BIT (SSPCON1_REGISTER , SSPCON1_CKP_BIT) ; 
    
   // Configure when the input data is sampled    
    CLR_BIT(SSPSTAT_REGISTER,SSPSTAT_SMP_BIT) ;
    
    // Configure the IO pins For SPI Master Mode
    DIO_SetPinDirection(PORTC_DIO,PIN5,OUTPUT) ;  // SDO -> Output
    DIO_SetPinDirection(PORTC_DIO,PIN4,INPUT)  ;  // SDI -> Input
    DIO_SetPinDirection(PORTC_DIO,PIN3,INPUT) ;   // SCK -> INPUT
    
    // Set SS (RA5/AN4) To Be Digital IO
    CLR_BIT(ADCON1_REGISTER,ADCON1_PCFG3_BIT) ;
    SET_BIT(ADCON1_REGISTER,ADCON1_PCFG2_BIT) ;
    CLR_BIT(ADCON1_REGISTER,ADCON1_PCFG1_BIT) ;
    CLR_BIT(ADCON1_REGISTER,ADCON1_PCFG0_BIT) ;
    
    DIO_SetPinDirection(PORTA_DIO,PIN5,INPUT) ; // SS -> Input
    
    // Enable SPI Transmission Interrupts (if needed)
    SET_BIT(PIE1_REGISTER , PIE1_SSPIE_BIT) ;
    SET_BIT(INTCON_REGISTER , INTCON_PEIE_BIT) ;  // Peripherals Interrupt Enable Bit
    SET_BIT(INTCON_REGISTER , INTCON_GIE_BIT)  ;  // Global Interrupt Enable Bit
    
} 

/*----------------------------------------------------------------------------*/

void SPI_SendByte    (u8 u8_Data) 
{
    SSPBUF_REGISTER = u8_Data ;
   // incase of non interrupt mode 
   // while (!(GET_BIT(SSPSTAT_REGISTER,SSPSTAT_BF_BIT))) ;
}

/*----------------------------------------------------------------------------*/

u8   SPI_RecieveByte (void) 
{
    u8 u8_DataRead = 0 ; 
    if (GET_BIT(SSPSTAT_REGISTER,SSPSTAT_BF_BIT))
    {
        u8_DataRead = SSPBUF_REGISTER ;
        CLR_BIT(SSPSTAT_REGISTER,SSPSTAT_BF_BIT) ;
        CLR_BIT(PIR1_REGISTER,PIR1_SSPIF) ;
        CLR_BIT(SSPCON1_REGISTER,SSPCON1_SSPOV_BIT) ;
        return u8_DataRead ;
    }
}

/*----------------------------------------------------------------------------*/

void __interrupt () ISR (void) 
{
    if ( GET_BIT(PIR1_REGISTER,PIR1_SSPIF) )
    {
        u8_DataRead = SSPBUF_REGISTER ; 
        CLR_BIT(PIR1_REGISTER,PIR1_SSPIF) ;
    }
    else
    {
        
    }

}

/*----------------------------------------------------------------------------*/