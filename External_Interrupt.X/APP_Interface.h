
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#ifndef APP_INTERFACE_H
#define	APP_INTERFACE_H


void SystemVars_Init (void) ;

void ON_Mode (void) ;
void OFF_Mode (void) ;

void SetTemp_Mode (void) ;


u8 Check_ON_OFF_Flag (void) ;
u8 Check_SetTempMode_Flag (void) ;

#endif	/* APP_INTERFACE_H */

