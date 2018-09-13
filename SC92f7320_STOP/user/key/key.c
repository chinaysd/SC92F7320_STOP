#include "key.h"


void Key_Init(void)
{
	P2CON &= ~0X01;
	P2PH  |= 0X01;
}

unsigned char Key_Down(void)
{
	if(0 == KEY_PIN)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}