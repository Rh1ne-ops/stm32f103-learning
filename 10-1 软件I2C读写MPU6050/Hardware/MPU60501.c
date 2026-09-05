//#include "stm32f10x.h"                  // Device header
//#include "MYI2C1.h"  
//#define MPU6050_ADDRESS   0xD0


//void MPU6050_WriteReg(uint8_t RegAddress,uint8_t Data){

//	MyI2C_Start();
//	MyI2C_SendByte(MPU6050_ADDRESS);
//	MyI2C_ReceiveAck();
//	MyI2C_SendByte(RegAddress);
//	MyI2C_ReceiveAck();
//	MyI2C_SendByte(Data);
//	MyI2C_ReceiveAck();
//	MyI2C_Stop();

//}
//void MPU6050_ReadReg(uint8_t RegAddress){
//	uint8_t Data;
//	MyI2C_Start();
//	MyI2C_SendByte(MPU6050_ADDRESS);
//	MyI2C_ReceiveAck();
//	MyI2C_SendByte(RegAddress);
//	MyI2C_ReceiveAck();

//	MyI2C_Start();
//	MyI2C_SendByte(MPU6050_ADDRESS |0x01);  
//	MyI2C_ReceiveAck();
//	Data = MyI2C_ReceiveByte();
//	MyI2C_SendAck(1);
//	MyI2C_Stop();
//}







