#include "system.h"

TIMEOUT_PARA TIMEOUT_Para[2];
unsigned char Flag,Flag_P;

void System_Init(void)
{
	TimeOutDet_Init();
	Led_Init();
	Timer_Init();
	Key_Init();
	Exit_Init();
	EA = 1;
}

void System_Handle(void)
{
  P13 = ~P13;
	#if 1
	if(!Flag)
	{
		Flag = 1;
		TimeOut_Record(&TIMEOUT_Para[0],Delay_Time);
		Led_Open();
		//Flag_P = 1;
	}
	if(1 == TimeOutDet_Check(&TIMEOUT_Para[0]))
	{
		//Flag_P = 0;
		#if 1
	  PCON |= 0x02;  //PCON 的 bit1 STOP 位写 1，配置 MCU 进入 STOP 模式	
    _nop_();       //至少需要 4 个_nop_()
    _nop_();
    _nop_();
    _nop_();
		_nop_();
    _nop_();
		Led_Close();
		//TR0=1;
		#endif
		//Stop_Mode();
		
	}
	#if 0
	if(Key_Down())
	{
		Led_Open();
	}
	else
	{
		Led_Close();
	}
	#endif
	#endif
	
}

/*****************************************************
*函数名称：void EX0/1/2() interrupt	0/2/10
*函数功能：外部中断初始化
*入口参数：void
*出口参数：void
*****************************************************/
void int0()interrupt 0
{
	//EINT0  =   0;		//关闭INT0中断
	//INT0R &= ~(1<<2); 	//关闭INT00上升沿中断
	//Led_Open();
	//PCON &= ~0x02;  //PCON 的 bit1 STOP 位写 1，配置 MCU 进入 STOP 模式
	//P26 = ~P26;	
}

void EX1() interrupt	2
{
   //P26 = ~P26;
	#if 0
	if(P16 == 0)
	{
		INT1_flag = 0x10; //INT12产生中断
	}
	if(P17 == 0)
	{
		INT1_flag = 0x20; //INT13产生中断
	}
	#endif
}

void EX2() interrupt	10
{
    //P26 = ~P26;
}

/**************************************************
*函数名称：void timer0/1/2() interrupt 1/3/5
*函数功能：定时器中断产生方波
*入口参数：void
*出口参数：void
**************************************************/
void timer0() interrupt 1
{
  TL0 = (65536 - 1000)%256;
	TH0 = (65536 - 1000)/256;
	//P20 = ~P20;	
	TimeOutDet_DecHandle();
	
}

void timer1() interrupt 3
{
	//P21 = ~P21;
}

void Timer2Int(void) interrupt 5
{		
	TF2 = 0;   //溢出清零
    //P26 = ~P26;
}

