#include"my_headers.h"
int pid[4],v,t;

void f(int num)
{

			while(wait(&v)!=-1)
			{
			v>>=8;
			printf("child %d exited.......\n",v);
			}

}


main()
{


pid[0]=getpid();

if(pid[1]=fork())
{
	

	if(pid[2]=fork())
		{
			

		if(pid[3]=fork())
			{
			
		printf("parent..%d child..%d %d %d\n",pid[0],pid[1],pid[2],pid[3]);
				signal(17,f);
				while((wait(&v))!=-1)
			{
				v>>=8;
				printf("child %d exited.......\n",v);
			}
				printf("parent3........exits%d %d\n",getpid());
	
			}
			else
			{
				srand(getpid());
				t=rand()%10+1;
				printf("child 3 delay for %d sec%d\n",t,getpid());
				sleep(t);
				exit(3);	

			}
		}
		else
		{
			srand(getpid());
			t=rand()%10+1;
			printf("child 2 delay for %d sec%d\n",t,getpid());
			sleep(t);
			exit(2);	
		}

}
else
{
		srand(getpid());
		t=rand()%10+1;
		printf("child 1 delay for %d sec%d\n",t,getpid());
		sleep(t);
		exit(1);	



}




}
