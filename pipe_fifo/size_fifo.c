#include"my_headers.h"

main()
{
int p[2];
char ch='A';
printf("process %d\n",getpid());
pipe(p);

if(fork()==0)
{
	long long int i=0;
		while(1)
	{
		if(write(p[1],&ch,1)==-1)		
		perror("write");
		printf("%Ld\n",i++);
	}
}

}
