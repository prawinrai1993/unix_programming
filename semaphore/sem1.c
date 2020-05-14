#include"my_headers.h"

main()
{
struct sembuf v;
int id;
	id=semget(1,3,IPC_CREAT | 0666);

if(id==-1)
{
perror("semget");
return;
}
	printf("id=%d pid=%d\n",id,getpid());
	printf("enter to access common resource\n");
	getchar();

	v.sem_num=0;
	v.sem_op=0;
	v.sem_flg=0;
	semop(id,&v,1);
	semctl(id,0,SETVAL,1);

	printf("common data access region\n");
	sleep(5);
	printf("CR access done enter to continue : \n");
	getchar();
	semctl(id,0,SETVAL,0);

}
