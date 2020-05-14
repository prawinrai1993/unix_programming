#include"my_headers.h"

main()
{
int pid;


if(fork())
	exit(0);
else
{
signal(SIGHUP,SIG_IGN);
//chdir("/home");
pid=setsid();
printf("%d",pid);
//daemon(1,1);
close(1);
close(2);
close(0);
while(1)
{
printf("hiii\n");
sleep(1);
}
}


}
