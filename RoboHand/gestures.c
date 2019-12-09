/*
 * gestures.c
 *
 * Created: 09.12.2019 20:30:43
 *  Author: piotr
 */ 

#include "gestures.h"

void Gesture_Rock(){
	Finger_Go_To(THUMB, THUMB_MAX);
	Finger_Go_To(INDEX, THUMB_MIN);
	Finger_Go_To(MIDDLE, THUMB_MAX);
	Finger_Go_To(RING, THUMB_MAX);
	Finger_Go_To(PINKY, THUMB_MIN);
}

void Gesture_Fuck(){
	Finger_Go_To(THUMB, THUMB_MIN);
	Finger_Go_To(INDEX, THUMB_MIN);
	Finger_Go_To(MIDDLE, THUMB_MAX);
	Finger_Go_To(RING, THUMB_MIN);
	Finger_Go_To(PINKY, THUMB_MIN);
}

void Gesture_Jumbo(){
	Finger_Go_To(THUMB, THUMB_MIN);
	Finger_Go_To(INDEX, THUMB_MAX);
	Finger_Go_To(MIDDLE, THUMB_MAX);
	Finger_Go_To(RING, THUMB_MAX);
	Finger_Go_To(PINKY, THUMB_MIN);
}

void Gesture_Ok(){
	Finger_Go_To(THUMB, THUMB_MIN);
	Finger_Go_To(INDEX, THUMB_MAX);
	Finger_Go_To(MIDDLE, THUMB_MAX);
	Finger_Go_To(RING, THUMB_MAX);
	Finger_Go_To(PINKY, THUMB_MAX);
}

void Gesture_OpenHand(){
	Finger_Go_To(THUMB, THUMB_MIN);
	Finger_Go_To(INDEX, THUMB_MIN);
	Finger_Go_To(MIDDLE, THUMB_MIN);
	Finger_Go_To(RING, THUMB_MIN);
	Finger_Go_To(PINKY, THUMB_MIN);
}

void Gesture_Fist(){
	Finger_Go_To(THUMB, THUMB_MAX);
	Finger_Go_To(INDEX, THUMB_MAX);
	Finger_Go_To(MIDDLE, THUMB_MAX);
	Finger_Go_To(RING, THUMB_MAX);
	Finger_Go_To(PINKY, THUMB_MAX);
}
