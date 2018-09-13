#include "stop_mode.h"
#include "intrins.h"

void Stop_Mode(void)
{
	TR0    = 0;		//关闭定时器	
	OPINX  = 0xC1;
	OPREG &= ~(1<<7);//关闭看门狗
	
	INT0R |= 1<<2;	//打开INT00上升沿中断
	
	EINT0  = 1;		//打开INT0中断
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
	OPREG |= 1<<7;//打开看门狗	
	TR0=1;
}


