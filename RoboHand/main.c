/*
 * Robo_hand.c
 *
 * Created: 04.12.2019 21:49:52
 * Author : piotr
 */ 

#include <util/delay.h>

#define F_CPU 16000000UL
#include "servos_basic.h"

int main(void){
	
	Init_All_Servos_As_Outputs();
	Init_All_Timers();
	
	Finger_Go_To(THUMB, 15);
	Finger_Go_To(INDEX, 19);
    while (1) {
		
    }
}




//
//int main(void){
	//
	//Init_All_Servos();
	//TCCR1A |= (1 << WGM11) | (1 << COM1B1);
	//TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11);
	//ICR1 = 24999;
	//
	//
	//while (1){
		//while(1) {
			//OCR1A = 1100;
//
			////_delay_ms(5000);
			////
			////OCR1A = 1199;
			////
			////_delay_ms(5000);
		//}
		//
	//}
//}