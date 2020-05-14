#include"my_headers.h"


main()
{
int c;

c=fork();
if(c)
{
	sleep(10);
	printf("in parent :%d\n",getpid());
}
else
{
//	sleep(5);
	printf("in child :%d\n",getpid());
}








}
