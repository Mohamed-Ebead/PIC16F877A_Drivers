/*
 * Sched_Prog.c
 *
 *  Created on: Jul 2, 2020
 *      Author: Mohamed  Ebead
 */

// shared libraries
#include "std_types.h"
#include "Bit_Logic.h"

// HAL

// MCAL
#include "Timer1_int.h"

// OS

#include "RTO_Private.h"
#include "RTO_Config.h"



// make an array of structures to hold your tasks data

Task_TCB Tasks[RTO_MAX_NB_OF_TASKS] ;

void RTO_Init(void)
{
	Timer_SetCallBack(&RTO_vid_StartSchedular) ;
}



/*------------------------------------------------------------------------------------------------------------------*/

void RTO_vid_CreateTask(u8 copy_u8Priority ,u16 copy_u16Priodicity ,u16 copy_u16FirstDelay ,void (*copy_pFn)(void) )
{
	// use priority as an index
	Tasks[copy_u8Priority].u16_Periocicity = copy_u16Priodicity ;
	Tasks[copy_u8Priority].u16_FirstDelay = copy_u16FirstDelay ;
	Tasks[copy_u8Priority].pFn = copy_pFn ;

}


/*------------------------------------------------------------------------------------------------------------------*/

static void RTO_vid_StartSchedular (void)
{
	u8 u8_TCB_Counter =0;
	for (u8_TCB_Counter = 0 ;u8_TCB_Counter<RTO_MAX_NB_OF_TASKS ; u8_TCB_Counter ++ )
	{
		if ( (Tasks[u8_TCB_Counter].u16_FirstDelay)== 0)
		{
			// Run Task
			Tasks[u8_TCB_Counter].pFn() ;

			// FirstDelay = Periocicity
			// periodicity determines how many steps until next call
			Tasks[u8_TCB_Counter].u16_FirstDelay = ( Tasks[u8_TCB_Counter].u16_Periocicity ) -1 ;


		}
		else
		{
			( Tasks[u8_TCB_Counter].u16_FirstDelay ) -- ;

		}

	}


}

/*------------------------------------------------------------------------------------------------------------------*/
