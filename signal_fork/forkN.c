#include"my_headers.h"
int sum,x,y,v;
main()
{
printf("enter two digits for sum=");
scanf("%d %d",&x,&y);


if(fork()==0)
{
	sum=x+y;
	exit(sum);
}
else
{
	wait(&v);
	v>>=8;
	printf("sum=%d\n",v);

}











}
