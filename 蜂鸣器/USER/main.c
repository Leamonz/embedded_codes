#include "beep.h"
#include "stm32f10x.h"
#include "delay.h"

void HardWare_Init()
{
	Delay_Init();//��ʱ��ʼ��
	BEEP_Init();//��������ʼ��
}

int main()
{
	HardWare_Init();
	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_3);
		DelayXms(300);
		GPIO_ResetBits(GPIOB,GPIO_Pin_3);
		DelayXms(300);
	}
	
}
