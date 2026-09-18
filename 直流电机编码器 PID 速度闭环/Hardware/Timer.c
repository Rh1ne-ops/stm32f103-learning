#include "stm32f10x.h"                  // Device header
#include "Encoder.h"
#include "Motor.h"
#include "PID.h"
#include "Delay.h"

static volatile int16_t TargetSpeed =0;
static volatile int16_t Speed =0;
static volatile int16_t Output =0;
static uint8_t StallCount = 0;


void Timer_Init(void){   //每0.1s进入一次中断读取数据并计算新的输出

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
			int16_t Count=	Encoder_Get();
			
			int16_t RawSpeed;
			RawSpeed = (int16_t)((int32_t)Count * 600 / 1536);
			Speed = Speed_Filter(RawSpeed);
			Output = PID_Calc(TargetSpeed,RawSpeed);		
//			RawSpeed=0;
//			Output = 100;堵转测试的
       if ((Output >= 90 || Output <= -90) &&
            (RawSpeed <= 5 && RawSpeed >= -5))
        {
            StallCount++;
        }
        else
        {
            StallCount = 0;
        }

        if (StallCount >= 10)
        {
            TargetSpeed = 0;
            Output = 0;
            Motor_SetSpeed(0);
            StallCount = 0;
					//Delay_ms(500); 堵转测试
					 
					
        }
        else
        {
            Motor_SetSpeed(Output);
        }
			
			TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
		}
}
int16_t Output_Get(void){
return Output;
}


int16_t Speed_Get(void){
return Speed ;
}



