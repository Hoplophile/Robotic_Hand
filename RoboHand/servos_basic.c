/*
 * finger_move.c
 *
 * Created: 05.12.2019 17:10:20
 *  Author: piotr
 */ 

#include "servos_basic.h"

// array of pins
uint8_t finger_pin[6] = {
	1<<3,	//0 - thumb
	1<<5,	//1 - index
	1<<6,	//2 - middle
	1<<1,	//3 - ring
	1<<2,	//4 - pinky
	1<<3	//5 - wrist
};


void Finger_Move(uint8_t finger, uint8_t percent_value) {
	
}

void Finger_Go_To(uint8_t finger, uint8_t percent_value) {
	switch(finger){
		case 0:	{ //thumb
			OCR2B = percent_value;		//pin 3 position (0-255)
			break;
		}
		case 1:	{ //index
			OCR0A = percent_value;		//pin 5 position (0-255)
			break;
		}
		case 2:	{ //middle
			OCR0B = percent_value;		//pin 6 position (0-255)
			break;
		}
		case 3:	{ //ring
			OCR1A = percent_value;		//pin 9 position (0-255)
			break;
		}
		case 4:	{ //pinky
			OCR1B = percent_value;		//pin 10 position (0-255)
			break;
		}
		case 5:	{ //wrist
			OCR2A = percent_value;		//pin 11 position (0-255)
			break;
		}
	}
}


void Init_Servo_As_Output(uint8_t finger) {
	if(finger < 3){
		DDRD |= finger_pin[finger];
		} else {
		DDRB |= finger_pin[finger];
	}
}

void Init_All_Servos_As_Outputs() {
	Init_Servo_As_Output(THUMB);
	Init_Servo_As_Output(INDEX);
	Init_Servo_As_Output(MIDDLE);
	Init_Servo_As_Output(RING);
	Init_Servo_As_Output(PINKY);
	Init_Servo_As_Output(WRIST);
}


void Init_Timer0() {
	//		  tmr 8-bit					  | use pin 5    | use pin 6
	TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1) | (1 << COM0B1);
	
	//		  prescaler 1024
	TCCR0B |= (1 << CS02) | (1 << CS00);						//16Mhz / (1024 * 255) = 61Hz
}

void Init_Timer1() {
	//		  tmr 8-bit    | use pin 9     | use pin 10
	TCCR1A |= (1 << WGM10) | (1 << COM1A1) | (1 << COM1B1);
	
	//		  tmr 8-bit    | prescaler 1024
	TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);			//16Mhz / (1024 * 255) = 61Hz
}

void Init_Timer2() {
	//		  tmr 8-bit					  | use pin 11    | use pin 3
	TCCR2A |= (1 << WGM21) | (1 << WGM20) | (1 << COM2A1) | (1 << COM2B1);
	
	//		  prescaler 1024
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);			//16Mhz / (1024 * 255) = 61Hz
}

void Init_All_Timers() {
	Init_Timer0();
	Init_Timer1();
	Init_Timer2();
}