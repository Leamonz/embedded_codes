#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "pwm.h"


void HARDWARE_Init(void){
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	PWM_Init(899, 0);//PWMÆµÂÊ£º 72MHz / 900 = 80KHz
}


int main(void)
{	
	u16 t = 0;
	u8 dir = 1;
	HARDWARE_Init();

	while(1){
		delay_ms(10);
		if(dir){//dir == 1----ÉÏÉý
			t++;
		}else{//dir == 0----ÏÂ½µ
			t--;
		}
		
		if(t > 300){
			dir = 0;
		}
		if (t == 0){
			dir = 1;
		}
		
		TIM_SetCompare2(TIM3, t);
	}
}

