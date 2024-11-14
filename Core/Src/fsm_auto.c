/*
 * fsm_auto.c
 *
 *  Created on: Oct 25, 2024
 *      Author: ASUS
 */
#include "fsm_auto.h"

void auto_run() {
    if (isButtonPressed(0) == 1) {
        HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin | EN4_Pin | EN5_Pin, GPIO_PIN_SET);
        MODE = MODE2;
    }

    if (MODE == MODE1) {
        switch (firstCoupleLedAutoState) {
            case LED_INIT:
                firstCoupleLedAutoState = RED;
                setTimer1(100);
                break;
            case RED:
                displayFirstLedCouple(RED);
                if (timer1_flag == 1) {
                    countdownFirstCoupleLed--;
                    if (countdownFirstCoupleLed == 0) {
                        countdownFirstCoupleLed = greenDelay;
                        firstCoupleLedAutoState = GREEN;
                    }
                    setTimer1(100);
                }
                break;
            case GREEN:
                displayFirstLedCouple(GREEN);
                if (timer1_flag == 1) {
                    countdownFirstCoupleLed--;
                    if (countdownFirstCoupleLed == 0) {
                        countdownFirstCoupleLed = yellowDelay;
                        firstCoupleLedAutoState = YELLOW;
                    }
                    setTimer1(100);
                }
                break;
            case YELLOW:
                displayFirstLedCouple(YELLOW);
                if (timer1_flag == 1) {
                    countdownFirstCoupleLed--;
                    if (countdownFirstCoupleLed == 0) {
                        countdownFirstCoupleLed = redDelay;
                        firstCoupleLedAutoState = RED;
                    }
                    setTimer1(100);  // Reset timer1
                }
                break;
            default:
                break;
        }

        switch (secondCoupleLedAutoState) {
            case LED_INIT:
                secondCoupleLedAutoState = GREEN;
                setTimer2(100);
                break;
            case RED:
                displaySecondLedCouple(RED);
                if (timer2_flag == 1) {
                    countdownSecondCoupleLed--;
                    if (countdownSecondCoupleLed == 0) {
                        countdownSecondCoupleLed = greenDelay;
                        secondCoupleLedAutoState = GREEN;
                    }
                    setTimer2(100);
                }
                break;
            case GREEN:
                displaySecondLedCouple(GREEN);
                if (timer2_flag == 1) {
                    countdownSecondCoupleLed--;
                    if (countdownSecondCoupleLed == 0) {
                        countdownSecondCoupleLed = yellowDelay;
                        secondCoupleLedAutoState = YELLOW;
                    }
                    setTimer2(100);
                }
                break;
            case YELLOW:
                displaySecondLedCouple(YELLOW);
                if (timer2_flag == 1) {
                    countdownSecondCoupleLed--;
                    if (countdownSecondCoupleLed == 0) {
                        countdownSecondCoupleLed = redDelay;
                        secondCoupleLedAutoState = RED;
                    }
                    setTimer2(100);
                }
                break;
            default:
                break;
        }

        switch (seg7AutoState) {
            case SEG_INIT:
                seg7AutoState = FIRST;
                setTimer3(1);
                break;
            case FIRST:
                if (timer3_flag == 1) {
                    showTimeDelay_First(countdownFirstCoupleLed, countdownSecondCoupleLed);
                    seg7AutoState = SECOND;
                    setTimer3(50);
                }
                break;
            case SECOND:
                if (timer3_flag == 1) {
                    showTimeDelay_Second(countdownFirstCoupleLed, countdownSecondCoupleLed);
                    seg7AutoState = FIRST;
                    setTimer3(50);
                }
                break;
            default:
                break;
        }
    }
}
