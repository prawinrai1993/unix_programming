#include"my_headers.h"


void f(int num)
{
printf("child  exited...\n");

}

main()
{
struct sigaction v;
int t,i;

v.sa_handler=f;
v.sa_flags=SA_NOCLDWAIT;

sigaction(SIGCHLD,&v,NULL);


for(i=1;i<=3;i++)
{

if(fork()==0)
{
	srand(getpid());
	t=rand()%10+1;
	printf("child %d created for %d secs\n",i,t);
	sleep(t);
	exit(0);
}

}
while(1);

}
