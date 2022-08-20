#include "stm32f10x.h"
#include "delay.h"


void HARDWARE_Init(void){
	delay_init();
}


int main(void)
{	
	HARDWARE_Init();
	while(1){
		;
	}
}

