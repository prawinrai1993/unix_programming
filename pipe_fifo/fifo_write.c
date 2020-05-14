#include"my_headers.h"


void f(int num)
{
printf("reader exited!!!!!!!!!!!\n");
exit(0);

}


main()
{
int fd;
char str[100];

if(mkfifo("fifo",0777)==-1)
perror("mkfifo");

signal(SIGPIPE,f);

fd=open("fifo",O_WRONLY);

while(1)
{
	printf("\nenter a message: ");
	fgets(str,20,stdin);
	if(write(fd,str,strlen(str)+1)>0);
	if(strstr(str,"quit"))
	break;

}

}
