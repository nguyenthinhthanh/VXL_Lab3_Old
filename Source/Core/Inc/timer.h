/*
 * timer.h
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

#define FREQUENCY				8000000	/*8Mhz frequencu*/

#define MAX_TIMER					2
#define DELAY_TIMER					0		/*1000ms for 7Seg*/
#define TRAFFIC_TIMER				1		/*For time in traffic*/
//#define AUTO_INCREASE				2		/*500ms increase value*/
//#define AUTO_MODE_CHANGE_TIMER	3		/*For 10s timer auto change mode*/

extern int TIMER_CYCLE;
extern int COUNTER;
extern int PRESCALER;

extern int Timer_Counter[MAX_TIMER];
extern int Timer_Flag[MAX_TIMER];

// Cycle in ms
void changeTimerCycle(int cycle);

int getTimerFlags(int index);

void setTimer(int index, int duration);

void runTimer(void);

#endif /* INC_TIMER_H_ */
