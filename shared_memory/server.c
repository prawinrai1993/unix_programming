#include"my_headers.h"


main()
{
	int id1,id2,id3;
	char *ptr1,*ptr2,*ptr3;
	id1=shmget(2,1000,IPC_CREAT | 0666);
	id2=shmget(3,1000,IPC_CREAT | 0666);
	id3=shmget(4,1000,IPC_CREAT | 0666);
	ptr1=shmat(id1,NULL,0);
	ptr2=shmat(id2,NULL,0);
	ptr3=shmat(id3,NULL,0);
bzero(ptr1,1000);
bzero(ptr3,1000);


	while(1)
	{
		if(ptr1[0]!=0)
		{
			strcpy(ptr2,ptr1);
			strcat(ptr3,ptr2);
			strcat(ptr3,"\n");
			bzero(ptr1,1000);
			usleep(100);
			bzero(ptr2,1000);
		}
	}






}
