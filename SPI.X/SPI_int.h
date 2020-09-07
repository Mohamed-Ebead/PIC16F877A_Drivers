/* 
 * File:   UART_int.h
 * Author: Mohamed  Ebead
 *
 * Created on July 20, 2020, 10:25 AM
 */

#ifndef SPI_INT_H
#define	SPI_INT_H


void SPI_MasterInit  (void) ;
void SPI_SlaveInit   (void) ;

void SPI_SendByte    (u8 u8_Data) ;
u8   SPI_RecieveByte (void) ;



#endif	/* SPI_INT_H */

