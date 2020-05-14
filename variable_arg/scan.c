#include"my_headers.h"

int scan(const char *,...);

main()
{	
	int x=12,a=10;
	double y=13.3;
	char z='A';
	char string[20];
	printf("d d c f s........\n");
	scan("%d %d %c %f %s",&x,&a,&z,&y,&string);
	printf("%d %d %c %f %s",x,a,z,y,string);


}


int scan(const char *v,...)
{
int p;
int i=0,cnt=1,*t=NULL;
double *f;
char c[20];
char *ch;
char *str;
va_list handle;


va_start(handle,v);

for(i=0;v[i];i++)
{
	if(v[i]=='%')
	switch(v[i+1])
	{
	case 'd':t=va_arg(handle,int*);
		gets(c);
		*t=atoi(c);
		break;
	case 'f':f=va_arg(handle,double *);
		gets(c);
		*f=xatof(c);
		break;

	case 'c':ch=va_arg(handle,char *);
		*ch=getchar();
		getchar();
		break;

	case 's':str=va_arg(handle,char *);
		gets(str);
		break;
	default:putchar('0');
		break;
	}


}
va_end(handle);
putchar('\n');

return cnt;
}



