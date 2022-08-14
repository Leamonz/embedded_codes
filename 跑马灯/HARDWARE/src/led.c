#include "led.h"
#include "stm32f10x.h"

void LED_Init(){
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//ʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOA, ENABLE);
	
	//��ʼ��GPIO
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_SET);
	
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 |GPIO_Pin_10;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	GPIO_WriteBit(GPIOC, GPIO_Pin_7 | GPIO_Pin_8 |GPIO_Pin_10, Bit_SET);
	
}

void LEDs_OFF(void){
	//�ߵ�ƽ�ص�
	GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_SET);
	GPIO_WriteBit(GPIOC, GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_10, Bit_SET);
}


void LEDs_ON(void){
	//�͵�ƽ����
	GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_RESET);
	GPIO_WriteBit(GPIOC, GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_10, Bit_RESET);
}
