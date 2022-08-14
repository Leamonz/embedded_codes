#include "led.h"
#include "stm32f10x.h"

LED_Status led_status;

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_12;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	LED1_Set(LED_OFF);
	LED2_Set(LED_OFF);
	LED3_Set(LED_OFF);
	LED4_Set(LED_OFF);
}

void LED1_Set(LED_ENUM status)
{
	GPIO_WriteBit(GPIOC,GPIO_Pin_7,(BitAction)(1-status));
	led_status.LED1_Sta=(_Bool)status;
}

void LED2_Set(LED_ENUM status)
{
	GPIO_WriteBit(GPIOC,GPIO_Pin_8,(BitAction)(1-status));
	led_status.LED2_Sta=(_Bool)status;
}

void LED3_Set(LED_ENUM status)
{
	GPIO_WriteBit(GPIOA,GPIO_Pin_12,(BitAction)(1-status));
	led_status.LED3_Sta=(_Bool)status;
}

void LED4_Set(LED_ENUM status)
{
	GPIO_WriteBit(GPIOC,GPIO_Pin_10,(BitAction)(1-status));
	led_status.LED4_Sta=(_Bool)status;
}
