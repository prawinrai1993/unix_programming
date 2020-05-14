#include"my_headers.h"


main()
{
int i,j=0;

for(i=1;i<5;i++)
	{
		if(fork()==0)
		{
		printf("%d: %d\n",j++,getpid());
		exit(0);
		}
	}

}
