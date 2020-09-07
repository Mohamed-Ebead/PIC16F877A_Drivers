# 1 "main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "main.c" 2








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
# 9 "main.c" 2



# 1 "./RTO_int.h" 1
# 13 "./RTO_int.h"
void RTO_Init(void) ;
void RTO_vid_CreateTask (u8 copy_u8Priority ,u16 copy_u16Priodicity ,u16 copy_u16FirstDelay ,void (*copy_pFn)(void) ) ;
# 12 "main.c" 2



# 1 "./Timer1_int.h" 1
# 13 "./Timer1_int.h"
void Timer1_Init_Comp (void) ;


void Timer_SetCallBack (void (*local_pFn)(void)) ;
# 15 "main.c" 2


# 1 "./interface.h" 1
# 13 "./interface.h"
void vid_SystemInit (void) ;


void RedLed_TOG (void);
void GreenLed_TOG (void);
void YellowLed_TOG (void);
# 17 "main.c" 2





int main (void)
{
 vid_SystemInit() ;
 RTO_Init() ;

 RTO_vid_CreateTask(0 ,3000 ,0 ,&RedLed_TOG ) ;
 RTO_vid_CreateTask(1 ,3000 ,1000 ,&GreenLed_TOG ) ;
 RTO_vid_CreateTask(2 ,3000 ,2000 ,&YellowLed_TOG ) ;


 Timer1_Init_Comp() ;


while(1) ;


return 0 ;
}
