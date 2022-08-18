#include "exti.h"
#include "stm32f10x.h"
#include "delay.h"
#include "key.h"
#include "led.h"

void My_EXTI_Init(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	
	//①初始化IO口
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	//②使能时钟；注意要开启IO口复用时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
	
	//③设置IO口与中断线的映射关系
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13);
	
	//④初始化线上中断
	EXTI_InitStruct.EXTI_Line = EXTI_Line13;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStruct);
	
	//⑤配置中断分组，并使能中断
	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);
	
}

void EXTI15_10_IRQHandler(void){
	delay_ms(10);//防抖动
	if(KEY1==0){
		LED1Set((enum LED_ENUM)!led_status.LED1_Sta);
		LED2Set((enum LED_ENUM)!led_status.LED2_Sta);
		LED3Set((enum LED_ENUM)!led_status.LED3_Sta);
		LED4Set((enum LED_ENUM)!led_status.LED4_Sta);
	}
	//每次中断服务函数结束时都需要手动清除标志位
	EXTI_ClearITPendingBit(EXTI_Line13);
}

