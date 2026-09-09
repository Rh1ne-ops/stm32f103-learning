#ifndef __PID_H
#define __PID_H
#include "stm32f10x.h"                  // Device header

void PID_Init(void);
int16_t PID_Calc(int16_t TargetSpeed,int16_t AcutalSpeed);
int16_t Speed_Filter(int16_t NewSpeed);
#endif
