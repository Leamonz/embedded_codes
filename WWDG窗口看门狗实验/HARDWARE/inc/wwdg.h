#ifndef __WWDG_H__
#define __WWDG_H__
#include "sys.h"

//tr --- 计数器的初始值
//wr --- 上窗口的值
//prer --- 预分频系数
void WWDG_Init(u8 tr, u8 wr, u32 prer);

void WWDG_Reset_Counter(u8 cnt);
void WWDG_IRQHandler();


#endif

