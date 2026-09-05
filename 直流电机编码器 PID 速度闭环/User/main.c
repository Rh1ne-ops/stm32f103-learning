#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "PWM.h"
int main(void){
	
	OLED_Init();
	Motor_Init();


	while(1)    
	{           
		

    
        GPIO_SetBits(GPIOA, GPIO_Pin_4);
        GPIO_ResetBits(GPIOA, GPIO_Pin_5);
        PWM_SetCompare(50);
        Delay_ms(3000);

        PWM_SetCompare(0);
        Delay_ms(1000);

        GPIO_SetBits(GPIOA, GPIO_Pin_5);
        GPIO_ResetBits(GPIOA, GPIO_Pin_4);
        PWM_SetCompare(50);
        Delay_ms(3000);

        PWM_SetCompare(0);
        Delay_ms(1000);
    }

	
}


