#include "stm32f10x.h"
#include "iwdg.h"

void IWDG_Init(u8 prer, u16 rlr){
	//①取消寄存器写保护
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	
	//②设置独立看门狗的预分频系数，确定时钟
	IWDG_SetPrescaler(prer);
	
	//③设置看门狗重装载值，确定溢出时间
	IWDG_SetReload(rlr);
	
	//④使能看门狗
	IWDG_Enable();
	
	//⑤应用程序喂狗
	IWDG_ReloadCounter();
}
