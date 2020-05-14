#include"my_headers.h"

main()
{
int p[2];
char str[20];
printf("process %d\n",getpid());
pipe(p);

if(fork()==0)
{
//	sleep(10);
	read(p[0],str,20);
	printf("child:str :%s\n",str);
}
else
{
	printf("\nenter a string: ");
	gets(str);
	write(p[1],str,strlen(str)+1);
}


}
