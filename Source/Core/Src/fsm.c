/*
 * fsm.c
 *
 *  Created on: Oct 6, 2024
 *      Author: ADMINS
 */

#include "fsm.h"

/*Default Mode*/
int FSM_State;

void setEnviromentStateInit(void){
	Led13_Count = 5;
	Led24_Count = 3;
	/*7Seg display immediate*/
	display7SEG_13(Led13_Count);
	display7SEG_24(Led24_Count);

	//setTimer(AUTO_INCREASE, 500);
	setEnviromentState0();
	FSM_State = RED_GREEN_STATE_MODE1;
}

void setEnviromentState0(void){
	Led13_Count = 5;
	Led24_Count = 3;
	setTimer(DELAY_TIMER, 1000);
	setTimer(TRAFFIC_TIMER, 3000);
}

void setEnviromentState1(void){
	Led24_Count = 2;
	setTimer(TRAFFIC_TIMER, 2000);
}
void setEnviromentState2(void){
	Led13_Count = 3;
	Led24_Count = 5;
	setTimer(TRAFFIC_TIMER, 3000);
}

void setEnviromentState3(void){
	Led13_Count = 2;
	setTimer(TRAFFIC_TIMER, 2000);
}

void setEnviromentState4(void){

}

void setEnviromentState5(void){

}

void setEnviromentState6(void){

}

void setEnviromentState7(void){

}

void setEnviromentState8(void){

}

void setEnviromentState9(void){

}

void doState0(void){
	doRedGreen_Traffic();

	if(getTimerFlags(DELAY_TIMER)){

		HAL_GPIO_WritePin(CHECK_GPIO_Port, CHECK_Pin, GPIO_PIN_RESET);
		display7SEG_13(Led13_Count);
		display7SEG_24(Led24_Count);


		Led13_Count--;
		Led24_Count--;

		setTimer(DELAY_TIMER, 1000);
	}
}

void doState1(void){
	doRedYellow_Traffic();

	if(getTimerFlags(DELAY_TIMER)){
		display7SEG_13(Led13_Count);
		display7SEG_24(Led24_Count);

		Led13_Count--;
		Led24_Count--;

		setTimer(DELAY_TIMER, 1000);
	}
}

void doState2(void){
	doGreenRed_Traffic();

	if(getTimerFlags(DELAY_TIMER)){
		display7SEG_13(Led13_Count);
		display7SEG_24(Led24_Count);

		Led13_Count--;
		Led24_Count--;

		setTimer(DELAY_TIMER, 1000);
	}
}

void doState3(void){
	doYellowRed_Traffic();

	if(getTimerFlags(DELAY_TIMER)){
		display7SEG_13(Led13_Count);
		display7SEG_24(Led24_Count);

		Led13_Count--;
		Led24_Count--;

		setTimer(DELAY_TIMER, 1000);
	}
}

void doState4(void){
	if(buttonState[1] == BUTTON_PRESSED){
		/*Increase time duration by one*/
		FSM_State = NORMAL_STATE_MODE_2;
	}

	if(buttonState[2] == BUTTON_PRESSED){
		/*Update blinking time duration*/
	}
}

void doState5(void){

}

void doState6(void){

}

void doState7(void){

}

void doState8(void){

}

void doState9(void){

}

void runFSM(void){
	switch(FSM_State){
	case RED_GREEN_STATE_MODE1:
		doState0();

		if(getTimerFlags(TRAFFIC_TIMER)){
			setEnviromentState1();
			FSM_State = RED_YELLOW_STATE_MODE1;
		}

		if(buttonState[0] == BUTTON_PRESSED){
			setEnviromentState4();	/*Mode 2*/
			FSM_State = NORMAL_STATE_MODE_2;
		}
		break;
	case RED_YELLOW_STATE_MODE1:
		doState1();

		if(getTimerFlags(TRAFFIC_TIMER)){
			setEnviromentState2();
			FSM_State = GREEN_RED_STATE_MODE1;
		}

		if(buttonState[0] == BUTTON_PRESSED){
			setEnviromentState4();	/*Mode 2*/
			FSM_State = NORMAL_STATE_MODE_2;
		}
		break;
	case GREEN_RED_STATE_MODE1:
		doState2();

		if(getTimerFlags(TRAFFIC_TIMER)){
			setEnviromentState3();
			FSM_State = YELLOW_RED_STATE_MODE1;
		}

		if(buttonState[0] == BUTTON_PRESSED){
			setEnviromentState4();	/*Mode 2*/
			FSM_State = NORMAL_STATE_MODE_2;
		}
		break;
	case YELLOW_RED_STATE_MODE1:
		doState3();

		if(getTimerFlags(TRAFFIC_TIMER)){
			setEnviromentState0();
			FSM_State = RED_GREEN_STATE_MODE1;
		}

		if(buttonState[0] == BUTTON_PRESSED){
			setEnviromentState4();	/*Mode 2*/
			FSM_State = NORMAL_STATE_MODE_2;
		}
		break;
	case NORMAL_STATE_MODE_2:
		doState4();

		if(buttonState[0] == BUTTON_PRESSED){
			setEnviromentState5();	/*Mode 3*/
			FSM_State = NORMAL_STATE_MODE_3;
		}
		break;
	case NORMAL_STATE_MODE_3:
		doState5();

		if(buttonState[0] == BUTTON_PRESSED){
			setEnviromentState5();	/*Mode 4*/
			FSM_State = NORMAL_STATE_MODE_4;
		}
		break;
	case NORMAL_STATE_MODE_4:
		doState6();

		if(buttonState[0] == BUTTON_PRESSED){
			setEnviromentState0();	/*Mode 1*/
			FSM_State = RED_GREEN_STATE_MODE1;
		}
		break;
	default:
		break;
	}

	return;
}
