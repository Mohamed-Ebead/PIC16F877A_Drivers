/* 
 * File:   CallBacks.h
 * Author: Mohamed  Ebead
 *
 * Created on July 11, 2020, 11:39 AM
 */

#ifndef CALLBACKS_H
#define	CALLBACKS_H




// call backs
void Timer1_SetCallBack (void (*pFun) (void)) ;
void RB0_SetCallBack    (void (*pFun) (void)) ;
void RB4_SetCallBack    (void (*pFun) (void)) ;
void RB5_SetCallBack    (void (*pFun) (void)) ;

void RB0_Handler (void) ;
void RB4_Handler (void) ;
void RB5_Handler (void) ;





#endif	/* CALLBACKS_H */

