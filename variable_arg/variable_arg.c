#include"my_headers.h"

int sum(int cnt,...);

main()
{

	printf("%d\n",sum(2,22,33));
	printf("%d\n",sum(5,2,3,4,5,6));
}


int sum(int cnt,...)
{
	int s=0;
	va_list handle;
	va_start(handle,cnt);
	while(cnt--)
	{
		s=s + va_arg(handle,int);

	}
	va_end(handle);
	return s;


}
