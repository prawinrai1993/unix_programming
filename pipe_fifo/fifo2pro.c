#include"my_headers.h"


main()
{
int fd1;

mkfifo("fifo3",0777);



if(fork())
{
	fd1=open("fifo3",O_RDONLY);
	close(0);
	dup(fd1);
	execlp("wc","wc",NULL);
}
else
{
	fd1=open("fifo3",O_WRONLY);
	close(1);
	dup(fd1);
	execlp("ls","ls",NULL);
}


}
