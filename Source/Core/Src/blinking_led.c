/*
 * blinking_led.c
 *
 *  Created on: Oct 8, 2024
 *      Author: ADMINS
 */


#include "blinking_led.h"

/*1s time duration default*/
int Time_LedRed_Duration = 1;
int Time_LedYellow_Duration = 1;
int Time_LedGreen_Duration = 1;

void runBlinkingLed(void){
	/*If mode is 2,3,4*/
	if(FSM_State >= NORMAL_STATE_MODE_2 && FSM_State <= NORMAL_STATE_MODE_4){
		activeTimer(BLINKING_LED_RED_TIMER);
		activeTimer(BLINKING_LED_YELLOW_TIMER);
		activeTimer(BLINKING_LED_GREEN_TIMER);

		if(getTimerFlags(BLINKING_LED_RED_TIMER)){
			HAL_GPIO_TogglePin(LED13_RED_GPIO_Port, LED13_RED_Pin);
			HAL_GPIO_TogglePin(LED24_RED_GPIO_Port, LED24_GREEN_Pin);

			int Time_Blinking = (Time_LedRed_Duration * TIME_SCALER) / 2;

			setTimer(BLINKING_LED_RED_TIMER, Time_Blinking);
		}

		if(getTimerFlags(BLINKING_LED_YELLOW_TIMER)){
			HAL_GPIO_TogglePin(LED13_YELLOW_GPIO_Port, LED13_YELLOW_Pin);
			HAL_GPIO_TogglePin(LED24_YELLOW_GPIO_Port, LED24_YELLOW_Pin);

			int Time_Blinking = (Time_LedYellow_Duration * TIME_SCALER) / 2;

			setTimer(BLINKING_LED_YELLOW_TIMER, Time_Blinking);
		}

		if(getTimerFlags(BLINKING_LED_GREEN_TIMER)){
			HAL_GPIO_TogglePin(LED13_GREEN_GPIO_Port, LED13_GREEN_Pin);
			HAL_GPIO_TogglePin(LED24_GREEN_GPIO_Port, LED24_GREEN_Pin);

			int Time_Blinking = (Time_LedGreen_Duration * TIME_SCALER) / 2;

			setTimer(BLINKING_LED_GREEN_TIMER, Time_Blinking);
		}
	}
	else{
		ignoreTimer(BLINKING_LED_RED_TIMER);
		ignoreTimer(BLINKING_LED_YELLOW_TIMER);
		ignoreTimer(BLINKING_LED_GREEN_TIMER);
	}
}
