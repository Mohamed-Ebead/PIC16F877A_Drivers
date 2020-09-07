/* 
 * File:   UART_Reg.h
 * Author: Mohamed  Ebead
 *
 * Created on July 20, 2020, 10:25 AM
 */

#ifndef UART_REG_H
#define	UART_REG_H


#define TXREG_REGISTER  (*((volatile u8*)0x19))
#define RCREG_REGISTER  (*((volatile u8*)0x1A))

#define SPBRG_REGISTER  (*((volatile u8*)0x99))

#define TXSTA_REGISTER  (*((volatile u8*)0x98))
#define TXSTA_CSRC_BIT  7
#define TXSTA_TX9_BIT   6
#define TXSTA_TXEN_BIT  5
#define TXSTA_SYNC_BIT  4
// 3 UNIMPLEMENTED 
#define TXSTA_BRGH_BIT  2
#define TXSTA_TRMT_BIT  1
#define TXSTA_TX9D_BIT  0



#define RCSTA_REGISTER  (*((volatile u8*)0x18))
#define RCSTA_SPEN_BIT    7
#define RCSTA_RX9_BIT     6
#define RCSTA_SREN_BIT    5
#define RCSTA_CREN_BIT    4
#define RCSTA_ADDEN_BIT   3
#define RCSTA_FERR_BIT    2
#define RCSTA_OERR_BIT    1
#define RCSTA_RX9D_BIT    0




#define PIE1_REGISTER    (*((volatile u8*)0x8C))
#define PIE1_RCIE_BIT      5

#define PIR1_REGISTER    (*((volatile u8*)0x0C))
#define PIR1_RCIF_BIT      5
#define PIR1_TXIF_BIT      4

#define INTCON_REGISTER  (*((volatile u8*)0x0B))
#define INTCON_GIE_BIT     7
#define INTCON_PEIE_BIT    6








#endif	/* UART_REG_H */

