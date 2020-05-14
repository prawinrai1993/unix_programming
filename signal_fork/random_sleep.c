#include"my_headers.h"

int v,i,t;

main()
{

for(i=1;i<=3;i++)
{
	if(fork()==0)
	{
		srand(getpid());
		t=rand()%10+1;
		printf("child%d ...created %dsecs\n",i,t);
		sleep(t);
		exit(i);
	}

}

	while(wait(&v)!=-1)
	{
		v>>=8;
		printf("parent collected......child%d exit\n",v);
	}
}
