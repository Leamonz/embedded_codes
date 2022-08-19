#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "wwdg.h"


void HARDWARE_Init(){
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	KEY_Init();

}


int main(void)
{	
	HARDWARE_Init();
	
	LED2Set(LED_ON);
	delay_ms(300);
	
	WWDG_Init(0x7f, 0x5f, WWDG_Prescaler_8);//�������ĳ�ʼֵΪ0x7f������ֵΪ0x5f��Ԥ��Ƶϵ��Ϊ8
	
	while(1){
		LED2Set(LED_OFF);
	}
}