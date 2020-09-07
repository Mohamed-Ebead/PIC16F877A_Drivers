/* 
 * File:   I2C_interface.h
 * Author: Mohamed  Ebead
 *
 * Created on July 6, 2020, 3:58 PM
 */

#ifndef I2C_INTERFACE_H
#define	I2C_INTERFACE_H


 
void I2C_Init  (void) ;
void I2C_Hold  (void) ;
void I2CBegin  (void) ;
void I2C_RepeatedStart (void) ;

void I2C_End   (void) ;
void I2C_Write (u8 u8_Data ) ;
u8 I2C_Read  (u8 ack) ;



#endif	/* I2C_INTERFACE_H */

