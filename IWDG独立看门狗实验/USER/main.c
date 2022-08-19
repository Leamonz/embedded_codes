#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "iwdg.h"


void HARDWARE_Init(void){
	delay_init();
	LED_Init();
	KEY_Init();
	IWDG_Init(4, 625);//预分频系数为4， 重装载寄存器的值为625 ------   溢出时间1s
}
int main(void)
{	
	HARDWARE_Init();

	
	delay_ms(300);//如果不喂狗，那么程序会一直复位，LED1会闪烁
	
	LED1Set(LED_ON);//先点亮LED1
	while(1){
		if(KEY_Scan(0) == KEY1_PRES){
			IWDG_ReloadCounter();//喂狗
		}
	}
}