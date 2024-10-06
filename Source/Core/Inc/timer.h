/*
 * timer.h
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include "input_reading.h"

#define MAX_TIMER	4
#define DELAY_TIMER				0		/*1000ms for 7Seg*/
#define TRAFFIC_TIMER			1		/*For time in traffic*/
#define AUTO_INCREASE			2		/*500ms increase value*/
#define AUTO_MODE_CHANGE_TIMER	3		/*For 10s timer auto change mode*/

extern int TIMER_CYCLE;

extern int Timer_Counter[MAX_TIMER];
extern int Timer_Flag[MAX_TIMER];


int getTimerFlags(int index);

void setTimer(int index, int duration);

void runTimer(void);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* INC_TIMER_H_ */
