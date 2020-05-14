#include<stdio.h>
#include<sys/resource.h>

void f1(void);
main()
{
	struct rlimit var;

	if(getrlimit(RLIMIT_CPU,&var)==-1)
	perror("getrlimit");
	else
	printf("CPU_TIME cur=%u max=%u\n",(unsigned int)var.rlim_cur,(unsigned int)var.rlim_max);

//	f1();
	var.rlim_cur=10;
	setrlimit(RLIMIT_CPU,&var);
	printf("CPU_TIME cur=%u max=%u\n",(unsigned int)var.rlim_cur,(unsigned int)var.rlim_max);
	f1();
}

void f1(void)
{
register long long int i=0;
while(1)
printf("%Ld\n",i++);
}
