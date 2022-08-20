#include "stm32f10x.h"
#include "TIM_INT.h"
#include "led.h"

//arr --- �Զ���װ��ֵ
//psc --- Ԥ��Ƶϵ��

void TIM_Init(u16 arr, u16 psc){
	TIM_TimeBaseInitTypeDef TIM_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//��ʹ�ܶ�ʱ��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	//�ڳ�ʼ����ʱ��
	TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStruct.TIM_Period = arr;
	TIM_InitStruct.TIM_Prescaler = psc;
	TIM_TimeBaseInit(TIM2, &TIM_InitStruct);
	
	//�ۿ�����ʱ���жϣ�����NVIC
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
	
	//��ʹ�ܶ�ʱ��
	TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2, TIM_IT_Update)){
		LED1Set((enum LED_ENUM)!led_status.LED1_Sta);//��תLED1
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);//�ֶ�����жϱ�־λ
	}
}
