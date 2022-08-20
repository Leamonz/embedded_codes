#ifndef __TIM_INT_H__
#define __TIM_INT_H__
#include "sys.h"
void TIM_Init(u16 arr, u16 psc);

void TIM2_IRQHandler(void);

#endif
