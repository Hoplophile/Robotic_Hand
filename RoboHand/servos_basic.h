/*
 * finger_basic.h
 *
 * Created: 05.12.2019 17:42:55
 *  Author: piotr
 */ 

#ifndef FINGER_BASIC_H_
#define FINGER_BASIC_H_

#include <avr/io.h>

// finger numbers
#define THUMB 0
#define INDEX 1
#define MIDDLE 2
#define RING 3
#define PINKY 4
#define WRIST 5

// MAX AND MIN VALUES
#define THUMB_MIN 7
#define THUMB_MAX 21
#define INDEX_MIN 7
#define INDEX_MAX 20
#define MIDDLE_MIN 6
#define MIDDLE_MAX 20
#define RING_MIN 7
#define RING_MAX 22
#define PINKY_MIN 8
#define PINKY_MAX 21
#define WRIST_MIN 0
#define WRIST_MAX 0

void Servo_Go_To(uint8_t, uint8_t);
void Finger_Move(uint8_t, int16_t);
void Finger_Go_To(uint8_t, uint8_t);
void Wrist_Go_To(uint8_t);
void Init_All_Servos_As_Outputs(void);
void Init_All_Timers(void);

#endif /* FINGER_BASIC_H_ */