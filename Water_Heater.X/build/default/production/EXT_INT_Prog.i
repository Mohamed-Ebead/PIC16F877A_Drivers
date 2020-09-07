# 1 "EXT_INT_Prog.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "EXT_INT_Prog.c" 2
# 10 "EXT_INT_Prog.c"
# 1 "./APP_config.h" 1
# 10 "EXT_INT_Prog.c" 2

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
# 11 "EXT_INT_Prog.c" 2

# 1 "./Bit_Logic.h" 1
# 12 "EXT_INT_Prog.c" 2


# 1 "./APP_Interface.h" 1
# 15 "./APP_Interface.h"
void Cooler_Init (void) ;
void Cooler_TurnOn (void) ;
void Cooler_TurnOff (void) ;



void Heater_Init (void) ;
void Heater_TurnOn (void) ;
void Heater_TurnOff (void) ;




void SystemVars_Init (void) ;
void System_Power (void) ;
void SetCallBacks (void) ;
void ON_Mode (void) ;
void OFF_Mode (void) ;
void SetTemp_Mode (void) ;





void TempSensor_Init (void) ;
void Temp_ControlWaterTemp (void) ;
# 14 "EXT_INT_Prog.c" 2



# 1 "./Interrupt_Config.h" 1
# 17 "EXT_INT_Prog.c" 2

# 1 "./_7_Segment_int.h" 1
# 14 "./_7_Segment_int.h"
void vid_7_Segment_Init (void) ;
void vid_7_Segment_DeInit (void) ;

void vid_Left_7_Segment_DisplayNumber (u8 u8_Number ) ;
void vid_Right_7_Segment_DisplayNumber (u8 u8_Number ) ;

void vid_7_Segment_UpCounter (void) ;

void vid_7_Segment_Display_2Digits (u8 u8_Num ) ;
# 18 "EXT_INT_Prog.c" 2



# 1 "./DIO_Interface.h" 1
# 39 "./DIO_Interface.h"
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);


void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);

void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal);
# 21 "EXT_INT_Prog.c" 2

# 1 "./INT_Reg.h" 1
# 22 "EXT_INT_Prog.c" 2

# 1 "./DIO_Reg.h" 1
# 23 "EXT_INT_Prog.c" 2





void (*GptrToFun_RB0) (void) ;
void (*GptrToFun_RB4) (void) ;
void (*GptrToFun_RB5) (void) ;






void RB0_SetCallBack (void (*pFun) (void))
{
    GptrToFun_RB0 = pFun ;
}


void RB4_SetCallBack (void (*pFun) (void))
{
    GptrToFun_RB4 = pFun ;
}


void RB5_SetCallBack (void (*pFun) (void))
{
    GptrToFun_RB5 = pFun ;
}




extern u8 State ;
extern u8 u8_Temp_Set ;
extern u8 ON_OFF_Flag ;
extern u8 ON_OFF_Status ;
extern u8 Set_Temp_Flag ;
extern u8 TempChange_Status ;



void EXT_INT_Init (void)
{
    DIO_SetPinDirection ( 1 , 0 , 0 ) ;
    DIO_SetPinDirection ( 1 , 4 , 0 ) ;
    DIO_SetPinDirection ( 1 , 5 , 0 ) ;

    ((*((volatile u8*)0x81))) &= ~(1 << (7)) ;

    ((*((volatile u8*)0x81))) &= ~(1 << (6)) ;
    ((*((volatile u8*)0x0B))) |= (1 << (4)) ;
    ((*((volatile u8*)0x0B))) |= (1 << (3)) ;
    ((*((volatile u8*)0x0B))) |= (1 << (7)) ;
}



void __attribute__((picinterrupt(("")))) ISR (void)
{

    if (((((*((volatile u8*)0x0B))) >> (1)) & 0x01))
    {
       GptrToFun_RB0 ();
       ((*((volatile u8*)0x0B))) &= ~(1 << (1)) ;

    }
    else if ( ((((*((volatile u8*)0x0B))) >> (0)) & 0x01) )
    {

        if ( ! DIO_GetPinValue(1,4) )
        {
            GptrToFun_RB4 () ;
        }

        else if ( ! DIO_GetPinValue(1,5) )
        {
            GptrToFun_RB5 () ;

        }
        else
        {

        }
        ((*((volatile u8*)0x0B))) &= ~(1 << (0)) ;

    }
    else
    {

    }
}
