#ifndef __PWM1_H
#define __PWM1_H
#include "stm32f10x.h"                  // Device header

void PWM_SetCompare1(uint16_t Compare);

void PWM_Init(void);
#endif
