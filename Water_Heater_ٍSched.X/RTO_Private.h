/*
 * Sched_Private.h
 *
 *  Created on: Jul 2, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef RTO_PRIVATE_H_
#define RTO_PRIVATE_H_

typedef struct
{
	u16 u16_Periocicity ;
	u16 u16_FirstDelay ;

	void (*pFn) (void) ;

}Task_TCB;


static void RTO_vid_StartSchedular (void) ;


#endif /* RTO_PRIVATE_H_ */
