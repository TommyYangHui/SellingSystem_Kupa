#define  _TIME_C
#include "config.h"
#include "keyboard.h"
#include "Time.h"
#include "main.h"
#include "Lcd1602.h"
//uint8 hello[]={'w','e','l','c','o','m','e',' ','t','o',' ', 'y','o','u'} ;
//uint8 inputmean[]=" please input ";
int32 num1 = 0,result,sale_sum;
uint8 len = 0;
uint8 str[12]; 

uint32 sum,type_A,type_B,type_C,type_A1,type_B1,type_C1;
//uint8 dian_qu;
void delay2s(void)   //误差 0us
{
    unsigned char a,b,c;
    for(c=127;c>0;c--)
        for(b=235;b>0;b--)
            for(a=32;a>0;a--);
    _nop_();  //if Keil,require use intrins.h
}
 void dianji()
{
	
	    	 if(type_A1!=0)
		{
		
			ledA=1;
			delay2s();
			ledA=0;	
				   
		}
		if(type_B1!=0)
		{
		
			ledB=1;
			delay2s();
			ledB=0;	
				   
		}
		if(type_C1!=0)
		{
		
			ledC=1;
			delay2s();
			ledC=0;	
				   
		}



	
	
}
uint8 LongToString(uint8 *str, int32 dat)
{
	int8 i = 0;
	uint8 len = 0;
	uint8 buf[12];

	if(dat < 0)
	{
		dat = -dat;
		*str++ = '-';
		len++;
	}
	do{
		buf[i++] = dat % 10;
		dat /= 10;
		}while(dat > 0);
	len += i;
	while(i-- > 0)
	{
		*str++ = buf[i] + '0';
	}
	*str = '\0';

	return len;
		
} 
void guanli()
{
	LcdFullClear();
	
	sale_sum=type_A*2+type_B*4+type_C*5;
	LcdShowStr(0, 0, "nA");
	len = LongToString(str, type_A);
	LcdShowStr(3, 0, str);
	LcdShowStr(8, 0, "nB");
	len = LongToString(str, type_B);
	LcdShowStr(11, 0, str);
	LcdShowStr(0, 1, "nC");
	len = LongToString(str, type_C);
	LcdShowStr(3, 1, str);
	LcdShowStr(8, 1, "summ");
	len = LongToString(str, sale_sum);
	LcdShowStr(12, 1, str);	
}
void jiesuan()
{
 	if(num1<sum)
	{
		LcdShowStr(1, 0, "the money less"); 
		LcdShowStr(1, 1, "plea input more ");	
		num1=0;
		
	}
	else if(num1==sum)
	{
		LcdFullClear();
		LcdShowStr(1, 0, "take goods");
		LcdShowStr(1, 1, "thanks");
		num1=0;
		sum=0;
		delay2s();
           	LcdFullClear();
		 LcdShowStr(1, 0, "move wait"); 
				
		dianji();
		  LcdFullClear();
		  LcdShowStr(1, 0, "thank you");

		  

		
		type_A=type_A+type_A1;
		type_B=type_B+type_B1;
		type_C=type_C+type_C1;
		type_A1=0;
		type_B1=0;
		type_C1=0;

		delay2s();
		LcdFullClear();
		  LcdShowStr(1, 0, "welcome you");

		

	}
	else if(num1>sum)
	{	
		LcdFullClear();
		LcdShowStr(1, 0, "charge you RMB");
		result=num1-sum;
		len = LongToString(str, result);
		LcdShowStr(len, 1, str); 
		LcdShowStr(6, 1, "thanks");
		sum=0;
		num1=0;
		delay2s();
		LcdFullClear();
		 LcdShowStr(1, 0, "move wait");
		dianji();
		LcdFullClear();
		  LcdShowStr(1, 0, "thank you");
		type_A=type_A+type_A1;
		type_B=type_B+type_B1;
		type_C=type_C+type_C1;
		type_A1=0;
		type_B1=0;
		type_C1=0;

		delay2s();
		LcdFullClear();
		  LcdShowStr(1, 0, "welcome you");
	/*	LcdFullClear();
		LcdShowStr(1, 0, "take goods"); 
		LcdShowStr(1, 0, "thanks"); */
		
	}
}   
void moneyinput(uint8 n)
{
	//len = LongToString(str, n);
	num1 = num1*10 + n;
   	len = LongToString(str, num1);
	LcdShowStr(16 - len, 1, str);
	
}
/*void welcome()
{
	LcdShowStr(0, 0, "welcome to you");
	LcdShowStr(0, 1, " please input ");
/*	uint16 i,j;
	for(i=0;i<14;i++)
	{
		str[i]=hello[i];	
	}
	LcdShowStr(0, 0, str);
	for(j=0;j<15;j++)
	{
		str[j]=inputmean[j];	
	}
	LcdShowStr(0, 1, str);	 */
/*	str[1]='0';
	str[2] = (TIME[6] >> 4) + '0';
	str[3] = (TIME[6] & 0x0F) + '0';
	str[4] = '-';
	str[5] = (TIME[4] >> 4) + '0';
	str[6] = (TIME[4] & 0x0F) + '0';
	str[7] = '-';
	str[8] = (TIME[3] >> 4) + '0';
	str[9] = (TIME[3] & 0x0F) + '0';
	str[10] = '\0';	*/
	
//} 
void KeyAction()
{
	uint8 keycode;
	keycode=KeyScan();
	switch(keycode)
	{
		case 'A':
		{
			LcdFullClear();
		 	LcdShowStr(1, 0, "num rice");
			LcdShowStr(1, 1, "price  2yuan");
			sum=sum+2;
		
			type_A1++;
			len = LongToString(str, type_A1);
			LcdShowStr(11+len, 0, str);
		}
		break;
		case 'B':
		{
			LcdFullClear();
		 	LcdShowStr(1, 0, "num  veg1");
			LcdShowStr(1, 1, "price  4yuan");
			sum=sum+4;
			
			type_B1++;
			len = LongToString(str, type_B1);
			LcdShowStr(11+len, 0, str);
		}
		break;  
	      case 'C':
		{
			LcdFullClear();
		 	LcdShowStr(1, 0, "num  veg2");
			LcdShowStr(1, 1, "price  5yuan");
			sum=sum+5;
			
			type_C1++;
			len = LongToString(str, type_C1);
			LcdShowStr(11+len, 0, str);
		}
		break;


	}
	if  ((keycode>='0') && (keycode<='9') && sum!=0)
	{
		LcdFullClear();
	 
		moneyinput(keycode-'0');
	}
	else if (keycode == 'D')  //确定键
     {
       
	 if(sum!=0 && num1==0)
	 {		  
	  	LcdFullClear();
	 	LcdShowStr(1, 0, "input money");
	 }
	 
	 else if(num1!=0)
	 {
	 	LcdFullClear();
		LcdShowStr(1, 0, "wait for acc");	 
	 	jiesuan();
	 }
	
	 else if(num1==0 && sum==0)
	 {
	 	//sum=0;
	 	LcdFullClear();
		LcdShowStr(1, 0, "wlcome you");
			 
	 	
	 } 

      // jiesuan();
     }
     else if (keycode == 'E')  //	 管理员模式
     {
     		guanli();	
     }
     else if (keycode == 'F')  //	 复位模式
     {
     		LcdFullClear();
		LcdShowStr(1, 0, "wlcome you");

     		sum=0;
		num1=0;
		type_A1=0;
		type_B1=0;
		type_C1=0;		
     }
	 
   /* if  ((keycode=='1') && (keycode=='2') && (keycode=='3'))  //本例中不响应字符键
    {
    	//	num1 = num1*10 + (keycode-'0');
    		//len = LongToString(str, num1);
	//	LcdShowStr(16 - len, 1, str);
	
/*	if(numscan==0)
	{
		//keyact=1;//欢迎界面消失
		LcdShowStr(1, 0, "input passward 3");
		mimaku[cou]=DIG_CODE[keycode-'0'];
		
		LcdShowStr(15 - cou, 1, "*");
		cou++;
			if(cou==8)
			{
				 cou=0;
				 temp=0;
				for(in=0;in<=7;in++)
				{
  					if(mima[in]!=mimaku[in])
    					{temp=1; break;}
 				}
				if(temp==1) 
				{
				//	P2=0x01;
					LcdFullClear();
					LcdShowStr(1, 0, "input again 2");
					error_cnt++;
					if(error_cnt==2)
					{
					 	LcdFullClear();
						LcdShowStr(1, 0, "input again 1");
						
					}
					else if(error_cnt==3)
					{
						numscan=1;
						LcdFullClear();
						LcdShowStr(1, 0, "no chance");
						
					}
				//	LcdFullClear();
					
					//cou=0;

				/*	LED2=0;
					Delay10ms(2);
					LED2=1;
					Delay10ms(2);
					LED2=0;
					Delay10ms(2);
					LED2=1; */
	/*			}
				else	*/
				/*	LED2=0;
					Delay10ms(10);
					LED2=1; */
					//P2=0x02;
				//	
			/*	{   
				 LcdFullClear();
				 LcdShowStr(1, 0, "ok");
				//cou=0;
				}
				
			} 
	}  */
    		
			
		
			 
		

    			
   // }
   /* else if (keycode == 'A')  //向上键，递增当前设置位的值
    {
     	//IncSetTime();
    }
    else if (keycode == 'B')  //向下键，递减当前设置位的值
    {
       // DecSetTime();
    }
    else if (keycode == 'F')  //向左键，向左切换设置位
    {
        //LeftShiftTimeSet();
    }
    else if (keycode == 'D')  //向右键，向右切换设置位
    {
       // RightShiftTimeSet();
    }
    else if (keycode =='E')  //回车键，进入设置模式/启用当前设置值
    {
       /* if (setIndex == 0)  //不处于设置状态时，进入设置状态
        {
            EnterTimeSet();
        }
        else                //已处于设置状态时，保存时间并退出设置状态
        {
            ExitTimeSet(1);
        } */
    //}	 
    /*else if (keycode == 'C')  //Esc键，取消当前设置
    {
       // ExitTimeSet(0);
    }	 */
}