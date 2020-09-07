
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#ifndef APP_INTERFACE_H
#define	APP_INTERFACE_H


/******************************* Fan Module ***********************************/
void Cooler_Init    (void) ;
void Cooler_TurnOn  (void) ;
void Cooler_TurnOff (void) ;
/******************************************************************************/

/******************************* Heater Module ********************************/
void Heater_Init    (void) ;
void Heater_TurnOn  (void) ;
void Heater_TurnOff (void) ;
/******************************************************************************/

/************************* External Interrupt Module **************************/

void SystemVars_Init (void) ;
void System_Power (void) ; 
void SetCallBacks (void) ;
void ON_Mode (void) ;
void OFF_Mode (void) ;
void SetTemp_Mode (void) ;

/******************************************************************************/

/********************************* ADC Module *********************************/

void TempSensor_Init (void) ;
void Temp_ControlWaterTemp (void) ;

/******************************************************************************/



#endif	/* APP_INTERFACE_H */

