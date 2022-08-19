#include "stm32f10x.h"
#include "iwdg.h"

void IWDG_Init(u8 prer, u16 rlr){
	//��ȡ���Ĵ���д����
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	
	//�����ö������Ź���Ԥ��Ƶϵ����ȷ��ʱ��
	IWDG_SetPrescaler(prer);
	
	//�����ÿ��Ź���װ��ֵ��ȷ�����ʱ��
	IWDG_SetReload(rlr);
	
	//��ʹ�ܿ��Ź�
	IWDG_Enable();
	
	//��Ӧ�ó���ι��
	IWDG_ReloadCounter();
}
