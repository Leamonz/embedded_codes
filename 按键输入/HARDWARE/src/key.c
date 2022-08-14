#include "key.h"
#include "stm32f10x.h"
#include "delay.h"

void Key_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD,ENABLE);//使能GPIOC,GPIOD的时钟
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;//设置为上拉输入，保持默认状态是高电平
	GPIO_Init(GPIOC,&GPIO_InitStruct);//初始化PC11,PC12,PC13。分别对应key2,key3,key1
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_2;
	GPIO_Init(GPIOD,&GPIO_InitStruct);//初始化PD2。对应key4
}

//mode = 1---支持连续输入   mode = 0---不支持连续输入
unsigned char Key_Scan(unsigned char mode)
{
	static unsigned char key_up=1;
	if(mode==1)
		key_up=1;
	if(key_up&&(!KEY1||!KEY2||!KEY3||!KEY4))//按下是低电平
	{
		DelayXms(10);//消抖动
		key_up=0;//表示按下按键
		if(!KEY1) //注意，这里按键识别有优先级，KEY1>KEY2>KEY3>KEY4s
			return KEY1_PRES;
		else if(!KEY2) 
			return KEY2_PRES;
		else if(!KEY3) 
			return KEY3_PRES;
		else if(!KEY4) 
			return KEY4_PRES;
	}
	else if(KEY1&&KEY2&&KEY3&&KEY4)//没有按下是高电平
		key_up=1;
	return 0;//没有按下任何按键则返回0
}
