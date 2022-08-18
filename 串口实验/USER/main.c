#include "stm32f10x.h"
#include "usart.h"
#include <stdio.h>


void USART1_Init(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	//��ʹ�����ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);
	//�ڳ�ʼ��IO��
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;//ģʽ���
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//�۳�ʼ��������ز���
	USART_InitStruct.USART_BaudRate = 115200;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��ʹ��Ӳ����	
	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;//���ͺͽ���ʹ��
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	
	USART_Init(USART1, &USART_InitStruct);
	//��ʹ�ܴ���1
	USART_Cmd(USART1, ENABLE);
	//�ݿ����ж�
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//���÷����ж�
	//�ݽ����ж����ȼ�������
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}
//���жϷ�����
void USART1_IRQHandler(void){
	//�������ݵı���
	u8 res;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET){
		res = USART_ReceiveData(USART1);
		USART_SendData(USART1, res);
	}
}

int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ2
	USART1_Init();
	while(1);
}

