#include"my_headers.h"

void f(int num)
{

int i,j;
for(i=0;i<1000000000;i++);
	for(j=0;j<100000000;j++);
printf("signal %d received\n",num);


}



main()
{

struct sigaction v;



//sigfillset(&v.sa_mask);
//sigaddset(&v.sa_mask,2);
v.sa_flags=0;
v.sa_handler=f;
sigaction(3,&v,NULL);

printf("process current action=%d\n",v.sa_handler);

while(1);

}
