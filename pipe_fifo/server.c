#include"my_headers.h"


void f(int num)
{

printf("client exited!!!!!!!!!\n");
exit(0);
}



main()
{
int fd1,fd2;
char str[1000];
	fd1=open("fifo1",O_RDONLY);
	fd2=open("fifo2",O_WRONLY);
	close(1);
	dup(fd2);
	signal(SIGPIPE,f);
while(1)
{
	if(strstr(str,"quit"))
		break;
	if(read(fd1,str,20)>0)
		system(str);
	
}

}
