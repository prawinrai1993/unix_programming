#include"my_headers.h"

main()
{
int fd;
char str[100];

if(mkfifo("fifo",0777)==-1)
perror("mkfifo");

fd=open("fifo",O_RDONLY);

while(1)
{
	if(read(fd,str,20)>0)
{
	printf("\nmessage received: ");
	printf("%s",str);
}
	if(strstr(str,"quit"))
	break;

}

}
