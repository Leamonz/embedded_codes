#include "stm32f10x.h"
#include "wwdg.h"
#include "led.h"

u8 WWDG_CNT = 0x7f;
void WWDG_Init(u8 tr, u8 wr, u32 prer){
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//①使能窗口看门狗时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	
	//②设置分频系数
	WWDG_SetPrescaler(prer);
	
	//③设置上窗口值
	WWDG_SetWindowValue(wr);
	
	WWDG_ClearFlag();//清除提前唤醒中断标志位
	
	//④开启提前唤醒中断并分组(可选)
	WWDG_EnableIT();
	NVIC_InitStruct.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
	
	WWDG_EnableIT();
	
	//⑤使能看门狗
	WWDG_CNT = tr & WWDG_CNT;//只取tr的低7位，因为计数寄存器只有7位用于存数据
	WWDG_Enable(WWDG_CNT);
	
}
//重新设置看门狗的计数器的值
void WWDG_Reset_Counter(u8 cnt){
	WWDG_Enable(cnt);
}

void WWDG_IRQHandler(){
	WWDG_SetCounter(WWDG_CNT);//如果没有这句，看门狗会复位
	
	WWDG_ClearFlag();//清除提前唤醒中断标志位
	
	LED1Set((enum LED_ENUM)!led_status.LED1_Sta);// 翻转LED1
}
