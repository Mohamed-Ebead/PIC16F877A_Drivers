/* 
 * File:   I2C_Register.h
 * Author: Mohamed  Ebead
 *
 * Created on July 6, 2020, 3:57 PM
 */

#ifndef I2C_REGISTER_H
#define	I2C_REGISTER_H

#define SSPADD_REGISTER     (*((volatile u8*)0x93))
#define SSPSTAT_REGISTER    (*((volatile u8*)0x94))
#define SSPCON1_REGISTER    (*((volatile u8*)0x14))
#define SSPCON2_REGISTER    (*((volatile u8*)0x91))
#define SSPBUF_REGISTER     (*((volatile u8*)0x13))

#define PIR1_REGISTER       (*((volatile u8*)0x0C))
#define PIR1_SSPIF          3 

#define TRISC_Register      (*((volatile u8*)0x87))

#define SCL_BIT  3
#define SDA_BIT  4


#define _XTAL_FREQ    20000000
#define I2C_SPEED     1000000


#endif	/* I2C_REGISTER_H */

