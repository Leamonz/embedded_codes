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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ2
	uart_init(115200);
	while(1)
	{
		if(USART_RX_STA&0x8000)
		{					   
			len=USART_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
			printf("\r\n�����͵���ϢΪ:\r\n\r\n");
			for(t=0;t<len;t++)
			{
				USART_SendData(USART1, USART_RX_BUF[t]);//�򴮿�1��������
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
			}
			printf("\r\n\r\n");//���뻻��
			USART_RX_STA=0;
		}else
		{
			times++;
			if(times%5000==0)
			{
				printf("\r\nս��STM32������ ����ʵ��\r\n");
				printf("����ԭ��@ALIENTEK\r\n\r\n");
			}
			if(times%200==0)printf("����������,�Իس�������\n");  
			if(times%30==0)LED1Set((enum LED_ENUM)!led_status.LED1_Sta);//��˸LED,��ʾϵͳ��������.
			delay_ms(10);   
		}
	}	 
}

