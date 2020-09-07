# 1 "RTO_Prog.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "RTO_Prog.c" 2








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
# 9 "RTO_Prog.c" 2

# 1 "./Bit_Logic.h" 1
# 10 "RTO_Prog.c" 2





# 1 "./Timer1_int.h" 1
# 13 "./Timer1_int.h"
void Timer1_Init_Comp (void) ;


void Timer_SetCallBack (void (*local_pFn)(void)) ;
# 15 "RTO_Prog.c" 2




# 1 "./RTO_Private.h" 1
# 11 "./RTO_Private.h"
typedef struct
{
 u16 u16_Periocicity ;
 u16 u16_FirstDelay ;

 void (*pFn) (void) ;

}Task_TCB;


static void RTO_vid_StartSchedular (void) ;
# 19 "RTO_Prog.c" 2

# 1 "./RTO_Config.h" 1
# 20 "RTO_Prog.c" 2






Task_TCB Tasks[3] ;

void RTO_Init(void)
{
 Timer_SetCallBack(&RTO_vid_StartSchedular) ;
}





void RTO_vid_CreateTask(u8 copy_u8Priority ,u16 copy_u16Priodicity ,u16 copy_u16FirstDelay ,void (*copy_pFn)(void) )
{

 Tasks[copy_u8Priority].u16_Periocicity = copy_u16Priodicity ;
 Tasks[copy_u8Priority].u16_FirstDelay = copy_u16FirstDelay ;
 Tasks[copy_u8Priority].pFn = copy_pFn ;

}




static void RTO_vid_StartSchedular (void)
{
 u8 u8_TCB_Counter =0;
 for (u8_TCB_Counter = 0 ;u8_TCB_Counter<3 ; u8_TCB_Counter ++ )
 {
  if ( (Tasks[u8_TCB_Counter].u16_FirstDelay)== 0)
  {

   Tasks[u8_TCB_Counter].pFn() ;



   Tasks[u8_TCB_Counter].u16_FirstDelay = ( Tasks[u8_TCB_Counter].u16_Periocicity ) -1 ;


  }
  else
  {
   ( Tasks[u8_TCB_Counter].u16_FirstDelay ) -- ;

  }

 }


}
