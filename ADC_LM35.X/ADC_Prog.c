
// shared libraries 
#include "std_types.h"
#include "Bit_Logic.h"
#include <xc.h>

// HAL
#include "ADC_Reg.h"

#define _XTAL_FREQ 8000000 

void ADC_Init (void) 
{
    /* Turn ADC ON 
     * Select AN0 Channel 
     * ADC clock = Fosc/8 
     */
    ADCCON0_REGISTER = 0x41 ; 
    
    /* All 8 channels are analog 
     * Result is right justified 
     */
    
    ADCCON1_REGISTER = 0x80 ; 
    
}

/*----------------------------------------------------------------------------*/

u16   ADC_Read (u8 u8_Channel) 
{
    if ((u8_Channel < 0) || (u8_Channel > 7) )
    {
       return 0 ;  
    }
    
  //  ADCCON0_REGISTER &= 0x11000101 ;  // clear channel selection bits 
    ADCCON0_REGISTER |= (u8_Channel <<3) ; // select the required channel 
    
    __delay_us(30) ;  // wait the aquisition time 
    
    SET_BIT(ADCCON0_REGISTER , 2 ) ; // set GO/DONe bit to start the conversion 
    
    while ( GET_BIT(ADCCON0_REGISTER , 2 )) ; // polling GO_DONE bit 
    
  return (u16)( (ADRESH_REGISTER << 8) + ADRESL_REGISTER ) ;
   
}

/*----------------------------------------------------------------------------*/
