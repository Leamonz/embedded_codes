#include "stm32f10x.h"
#include "wwdg.h"
#include "led.h"

u8 WWDG_CNT = 0x7f;
void WWDG_Init(u8 tr, u8 wr, u32 prer){
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//��ʹ�ܴ��ڿ��Ź�ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	
	//�����÷�Ƶϵ��
	WWDG_SetPrescaler(prer);
	
	//�������ϴ���ֵ
	WWDG_SetWindowValue(wr);
	
	WWDG_ClearFlag();//�����ǰ�����жϱ�־λ
	
	//�ܿ�����ǰ�����жϲ�����(��ѡ)
	WWDG_EnableIT();
	NVIC_InitStruct.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
	
	WWDG_EnableIT();
	
	//��ʹ�ܿ��Ź�
	WWDG_CNT = tr & WWDG_CNT;//ֻȡtr�ĵ�7λ����Ϊ�����Ĵ���ֻ��7λ���ڴ�����
	WWDG_Enable(WWDG_CNT);
	
}
//�������ÿ��Ź��ļ�������ֵ
void WWDG_Reset_Counter(u8 cnt){
	WWDG_Enable(cnt);
}

void WWDG_IRQHandler(){
	WWDG_SetCounter(WWDG_CNT);//���û����䣬���Ź��Ḵλ
	
	WWDG_ClearFlag();//�����ǰ�����жϱ�־λ
	
	LED1Set((enum LED_ENUM)!led_status.LED1_Sta);// ��תLED1
}
