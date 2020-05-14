#include"my_headers.h"

int sum(int,int);
int mul(int,int);
int divide(int,int);
typedef int (*funcptr)(int,int);
int f(int,int,funcptr);
main()
{
funcptr p[4]={NULL,sum,mul,divide};
int x,y,c,i;
printf("enter two digits(x y):");
scanf("%d %d",&x,&y);
printf("enter choice(1,2,3)(sum,mul,div):");
scanf("%d",&i);
c=f(x,y,p[i]);
printf("result=%d\n",c);
}


int sum(int x,int y)
{
	return x+y;

}

int mul(int x,int y)
{

	return x*y;

}

int divide(int x,int y)
{

	return (x/y);

}

int f(int x,int y,int (*p)(int,int))
{

	return ((*p)(x,y));


}




