/* 
 * File:   UART_Reg.h
 * Author: Mohamed  Ebead
 *
 * Created on July 20, 2020, 10:25 AM
 */

#ifndef SPI_REG_H
#define	SPI_REG_H



#define SSPADD_REGISTER     (*((volatile u8*)0x93))

#define SSPSTAT_REGISTER    (*((volatile u8*)0x94))
#define SSPSTAT_SMP_BIT     7
#define SSPSTAT_CKE_BIT     6
#define SSPSTAT_BF_BIT      0


#define SSPCON1_REGISTER    (*((volatile u8*)0x14))
#define SSPCON1_SSPOV_BIT   6
#define SSPCON1_SSPEN_BIT   5
#define SSPCON1_CKP_BIT     4
#define SSPCON1_SSPM3_BIT   3
#define SSPCON1_SSPM2_BIT   2
#define SSPCON1_SSPM1_BIT   1
#define SSPCON1_SSPM0_BIT   0


#define PIE1_REGISTER    (*((volatile u8*)0x8C))
#define PIE1_SSPIE_BIT     3


#define SSPCON2_REGISTER    (*((volatile u8*)0x91))
#define SSPBUF_REGISTER     (*((volatile u8*)0x13))

#define PIR1_REGISTER       (*((volatile u8*)0x0C))
#define PIR1_SSPIF          3 

#define ADCON1_REGISTER   (*((volatile u8*)0x9F))
#define ADCON1_PCFG3_BIT       3
#define ADCON1_PCFG2_BIT       2
#define ADCON1_PCFG1_BIT       1
#define ADCON1_PCFG0_BIT       0

#define INTCON_REGISTER  (*((volatile u8*)0x0B))
#define INTCON_GIE_BIT     7
#define INTCON_PEIE_BIT    6



/*----------------------------------------------------------------------------*/





#endif	/* SPI_REG_H */

