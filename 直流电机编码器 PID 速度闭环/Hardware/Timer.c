#include "stm32f10x.h"                  // Device header
#include "Encoder.h"
#include "Motor.h"
#include "PID.h"

static volatile int16_t TargetSpeed =0;
static volatile int16_t Speed =0;
static volatile int16_t Output =0;


void Timer_Init(void){

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_Period=1000 -1;
	TIM_TimeBaseInitStructure.TIM_Prescaler=7200 -1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0; 
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);
	TIM_Cmd(TIM4,ENABLE);
}
void Speed_SetTarget(int16_t Target){
	TargetSpeed =Target;
}
void TIM4_IRQHandler(void){
		if(TIM_GetITStatus(TIM4,TIM_IT_Update)==SET){
		
			Speed = Encoder_Get();
			
			Output = PID_Calc(TargetSpeed,Speed);
			Motor_SetSpeed(Output);
			
			TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
		}
}
int16_t Output_Get(void){
return Output;
}


int16_t Speed_Get(void){
return Speed;
}



