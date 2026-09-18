#include "stm32f10x.h"                  // Device header

void MyI2C_W_SS(uint8_t BitValue){
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)BitValue);
}
void MyI2C_W_SCK(uint8_t BitValue){
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)BitValue);
}
void MyI2C_W_MOSI(uint8_t BitValue){
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)BitValue);
}
uint8_t MyI2C_R_MISO(void){
	return GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6);
}


void MySPI_Init(void){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin	= GPIO_Pin_4 | GPIO_Pin_5|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed	=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin	= GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed	=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	MyI2C_W_SS(1);
	MyI2C_W_SCK(0);
	
}
void MySPI_Start(void){
	MyI2C_W_SS(0);
}
void MySPI_Stop(void){
	MyI2C_W_SS(1);
}

uint8_t MySPI_SwapByte(uint8_t ByteSend){
	uint8_t ReceiveByte = 0x00;
	for (uint8_t i=0;i<8;i++){
		MyI2C_W_MOSI(ByteSend &(0x80>>i));
		MyI2C_W_SCK(1);
		if(MyI2C_R_MISO()==1){ReceiveByte |= (0x80>>i);}
	
	}
	return ReceiveByte;
}
	

