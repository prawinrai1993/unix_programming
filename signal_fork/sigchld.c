#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
void watch(int num)
{
	int v;
	printf("parent recieved sigchld!!!!\n\n");

	while(wait(&v)!=-1);
	printf("child %d exited......\n\n",v>>8);

}


main()
{

	signal(SIGCHLD,watch);

	if(fork())
	{

		printf("in parent process......\n\n");

		sleep(4);
		printf("parent exiting.....\n");

	}
	else
	{

		printf("in child process........\n");

		sleep(2);
		exit(1);


	}



}
