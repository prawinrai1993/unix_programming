#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>


main()
{
int x=10,y=20;

if(fork()==0)
{
printf("in child process.......%d,%d\n\n\n",x,y);
x++;
y++;
printf("in child process.......%d,%d\n\n\n",x,y);
while(1);
}
else
{
	sleep(2);
	printf("inparent process......%d,%d\n\n\n",x,y);
while(1);

}



}
