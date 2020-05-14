#include"my_headers.h"

main()
{

int id,fd,i;
struct sembuf v;
id=semget(1,1,IPC_CREAT | 0666);
if(id==-1)
{
perror("semget");
return;
}

v.sem_num=0;
v.sem_op=0;
v.sem_flg=0;

semop(id,&v,0);
if(fork()==0)
{
char str[12];
	semctl(id,0,SETVAL,1);
fd=open("test",O_CREAT | O_WRONLY | O_APPEND, 0777);
//	close(1);
//	dup(fd);
	for(i=0;i<10;i++)
		str[i]=i+48;
str[i]=0;
	write(fd,str,strlen(str));

	close(fd);

	semctl(id,0,SETVAL,0);
	exit(0);

}
else
{
char str[11];
	semctl(id,0,SETVAL,1);
fd=open("test",O_CREAT | O_WRONLY | O_APPEND, 0777);
//	close(1);
//	dup(fd);

	for(i=0;i<10;i++)
		str[i]=i+65;
	str[i]=0;
	write(fd,str,strlen(str));
	close(fd);

	semctl(id,0,SETVAL,0);
	wait(0);	

}



}
