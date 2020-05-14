#include<stdio.h>
#include<sys/resource.h>
void f1(void);

main()
{
struct rlimit var;

	if(getrlimit(RLIMIT_DATA,&var)==-1)
	perror("getrlimit");
	else
printf("Virtual section soft=%u hard=%u ",(unsigned int)var.rlim_cur,(unsigned int)var.rlim_max);

//f1();
	var.rlim_cur=10000000;
	//var.rlim_max=10;

	setrlimit(RLIMIT_DATA,&var);

printf("\nVirtual section soft=%u hard=%u\n",(unsigned int)var.rlim_cur,(unsigned int)var.rlim_max);

f1();

}


void f1(void)
{
int i;
char *v=NULL;
for(i=1;i<=20;i++)
	{
		v=(char *)realloc(v,sizeof(char)*i*1000000);
//		v[i-1]=getchar();
		printf("%d  memory_allocated=%d\n",i,i*1000000);
	}
//printf("%s",v);
}
