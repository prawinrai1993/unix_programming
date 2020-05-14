#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

main(int argc,char **argv)
{
FILE *fp=NULL,*fp1=NULL;
char *str=NULL,ch;
int cnt=0,i,fd1,fd2;


mkfifo("FIFO1",0777);
mkfifo("FIFO2",0777);

fd1=open("FIFO1",O_RDWR);
fd2=open("FIFO2",O_RDWR);

fp=fopen(argv[1],"r");


while((ch=fgetc(fp))!=EOF)
{
str=(char *)realloc(str,sizeof(char)*(cnt+1));
str[cnt++]=ch;
}
str=(char *)realloc(str,sizeof(char)*(cnt+1));
str[cnt]='\0';



if(fork())
{
fp1=fopen("uppercase","w");
write(fd1,str,strlen(str)+1);
read(fd2,str,strlen(str)+1);
printf("%s",str);
fputs(str,fp1);

}
else
{
i=0;
read(fd1,str,strlen(str)+1);
while(str[i])
{
	if((str[i]>='a')&&(str[i]<='z'))
		str[i]=str[i]-32;

	i++;
}

write(fd2,str,strlen(str)+1);

}





}
