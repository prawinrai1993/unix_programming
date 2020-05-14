#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
main()
{
int fd1,fd2;
/*
mkfifo("FIFO1",0666);
mkfifo("FIFO2",0666);
*/
fd1=open("FIFO1",O_RDWR );
fd2=open("FIFO2",O_RDWR );

if(fork()==0)
{
while(1)
{
char buff[1000];
if((read(fd1,buff,1000))>0)
printf("armstrong number: %s......\n\n",buff);
printf("enter first number: ");
fflush(stdout);
}

}
else
{
while(1)
{
char str1[10],str2[10];
printf("enter first number: ");
scanf("%s",str1);
write(fd2,str1,strlen(str1)+1);
printf("enter second number: ");
scanf("%s",str2);
write(fd2,str2,strlen(str2)+1);

}

}





}
