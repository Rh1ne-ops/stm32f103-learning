#include "stm32f10x.h"                  // Device header

int16_t Speed_Filter(int16_t NewSpeed){
		static int16_t Buffer[4] = {0};
    static uint8_t Index = 0;
    static uint8_t Num = 0;
    static int32_t Sum = 0;
		
		Sum -= Buffer[Index];
		Buffer[Index] = NewSpeed;
		Sum += Buffer[Index] ;
		
		Index++;	
		if(Index ==4){Index=0;}
		if(Num<4){
		Num++;
		}
	
		return (int16_t)(Sum/Num);

}
	float kp =0.60f;
	float ki =0.15f;
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







