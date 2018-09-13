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
	  PCON |= 0x02;  //PCON �� bit1 STOP λд 1������ MCU ���� STOP ģʽ	
    _nop_();       //������Ҫ 4 ��_nop_()
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
*�������ƣ�void EX0/1/2() interrupt	0/2/10
*�������ܣ��ⲿ�жϳ�ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void int0()interrupt 0
{
	//EINT0  =   0;		//�ر�INT0�ж�
	//INT0R &= ~(1<<2); 	//�ر�INT00�������ж�
	//Led_Open();
	//PCON &= ~0x02;  //PCON �� bit1 STOP λд 1������ MCU ���� STOP ģʽ
	//P26 = ~P26;	
}

void EX1() interrupt	2
{
   //P26 = ~P26;
	#if 0
	if(P16 == 0)
	{
		INT1_flag = 0x10; //INT12�����ж�
	}
	if(P17 == 0)
	{
		INT1_flag = 0x20; //INT13�����ж�
	}
	#endif
}

void EX2() interrupt	10
{
    //P26 = ~P26;
}

/**************************************************
*�������ƣ�void timer0/1/2() interrupt 1/3/5
*�������ܣ���ʱ���жϲ�������
*��ڲ�����void
*���ڲ�����void
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
	TF2 = 0;   //�������
    //P26 = ~P26;
}

