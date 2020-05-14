#include"my_headers.h"


main()
{
	int id1,id2,id3;
	char *ptr1,*ptr2,*ptr3;
	char name[20];
	char str[80];
	char check[10];
	id1=shmget(2,1000,IPC_CREAT | 0666);
	id2=shmget(3,1000,IPC_CREAT | 0666);
	id3=shmget(4,1000,IPC_CREAT | 0666);
	ptr1=shmat(id1,NULL,0);
	ptr2=shmat(id2,NULL,0);
	ptr3=shmat(id3,NULL,0);
srand(getpid());
printf("enter user name: ");
gets(name);
strcat(name,": ");
bzero(ptr1,1000);
fputs(ptr3,stdout);

if(fork()==0)
{
	while(1)
	{
		if(ptr2[0]!=0)
		{
		printf("\n%s\n",ptr2);
		usleep(100);
		bzero(ptr2,1000);
		}
	}


}
else
{
	while(1)
	{
				
		gets(str);
		strcpy(ptr1,name);
		strcat(ptr1,str);
	}

}

}
