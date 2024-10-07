/*
 * traffic.c
 *
 *  Created on: Oct 6, 2024
 *      Author: ADMINS
 */

#include "Traffic.h"

void doRedGreen_Traffic(void){
	HAL_GPIO_WritePin(LED13_RED_GPIO_Port, LED13_RED_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED24_GREEN_GPIO_Port, LED24_GREEN_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED13_GREEN_GPIO_Port, LED13_GREEN_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED13_YELLOW_GPIO_Port, LED13_YELLOW_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED24_RED_GPIO_Port, LED24_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED24_YELLOW_GPIO_Port, LED24_YELLOW_Pin, GPIO_PIN_RESET);
}

void doRedYellow_Traffic(void){
	HAL_GPIO_WritePin(LED24_GREEN_GPIO_Port, LED24_GREEN_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED24_YELLOW_GPIO_Port, LED24_YELLOW_Pin, GPIO_PIN_SET);
}

void doGreenRed_Traffic(void){
	HAL_GPIO_WritePin(LED13_RED_GPIO_Port, LED13_RED_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED24_YELLOW_GPIO_Port, LED24_YELLOW_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED24_RED_GPIO_Port, LED24_RED_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED13_GREEN_GPIO_Port, LED13_GREEN_Pin, GPIO_PIN_SET);
}

void doYellowRed_Traffic(void){
	HAL_GPIO_WritePin(LED13_GREEN_GPIO_Port, LED13_GREEN_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED13_YELLOW_GPIO_Port, LED13_YELLOW_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED24_RED_GPIO_Port, LED24_RED_Pin, GPIO_PIN_SET);
}
