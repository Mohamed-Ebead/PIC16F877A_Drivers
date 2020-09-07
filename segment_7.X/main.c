/*
 * File:   main.c
 * Author: Mohamed  Ebead
 *
 * Created on June 29, 2020, 9:43 AM
 */

// shared libraries 
#include "config.h"
#include "std_types.h"

// MCAL  
#include "_7_Segment_int.h"





void main(void) {
    
    vid_7_Segment_Init () ;
    
    while(1)
    {
        vid_7_Segment_Display_2Digits (35 ) ;
        vid_7_Segment_Display_2Digits (40 ) ;
        vid_7_Segment_Display_2Digits (45 ) ;
        vid_7_Segment_Display_2Digits (50 ) ;
   // vid_7_Segment_UpCounter();    
    }
    
    return;
}

