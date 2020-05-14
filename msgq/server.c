#include"my_headers.h"
struct msgbuf
{
long mtype;
char mtext[60];
};

main()
{

int id;
struct msgbuf v;
struct msqid_ds u;
id=msgget(1,IPC_CREAT | 0666);

if(id==-1)
{
	perror("msgget");
	return;
}
if(fork()==0)
{
	while(1)
	{
		if(msgrcv(id,&v,60,5,MSG_NOERROR)==-1)
			printf("msgrcv");

		v.mtype=2;
		msgsnd(id,&v,strlen(v.mtext)+1,0);
		printf("hiii.........user1\n");
	}
		
}
else
{

	while(1)
	{
		if(msgrcv(id,&v,60,4,MSG_NOERROR)==-1)
			printf("msgrcv");
		v.mtype=1;
		msgsnd(id,&v,strlen(v.mtext)+1,0);
		printf("hiii.........user2\n");
	}





}

}

