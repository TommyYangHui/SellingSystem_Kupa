#ifndef _CONFIG_H
#define _CONFIG_H

/* 通用头文件 */
#include <reg52.h>
#include <intrins.h>

/* 数据类型定义 */
typedef  signed    char    int8;    // 8位有符号整型数
typedef  signed    int     int16;   //16位有符号整型数
typedef  signed    long    int32;   //32位有符号整型数
typedef  unsigned  char    uint8;   // 8位无符号整型数
typedef  unsigned  int     uint16;  //16位无符号整型数
typedef  unsigned  long    uint32;  //32位无符号整型数

sbit PWM=P3^0;

/* IO引脚分配定义 */
#define LCD1602_DB  P0   //1602液晶数据端口
sbit LCD1602_RS = P2^6;
sbit LCD1602_RW = P2^5;
sbit LCD1602_E = P2^7;

#define KeyPort P1			  //���尴��״̬������״̬����


#define key_state_0 0      
#define key_state_1 1
#define key_state_2 2
#define key_state_3 3

#define NO_key        0

sbit ledA=P2^0;
sbit ledB=P2^1;
sbit ledC=P2^2;
#endif
