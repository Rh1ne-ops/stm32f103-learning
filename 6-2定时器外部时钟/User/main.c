#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer1.h"

uint16_t Num =0;
//int main(void){
//	
//	OLED_Init();
//	Timer_Init();

//	OLED_ShowString(1,1,"Num:");
//	OLED_ShowString(2,1,"CNT:");
//	

//	

//	while(1)    
//	{           
//		OLED_ShowNum(1,5,Num,5);
//		OLED_ShowNum(2,5,Timer_GetCounter(),5);

//	}
//}

//void TIM2_IRQHandler(void)
//{
//	if(TIM_GetFlagStatus(TIM2,TIM_FLAG_Update)==SET)
//	{
//		
//		Num++;
//		TIM_ClearFlag(TIM2,TIM_FLAG_Update);
//	}


//}
int main (void)
{
	Timer_Init();
	OLED_Init();
	
	OLED_ShowString(1,1,"Num:");
	OLED_ShowString(2,1,"CNT:");
	
	while(1)
	{
		OLED_ShowNum(1,5,Num,5);
		OLED_ShowNum(2,5,Timer_GetNum(),5);
	
	}
	


}
void TIM2_IRQHandler(void)
{
	if(TIM_GetFlagStatus(TIM2,TIM_FLAG_Update)==SET)
		{
			Num++;
			TIM_ClearITPendingBit(TIM2,TIM_FLAG_Update);
		}



}










