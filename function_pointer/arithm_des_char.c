#include"my_headers.h"


int divide(int,int);
int sub(int,int);
int mul(int x,int y);
int divide(int x,int y);
int sum(int x,int y);
typedef int (*funcptr)(int,int);
int f(int,int,funcptr);
int main()
{
	funcptr p[6]={mul,sum,0,sub,0,divide};

	int x,y,c;
	char choice;
	printf("enter two digits(x y):");
	scanf("%d %d",&x,&y);

	printf("enter choice(*,+,-,/)(mul,add,sub,div): ");
	getchar();
	scanf("%c",&choice);

	choice=choice-42;
	c=f(x,y,p[choice]);
	printf("result= %d\n",c);
}


int sub(int x,int y)
{
	return (x-y);

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




