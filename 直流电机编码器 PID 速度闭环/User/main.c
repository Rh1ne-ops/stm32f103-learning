#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "PWM.h"
#include "Encoder.h"
#include "Timer.h"
#include "PID.h"
#include "Serial.h"
#include "Key.h"

uint8_t KeyNum;
int16_t Target=0;
uint16_t Count = 0;
int main(void){
	
	OLED_Init();
	Key_Init();
	Motor_Init();
	Serial_Init();
	Encoder_Init();
	PID_Init();
	Timer_Init();


	Target =50;
	
	OLED_ShowString(1,1,"Speed:");
	OLED_ShowString(2,1,"Target:");
	OLED_ShowString(3,1,"Output:");
	
	OLED_ShowString(1,12,"RPM");
	OLED_ShowString(2,12,"RPM");
	OLED_ShowString(3,12,"%");

//	Motor_SetSpeed(30);                 
	
	
	Speed_SetTarget(Target);
	
	while(1)    
	{           
		OLED_ShowSignedNum(2,7,Target,4);
		OLED_ShowSignedNum(1,7,Speed_Get(),4);
		OLED_ShowSignedNum(3,7,Output_Get(),4);
		
		Serial_Printf("%d,%d,%d\r\n",
                  Target,
                  Speed_Get(),
                  Output_Get());
		Speed_SetTarget(Target);
		  Count++;
		KeyNum = Key_GetNum();
		if(KeyNum==2){
			Target+=50;
			if(Target>200)
			{	
			Target=0;
			}
			Speed_SetTarget(Target);
		}
		
		
       
//        if(Count >= 50)    自发更换速度 测试用的
//        {  
//            Count = 0;

//            if(Target == 200)
//            {
//                Target = 100;
//            }
//            else
//            {
//                Target = 200;
//            }

//            Speed_SetTarget(Target);
//        }
		
		
		Delay_ms(100);
    }

	
// OLED_Init();
//    Motor_Init();
//    Encoder_Init();

//    TIM_SetCounter(TIM3, 0);

//    OLED_ShowString(1, 1, "Count:");

		//    Motor_SetSpeed(20);   // 找电机一圈多少个脉冲的

//    while (1)
//    {
//        OLED_ShowSignedNum(
//            2,
//            1,
//            (int16_t)TIM_GetCounter(TIM3),
//            6
//        );
//    }
}


