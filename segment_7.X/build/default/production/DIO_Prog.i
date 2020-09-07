# 1 "DIO_Prog.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "DIO_Prog.c" 2






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
# 7 "DIO_Prog.c" 2

# 1 "./Bit_Logic.h" 1
# 8 "DIO_Prog.c" 2


# 1 "./DIO_Interface.h" 1
# 39 "./DIO_Interface.h"
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);


void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);

void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal);
# 10 "DIO_Prog.c" 2

# 1 "./DIO_Reg.h" 1
# 11 "DIO_Prog.c" 2






void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy)
{

 if ((u8PortIdCopy <= 3) && (u8PinIdCopy <= 7))
 {
  if ( u8PinDirCopy == 1 )
  {

   switch (u8PortIdCopy)
   {
    case 0: ((*((volatile u8*)0x85))) &= ~(1 << (u8PinIdCopy)); break;
    case 1: ((*((volatile u8*)0x86))) &= ~(1 << (u8PinIdCopy)); break;
    case 2: ((*((volatile u8*)0x87))) &= ~(1 << (u8PinIdCopy)); break;
    case 3: ((*((volatile u8*)0x88))) &= ~(1 << (u8PinIdCopy)); break;
   }
  }

  else if ( u8PinDirCopy == 0 )
  {

   switch (u8PortIdCopy)
   {
    case 0: ((*((volatile u8*)0x85))) |= (1 << (u8PinIdCopy)); break;
    case 1: ((*((volatile u8*)0x86))) |= (1 << (u8PinIdCopy)); break;
    case 2: ((*((volatile u8*)0x87))) |= (1 << (u8PinIdCopy)); break;
    case 3: ((*((volatile u8*)0x88))) |= (1 << (u8PinIdCopy)); break;
   }
  }

  else
  {

  }
 }

 else
 {

 }
}




void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy)
{

 if ((u8PortIdCopy <= 3) && (u8PinIdCopy <= 7))
 {
  if (u8PinValCopy == 1)
  {

   switch (u8PortIdCopy)
   {
    case 0: ((*((volatile u8*)0x05))) |= (1 << (u8PinIdCopy)); break;
    case 1: ((*((volatile u8*)0x06))) |= (1 << (u8PinIdCopy)); break;
    case 2: ((*((volatile u8*)0x07))) |= (1 << (u8PinIdCopy)); break;
    case 3: ((*((volatile u8*)0x08))) |= (1 << (u8PinIdCopy)); break;
   }

  }

  else if (u8PinValCopy == 0)
  {

   switch (u8PortIdCopy)
   {
    case 0: ((*((volatile u8*)0x05))) &= ~(1 << (u8PinIdCopy)); break;
    case 1: ((*((volatile u8*)0x06))) &= ~(1 << (u8PinIdCopy)); break;
    case 2: ((*((volatile u8*)0x07))) &= ~(1 << (u8PinIdCopy)); break;
    case 3: ((*((volatile u8*)0x08))) &= ~(1 << (u8PinIdCopy)); break;
   }
  }

  else
  {

  }
 }

 else
 {

 }
}



u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{

 u8 u8ResultLocal;

 if ((u8PortIdCopy <= 3) && (u8PinIdCopy <= 7))
 {

  switch (u8PortIdCopy)
  {
   case 0: u8ResultLocal= ((((*((volatile u8*)0x05))) >> (u8PinIdCopy)) & 0x01); break;
   case 1: u8ResultLocal= ((((*((volatile u8*)0x06))) >> (u8PinIdCopy)) & 0x01); break;
   case 2: u8ResultLocal= ((((*((volatile u8*)0x07))) >> (u8PinIdCopy)) & 0x01); break;
   case 3: u8ResultLocal= ((((*((volatile u8*)0x08))) >> (u8PinIdCopy)) & 0x01); break;
  }
 }

 else
 {

  u8ResultLocal = 0xFF;
 }

 return u8ResultLocal;
}



void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir)
{

 switch (u8PortId)
 {
   case 0: (*((volatile u8*)0x85)) = u8PortDir; break;
   case 1: (*((volatile u8*)0x86)) = u8PortDir; break;
   case 2: (*((volatile u8*)0x87)) = u8PortDir; break;
   case 3: (*((volatile u8*)0x88)) = u8PortDir; break;
  default: break;
 }
}



void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal)
{

 switch (u8PortId)
 {
   case 0: (*((volatile u8*)0x05)) = u8PortVal; break;
   case 1: (*((volatile u8*)0x06)) = u8PortVal; break;
   case 2: (*((volatile u8*)0x07)) = u8PortVal; break;
   case 3: (*((volatile u8*)0x08)) = u8PortVal; break;
  default: break;
 }
}
