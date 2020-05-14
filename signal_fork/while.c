#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

main()
{

printf("\n\n%d.................\n\n",getpid());
fflush(stdout);
while(1);

printf("out of while/.........\n\n\n");


}
