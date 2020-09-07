# 1 "UART_Prog.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "UART_Prog.c" 2








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
# 9 "UART_Prog.c" 2

# 1 "./Bit_Logic.h" 1
# 10 "UART_Prog.c" 2




# 1 "./UART_Reg.h" 1
# 14 "UART_Prog.c" 2

# 1 "./DIO_Interface.h" 1
# 37 "./DIO_Interface.h"
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);


void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);

void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal);
# 15 "UART_Prog.c" 2


 extern u8 u8_DataRead ;


void UART_TransmitterInit (void)
{
    ((*((volatile u8*)0x98))) |= (1 << (2)) ;
    (*((volatile u8*)0x99)) = 25 ;


    ((*((volatile u8*)0x98))) &= ~(1 << (4)) ;
    ((*((volatile u8*)0x18))) |= (1 << (7)) ;


    DIO_SetPinDirection(2 , 6 , 0) ;
    DIO_SetPinDirection(2 , 7 , 0) ;

    ((*((volatile u8*)0x98))) |= (1 << (5)) ;
}



void UART_RecieverInit (void)
{
    ((*((volatile u8*)0x98))) |= (1 << (2)) ;
    (*((volatile u8*)0x99)) = 25 ;


    ((*((volatile u8*)0x98))) &= ~(1 << (4)) ;
    ((*((volatile u8*)0x18))) |= (1 << (7)) ;


    DIO_SetPinDirection(2 , 6 , 0) ;
    DIO_SetPinDirection(2 , 7 , 0) ;


    ((*((volatile u8*)0x8C))) |= (1 << (5));
    ((*((volatile u8*)0x0B))) |= (1 << (6)) ;
    ((*((volatile u8*)0x0B))) |= (1 << (7)) ;

    ((*((volatile u8*)0x18))) |= (1 << (4)) ;
}



void UART_SendByte (u8 u8_Data)
{
    while (!(((((*((volatile u8*)0x98))) >> (1)) & 0x01))) ;
    (*((volatile u8*)0x19)) = u8_Data ;
}



u8 UART_RecieveByte (void)
{
    while (!(((((*((volatile u8*)0x0C))) >> (5)) & 0x01))) ;
    return (*((volatile u8*)0x1A)) ;
}



void __attribute__((picinterrupt(("")))) ISR (void)
{
    if ( ((((*((volatile u8*)0x0C))) >> (5)) & 0x01) )
    {
        u8_DataRead = (*((volatile u8*)0x1A)) ;
        ((*((volatile u8*)0x0C))) &= ~(1 << (5)) ;
    }
    else
    {

    }

}
