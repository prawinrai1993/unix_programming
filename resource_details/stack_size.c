#include<stdio.h>
#include<sys/resource.h>

void f1(void);
main()
	{
		
		struct rlimit var;
	//to know the sizeof the stack
	if(getrlimit(RLIMIT_STACK,&var)==-1)
	perror("getrlimit");
	else
	printf("stack cur=%u max=%u \n",(unsigned int)var.rlim_cur,(unsigned int)var.rlim_max);
	var.rlim_cur*=3;
	setrlimit(RLIMIT_STACK,&var);
	printf("stack cur=%u max=%u \n",(unsigned int)var.rlim_cur,(unsigned int)var.rlim_max);
		
	f1();	
	}

	void f1(void)
	{
		static i;
		char a[1000000]={0};
		i++;
		if(i<20)
		f1();
		printf("returning..............\n");


	}
