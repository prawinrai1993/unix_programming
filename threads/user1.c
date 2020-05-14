#include"my_headers.h"


pthread_t tid_1,tid_2;

void * recieve(void *ptr)
{
int fd1,fd2;
char str[100];
if(mkfifo("fifo1",0666)==-1)
perror("mkfifo");
if(mkfifo("fifo2",0666)==-1)
perror("mkfifo");

fd1=open("fifo1",O_RDWR);
fd2=open("fifo2",O_RDWR);


while(1)
{
	if(read(fd2,str,100)>0)
	{
		printf("\n%40s","msg_rec: ");
		fflush(stdout);
		fputs(str,stdout);
		fflush(stdout);
		printf("\nsnd_msg : ");
	}
	else
		break;

}

}

void * send(void *ptr)
{
int fd1,fd2;
char str[100];
if(mkfifo("fifo1",0666)==-1)
perror("mkfifo");
if(mkfifo("fifo2",0666)==-1)
perror("mkfifo");

fd1=open("fifo1",O_RDWR);
fd2=open("fifo2",O_RDWR);


while(1)
{
printf("\nsnd_msg : ");
gets(str);
write(fd1,str,strlen(str)+1);
}


}



main()
{
pthread_create(&tid_1,NULL,recieve,NULL);
pthread_create(&tid_2,NULL,send,NULL);
while(1);
//pthread_exit(0);
}
