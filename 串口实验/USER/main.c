#include "stm32f10x.h"
#include "usart.h"
#include "delay.h"
#include "led.h"
#include <stdio.h>



int main(void)
{	
	u16 t;
	u16 len;
	u16 times = 0;
	delay_init();
	LED_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为2
	uart_init(115200);
	while(1)
	{
		if(USART_RX_STA&0x8000)
		{					   
			len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
			printf("\r\n您发送的消息为:\r\n\r\n");
			for(t=0;t<len;t++)
			{
				USART_SendData(USART1, USART_RX_BUF[t]);//向串口1发送数据
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
			}
			printf("\r\n\r\n");//插入换行
			USART_RX_STA=0;
		}else
		{
			times++;
			if(times%5000==0)
			{
				printf("\r\n战舰STM32开发板 串口实验\r\n");
				printf("正点原子@ALIENTEK\r\n\r\n");
			}
			if(times%200==0)printf("请输入数据,以回车键结束\n");  
			if(times%30==0)LED1Set((enum LED_ENUM)!led_status.LED1_Sta);//闪烁LED,提示系统正在运行.
			delay_ms(10);   
		}
	}	 
}

