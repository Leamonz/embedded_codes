#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

void Hardware_Init(void)
{
	Delay_Init();
	LED_Init();
}

int main()
{
	Hardware_Init();
	while(1)
	{
		
		LED1_Set(LED_ON); DelayMs(500); LED1_Set(LED_OFF);
		LED2_Set(LED_ON); DelayMs(500); LED2_Set(LED_OFF);
		LED3_Set(LED_ON); DelayMs(500); LED3_Set(LED_OFF);
		LED4_Set(LED_ON); DelayMs(500); LED4_Set(LED_OFF);
	
	}
}
