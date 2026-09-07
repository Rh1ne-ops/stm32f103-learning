#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "PWM.h"
#include "Encoder.h"
#include "Timer.h"
#include "PID.h"
#include "Serial.h"

int16_t Target=0;
uint16_t Count = 0;
int main(void){
	
	OLED_Init();
	Motor_Init();
	Serial_Init();
	Encoder_Init();
	PID_Init();
	Timer_Init();

	
	Target =300;
	
	OLED_ShowString(1,1,"Speed:");
	OLED_ShowString(2,1,"Target:");
	OLED_ShowString(3,1,"Output:");

//	Motor_SetSpeed(20);
	
	
	Speed_SetTarget(Target);
	
	while(1)    
	{           
		OLED_ShowSignedNum(2,9,Target,4);
		OLED_ShowSignedNum(1,7,Speed_Get(),4);
		OLED_ShowSignedNum(3,7,Output_Get(),4);
		
		Serial_Printf("%d,%d,%d\r\n",
                  Target,
                  Speed_Get(),
                  Output_Get());
		
		  Count++;

        /* 100ms × 50 = 5秒 */
        if(Count >= 50)
        {
            Count = 0;

            if(Target == 300)
            {
                Target = 500;
            }
            else
            {
                Target = 300;
            }

            Speed_SetTarget(Target);
        }
		
		
		Delay_ms(300);
    }

	
}


