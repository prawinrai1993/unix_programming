#include"my_headers.h"

main()
{
int fd1,fd2;
char str[1000];

	if(mkfifo("fifo1",0666)==-1)
		perror("mkfifo");
fd1=open("fifo1",O_RDWR);
	while(1)
	{
	printf("$");
	fgets(str,20,stdin);
	if(write(fd1,str,strlen(str)+1)>0);
	sleep(1);
	read(fd1,str,1000);
	printf("%40s",str);
	}

}
