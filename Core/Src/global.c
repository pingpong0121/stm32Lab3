/*
 * global.c
 *
 *  Created on: Oct 25, 2024
 *      Author: ASUS
 */
#include "global.h"

enum ModeState MODE;

enum LedToggleState mode2Toggle;
enum SegState mode2Seg;
enum IncreaseDelayState mode2Increase;

enum LedToggleState mode3Toggle;
enum SegState mode3Seg;
enum IncreaseDelayState mode3Increase;

enum LedToggleState mode4Toggle;
enum SegState mode4Seg;
enum IncreaseDelayState mode4Increase;

enum LedState firstCoupleLedAutoState;
enum LedState secondCoupleLedAutoState;
enum SegState seg7AutoState;

int redDelay = 10;
int greenDelay = 6;
int yellowDelay = 4;


int countdownFirstCoupleLed;
int countdownSecondCoupleLed;

void setValues(void){
	MODE = MODE1;

	mode2Toggle = TOGGLE_INIT;
	mode2Seg = SEG_INIT;
	mode2Increase = INCREASE_INIT;

	mode3Toggle = TOGGLE_INIT;
	mode3Seg = SEG_INIT;
	mode3Increase = INCREASE_INIT;

	mode4Toggle = TOGGLE_INIT;
	mode4Seg = SEG_INIT;
	mode4Increase = INCREASE_INIT;

	firstCoupleLedAutoState = LED_INIT;
	secondCoupleLedAutoState = LED_INIT;
	seg7AutoState = SEG_INIT;

	countdownFirstCoupleLed = redDelay;
	countdownSecondCoupleLed = greenDelay;
}

