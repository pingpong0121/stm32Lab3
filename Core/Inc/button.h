/*
 * button.h
 *
 *  Created on: Oct 25, 2024
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"


#define NORMAL_STATE SET
#define PRESSED_STATE RESET
#define BUTTONS_NUMBER 3

int isButtonPressed(int i);

void getKeyInput();

#endif /* INC_BUTTON_H_ */
