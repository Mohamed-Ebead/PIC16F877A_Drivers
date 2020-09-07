/*
 * program.c
 *
 *  Created on: Apr 13, 2020
 *      Author: Mohamed  Ebead
 */



#include "std_types.h"
#include "Bit_Logic.h"

#include "DIO_Interface.h"
#include "DIO_Reg.h"
#include "config.h"

/***--------------------------------------------------------------***/

void vid_SystemInit (void)
{
	DIO_SetPinDirection (PORTC_DIO, RED_LED, OUTPUT);
	DIO_SetPinDirection (PORTC_DIO, GREEN_LED, OUTPUT);
	DIO_SetPinDirection (PORTC_DIO, YELLOW_LED, OUTPUT);

}

/***--------------------------------------------------------------***/

void RedLed_TOG (void)
{
	TOG_BIT(PORTC_Register,RED_LED) ;
}

/***--------------------------------------------------------------***/

void GreenLed_TOG (void)
{
	TOG_BIT(PORTC_Register,GREEN_LED) ;

}

/***--------------------------------------------------------------***/

void YellowLed_TOG (void)
{
	TOG_BIT(PORTC_Register,YELLOW_LED) ;

}

/***--------------------------------------------------------------***/








