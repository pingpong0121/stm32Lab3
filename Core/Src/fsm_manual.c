/*
 * fsm_manual.c
 *
 *  Created on: Oct 31, 2024
 *      Author: ASUS
 */

#include "fsm_manual.h"

void mode2_run() {
    switch (mode2Toggle) {
        case TOGGLE_INIT:
            HAL_GPIO_WritePin(GPIOA, RED1_Pin | YELLOW1_Pin | GREEN1_Pin | RED2_Pin | YELLOW2_Pin | GREEN2_Pin, GPIO_PIN_SET);
            mode2Toggle = TOGGLE;
            setTimer1(25);
            break;
        case TOGGLE:
            if (timer1_flag == 1) {
                toggleLeds(RED);
                setTimer1(25);
            }
            break;
        default:
            break;
    }

    switch (mode2Increase) {
        case INCREASE_INIT:
            if (isButtonPressed(1) == 1) {
                mode2Increase = INCREASE;
                redDelay += 1;
                greenDelay += 1;
            }
            break;
        case INCREASE:
            if (isButtonPressed(1) == 1) {
                redDelay += 1;
                greenDelay += 1;
                if (redDelay >= 99) redDelay = 1;
            }
            if (isButtonPressed(2) == 1) {
                HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin | EN4_Pin | EN5_Pin, GPIO_PIN_SET);
                MODE = MODE1;
                setValues();
            }
            break;
        default:
            break;
    }

    switch (mode2Seg) {
        case SEG_INIT:
            mode2Seg = FIRST;
            setTimer2(25);
            break;
        case FIRST:
            if (timer2_flag == 1) {
                showTimeDelay1(redDelay);
                mode2Seg = SECOND;
                setTimer2(25);
            }
            break;
        case SECOND:
            if (timer2_flag == 1) {
                showTimeDelay2(redDelay);
                setTimer2(25);
                mode2Seg = FIRST;
            }
            break;
        default:
            break;
    }
}

void mode3_run() {
    switch (mode3Toggle) {
        case TOGGLE_INIT:
            HAL_GPIO_WritePin(GPIOA, RED1_Pin | YELLOW1_Pin | GREEN1_Pin | RED2_Pin | YELLOW2_Pin | GREEN2_Pin, GPIO_PIN_SET);
            mode3Toggle = TOGGLE;
            setTimer3(25);
            break;
        case TOGGLE:
            if (timer3_flag == 1) {
                toggleLeds(YELLOW);
                setTimer3(25);
            }
            break;
        default:
            break;
    }

    switch (mode3Increase) {
        case INCREASE_INIT:
            if (isButtonPressed(1) == 1) {
                mode3Increase = INCREASE;
                yellowDelay += 1;
                redDelay += 1;
            }
            break;
        case INCREASE:
            if (isButtonPressed(1) == 1) {
                yellowDelay += 1;
                redDelay += 1;
                if (yellowDelay >= 99) yellowDelay = 1;
            }
            if (isButtonPressed(2) == 1) {
                HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin | EN4_Pin | EN5_Pin, GPIO_PIN_SET);
                MODE = MODE1;
                setValues();
            }
            break;
        default:
            break;
    }

    switch (mode3Seg) {
        case SEG_INIT:
            mode3Seg = FIRST;
            setTimer4(25);
            break;
        case FIRST:
            if (timer4_flag == 1) {
                showTimeDelay1(yellowDelay);
                mode3Seg = SECOND;
                setTimer4(25);
            }
            break;
        case SECOND:
            if (timer4_flag == 1) {
                showTimeDelay2(yellowDelay);
                setTimer4(25);
                mode3Seg = FIRST;
            }
            break;
        default:
            break;
    }
}

void mode4_run() {
    switch (mode4Toggle) {
        case TOGGLE_INIT:
            HAL_GPIO_WritePin(GPIOA, RED1_Pin | YELLOW1_Pin | GREEN1_Pin | RED2_Pin | YELLOW2_Pin | GREEN2_Pin, GPIO_PIN_SET);
            mode4Toggle = TOGGLE;
            setTimer5(25);
            break;
        case TOGGLE:
            if (timer5_flag == 1) {
                toggleLeds(GREEN);
                setTimer5(25);
            }
            break;
        default:
            break;
    }

    switch (mode4Increase) {
        case INCREASE_INIT:
            if (isButtonPressed(1) == 1) {
                mode4Increase = INCREASE;
                greenDelay += 1;
                redDelay += 1;
            }
            break;
        case INCREASE:
            if (isButtonPressed(1) == 1) {
                greenDelay += 1;
                redDelay += 1;
                if (greenDelay >= 99) greenDelay = 1;
            }
            if (isButtonPressed(2) == 1) {
                HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin | EN4_Pin | EN5_Pin, GPIO_PIN_SET);
                MODE = MODE1;
                setValues();
            }
            break;
        default:
            break;
    }

    switch (mode4Seg) {
        case SEG_INIT:
            mode4Seg = FIRST;
            setTimer6(25);
            break;
        case FIRST:
            if (timer6_flag == 1) {
                showTimeDelay1(greenDelay);
                mode4Seg = SECOND;
                setTimer6(25);
            }
            break;
        case SECOND:
            if (timer6_flag == 1) {
                showTimeDelay2(greenDelay);
                setTimer6(25);
                mode4Seg = FIRST;
            }
            break;
        default:
            break;
    }
}

void manual_run() {
    switch (MODE) {
        case MODE2:
            mode2_run();
            if (isButtonPressed(0) == 1) {
                MODE = MODE3;
            }
            break;
        case MODE3:
            mode3_run();
            if (isButtonPressed(0) == 1) {
                MODE = MODE4;
            }
            break;
        case MODE4:
            mode4_run();
            if (isButtonPressed(0) == 1) {
                HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin | EN4_Pin | EN5_Pin, GPIO_PIN_SET);
                MODE = MODE1;
                setValues();
            }
            break;
        default:
            break;
    }
}
