# 1 "Timer1_Prog.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "Timer1_Prog.c" 2



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
# 4 "Timer1_Prog.c" 2

# 1 "./Bit_Logic.h" 1
# 5 "Timer1_Prog.c" 2



# 1 "./Timer1_Reg.h" 1
# 8 "Timer1_Prog.c" 2

# 1 "./DIO_Reg.h" 1
# 9 "Timer1_Prog.c" 2

# 1 "./DIO_Interface.h" 1
# 39 "./DIO_Interface.h"
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);


void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);

void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal);
# 10 "Timer1_Prog.c" 2




static void(*Global_pFn)(void) ;



void Timer1_Init_Comp (void)
{

    (*((volatile u8*)0x0E)) = 0 ;
    (*((volatile u8*)0x0F)) = 0 ;







    (*((volatile u8*)0x10)) = 0b00100001 ;





    (*((volatile u8*)0x17)) = 0b00001011 ;


    (*((volatile u16*)0x15)) = 1000 ;


    ((*((volatile u8*)0x8C))) |= (1 << (2)) ;


    ((*((volatile u8*)0x0B))) |= (1 << (6)) ;


    ((*((volatile u8*)0x0B))) |= (1 << (7)) ;

}



 void Timer_SetCallBack (void (*local_pFn)(void))
{
 Global_pFn = local_pFn ;

}



void __attribute__((picinterrupt(("")))) ISR (void)
{
    if (((((*((volatile u8*)0x0C))) >> (2)) & 0x01))
    {
        Global_pFn () ;
        ((*((volatile u8*)0x0C))) &= ~(1 << (2)) ;

    }
}
