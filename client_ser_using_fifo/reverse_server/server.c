#include"my_headers.h"



main()
{
int fd1,fd2,i=0,j=0;
char str[40],ptr[40];
mkfifo("fifo1",0777);
mkfifo("fifo2",0777);

fd1=open("fifo1",O_RDWR);
fd2=open("fifo2",O_RDWR);

while(1)
{
	read(fd2,str,40);
	i=strlen(str);
	while(i)
	{
		ptr[j++]=str[i-1];
		i--;
	}
ptr[j]='\0';
write(fd1,ptr,strlen(ptr)+1);
j=0;
}

}
