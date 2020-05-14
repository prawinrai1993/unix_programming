#include"my_headers.h"

main()
{
struct sembuf v;
int id,i;
	id=semget(1,3,IPC_CREAT | 0666);

if(id==-1)
{
perror("semget");
return;
}

	printf("id=%d pid=%d\n",id,getpid());

	

if(fork())
{
	if(fork())
	{
			if(fork());
			else		
			for(i=1;i<27;i++)
				{
					struct sembuf v;
					v.sem_num=0;
					v.sem_op=0;
					v.sem_flg=0;
					semop(id,&v,1);
					semctl(id,0,SETVAL,1);
//					usleep(100);
					printf("%d",i);
					fflush(stdout);
					semctl(id,1,SETVAL,0);

				}
		
	}
	else
	{		
		for(i=1;i<27;i++)
		{
			struct sembuf v;
			v.sem_num=1;
			v.sem_op=0;
			v.sem_flg=0;
			semop(id,&v,1);
			semctl(id,1,SETVAL,1);
//			usleep(100);
			printf("%c",96+i);
			fflush(stdout);
			semctl(id,2,SETVAL,0);

		}
	}
}
else
{
	for(i=1;i<27;i++)
{
	struct sembuf v;
	v.sem_num=2;
	v.sem_op=0;
	v.sem_flg=0;
	semop(id,&v,1);
	semctl(id,2,SETVAL,1);
		printf("%c",64+i);
		fflush(stdout);
//	usleep(100);
	semctl(id,0,SETVAL,0);

}
}
sleep(1);
printf("\n");
}
