/*
 * led_display.c
 *
 *  Created on: Oct 30, 2024
 *      Author: ASUS
 */


#include "led_display.h"

	void displayFirstLedCouple(enum LedState state_1){
		switch(state_1){
		 case LED_INIT:
			  HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
			  HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
			  HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
				 break;
		 case RED:
			 HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
			 HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
			 HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
				 break;
		 case YELLOW:
			 HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
			 HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
			 HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
				 break;
		 case GREEN:
			 HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
			 HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
			 HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
				 break;
		 default:
			 break;
		}
	}



	void displaySecondLedCouple(enum LedState state_2){
		switch(state_2){
			 case LED_INIT:
				 HAL_GPIO_WritePin( GREEN2_GPIO_Port , GREEN2_Pin , SET) ;
				 HAL_GPIO_WritePin( YELLOW2_GPIO_Port , YELLOW2_Pin , SET ) ;
				 HAL_GPIO_WritePin( RED2_GPIO_Port , RED2_Pin , SET ) ;
				 break;
			case RED:
				HAL_GPIO_WritePin( GREEN2_GPIO_Port , GREEN2_Pin , SET) ;
				HAL_GPIO_WritePin( YELLOW2_GPIO_Port , YELLOW2_Pin , SET ) ;
				HAL_GPIO_WritePin( RED2_GPIO_Port , RED2_Pin , RESET ) ;
				break;
			case YELLOW:
				HAL_GPIO_WritePin( GREEN2_GPIO_Port , GREEN2_Pin , SET) ;
				HAL_GPIO_WritePin( YELLOW2_GPIO_Port , YELLOW2_Pin , RESET ) ;
				HAL_GPIO_WritePin( RED2_GPIO_Port , RED2_Pin , SET ) ;
				break;
			case GREEN:
				HAL_GPIO_WritePin( GREEN2_GPIO_Port , GREEN2_Pin , RESET) ;
				HAL_GPIO_WritePin( YELLOW2_GPIO_Port , YELLOW2_Pin , SET ) ;
				HAL_GPIO_WritePin( RED2_GPIO_Port , RED2_Pin , SET ) ;
				break;
			default:
			  break;
	   }
	}

void toggleLeds(enum LedState state){
	switch(state){
	 case GREEN:
			 HAL_GPIO_TogglePin( GREEN1_GPIO_Port , GREEN1_Pin) ;
			 HAL_GPIO_TogglePin( GREEN2_GPIO_Port , GREEN2_Pin) ;
			 break;
	 case YELLOW:
			 HAL_GPIO_TogglePin( YELLOW1_GPIO_Port , YELLOW1_Pin) ;
			 HAL_GPIO_TogglePin( YELLOW2_GPIO_Port , YELLOW2_Pin) ;
			 break;
	 case RED:
			 HAL_GPIO_TogglePin( RED1_GPIO_Port , RED1_Pin) ;
			 HAL_GPIO_TogglePin( RED2_GPIO_Port , RED2_Pin) ;
			 break;
	 default:
		 break;
	}
}

void displaySEG7_1(int num) {
    char led7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
    for (int i = 0; i < 7; i++) {
        HAL_GPIO_WritePin(GPIOB, A1_Pin << i, (led7seg[num] >> i) & 1);
    }
}
void displaySEG7_2(int num) {
    char led7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
    for (int i = 0; i < 7; i++) {
        HAL_GPIO_WritePin(GPIOB, A2_Pin << i, (led7seg[num] >> i) & 1);
    }
}

void enable0(){
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
}

void enable1(){
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
}

void enable2(){
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
}

void enable3(){
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
}
void enable4(){
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
		HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, SET);
}

void enable5(){
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
		HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, RESET);
}
void showTimeDelay_First(int first, int second){
	first--;
	second--;
	enable0();
	displaySEG7_1(first/10);
	enable2();
	displaySEG7_2(second/10);
}

void showTimeDelay_Second(int first, int second){
	first--;
	second--;
	enable1();
	displaySEG7_1(first%10);
	enable3();
	displaySEG7_2(second%10);
}
void showTimeDelay1(int delaytime){
	delaytime--;
	enable4();
	displaySEG7_1(delaytime/10);
}
void showTimeDelay2(int delaytime){
	delaytime--;
	enable5();
	displaySEG7_2(delaytime%10);
}

