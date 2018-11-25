

//信号的三种处理机制
//
//默认  忽略 自定义
//
//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>


int main()
{
	//忽略处理  SIG_IGN   SIG_DFL
   //阻塞一个信号后，信号依然会注册在pending集合中，
   //忽略一个信号后，信号来了就直接丢弃，不会注册

signal(2,SIG_IGN);
getchar();
signal(2,SIG_DFL);
while(1)
{
	fflush(stdout);
	printf("一切都会好起来的~~~\n");
    sleep(1);

}	
	return 0;
	}
