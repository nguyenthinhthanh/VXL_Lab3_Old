/*
 * timer.c
 *
 *  Created on: Oct 2, 2024
 *      Author: ADMINS
 */

#include "timer.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2){
		button_reading();
	}
}
