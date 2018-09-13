#include "led.h"




void Led_Open(void)
{
	Led_Pin = 1;
}

void Led_Close(void)
{
	Led_Pin = 0;
}

void Led_Init(void)
{
	P0CON=0xFF;
	P1CON=0xFF;
	P2CON=0xFF;
	P5CON=0xFF;
	Led_Close();
	//Led_Open();
}
