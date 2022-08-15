#include "stm32f10x.h"
#include "delay.h"
#include "key.h"
#include "led.h"

void HardWare_Init()
{
	Delay_Init();
	KEY_Init();//初始化按键
	LED_Init();//初始化LED
}
 int main(void)
 {	
		HardWare_Init();
	 LED1Set(LED_OFF);
	 LED2Set(LED_OFF);
	 LED3Set(LED_OFF);
	 LED4Set(LED_OFF);
		while(1)
		{
			unsigned char key = KEY_Scan(1);
			if(key){
					switch (key){
					case KEY1_PRES:
						LED1Set(!led_status.LED1_Sta);
						break;
					case KEY2_PRES:
						LED2Set(!led_status.LED2_Sta);
						break;
					case KEY3_PRES:
						LED3Set(!led_status.LED3_Sta);
						break;
					case KEY4_PRES:
						LED4Set(!led_status.LED4_Sta);
						break;
					default:
						break;
				}
			}
			DelayMs(200);
		}
 }
