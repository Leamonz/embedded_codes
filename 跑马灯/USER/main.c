#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

void HARDWARE_Init(void){
	LED_Init();
	Delay_Init();
	
}

int main(){
	//Ӳ����ʼ��
	HARDWARE_Init();

	while(1){
		//�ߵ�ƽ�ص�
		GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_SET);
		GPIO_WriteBit(GPIOC, GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_10, Bit_SET);

		DelayMs(500);
		
		//�͵�ƽ����
		GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_RESET);
		GPIO_WriteBit(GPIOC, GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_10, Bit_RESET);
		
		DelayMs(500);
	}
}

