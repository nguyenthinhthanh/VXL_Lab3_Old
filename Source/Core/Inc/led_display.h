/*
 * led_display.h
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"

extern int Led13_Count;
extern int Led24_Count;

void display7SEG_13(int number);

void display7SEG_24(int number);

void display7SEG_Time(int number);

#endif /* INC_LED_DISPLAY_H_ */
