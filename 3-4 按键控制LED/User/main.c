#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED1.h"
#include "Key1.h"
//                      开始模块化！！
uint8_t KeyNum;

int main(void){
	
	LED_Init();
	Key_Init();
	while(1)    //如果按下按键1，LED1的电平是0，则反转为1；1则反转为0；按键2同理。不难，写出turn函数。on off 函数就比较直接一点
	{           //Key_getnum函数作用就是把按下去这一操作变成一个keynum的值，以便触发turn；
		KeyNum = Key_GetNum();
		if(KeyNum==1){
		LED1_Turn();
		}
		if(KeyNum==2){
		LED2_Turn();
		}
		
	}
}

// 按键控制LED over
// 二次实验结束
