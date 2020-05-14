#include"my_headers.h"


int pid[4];

void f(int num)
{
static int x;
x++;
if(x==3)
{
	printf("child 1 exited.....%d\n",pid[1]);
	kill(pid[1],-9);
}

if(x==5)
{
	printf("child 2 exited.....%d\n",pid[2]);
	kill(pid[2],-9);
}

if(x==8)
{
	printf("child 3 exited.....%d\n",pid[3]);
	kill(pid[3],-9);
}

alarm(1);

}

main()
{

int i,t;

signal(SIGALRM,f);

for(i=1;i<=3;i++)
{
if((pid[i]=fork())==0)
{
	srand(getpid());
	t=rand()%10+1;
	printf("child %d sleep for %d secs process=%d\n",i,t,getpid());
	sleep(t);

//	exit(1);
}
}


//alarm(1);
//while(wait(0)!=-1);
printf("parent exiting..........\n");
exit(0);

}
