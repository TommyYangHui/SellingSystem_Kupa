#ifndef _LCD1602_H
#define _LCD1602_H

#ifndef _LCD1602_C
#endif	

void InitLcd1602();
void Delay1us(uint16 a);

void LcdSetCursor(uint8 x, uint8 y);
void LcdShowStr(uint8 x, uint8 y, uint8 *str);
//void LcdOpenCursor();
//void LcdCloseCursor();
void LcdFullClear();
//void LcdWriteDat(uint8 dat);
//void LcdWriteCmd(uint8 cmd);
//void LcdWaitReady();

#endif
