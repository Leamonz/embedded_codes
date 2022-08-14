#include "beep.h"
#include "stm32f10x.h"
#include "delay.h"

void HardWare_Init()
{
	delay_init();//��ʱ��ʼ��
	BEEP_Init();//��������ʼ��
}

int main()
{
	HardWare_Init();
	while(1)
	{
		GPIO_WriteBit(GPIOB, GPIO_Pin_3, Bit_SET);
		delay_ms(500);
		
		
		GPIO_WriteBit(GPIOB, GPIO_Pin_3, Bit_RESET);
		delay_ms(500);
	}
	
}
