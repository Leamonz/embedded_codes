#include "stm32f10x.h"
#include "delay.h"
#include "key.h"
#include "led.h"

void HardWare_Init()
{
	Delay_Init();
	Key_Init();//初始化按键
	LED_Init();//初始化LED
}
 int main(void)
 {	
		HardWare_Init();
		while(1)
		{
			unsigned char key=Key_Scan(1);
			switch(key)
			{
				case KEY1_PRES:
					LED1_Set((LED_ENUM)!led_status.LED1_Sta);
					break;
				case KEY2_PRES:
					LED2_Set((LED_ENUM)!led_status.LED2_Sta);
					break;
				case KEY3_PRES:
					LED3_Set((LED_ENUM)!led_status.LED3_Sta);
					break;
				case KEY4_PRES:
					LED4_Set((LED_ENUM)!led_status.LED4_Sta);
					break;
				default:
					break;
			}
			DelayMs(200);
		}
 }
