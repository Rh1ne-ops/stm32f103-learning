#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor1.h"
#include "Key.h"
#include "PWM1.h"
uint8_t KeyNum;
int8_t Speed=0;
int main(void){
	
	OLED_Init();
	Motor_Init();
	Key_Init();
	
	Motor_SetSpeed(0);
	OLED_ShowString(1,1,"Speed:");
	
	while(1)    
	{           
		KeyNum=Key_GetNum();
		if(KeyNum ==2)
		{
			Speed +=20;
		if(Speed>100)
		{
		Speed =-100;
		}
		}
		Motor_SetSpeed(Speed);
		OLED_ShowSignedNum(1,7,Speed,3);
		}
}

//int main(void)
//{
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

//    GPIO_InitTypeDef GPIO_InitStructure;

//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//    GPIO_InitStructure.GPIO_Pin =
//        GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

//    GPIO_Init(GPIOA, &GPIO_InitStructure);

//    // PWMA??100%??
//    GPIO_SetBits(GPIOA, GPIO_Pin_2);

//    // ????
//    GPIO_SetBits(GPIOA, GPIO_Pin_4);
//    GPIO_ResetBits(GPIOA, GPIO_Pin_5);

//    while(1)
//    {
//    }
//}

