/*
 * Robo_hand.c
 *
 * Created: 04.12.2019 21:49:52
 * Author : piotr
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "servos_basic.h"
#include "gestures.h"

int main(void){
	
	Init_All_Servos_As_Outputs();
	Init_All_Timers();
	
	//Servo_Go_To(THUMB, 12);
	//Servo_Go_To(INDEX, INDEX_MAX);
	//Servo_Go_To(MIDDLE, MIDDLE_MIN);
	//Servo_Go_To(RING, 20);
	//Servo_Go_To(PINKY, 21);
	
	//Servo_Go_To(WRIST, 250);
	//Finger_Go_To(THUMB, 20);
	//Finger_Go_To(INDEX, 50);
	//Finger_Go_To(MIDDLE, THUMB_MIN);
	//Finger_Go_To(RING, THUMB_MIN);
	//Finger_Go_To(PINKY, THUMB_MIN);
	Gesture_Rock();
	_delay_ms(3000);
	Gesture_Fuck();
	_delay_ms(3000);
	Gesture_Jumbo();
	_delay_ms(3000);
	Gesture_Fist();
	_delay_ms(3000);
	Gesture_Ok();
	_delay_ms(3000);
	
    while (1) {
		
    }
}