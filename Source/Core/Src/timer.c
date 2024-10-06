/*
 * timer.c
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */

#include "timer.h"


int TIMER_CYCLE = 10;

int Timer_Counter[MAX_TIMER];
int Timer_Flag[MAX_TIMER];


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
		if(Timer_Counter[i] <=0){
			Timer_Flag[i] = 1;
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2){
		button_reading();
	}
}
