#include<stdio.h>
#include<sys/resource.h>
#include<stdlib.h>
main(int argc,char **argv)
{
int signum,pid;
struct rlimit var;

	if(argc<3)
	{
		printf("ERROR: usage_syntax <./sigkill> <pid> <signum>");
		return;
	}


pid=atoi(argv[1]);
signum=atoi(argv[2]);

	kill(pid,signum);


return;




}

