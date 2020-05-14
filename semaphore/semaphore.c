#include"my_headers.h"
int id,shmid;

void par(void)
{
	char *ptr;
	int i;
	struct sembuf v={0,0,0};
	id=semget(3,1,IPC_CREAT | 0666);
	if(id<0)
	printf("semaphore not create...\n");
	shmid=shmget(2,20,IPC_CREAT |0666);
	ptr=(char *)shmat(shmid,NULL,0);

	printf("PARENT is waiting ...\n");
	/////////////////////////
	v.sem_num=0;
	v.sem_op=0;
	v.sem_flg=0;
	semop(id,&v,1);
	semctl(id,0,SETVAL,1);

	for(i=0;i<26;i++)
	{
		ptr[i]=i+65;
//		printf("%c..",ptr[i]);
		fflush(stdout);
		sleep(1);
	}
	semctl(id,0,SETVAL,0);
	//////////////////////////
	shmdt(ptr);
	exit(0);
}

void chi(void)
{
	char *ptr;
	int i;
	struct sembuf v;
	id=semget(3,1,IPC_CREAT | 0666);
	if(id<0)
	printf("semaphore not create...\n");
	shmid=shmget(2,20,IPC_CREAT |0666);
	ptr=(char *)shmat(shmid,NULL,0);
	printf("child is waiting....\n");
	/////////////////////////
	v.sem_num=0;
	v.sem_op=0;
	v.sem_flg=0;
	semop(id,&v,1);
	semctl(id,0,SETVAL,1);
	for(i=0;i<26;i++)
	{
//		printf("child is writing....\n");
		ptr[i]=i+97;
//		printf("%c..",ptr[i]);
		fflush(stdout);
		sleep(1);
	}
	semctl(id,0,SETVAL,0);
	shmdt(ptr);
	exit(0);
}

void print()
{
	int i;
	char *ptr;
	shmid=shmget(2,20,IPC_CREAT |0666);
	ptr=(char *)shmat(shmid,NULL,0);
	while(1)
	{
	for(i=0;i<26;i++)
	{
		printf("%c..",ptr[i]);
		fflush(stdout);
	}
	sleep(1);
	system("clear");
	}

}

int main()
{

int x,i;
char *ptr;
	if(fork())
	{	if(fork())
		{
		print();
		}
		else
		{
		par();
		}
	}
	else
	{
		chi();
	}
wait(&x);

}
