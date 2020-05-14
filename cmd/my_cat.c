#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int copyfile(int fdin,char *);

main(int argc,char **argv)
{

if(argc<2)
{
printf("Usage syntax:  <my_cat>  <filename>");

}


	int number_bytes;

	number_bytes=copyfile(STDIN_FILENO,argv[1]);

	printf("number of bytes copied to file.......%d\n",number_bytes);

}



int copyfile(int fdin,char *str)
{
	int fd,i=0;
	char buff[1000],ch[1];

	fd=open(str,O_WRONLY|O_CREAT|O_TRUNC,0666);


	while(read(fdin,ch,1)!=0)
	{
	buff[i++]=ch[0];
	}
	buff[i]='\0';


	return(write(fd,buff,strlen(buff)));

}
