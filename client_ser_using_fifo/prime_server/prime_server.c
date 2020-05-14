#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
main()
{
int fd1,fd2;
int num1,num2,test,x=0,i=0,cnt;
char str[1000]={0},buff[20],temp[20];
bzero(str,1000);
/*
mkfifo("FIFO1",0777);
mkfifo("FIFO2",0777);
*/
fd1=open("FIFO1",O_RDWR);
fd2=open("FIFO2",O_RDWR);

while(1)
{
if((read(fd2,buff,20))>0)
{
num1=atoi(buff);
}
if((read(fd2,buff,20))>0)
{
num2=atoi(buff);
}
for(i=num1;i<=num2;i++)
{

cnt=0;
if(prime(i))
{


sprintf(temp,"%d",i);
strcat(str,temp);
strcat(str,"  ");
}

}

printf("%s ............\n\n",str);
write(fd1,str,strlen(str)+1);
}
}

int prime(int num)
{
int cnt=0,i;

if((num==1)||(num==0))
return 0;

for(i=1;i<=num;i++)
{
if((num%i)==0)
cnt++;

if(cnt==3)
return 0;
}
return 1;
}
