#include "exit_interrupt.h"



void Exit_Init(void)
{
  P1CON &= ~0X04;     //�ж�IO������Ϊ��������
	P1PH  |= 0X04;     //�ж�IO������Ϊ���������	
	
  //����INT03�������жϡ�INT12/13�½����жϡ�INT24/25˫���ж�
  //�½�������	
	//INT0F = 0X0C ;    //xxxx 0000  0�ر� 1ʹ��
	//INT1F = 0X0C ;    //xxxx xxxx  0�ر� 1ʹ��
  //INT2F = 0X30 ;    //0000 xxxx  0�ر� 1ʹ��
    //����������	
	INT0R = 0X04 ;    //xxxx 0000  0�ر� 1ʹ�� 
	INT1R = 0X00 ;    //xxxx xxxx  0�ر� 1ʹ��
	INT2R = 0X30 ;    //0000 xxxx  0�ر� 1ʹ��	
	//�ⲿ�ж����ȼ�����
	IE  |= 0x05;	//0000 0x0x
	IE1 |= 0x08;	//0000 x000  INT2ʹ��
	IP  |= 0X00;
	IP1 |= 0X00;
	EINT0 = 1;
	
}


