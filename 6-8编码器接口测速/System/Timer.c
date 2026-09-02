#include "stm32f10x.h"                  // Device header


void Timer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	TIM_InternalClockConfig(TIM2);//内部通道
	
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode =TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period =10000 -1;
	TIM_TimeBaseInitStructure.TIM_Prescaler =7200 -1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter =0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_Initstructure;
	NVIC_Initstructure.NVIC_IRQChannel =TIM2_IRQn;
	NVIC_Initstructure.NVIC_IRQChannelCmd =ENABLE;
	NVIC_Initstructure.NVIC_IRQChannelPreemptionPriority =2;
	NVIC_Initstructure.NVIC_IRQChannelSubPriority =1;
	NVIC_Init(&NVIC_Initstructure);
	
	TIM_Cmd(TIM2,ENABLE);
}

//void TIM2_IRQHandler(void)
//{
//	if(TIM_GetFlagStatus(TIM2,TIM_FLAG_Update)==SET)
//	{
//		
//		
//		TIM_ClearFlag(TIM2,TIM_FLAG_Update);
//	}


//}


