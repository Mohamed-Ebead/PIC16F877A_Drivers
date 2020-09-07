/*
 * Sched_int.h
 *
 *  Created on: Jul 2, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef RTO_INT_H_
#define RTO_INT_H_



void RTO_Init(void) ;
void RTO_vid_CreateTask (u8 copy_u8Priority ,u16 copy_u16Priodicity ,u16 copy_u16FirstDelay ,void (*copy_pFn)(void) ) ;

#endif /* RTO_INT_H_ */
