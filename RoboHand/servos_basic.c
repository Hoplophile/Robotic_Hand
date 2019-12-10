/*
 * finger_move.c
 *
 * Created: 05.12.2019 17:10:20
 *  Author: piotr
 */ 

#include "servos_basic.h"

// array of pins
uint8_t servo_pin[6] = {
	1<<3,	//0 - thumb
	1<<5,	//1 - index
	1<<6,	//2 - middle
	1<<1,	//3 - ring
	1<<2,	//4 - pinky
	1<<3	//5 - wrist
};

//current fingers positions
uint8_t servo_position[6] = {
	0,	//0 - thumb
	0,	//1 - index
	0,	//2 - middle
	0,	//3 - ring
	0,	//4 - pinky
	0	//5 - wrist
};

/* Servo_Go_To
*  Set PWM value for selected servo
*
*  servo:			number of servo to move
*  position:		value of timer for servo's PWM
*/
void Servo_Go_To(uint8_t servo, uint8_t position){
	
	switch(servo){
		case 0: {
			OCR2B = position;		//pin 3 position (0-255)
			break;
		}
		case 1: {
			OCR0B = position;		//pin 5 position (0-255)
			break;
		}
		case 2: {
			OCR0A = position;		//pin 6 position (0-255)
			break;
		}
		case 3: {
			OCR1A = position;		//pin 9 position (0-255)
			break;
		}
		case 4: {
			OCR1B = position;		//pin 10 position (0-255)
			break;
		}
		case 5: {
			OCR2A = position;		//pin 11 position (0-255)
			break;
		}
	}
	servo_position[servo] = position;
}

/* Finger_Move
*  Move finger by given percentage of full scale
*
*  finger:			number of given finger
*  percent_value:	percent of full move
*/
void Finger_Move(uint8_t finger, int16_t percent_value) {
	uint8_t position;
	uint8_t max, min;
	
	switch(finger){
		case 0:	{ //thumb
			max = THUMB_MAX;
			min = THUMB_MIN;
			break;
		}
		case 1:	{ //index
			max = INDEX_MAX;
			min = INDEX_MIN;
			break;
		}
		case 2:	{ //middle
			max = MIDDLE_MAX;
			min = MIDDLE_MIN;
			break;
		}
		case 3:	{ //ring
			max = RING_MAX;
			min = RING_MIN;
			break;
		}
		case 4:	{ //pinky
			max = PINKY_MAX;
			min = PINKY_MIN;
			break;
		}
		default: {
			min = 0;
			max = 0;
			break;
		}
	}
	position = servo_position[finger] + ((max - min) * percent_value / 100);
	position = (position > max) ? max : position;
	position = (position < min) ? min : position;
	Servo_Go_To(finger, position);	
}

/* Finger_Go_To
*  Move finger to given percentage of full scale
*
*  finger:			number of given finger
*  percent_value:	percent of full move
*/
void Finger_Go_To(uint8_t finger, uint8_t percent_value) {
	uint32_t position;
	
	switch(finger){
		case 0:	{ //thumb
			position = THUMB_MIN + ((THUMB_MAX - THUMB_MIN) * percent_value / 100);
			break;
		}
		case 1:	{ //index
			position = INDEX_MIN + ((INDEX_MAX - INDEX_MIN) * percent_value / 100);
			break;
		}
		case 2:	{ //middle
			position = MIDDLE_MIN + ((MIDDLE_MAX - MIDDLE_MIN) * percent_value / 100);
			break;
		}
		case 3:	{ //ring
			position = RING_MIN + ((RING_MAX - RING_MIN) * percent_value / 100);
			break;
		}
		case 4:	{ //pinky
			position = PINKY_MIN + ((PINKY_MAX - PINKY_MIN) * percent_value / 100);
			break;
		}
		default:
			position = 0;
			break;
	}
	Servo_Go_To(finger, (uint8_t)position);
}

/* Wrist_Go_To
*  Move wrist to given percentage of full scale
*
*  percent_value:	percent of full move
*/
void Wrist_Go_To(uint8_t percent_value){
	uint8_t position;

	position = WRIST_MIN + ((WRIST_MAX - WRIST_MIN) * percent_value / 100);
	Servo_Go_To(5, position);
}

/* Init_Servo_As_Output
*  Write bit to register to set servo as output
*
*  servo:		number of servo to set
*/
void Init_Servo_As_Output(uint8_t servo) {
	if(servo < 3){
		DDRD |= servo_pin[servo];
		} else {
		DDRB |= servo_pin[servo];
	}
}

/* Init_All_Servos_As_Outputs
*  Call Init_Servo_As_Output for all servos
*
*/
void Init_All_Servos_As_Outputs() {
	Init_Servo_As_Output(THUMB);
	Init_Servo_As_Output(INDEX);
	Init_Servo_As_Output(MIDDLE);
	Init_Servo_As_Output(RING);
	Init_Servo_As_Output(PINKY);
	Init_Servo_As_Output(WRIST);
}

/* Init_Timer0
*  Initialize Timer0 for Fast PWM on pins 5 and 6
*
*/
void Init_Timer0() {
	//		  tmr 8-bit					  | use pin 5    | use pin 6
	TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1) | (1 << COM0B1);
	
	//		  prescaler 1024
	TCCR0B |= (1 << CS02) | (1 << CS00);						//16Mhz / (1024 * 255) = 61Hz
}

/* Init_Timer1
*  Initialize Timer1 for Fast PWM on pins 9 and 10
*
*/
void Init_Timer1() {
	//		  tmr 8-bit    | use pin 9     | use pin 10
	TCCR1A |= (1 << WGM10) | (1 << COM1A1) | (1 << COM1B1);
	
	//		  tmr 8-bit    | prescaler 1024
	TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);			//16Mhz / (1024 * 255) = 61Hz
}

/* Init_Timer2
*  Initialize Timer2 for Fast PWM on pins 11 and 3
*
*/
void Init_Timer2() {
	//		  tmr 8-bit					  | use pin 11    | use pin 3
	TCCR2A |= (1 << WGM21) | (1 << WGM20) | (1 << COM2A1) | (1 << COM2B1);
	
	//		  prescaler 1024
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);			//16Mhz / (1024 * 255) = 61Hz
}

/* Init_All_Timers
*  Call all functions initializing timers for Fast PWMs
*
*/
void Init_All_Timers() {
	Init_Timer0();
	Init_Timer1();
	Init_Timer2();
}