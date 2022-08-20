#include "stm32f10x.h"
#include "delay.h"
#include "TIM_INT.h"
#include "led.h"


void HARDWARE_Init(void){
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	TIM_Init(4999, 7199);//500ms
	LED_Init();
}


int main(void)
{	
	HARDWARE_Init();
	while(1){
		LED2Set((enum LED_ENUM)!led_status.LED2_Sta);
		delay_ms(200);
	}
}

