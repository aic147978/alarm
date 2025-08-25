#ifndef __ESP8266_H
#define __ESP8266_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////
// 本程序只供学习使用，未经作者许可，不得用于其它任何用途
// ALIENTEK STM32F429
// ESP8266 AT指令驱动
// 版权所有，盗版必究
////////////////////////////////////////////////////////////////////////////////// 

#define EN_USART3_RX    1           //1,使能USART3接收;0,禁止

extern UART_HandleTypeDef ESP8266_UART_Handler;
extern u8  ESP8266_RX_BUF[512];
extern u16 ESP8266_RX_CNT;

void ESP8266_Init(u32 bound);
u8 ESP8266_SendCmd(char *cmd,char *ack,u16 waittime);
u8 ESP8266_JoinAP(char *ssid,char *pwd);
u8 ESP8266_StartTCP(char *ip,char *port);
u8 ESP8266_SendData(char *data);
void ESP8266_Receive_Data(u8 *buf,u16 *len);

#endif
