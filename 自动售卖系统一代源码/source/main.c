#define  _MAIN_C
#include "config.h"
 #include "main.h"
#include "Lcd1602.h"
#include "Time.h"
#include "keyboard.h"





void main()
{
	//P3=0xfe;
	
	TimerConfiguration(); //初始化定时器
	InitLcd1602();	    //初始化LCD1602
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
    TMOD = 0x01; //选择工作方式1
    TH0 = 0xD8;	   //10ms
    TL0 = 0xF0;
    EA = 1;			 //打开总中断
    ET0 = 1;		 //打开定时器0中断
    TR0 = 0;		 //启动定时器0
}
void Timer0() interrupt 1
{
	 TH0 = 0xD8;
     TL0 = 0xF0;
     //if(error_cnt<3)
	//{
	
	 KeyScan();		  //按键扫描    10ms扫描一次
	 KeyAction();	  //按键动作函数
	 
	 
		
	
	 
}