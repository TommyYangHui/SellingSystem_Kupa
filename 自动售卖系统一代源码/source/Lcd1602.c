#define  _LCD1602_C
#include "config.h"
#include "Lcd1602.h"
#include "Time.h"

void LcdWaitReady()
{
	uint8 sta;
	LCD1602_DB = 0xFF;
	LCD1602_RS = 0;
	LCD1602_RW = 1;
	do	{
		LCD1602_E=1;
		sta=LCD1602_DB;			  //读取状态字
		LCD1602_E=0;
	
	} while(sta & 0x80);
}

void LcdWriteCmd(uint8 cmd)
{
	LcdWaitReady();
	LCD1602_RS = 0;
	LCD1602_RW = 0;
	LCD1602_DB=cmd;
	Delay1us(10);
	LCD1602_E=1;
	Delay1us(10);
	LCD1602_E=0;

}
void LcdWriteDat(uint8 dat)
{
	
  LcdWaitReady();
	LCD1602_RS = 1;
	LCD1602_RW = 0;
	LCD1602_DB=dat;
	Delay1us(10);
	LCD1602_E=1;
	Delay1us(10);
	LCD1602_E=0; 
}
void LcdSetCursor(uint8 x,uint8 y)
{
	uint8 addr;
	if(y==0)
		addr=0x00+x;					  
	else
		addr=0x40+x;
	LcdWriteCmd(addr | 0x80);	//忙
	
}
void LcdShowStr(uint8 x, uint8 y, uint8 *str)
{
	LcdSetCursor(x, y);
	while(*str!='\0')
	{
	 	LcdWriteDat(*str++);
	}
}
/* ������� */
void LcdFullClear()
{
    LcdWriteCmd(0x01);
}
/* 打开光标的闪烁效果 */
/*void LcdOpenCursor()
{
	LcdWriteCmd(0x0F);
} */
/* 关闭光标显示 */
/*void LcdCloseCursor()
{
	LcdWriteCmd(0x0C);
}*/
void Delay1us(uint16 a)
{
	uint16 b,c;
	for(c=a;c>0;c--)
		for(b=110;b>0;b--);
}
void InitLcd1602()
{						 	
	LcdWriteCmd(0x38);
	LcdWriteCmd(0x0C);
	LcdWriteCmd(0x06);
	LcdWriteCmd(0x01);
}