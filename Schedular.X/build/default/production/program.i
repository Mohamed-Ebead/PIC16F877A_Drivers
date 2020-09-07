# 1 "program.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "program.c" 2
# 10 "program.c"
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
# 10 "program.c" 2

# 1 "./Bit_Logic.h" 1
# 11 "program.c" 2


# 1 "./DIO_Interface.h" 1
# 39 "./DIO_Interface.h"
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);


void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);

void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal);
# 13 "program.c" 2

# 1 "./DIO_Reg.h" 1
# 14 "program.c" 2

# 1 "./config.h" 1
# 15 "program.c" 2




void vid_SystemInit (void)
{
 DIO_SetPinDirection (2, 0, 1);
 DIO_SetPinDirection (2, 1, 1);
 DIO_SetPinDirection (2, 2, 1);

}



void RedLed_TOG (void)
{
 ((*((volatile u8*)0x07))) ^= (1 << (0)) ;
}



void GreenLed_TOG (void)
{
 ((*((volatile u8*)0x07))) ^= (1 << (1)) ;

}



void YellowLed_TOG (void)
{
 ((*((volatile u8*)0x07))) ^= (1 << (2)) ;

}
