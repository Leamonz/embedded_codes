#ifndef __LED_H
#define __LED_H

#define RED GPIO_Pin_7
#define GREEN GPIO_Pin_8
#define YELLOW GPIO_Pin_12
#define BLUE GPIO_Pin_10

struct LED_Status{
	_Bool LED1_Sta;
	_Bool LED2_Sta;
	_Bool LED3_Sta;
	_Bool LED4_Sta;
};

extern struct LED_Status led_status;

enum LED_ENUM{
	LED_OFF = 0,
	LED_ON
};

void LED_Init(void);


void LED1Set(enum LED_ENUM status);
void LED2Set(enum LED_ENUM status);
void LED3Set(enum LED_ENUM status);
void LED4Set(enum LED_ENUM status);

#endif
