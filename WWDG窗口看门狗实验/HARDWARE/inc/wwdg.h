#ifndef __WWDG_H__
#define __WWDG_H__
#include "sys.h"

//tr --- �������ĳ�ʼֵ
//wr --- �ϴ��ڵ�ֵ
//prer --- Ԥ��Ƶϵ��
void WWDG_Init(u8 tr, u8 wr, u32 prer);

void WWDG_Reset_Counter(u8 cnt);
void WWDG_IRQHandler();


#endif

