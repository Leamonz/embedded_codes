#include "stm32f10x.h"
#include "TIM_INT.h"
#include "led.h"

//arr --- 自动重装载值
//psc --- 预分频系数

void TIM_Init(u16 arr, u16 psc){
	TIM_TimeBaseInitTypeDef TIM_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//①使能定时器时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	//②初始化定时器
	TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStruct.TIM_Period = arr;
	TIM_InitStruct.TIM_Prescaler = psc;
	TIM_TimeBaseInit(TIM2, &TIM_InitStruct);
	
	//③开启定时器中断，配置NVIC
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
	
	//④使能定时器
	TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2, TIM_IT_Update)){
		LED1Set((enum LED_ENUM)!led_status.LED1_Sta);//翻转LED1
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);//手动清除中断标志位
	}
}
