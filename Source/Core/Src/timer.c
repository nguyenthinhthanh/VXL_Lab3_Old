/*
 * timer.c
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */

#include "timer.h"

int TIMER_CYCLE = 10;
int COUNTER		= 9;
int PRESCALER	= 7999;

int Timer_Counter[MAX_TIMER];
int Timer_Flag[MAX_TIMER];

// Cycle in ms
/*void changeTimerCycle(int cycle){
	COUNTER = ((FREQUENCY * cycle) / ((PRESCALER + 1)*1000)) - 1;

	//__HAL_TIM_SET_PRESCALER(&htim2,PRESCALER);
	__HAL_TIM_SET_COUNTER(&htim2,COUNTER);
	TIMER_CYCLE = cycle;
}*/

int getTimerFlags(int index){
	return Timer_Flag[index];
}

void setTimer(int index, int duration){
	Timer_Counter[index] = duration/TIMER_CYCLE;
	Timer_Flag[index] = 0;
}

void runTimer(void){
	for(int i=0;i<MAX_TIMER;i++){
		Timer_Counter[i]--;
		if(Timer_Counter[i] <= 0){
			Timer_Flag[i] = 1;
		}
	}
}


