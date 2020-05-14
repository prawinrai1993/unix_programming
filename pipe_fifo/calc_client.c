#include"my_headers.h"

main()
{
char str[100];
int fd1,fd2;
	if(mkfifo("f1",0666)==-1)
	perror("mkfifo");
	if(mkfifo("f2",0666)==-1)
	perror("mkfifo");


	fd1=open("f1",O_RDWR);
	fd2=open("f2",O_RDWR);
while(1)
{
	printf("\nenter equation: ");
	gets(str);
	
	if(write(fd1,str,strlen(str)+1)<0)
	{
		printf("%s","server not responding!!!!!!!\n");
	}
	
	bzero(str,100);	
	if(read(fd2,str,100)>0)
	printf("result= %s\n",str);	

}
}
