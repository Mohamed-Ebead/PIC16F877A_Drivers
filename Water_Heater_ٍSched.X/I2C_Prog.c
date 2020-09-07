
// shared libraries
#include "Std_Types.h"
#include "Bit_Logic.h"


//HAL
#include "DIO_Interface.h"
#include "I2C_Register.h"
#include "I2C_interface.h"



/*----------------------------------------------------------------------------*/
 
void I2C_Init  (void) 
{
    
    SSPADD_REGISTER = (_XTAL_FREQ/(4*I2C_SPEED)) - 1;

    SSPCON1_REGISTER = 0b00101000 ;
   // SSPCON2_REGISTER = 0x00 ; 
    
  // SSPADD_REGISTER = ((_XTAL_FREQ/4000)/I2C_SPEED) - 1;
    SSPSTAT_REGISTER = 0x00 ;
    
    DIO_SetPinDirection(PORTC_DIO , SCL_BIT , INPUT) ;
    DIO_SetPinDirection(PORTC_DIO , SDA_BIT , INPUT) ;
    
}

/*----------------------------------------------------------------------------*/

void I2C_Hold  (void) 
{
 
    while ( (SSPSTAT_REGISTER & 0x04) || (SSPCON2_REGISTER & 0x1F)) ; 
}

/*----------------------------------------------------------------------------*/

void I2CBegin  (void) 
{
     I2C_Hold() ;
    SET_BIT (SSPCON2_REGISTER , 0 ) ; // set SEN bit 
    
}

void I2C_RepeatedStart (void)
{
         I2C_Hold() ;

     SET_BIT(SSPCON2_REGISTER , 1) ; // repeated start 
}
/*----------------------------------------------------------------------------*/

void I2C_End   (void) 
{
   I2C_Hold() ;
   SET_BIT (SSPCON2_REGISTER , 2 ) ; // set PEN bit 
    
    
}

/*----------------------------------------------------------------------------*/

void I2C_Write (u8 u8_Data ) 
{
    I2C_Hold();
    SSPBUF_REGISTER = u8_Data ;
}

/*----------------------------------------------------------------------------*/


u8 I2C_Read  (u8 ack) 
{
    u8 u8_DataRead ; 
    I2C_Hold() ;
    SET_BIT(SSPCON2_REGISTER , 3) ; // set RCEN bit recieve enable bit
    
    I2C_Hold() ;
    u8_DataRead = SSPBUF_REGISTER ;
    
    I2C_Hold() ;
    
    if (ack)
    {
        SET_BIT(SSPCON2_REGISTER , 5);  // ACKDT bit 
    }
    else
    {
        CLR_BIT(SSPCON2_REGISTER , 5);

    }
    
    SET_BIT(SSPCON2_REGISTER,4 ) ; // ack sequence enable bit 
    
    return u8_DataRead ;
}
