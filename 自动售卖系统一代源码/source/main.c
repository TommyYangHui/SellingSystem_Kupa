#define  _MAIN_C
#include "config.h"
 #include "main.h"
#include "Lcd1602.h"
#include "Time.h"
#include "keyboard.h"





void main()
{
	//P3=0xfe;
	
	TimerConfiguration(); //��ʼ����ʱ��
	InitLcd1602();	    //��ʼ��LCD1602
	ledA=0;
	ledB=0;
	ledC=0; 
	/* LcdShowStr(1, 0, "wait for init");
	 delay2s();
	 LcdFullClear(); */
	 LcdShowStr(1, 0, "welcome you");
	 TR0 = 1;								     
	while(1)
	{
			
		

	//	
	}
	

}
void TimerConfiguration()
{
    TMOD = 0x01; //ѡ������ʽ1
    TH0 = 0xD8;	   //10ms
    TL0 = 0xF0;
    EA = 1;			 //�����ж�
    ET0 = 1;		 //�򿪶�ʱ��0�ж�
    TR0 = 0;		 //������ʱ��0
}
void Timer0() interrupt 1
{
	 TH0 = 0xD8;
     TL0 = 0xF0;
     //if(error_cnt<3)
	//{
	
	 KeyScan();		  //����ɨ��    10msɨ��һ��
	 KeyAction();	  //������������
	 
	 
		
	
	 
}