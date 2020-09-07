# 1 "EXT_INT_Prog.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "EXT_INT_Prog.c" 2







# 1 "./std_types.h" 1
# 13 "./std_types.h"
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
# 8 "EXT_INT_Prog.c" 2

# 1 "./Bit_Logic.h" 1
# 9 "EXT_INT_Prog.c" 2


# 1 "./DIO_Interface.h" 1
# 39 "./DIO_Interface.h"
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);


void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);

void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal);
# 11 "EXT_INT_Prog.c" 2

# 1 "./INT_Reg.h" 1
# 12 "EXT_INT_Prog.c" 2

# 1 "./DIO_Reg.h" 1
# 13 "EXT_INT_Prog.c" 2


void EXT_INT_Init (void)
{
    DIO_SetPinDirection ( 1 , 0 , 0 ) ;
    ((*((volatile u8*)0x81))) |= (1 << (6)) ;
    ((*((volatile u8*)0x0B))) |= (1 << (4)) ;
    ((*((volatile u8*)0x0B))) |= (1 << (7)) ;
}



void __attribute__((picinterrupt(("")))) ISR (void)
{
    if (((((*((volatile u8*)0x0B))) >> (1)) & 0x01))
    {
     ((*((volatile u8*)0x05))) ^= (1 << (0)) ;
     ((*((volatile u8*)0x0B))) &= ~(1 << (1)) ;
    }
}
