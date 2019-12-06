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
#define INDEX_MAX 3300
#define INDEX_MIN 1100

void Finger_Move(uint8_t, uint8_t);
void Finger_Go_To(uint8_t, uint8_t);
void Init_All_Servos_As_Outputs(void);
void Init_All_Timers(void);

#endif /* FINGER_BASIC_H_ */