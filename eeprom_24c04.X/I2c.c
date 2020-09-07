#include <xc.h>
#include "BIT_CALC.h"
#include "Bit_Logic.h"
#include "Typdefs.h"
#include "I2c.h"
#include"I2C_Register.h"
#include "DIO_Interface.h"
#include"Std_Types.h"


/*Initializes SDA and SCK pins direction and sets the appropriate bits in the
 *in the control registers as master                                                */
/*Initializes SDA and SCK pins direction and sets the appropriate bits in the
 *in the control registers as master                                                */
void I2C_init (void)
{
    
    SSPADD_REGISTER = (_XTAL_FREQ/(4*I2C_SPEED)) - 1;

    SSPCON1_REGISTER = 0b00101000 ;
   // SSPCON2_REGISTER = 0x00 ; 
    
  // SSPADD_REGISTER = ((_XTAL_FREQ/4000)/I2C_SPEED) - 1;
    SSPSTAT_REGISTER = 0x00 ;
    
    DIO_SetPinDirection(PORTC_DIO , SCL_BIT , INPUT) ;
    DIO_SetPinDirection(PORTC_DIO , SDA_BIT , INPUT) ;
    /*
//  SSPADD =  ((_XTAL_FREQ/4000)/clock) - 1;
   SSPADD = (_XTAL_FREQ/(4*clock))-1;  // here clock is the BR/clock speed    
    SSPCON = 0b00101000;     //first 4 bits I2c master mode , 6th bit is SSPEN enables the scl and sda line
    SSPSTAT = 0;
    TRISC3 = 1;
    TRISC4 = 1;*/
}
/*Stretch the I2c until operation is complete*/
void I2C_wait (void)
{
   // while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));    // wait for start bit to clear in SSPSTAT and bits 0 to 4 in SSPCON2
while ( (SSPSTAT_REGISTER & 0x04) || (SSPCON2_REGISTER & 0x1F)) ; 
}
/*Begin I2c protocol*/
void I2C_start (void)
{/*
    I2C_wait ();
    SSPCON2 |= 0x01; // SEN=1 -> initiate the START condition on SDA and SCL pins
*/
    I2C_wait() ;
    SET_BIT (SSPCON2_REGISTER , 0 ) ; // set SEN bit 
    

}
void I2C_repeated_start (void)
{
    I2C_wait();
    SSPCON2 |= 0x02; // RSEN=1  -> initiate REPEATED START condition on SDA and SCL pins
}
/*End I2c protocol*/
void I2C_stop (void)
{
    I2C_wait ();
   // SSPCON2 |= 0x04; // PEN=1 -> initiate the STOP condition on SDA and SCL pins
SET_BIT (SSPCON2_REGISTER , 2 ) ; // set PEN bit 
}
/*Writes a byte*/
void I2C_write (uint_8 data)
{
    I2C_wait ();
   // SSPBUF = data;  // load data into SSPBUF register
  SSPBUF_REGISTER = data ;
}
/*Reads a byte*/

/*
uint_8 I2C_read (uint_8 ack)
{
    uint_8 temp;
    I2C_wait();
    RCEN = 1;    // enable receive mode for I2c 
    I2C_wait();
    temp = SSPBUF;   // load data from Buffer to the temp
    I2C_wait();
    ACKDT = (ack);  // 0-- not ACK , 1-- ACK
    ACKEN = 1;   // Send Acknowledgement
    return temp;
}*/