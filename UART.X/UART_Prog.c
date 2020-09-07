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
#include "UART_Reg.h"
#include "DIO_Interface.h"

 extern u8 u8_DataRead ; 


void UART_TransmitterInit  (void) 
{
    SET_BIT(TXSTA_REGISTER,TXSTA_BRGH_BIT) ;// Set For High-Speed Baud Rate
    SPBRG_REGISTER = 25 ;  // Set The Baud Rate To Be 9600 bps
    
    // Enable The Asynchronous Serial Port
    CLR_BIT(TXSTA_REGISTER,TXSTA_SYNC_BIT) ;
    SET_BIT(RCSTA_REGISTER,RCSTA_SPEN_BIT) ;
    
    // Set The RX-TX Pins to be in UART mode 
    DIO_SetPinDirection(PORTC_DIO , PIN6 , INPUT) ;
    DIO_SetPinDirection(PORTC_DIO , PIN7 , INPUT) ;
  
    SET_BIT(TXSTA_REGISTER,TXSTA_TXEN_BIT) ; // Enable UART Transmission
}

/*----------------------------------------------------------------------------*/

void UART_RecieverInit   (void) 
{
    SET_BIT(TXSTA_REGISTER,TXSTA_BRGH_BIT) ;// Set For High-Speed Baud Rate
    SPBRG_REGISTER = 25 ;  // Set The Baud Rate To Be 9600 bps
    
    // Enable The Asynchronous Serial Port
    CLR_BIT(TXSTA_REGISTER,TXSTA_SYNC_BIT) ;
    SET_BIT(RCSTA_REGISTER,RCSTA_SPEN_BIT) ;
    
    // Set The RX-TX Pins to be in UART mode 
    DIO_SetPinDirection(PORTC_DIO , PIN6 , INPUT) ;
    DIO_SetPinDirection(PORTC_DIO , PIN7 , INPUT) ;
  
    //Setup UART Receiving Interrupt
    SET_BIT(PIE1_REGISTER,PIE1_RCIE_BIT);   // UART Receving Interrupt Enable Bit
    SET_BIT(INTCON_REGISTER , INTCON_PEIE_BIT) ;  // Peripherals Interrupt Enable Bit
    SET_BIT(INTCON_REGISTER , INTCON_GIE_BIT)  ;  // Global Interrupt Enable Bit
    
    SET_BIT(RCSTA_REGISTER,RCSTA_CREN_BIT) ;  // Enable Data Reception
} 

/*----------------------------------------------------------------------------*/

void UART_SendByte    (u8 u8_Data) 
{
    while (!(GET_BIT(TXSTA_REGISTER,TXSTA_TRMT_BIT))) ;
    TXREG_REGISTER = u8_Data ;
}

/*----------------------------------------------------------------------------*/

u8   UART_RecieveByte (void) 
{
    while (!(GET_BIT(PIR1_REGISTER,PIR1_RCIF_BIT))) ;
    return RCREG_REGISTER ; 
}

/*----------------------------------------------------------------------------*/

void __interrupt () ISR (void) 
{
    if ( GET_BIT(PIR1_REGISTER,PIR1_RCIF_BIT) )
    {
        u8_DataRead = RCREG_REGISTER ; 
        CLR_BIT(PIR1_REGISTER,PIR1_RCIF_BIT) ;
    }
    else
    {
        
    }
    
}
/*----------------------------------------------------------------------------*/