#include"my_headers.h"

main()
{



signal(SIGHUP,SIG_IGN);

if(fork())
{
sleep(1);
close(0);
close(1);
close(2);
exit(0);
}
else
while(1);


}
