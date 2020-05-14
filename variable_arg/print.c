#include"my_headers.h"

int print(const char *,...);

main()
{	
	int x=12,a=10;
	float y=13.3;
	char z='A';
	print("%d %d %d %c %f %f %c %s",x,a,33,z,y,11.45,'b',"praveen");



}


int print(const char *v,...)
{
char *p;
int i=0,cnt=1,t;
double f;
char c;
va_list handle;
char string[1000];
bzero(string,1000);


va_start(handle,v);

for(i=0;v[i];i++)
{
	if(v[i]=='%')
	switch(v[i+1])
	{
	case 'd':t=va_arg(handle,int);
		p=itoa(t);
		puts(p);
		break;
	case 'f':f=va_arg(handle,double);
		p=xftoa(f);
		fgets(p,20,stdout);
		break;

	case 'c':c=va_arg(handle,int);
		putchar(c);
		break;

	case 's':p=va_arg(handle,char *);
		puts(p);
		break;
	case 'b':p=va_arg(handle,char *);
		puts(p);
		break;

	default:putchar('0');
		break;

	}


}
va_end(handle);
putchar('\n');
puts(string);

return cnt;
}



