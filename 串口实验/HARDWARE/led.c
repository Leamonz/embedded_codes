#include "led.h"
#include "stm32f10x.h"

struct LED_Status led_status;

void LED_Init(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);// πƒ‹ ±÷”
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_10;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	LED1Set(LED_OFF);
	LED2Set(LED_OFF);
	LED3Set(LED_OFF);
	LED4Set(LED_OFF);

}

void LED1Set(enum LED_ENUM status){
	GPIO_WriteBit(GPIOC, RED, status != LED_ON ? Bit_SET : Bit_RESET);
	led_status.LED1_Sta = (_Bool)status;
}

void LED2Set(enum LED_ENUM status){
	GPIO_WriteBit(GPIOC, GREEN, status != LED_ON ? Bit_SET : Bit_RESET);
	led_status.LED2_Sta = (_Bool)status;
}
void LED3Set(enum LED_ENUM status){
	GPIO_WriteBit(GPIOA, YELLOW, status != LED_ON ? Bit_SET : Bit_RESET);
	led_status.LED3_Sta = (_Bool)status;
}
void LED4Set(enum LED_ENUM status){
	GPIO_WriteBit(GPIOC, BLUE, status != LED_ON ? Bit_SET : Bit_RESET);
	led_status.LED4_Sta = (_Bool)status;
}
