#include "key.h"
#include "stm32f10x.h"
#include "delay.h"

void KEY_Init(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOD, &GPIO_InitStruct);
	
}
//低电平表示按下，高电平表示松开
//mode == 1---支持连续按； mode == 0---不支持连续按
unsigned char KEY_Scan(unsigned char mode){
	static unsigned char key_up = 1;
	if(mode == 1){
		key_up = 1;
	}
	if(key_up && (KEY1 == 0 || KEY2 == 0 || KEY3 == 0 || KEY4 == 0)){
		delay_ms(10);//消除抖动'
		key_up = 0;
		//以下按键有响应优先级： KEY1 > KEY2 > KEY3 > KEY4
		if(KEY1 == 0)
			return KEY1_PRES;
		else if(KEY2 == 0)
			return KEY2_PRES;
		else if(KEY3 == 0)
			return KEY3_PRES;
		else if(KEY4 == 0)
			return KEY4_PRES;
	}
	else if(KEY1 == 1&&KEY2 == 1&&KEY3 == 1&&KEY4 == 1){
		key_up = 1;
	}
	return 0;//没有按键按下
}

