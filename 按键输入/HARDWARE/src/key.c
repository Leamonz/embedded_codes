#include "key.h"
#include "stm32f10x.h"
#include "delay.h"

void Key_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD,ENABLE);//ʹ��GPIOC,GPIOD��ʱ��
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;//����Ϊ�������룬����Ĭ��״̬�Ǹߵ�ƽ
	GPIO_Init(GPIOC,&GPIO_InitStruct);//��ʼ��PC11,PC12,PC13���ֱ��Ӧkey2,key3,key1
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_2;
	GPIO_Init(GPIOD,&GPIO_InitStruct);//��ʼ��PD2����Ӧkey4
}

//mode = 1---֧����������   mode = 0---��֧����������
unsigned char Key_Scan(unsigned char mode)
{
	static unsigned char key_up=1;
	if(mode==1)
		key_up=1;
	if(key_up&&(!KEY1||!KEY2||!KEY3||!KEY4))//�����ǵ͵�ƽ
	{
		DelayXms(10);//������
		key_up=0;//��ʾ���°���
		if(!KEY1) //ע�⣬���ﰴ��ʶ�������ȼ���KEY1>KEY2>KEY3>KEY4s
			return KEY1_PRES;
		else if(!KEY2) 
			return KEY2_PRES;
		else if(!KEY3) 
			return KEY3_PRES;
		else if(!KEY4) 
			return KEY4_PRES;
	}
	else if(KEY1&&KEY2&&KEY3&&KEY4)//û�а����Ǹߵ�ƽ
		key_up=1;
	return 0;//û�а����κΰ����򷵻�0
}
