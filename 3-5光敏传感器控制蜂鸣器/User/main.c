#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Buzzer1.h"
#include "LightSensor1.h"


//LIGHT_GET 将光敏电阻转换成值，然后用Buzzer判断后使蜂鸣器启动。遮住光源时蜂鸣器响
int main(void){
	
	Buzzer_Init();
	LightSensor_Init();
	while(1)
	{
		if(LightSensor_Get()==0)	
		{
		Buzzer_ON();
		}
		else{Buzzer_OFF();}
	}
}
// 按键控制LED over
// 光敏电阻控制蜂鸣器 √
