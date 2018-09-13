#include "exit_interrupt.h"



void Exit_Init(void)
{
  P1CON &= ~0X04;     //中断IO口设置为高阻输入
	P1PH  |= 0X04;     //中断IO口设置为高阻带上拉	
	
  //配置INT03上升沿中断、INT12/13下降沿中断、INT24/25双沿中断
  //下降沿设置	
	//INT0F = 0X0C ;    //xxxx 0000  0关闭 1使能
	//INT1F = 0X0C ;    //xxxx xxxx  0关闭 1使能
  //INT2F = 0X30 ;    //0000 xxxx  0关闭 1使能
    //上升沿设置	
	INT0R = 0X04 ;    //xxxx 0000  0关闭 1使能 
	INT1R = 0X00 ;    //xxxx xxxx  0关闭 1使能
	INT2R = 0X30 ;    //0000 xxxx  0关闭 1使能	
	//外部中断优先级设置
	IE  |= 0x05;	//0000 0x0x
	IE1 |= 0x08;	//0000 x000  INT2使能
	IP  |= 0X00;
	IP1 |= 0X00;
	EINT0 = 1;
	
}


