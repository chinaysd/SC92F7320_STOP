#include "stop_mode.h"
#include "intrins.h"

void Stop_Mode(void)
{
	TR0    = 0;		//�رն�ʱ��	
	OPINX  = 0xC1;
	OPREG &= ~(1<<7);//�رտ��Ź�
	
	INT0R |= 1<<2;	//��INT00�������ж�
	
	EINT0  = 1;		//��INT0�ж�
	PCON |= 0X02;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	
	OPINX  = 0xC1;
	OPREG |= 1<<7;//�򿪿��Ź�	
	TR0=1;
}


