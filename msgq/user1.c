#include"my_headers.h"


struct msgbuf
{
long mtype;
char mtext[60];
};

main()
{


struct tm *tmptr;
int id;
struct msgbuf v;
struct timeb tim;
char datestring[20];
char timestring[20];
id=msgget(1,IPC_CREAT | 0666);
if(id==-1)
{
	perror("msgget");
	return;
}

		v.mtype=5;



if(fork()==0)
{
	
	while(1)
	{

		printf("\nsend_msg: ");

		gets(v.mtext);
		ftime(&tim);
		tmptr=localtime(&tim.time);
		strftime(datestring,20,"%F",tmptr);
		strftime(timestring,20,"%T",tmptr);
		strcat(v.mtext,"(");
		strcat(v.mtext,datestring);
		strcat(v.mtext,",");
		strcat(v.mtext,timestring);
		strcat(v.mtext,")");
		if(msgsnd(id,&v,strlen(v.mtext)+1,0)==-1)
			perror("msgsnd");

	}

}
else
{

	while(1)
	{
		if(msgrcv(id,&v,60,1,MSG_NOERROR)==-1)
			printf("msgrcv");
		
		printf("\n%50s: %s\n","msg_recd",v.mtext);
		
	}



	}
}
