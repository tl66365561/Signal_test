//信号的使用机制
//
//一秒钟之内count执行了多少次，
//
//
//存在问题：gdb调试怎么一次一次的观察 count?怎么一次一次的执行for循环?
//
//
 #include<unistd.h>
 #include<stdio.h>
 #include<signal.h>

 /*int main()
 {
	 int count=0;
	 alarm(1);
	 for(;1;count++)
	 {
		 printf("count= %d\n",count);
		 
		 
		 }
	 
	 
	 
	 
	 return 0;
	 }
	 */



void printsigset(sigset_t *set)
{
	int i=1;
	for(;i<32;i++)
	{
	if(	sigismember(set,i))
  {
    fflush(stdout);
    putchar('1');
 }
    else
     {
        fflush(stdout);
        putchar('0');
    
	}
	
	}
	printf("\n");
}

 int  main()
{
	sigset_t s,p;
	sigemptyset(&s);
	sigaddset(&s,SIGINT);
	sigprocmask(SIG_BLOCK,&s,NULL);
	while(1)
	{
		sigpending(&s);
		printsigset(&s);
		sleep(1);
	}
		
    return 0;
	}
