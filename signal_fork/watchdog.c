#include"my_headers.h"

int i,pid[3];


void f(int num)
{
static cnt;

cnt++;
if(cnt==3)
{
if((kill(pid[0],9))!=-1)
printf("child 1 killed...%d\n",pid[0]);
}
else if(cnt==7)
{
if((kill(pid[1],9))!=-1)
printf("child 2 killed...%d\n",pid[1]);
}
else if(cnt==9)
{
if((kill(pid[2],9))!=-1)
printf("child 3 killed...%d\n",pid[2]);
}

alarm(1);
}




main()
{

int t,v;
signal(SIGALRM,f);
alarm(1);

printf("parent id %d........\n",getpid());



for(i=0;i<3;i++)
{
if((pid[i]=fork())==0)
{
srand(getpid());
t=rand()%10+4;
printf("child %d ........%d.........%dsecs\n",i+1,getpid(),t);
sleep(t);
printf("child%d.......exiting\n");
exit(0);
}
}


while(wait(&v)!=-1);


printf("parent %d......exiting\n",getpid());
}
