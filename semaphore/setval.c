#include"my_headers.h"

main(int argc,char **argv)
{
	struct sembuf v;
	int id,index,val,set;
	id=semget(1,3,IPC_CREAT | 0666);
	if(id==-1)
	{
	perror("semget");
	return;
	}

	index=atoi(argv[1]);
	set=atoi(argv[2]);

	val=semctl(id,index,SETVAL,set);
	if(val==-1)
	{
		perror("semctl");
		return;
	}
	else	
	printf("id =%d val=%d \n",id,val);


}
