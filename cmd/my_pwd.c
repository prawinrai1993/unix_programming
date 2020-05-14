#include<unistd.h>
#include<stdio.h>
main()
{
char str[1000];

if(getcwd(str,1000)<0)
perror("getcwd");
else
printf("current directory: %s\n\n",str);


}
