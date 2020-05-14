#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<string.h>

void wakeup(int num)
{

printf("\npasword not entered so exiting.......\n");
raise(SIGKILL);

}


main()
{
char str[1000];
int ret;
signal(SIGALRM,wakeup);

alarm(5);
printf("enter the password in 5 seconds: ");
fflush(stdout);
scanf("%[^\n]s",str);



str[strlen(str)]='\0';
printf("entered password: %s....\n\n",str);


}
