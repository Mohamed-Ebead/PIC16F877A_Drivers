
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DIO_INTERFACE_H
#define	DIO_INTERFACE_H

#include "Std_Types.h"
/* Port Defines */
#define PORTA_DIO    0
#define PORTB_DIO    1
#define PORTC_DIO    2
#define PORTD_DIO    3

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Directions */
#define INPUT  0
#define OUTPUT 1

/* PIN Value Options */
#define HIGH   1
#define LOW    0

/* IO Pins */
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);

/* IO Ports */
void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);

void DIO_SetPortValue     (u8 u8PortId, u8 u8PortVal);


#endif	/* DIO_INTERFACE_H */

