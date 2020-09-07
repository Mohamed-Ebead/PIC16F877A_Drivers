
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  


/* Group A Registers */
#define PORTA_Register  (*((volatile u8*)0x05))
#define TRISA_Register  (*((volatile u8*)0x85))

/* Group B Registers */
#define PORTB_Register  (*((volatile u8*)0x06))
#define TRISB_Register  (*((volatile u8*)0x86))

/* Group C Registers */
#define PORTC_Register  (*((volatile u8*)0x07))
#define TRISC_Register  (*((volatile u8*)0x87))

/* Group D Registers */
#define PORTD_Register  (*((volatile u8*)0x08))
#define TRISD_Register  (*((volatile u8*)0x88))



#endif	/* XC_HEADER_TEMPLATE_H */

