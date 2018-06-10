#define  _KEY_BOARD_C
#include "config.h"
#include "keyboard.h"

//#include "main.h"



uint8 KeyScan()
{    
    uint8 key_temp;
    uint8 key_num = NO_key;
    static uint8 key_status = key_state_0;         //����״̬

    //�߷�ת��ɨ�����
    KeyPort = 0x0f;
    key_temp = KeyPort;
    KeyPort = 0xf0;
    key_temp |= KeyPort;
    KeyPort = 0xff;

    switch(key_status)
    {
        case key_state_0:                                    //״̬��Ϊ��ʼ״̬
            if(key_temp != 0xff)
                key_status = key_state_1;
            break;
        case key_state_1:                                   //״̬һΪ��������״̬
            if(key_temp == 0xff)
                key_status = key_state_0;             //��ֻ�Ƕ���������״̬��
            else
            {
                key_status = key_state_2;            //��ȷʵ���£�����״̬��
                switch(key_temp)
                {
                    case 0x7e:        //0111 1110
                        key_num = 'A';	
                        break;
                    case 0xbe:        //1011 1110
                        key_num = '3';	
                        break;
                    case 0xde:        //1101 1110
                        key_num = '2';	
                        break;
                    case 0x7d:        //0111 1101
                        key_num = 'B';	 
                        break;
                    case 0xbd:        //1011 1101
                        key_num = '6';	 
                        break;
                    case 0xdd:        //1101 1101
                        key_num = '5';	  
                        break;
                    case 0x7b:        //0111 1011
                        key_num = 'C';	  
                        break;
                    case 0xbb:        //1011 1011
                        key_num = '9';	   
                        break;
                    case 0xdb:        //1101 1011
                        key_num = '8';	   
                        break;
                    case 0xb7:        //1011 0111
                        key_num = 'F';	   
                        break;
                    case 0x77:        //0111 0111
                        key_num = 'D';                  //*
                        break;
                    case 0xd7:        //1101 0111
                        key_num = '0';                  //#
                        break;		   
                    case 0xee:        //1110 1110
                        key_num = '1';                 //F1
                        break;
                    case 0xed:        //1110 1101
                        key_num = '4';                  //F2
                        break;
                    case 0xeb:        //1110 1011
                        key_num = '7';                  //F3
                        break;
                    case 0xe7:        //1110 0111
                        key_num = 'E';                  //F4
                        break;
                }
            }
            break;
        case key_state_2:                                      //״̬����ʾȷʵ�а�������
            if(key_temp == 0xff)
                key_status = key_state_3;                //����⵽���֣�����״̬��
            break;
        case key_state_3:
            if(key_temp == 0xff)
                key_status = key_state_0;               //���ж�ȷʵ���ֺ󣬵��س�ʼ״̬��
            else
                key_status = key_state_2;              //��ֻ�Ƕ���������������֣�����״̬��
            break;
    }
    return key_num;
}

