/*
 * gestures.c
 *
 * Created: 09.12.2019 20:30:43
 *  Author: piotr
 */ 

#include "gestures.h"

void Gesture_Rock(){
	Finger_Go_To(THUMB, CLOSE);
	Finger_Go_To(INDEX, OPEN);
	Finger_Go_To(MIDDLE, CLOSE);
	Finger_Go_To(RING, CLOSE);
	Finger_Go_To(PINKY, OPEN);
}

void Gesture_Fuck(){
	Finger_Go_To(THUMB, CLOSE);
	Finger_Go_To(INDEX, CLOSE);
	Finger_Go_To(MIDDLE, OPEN);
	Finger_Go_To(RING, CLOSE);
	Finger_Go_To(PINKY, CLOSE);
}

void Gesture_Jumbo(){
	Finger_Go_To(THUMB, OPEN);
	Finger_Go_To(INDEX, CLOSE);
	Finger_Go_To(MIDDLE, CLOSE);
	Finger_Go_To(RING, CLOSE);
	Finger_Go_To(PINKY, OPEN);
}

void Gesture_Ok(){
	Finger_Go_To(THUMB, OPEN);
	Finger_Go_To(INDEX, CLOSE);
	Finger_Go_To(MIDDLE, CLOSE);
	Finger_Go_To(RING, CLOSE);
	Finger_Go_To(PINKY, CLOSE);
}

void Gesture_OpenHand(){
	Finger_Go_To(THUMB, OPEN);
	Finger_Go_To(INDEX, OPEN);
	Finger_Go_To(MIDDLE, OPEN);
	Finger_Go_To(RING, OPEN);
	Finger_Go_To(PINKY, OPEN);
}

void Gesture_Fist(){
	Finger_Go_To(THUMB, CLOSE);
	Finger_Go_To(INDEX, CLOSE);
	Finger_Go_To(MIDDLE, CLOSE);
	Finger_Go_To(RING, CLOSE);
	Finger_Go_To(PINKY, CLOSE);
}
