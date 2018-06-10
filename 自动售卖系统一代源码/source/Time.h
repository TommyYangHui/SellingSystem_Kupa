#ifndef _TIME_H
#define _TIME_H


#ifndef _TIME_C
//extern uint8 setIndex = 0;  //时间设置索引
//extern int8 hello[];
//extern uint8 inputmean[];
extern uint8 len;
//extern int32 num1;
extern uint8 str[12];
extern uint32 type_A1,type_B1,type_C1;

//uint8 error_cnt=0;
#endif

void delay2s(void);
void KeyAction();
uint8 LongToString(uint8 *str, int32 dat);
//void welcome();			   
#endif