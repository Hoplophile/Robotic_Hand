/*
 * Robo_hand.c
 *
 * Created: 04.12.2019 21:49:52
 * Author : piotr
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "servos_basic.h"

int main(void){
	
	Init_All_Servos_As_Outputs();
	Init_All_Timers();
	
	Finger_Go_To(THUMB, THUMB_MIN);
	Finger_Go_To(INDEX, THUMB_MIN);
	Finger_Go_To(MIDDLE, THUMB_MIN);
	Finger_Go_To(RING, THUMB_MIN);
	Finger_Go_To(PINKY, THUMB_MIN);
	
    while (1) {
		
    }
}