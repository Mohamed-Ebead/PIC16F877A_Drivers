/*
 * main.c
 *
 *  Created on: Apr 13, 2020
 *      Author: Mohamed  Ebead
 */

// shared libraries
#include "std_types.h"

// OS layer
#include "RTO_int.h"

// HAL
#include "Timer1_int.h"

#include "interface.h"




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

