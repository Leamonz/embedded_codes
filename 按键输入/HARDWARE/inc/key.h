#ifndef _KEY_H
#define _KEY_H

#define KEY1 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)
#define KEY2 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_11)
#define KEY3 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_12)
#define KEY4 GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2)

#define KEY1_PRES 3
#define KEY2_PRES 6
#define KEY3_PRES 9
#define KEY4_PRES 12

void Key_Init(void);//≥ı ºªØ
unsigned char Key_Scan(unsigned char mode);//∞¥º¸…®√Ë


#endif
