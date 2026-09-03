#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM1.h"
#include "IC1.h"

uint8_t i;
int main(void){
	
	OLED_Init();
	PWM_Init();
	IC_Init();

	
	OLED_ShowString(1,1,"Freq:00000Hz");
	PWM_SetPrescaler(72-1);    //频率freq=  72M/(PSc+1)/  100
	PWM_SetCompare1(40);        //占空比 Duty =CCR/ARR(100)

	while(1)    
	{           
		OLED_ShowNum(1,6,IC_GetFreq(),5);
	}
}


