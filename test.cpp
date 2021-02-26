#include  <reg51.h>                         /*=== 头文件包含 ===*/
#include  <absacc.h>
#include  <intrins.h>
sbit P1_7=P1^7;
sbit P3_3=P3^3;
sbit P3_4=P3^4;
void delay(unsigned int i1);

void int1() interrupt 2 using 1
{//外部中断1服务程序
    while(1)
    {
       P1=0x80&P1;
       P1_7=1; delay(30);		 //P1.7 发出频率声音
       P1_7=0; delay(30);
       if (P3_3) break;		   // 故障排除 
    }
}
void main(void)
{
    P1=0x00;
	
    while(1)
    {
       if (!P3_4)				  //启动运行 
       {
          IE=IE|0x84;				// 开外部中断1 	 开中断 
          IP=IP|0x04;			   //外部 	INT1 优先
          PSW=0;
	 
          while(1)
          {
            P1=0x01;                                                                                                                                                                                                                                                                                                                                                     			  // 1号工序
		    delay(2000);
            P1=0x02;  delay(2000);	  //2号工序
            P1=0x04;  delay(2000);
            P1=0x08;  delay(2000);
            P1=0x10;  delay(2000);
            P1=0x20;  delay(2000);
            P1=0x40;  delay(2000);	 //7号工序
          }
       }
    }
}
// delay(1000);//12M ,0.5S
void delay(unsigned int i1)
{
   unsigned int ii;
   unsigned char jj;
   for (ii=0;ii<i1;ii++)
      for (jj=0;jj<162;jj++);
}
