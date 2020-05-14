#include"my_headers.h"

main(int argc,char **argv)
{
int p[2];
int fd1,fd2,size;
char *str=NULL;
pipe(p);
	fd1=open(argv[1],O_RDONLY);
	size=lseek(fd1,0,2);
	lseek(fd1,0,0);
	close(fd1);
	str=sbrk(size);


if(fork()==0)
{
	fd1=open(argv[1],O_RDONLY);
	read(fd1,str,size);
	close(fd1);
	write(p[1],str,size);
}
else
{
	read(p[0],str,size);
	fd2=open(argv[2],O_WRONLY | O_CREAT |O_TRUNC,0666);
	write(fd2,str,size);
	close(fd2);
	printf("file copied sucessfully!!!!!!!!!!!!!!\n\n");
}

}
