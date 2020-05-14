#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
int armstrong(int num);
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
		if(armstrong(i))
	{
		test=i;
		while(test)
		{
		test=test/10;
		cnt++;
		}

	test=i;

	temp[cnt]='\0';
		while(test)
		{
		//x=x*10;
		x=test%10;
		temp[cnt-1]=x+48;
		cnt--;
		test=test/10;
		}
strcat(str,temp);
strcat(str,"  ");
}

}

printf("%s ............\n\n",str);
write(fd1,str,strlen(str)+1);
}
}

int armstrong(int num)
{
int cnt=0,i,x,res=0;
i=num;
while(i)
{
	x=i%10;
	res=(x*x*x)+res;
	i=i/10;
}
if(res!=num)
return 0;
else
return 1;
}
