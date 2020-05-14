#include"my_headers.h"


main()
{
int p[2];

pipe(p);

if(fork())
{
	close(0);
	dup(p[0]);
//	close(p[1]);
	fcntl(p[1],F_SETFD,1);  //if value 1 close file des;
	execlp("wc","wc",NULL);
}
else
{
	close(1);
	dup(p[1]);
//	close(p[0]);
	fcntl(p[0],F_SETFD,1);	//if value 1 close file des;
	execlp("ls","ls",NULL);
}


}
