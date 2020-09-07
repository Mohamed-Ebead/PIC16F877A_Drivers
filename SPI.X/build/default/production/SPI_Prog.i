# 1 "SPI_Prog.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "SPI_Prog.c" 2








# 1 "./Std_Types.h" 1
# 12 "./Std_Types.h"
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
# 9 "SPI_Prog.c" 2

# 1 "./Bit_Logic.h" 1
# 10 "SPI_Prog.c" 2




# 1 "./SPI_Reg.h" 1
# 14 "SPI_Prog.c" 2

# 1 "./DIO_Interface.h" 1
# 37 "./DIO_Interface.h"
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);


void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);

void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal);
# 15 "SPI_Prog.c" 2


extern u8 u8_DataRead ;


void SPI_MasterInit (void)
{


    ((*((volatile u8*)0x14))) &= ~(1 << (0)) ;
    ((*((volatile u8*)0x14))) &= ~(1 << (1)) ;
    ((*((volatile u8*)0x14))) &= ~(1 << (2)) ;
    ((*((volatile u8*)0x14))) &= ~(1 << (3)) ;


    ((*((volatile u8*)0x14))) |= (1 << (5)) ;


    ((*((volatile u8*)0x94))) &= ~(1 << (6)) ;
    ((*((volatile u8*)0x14))) &= ~(1 << (4)) ;


    ((*((volatile u8*)0x94))) &= ~(1 << (7)) ;


    DIO_SetPinDirection(2,5,1) ;
    DIO_SetPinDirection(2,4,0) ;
    DIO_SetPinDirection(2,3,1) ;


    ((*((volatile u8*)0x8C))) |= (1 << (3)) ;
    ((*((volatile u8*)0x0B))) |= (1 << (6)) ;
    ((*((volatile u8*)0x0B))) |= (1 << (7)) ;

}



void SPI_SlaveInit (void)
{


    ((*((volatile u8*)0x14))) &= ~(1 << (0)) ;
    ((*((volatile u8*)0x14))) &= ~(1 << (1)) ;
    ((*((volatile u8*)0x14))) |= (1 << (2)) ;
    ((*((volatile u8*)0x14))) &= ~(1 << (3)) ;


    ((*((volatile u8*)0x14))) |= (1 << (5)) ;


    ((*((volatile u8*)0x94))) &= ~(1 << (6)) ;
    ((*((volatile u8*)0x14))) &= ~(1 << (4)) ;


    ((*((volatile u8*)0x94))) &= ~(1 << (7)) ;


    DIO_SetPinDirection(2,5,1) ;
    DIO_SetPinDirection(2,4,0) ;
    DIO_SetPinDirection(2,3,0) ;


    ((*((volatile u8*)0x9F))) &= ~(1 << (3)) ;
    ((*((volatile u8*)0x9F))) |= (1 << (2)) ;
    ((*((volatile u8*)0x9F))) &= ~(1 << (1)) ;
    ((*((volatile u8*)0x9F))) &= ~(1 << (0)) ;

    DIO_SetPinDirection(0,5,0) ;


    ((*((volatile u8*)0x8C))) |= (1 << (3)) ;
    ((*((volatile u8*)0x0B))) |= (1 << (6)) ;
    ((*((volatile u8*)0x0B))) |= (1 << (7)) ;

}



void SPI_SendByte (u8 u8_Data)
{
    (*((volatile u8*)0x13)) = u8_Data ;


}



u8 SPI_RecieveByte (void)
{
    u8 u8_DataRead = 0 ;
    if (((((*((volatile u8*)0x94))) >> (0)) & 0x01))
    {
        u8_DataRead = (*((volatile u8*)0x13)) ;
        ((*((volatile u8*)0x94))) &= ~(1 << (0)) ;
        ((*((volatile u8*)0x0C))) &= ~(1 << (3)) ;
        ((*((volatile u8*)0x14))) &= ~(1 << (6)) ;
        return u8_DataRead ;
    }
}



void __attribute__((picinterrupt(("")))) ISR (void)
{
    if ( ((((*((volatile u8*)0x0C))) >> (3)) & 0x01) )
    {
        u8_DataRead = (*((volatile u8*)0x13)) ;
        ((*((volatile u8*)0x0C))) &= ~(1 << (3)) ;
    }
    else
    {

    }

}
