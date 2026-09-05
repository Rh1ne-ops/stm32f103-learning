#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial1.h"

uint8_t Data;

int main(void){
	
	OLED_Init();
	Serial_Init();

	OLED_ShowString(1,1,"RXData:");
	
	while(1)    
	{           
		if(Serial_GetFlag()==1)
	{
		Data = Serial_GetData();
		Serial_SendByte(Data);
}
	OLED_ShowHexNum(1,8,Data,4);
	
	}
}


