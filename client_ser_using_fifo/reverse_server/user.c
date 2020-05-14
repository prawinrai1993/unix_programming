#include"my_headers.h"

main()
{
int fd1,fd2;
char str[40];
mkfifo("fifo1",0777);
mkfifo("fifo2",0777);

fd1=open("fifo1",O_RDWR);
fd2=open("fifo2",O_RDWR);

if(fork())
{
while(1)
{
read(fd1,str,40);
printf("\nreverse string: %s\n",str);
printf("enter a string: ");
fflush(stdout);
}
}
else
{
printf("enter a string: ");
fflush(stdout);
while(1)
{
gets(str);
write(fd2,str,strlen(str)+1);
}
}



}
