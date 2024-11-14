/*
 * software_timer.h
 *
 *  Created on: Oct 25, 2024
 *      Author: ASUS
 */

#ifndef __SOFTWARE_TIMER_H
#define __SOFTWARE_TIMER_H

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;
extern int timer5_flag;
extern int timer6_flag;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void setTimer6(int duration);
void timer_run(void);

#endif /* __SOFTWARE_TIMER_H */
