#include"my_headers.h"

typedef void (*p)(int);


char * test(int num)
{
	
	p ptr;
	static char msg[20];
	ptr=signal(num,SIG_IGN);
	signal(num,ptr);

	if(ptr==SIG_DFL)
	strcpy(msg,"Default");
	else if(ptr==SIG_IGN)
	strcpy(msg,"IGNORE");
	else
	strcpy(msg,"UserDefined");

return msg;

}


main()
{
int signum;
char *p;
signal(24,SIG_IGN);

printf("enter signal number to check status:");
scanf("%d",&signum);


p=test(signum);

printf("%s\n",p);




}
