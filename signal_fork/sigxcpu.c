#include"my_headers.h"

main()
{
struct rlimit v;
signal(SIGXCPU,SIG_IGN);
	if(getrlimit(RLIMIT_CPU,&v)==-1)
	perror("getrlimit");
	else
	printf("CPU_TIME cur=%u max=%u\n",(unsigned int)v.rlim_cur,(unsigned int)v.rlim_max);

	v.rlim_cur=5;
	v.rlim_max=10;
	setrlimit(RLIMIT_CPU,&v);
	printf("CPU_TIME cur=%u max=%u\n",(unsigned int)v.rlim_cur,(unsigned int)v.rlim_max);

	while(1);

}
