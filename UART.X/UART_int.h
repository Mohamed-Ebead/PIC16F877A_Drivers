/* 
 * File:   UART_int.h
 * Author: Mohamed  Ebead
 *
 * Created on July 20, 2020, 10:25 AM
 */

#ifndef UART_INT_H
#define	UART_INT_H


void UART_TransmitterInit  (void) ;
void UART_RecieverInit   (void) ;

void UART_SendByte    (u8 u8_Data) ;
u8   UART_RecieveByte (void) ;



#endif	/* UART_INT_H */

