/*
 * 7_seg.h
 *
 *  Created on: Oct 25, 2024
 *      Author:   ASUS
 */

#ifndef INC_DISPLAY_LED_H_
#define INC_DISPLAY_LED_H_

#include "main.h"
#include "global.h"


void displayFirstLedCouple(enum LedState state_1);

void displaySecondLedCouple(enum LedState state_2);

void toggleLeds(enum LedState state);

void displaySEG7_1(int num);

void displaySEG7_2(int num);

void enable0();

void enable1();

void enable2();

void enable3();

void enable4();

void enable5();

void showTimeDelay_First(int first, int second);

void showTimeDelay_Second(int first, int second);

void showTimeDelay1(int delaytime);

void showTimeDelay2(int delaytime);

#endif /* INC_DISPLAY_LED_H_ */
