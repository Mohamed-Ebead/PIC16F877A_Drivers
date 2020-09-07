# 1 "I2C_Prog.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "I2C_Prog.c" 2


# 1 "./Std_Types.h" 1
# 13 "./Std_Types.h"
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
# 3 "I2C_Prog.c" 2

# 1 "./Bit_Logic.h" 1
# 4 "I2C_Prog.c" 2




# 1 "./DIO_Interface.h" 1
# 39 "./DIO_Interface.h"
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);


void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);

void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal);
# 8 "I2C_Prog.c" 2

# 1 "./I2C_Register.h" 1
# 9 "I2C_Prog.c" 2

# 1 "./I2C_interface.h" 1
# 13 "./I2C_interface.h"
void I2C_Init (void) ;
void I2C_Hold (void) ;
void I2CBegin (void) ;
void I2C_RepeatedStart (void) ;

void I2C_End (void) ;
void I2C_Write (u8 u8_Data ) ;
u8 I2C_Read (u8 ack) ;
# 10 "I2C_Prog.c" 2






void I2C_Init (void)
{

    (*((volatile u8*)0x93)) = (20000000/(4*1000000)) - 1;

    (*((volatile u8*)0x14)) = 0b00101000 ;



    (*((volatile u8*)0x94)) = 0x00 ;

    DIO_SetPinDirection(2 , 3 , 0) ;
    DIO_SetPinDirection(2 , 4 , 0) ;

}



void I2C_Hold (void)
{

    while ( ((*((volatile u8*)0x94)) & 0x04) || ((*((volatile u8*)0x91)) & 0x1F)) ;
}



void I2CBegin (void)
{
     I2C_Hold() ;
    ((*((volatile u8*)0x91))) |= (1 << (0)) ;

}

void I2C_RepeatedStart (void)
{
         I2C_Hold() ;

     ((*((volatile u8*)0x91))) |= (1 << (1)) ;
}


void I2C_End (void)
{
   I2C_Hold() ;
   ((*((volatile u8*)0x91))) |= (1 << (2)) ;


}



void I2C_Write (u8 u8_Data )
{
    I2C_Hold();
    (*((volatile u8*)0x13)) = u8_Data ;
}




u8 I2C_Read (u8 ack)
{
    u8 u8_DataRead ;
    I2C_Hold() ;
    ((*((volatile u8*)0x91))) |= (1 << (3)) ;

    I2C_Hold() ;
    u8_DataRead = (*((volatile u8*)0x13)) ;

    I2C_Hold() ;

    if (ack)
    {
        ((*((volatile u8*)0x91))) |= (1 << (5));
    }
    else
    {
        ((*((volatile u8*)0x91))) &= ~(1 << (5));

    }

    ((*((volatile u8*)0x91))) |= (1 << (4)) ;

    return u8_DataRead ;
}
