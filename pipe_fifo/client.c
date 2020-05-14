#include"my_headers.h"


void f(int num)
{
printf("server exited!!!!!!!!!\n");
exit(0);

}


main()
{
int fd1,fd2;
char str[1000];

	if(mkfifo("fifo1",0666)==-1)
		perror("mkfifo");
	if(mkfifo("fifo2",0666)==-1)
		perror("mkfifo");
fd1=open("fifo1",O_WRONLY);
fd2=open("fifo2",O_RDONLY);
signal(SIGPIPE,f);

while(1)
{
	printf("$");
	fgets(str,20,stdin);
	if(write(fd1,str,strlen(str)+1)>0);
	
	read(fd2,str,1000);
	printf("%s",str);
	if(strstr(str,"quit"))
	break;

}

}
