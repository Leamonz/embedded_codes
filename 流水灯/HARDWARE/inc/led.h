#ifndef __LED_H
#define __LED_H
#include "stm32f10x.h"
void LED_Init(void);

typedef struct
{
	_Bool LED1_Sta;
	_Bool LED2_Sta;
	_Bool LED3_Sta;
	_Bool LED4_Sta;
}LED_Status;

typedef enum
{
	LED_OFF = 0,
	LED_ON
}LED_ENUM;

void LED1_Set(LED_ENUM status);
void LED2_Set(LED_ENUM status);
void LED3_Set(LED_ENUM status);
void LED4_Set(LED_ENUM status);


#endif
