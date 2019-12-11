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
//#include "uart.h"

int main(void){
	
	Init_All_Servos_As_Outputs();
	Init_All_Timers();
	
    while (1) {
	    Gesture_Rock();
	    _delay_ms(3000);
	    Gesture_Jumbo();
	    _delay_ms(3000);
	    Gesture_Fist();
	    _delay_ms(3000);
	    Gesture_Ok();
	    _delay_ms(3000);
		
    }
}