#include "stm32f10x.h"
#include "exti.h"
#include "delay.h"
#include "key.h"
#include "led.h"

int main(void)
{	
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	KEY_Init();
	LED_Init();
	My_EXTI_Init();
	while(1) ;
}

