#ifndef __TIMER_H
#define __TIMER_H
#include "stm32f10x.h"                  // Device header

int16_t Output_Get(void);
int16_t Speed_Get(void);
void Timer_Init(void);
void Speed_SetTarget(int16_t Target);
#endif
