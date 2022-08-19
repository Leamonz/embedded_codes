#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "iwdg.h"


void HARDWARE_Init(void){
	delay_init();
	LED_Init();
	KEY_Init();
	IWDG_Init(4, 625);//Ԥ��Ƶϵ��Ϊ4�� ��װ�ؼĴ�����ֵΪ625 ------   ���ʱ��1s
}
int main(void)
{	
	HARDWARE_Init();

	
	delay_ms(300);//�����ι������ô�����һֱ��λ��LED1����˸
	
	LED1Set(LED_ON);//�ȵ���LED1
	while(1){
		if(KEY_Scan(0) == KEY1_PRES){
			IWDG_ReloadCounter();//ι��
		}
	}
}