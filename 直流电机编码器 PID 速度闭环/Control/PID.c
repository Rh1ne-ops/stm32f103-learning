#include "stm32f10x.h"                  // Device header

	float kp =0.25f;
	float ki =0.05f;
	float kd =0.0f;


	float	Integral;
	int16_t Lasterror;
	
void PID_Init(void){
	Integral =0;
	Lasterror =0;
}

int16_t PID_Calc(int16_t TargetSpeed,int16_t AcutalSpeed){
	
	int16_t Error = TargetSpeed-AcutalSpeed;
	float output;
	
	Integral += Error;
	
	if(Integral>8000){Integral=8000;}
	if(Integral<-8000){Integral=-8000;}
	
	
	output = kp * Error +
					 ki * Integral +
					 kd * (Error - Lasterror);
	Lasterror = Error;
	
	if(output >100){output =100;}
	if(output <-100){output =-100;}
	
	return (int16_t)output;

}







