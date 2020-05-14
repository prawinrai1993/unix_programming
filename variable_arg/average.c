#include"my_headers.h"

double average(int cnt,...);

main()
{

	printf("%lf\n",average(2,22,33));
	printf("%lf\n",average(5,2,3,4,5,6));
}


double average(int cnt,...)
{
	double s=0;
	int i=0;
	va_list handle;
	va_start(handle,cnt);
	i=cnt;
	while(cnt--)
	{
		s=s + va_arg(handle,int);

	}
	va_end(handle);

	s=s/i;
	return s;


}
