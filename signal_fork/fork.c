#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

main()
{
int i;


for(i=0;i<10;i++)
{
if(fork()==0)
sleep(1);
}

}
