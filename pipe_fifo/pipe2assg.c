#include"my_headers.h"


main(int argc,char **argv)
{
int p[2];

if(argc<3)
{
printf("USAGE: <./a.out> <filename> <pattern>\n");
return;
}

pipe(p);

if(fork())
{
	close(0);
	dup(p[0]);
	close(p[1]);
//	fcntl(p[1],F_SETFD,1);
	execlp("grep","grep",argv[2],NULL);
}
else
{
	close(1);
	dup(p[1]);
	close(p[0]);
//	fcntl(p[0],F_SETFD,1);
	execlp("nm","nm",argv[1],NULL);
}


}
