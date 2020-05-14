#include"my_headers.h"


void f(int num)
{
printf("user is offline!!!!!!!!!!!\n");
	printf("exiting...........\n");
	exit(0);
}


main()
{
int fd1,fd2;
char str[1000];
char user1[20],user2[20];
//mkfifo("fifo1",0666);
//mkfifo("fifo2",0666);


		fd2=open("fifo2",O_RDWR);
		fd1=open("fifo1",O_RDWR);



	printf("\nenter name of user: ");
	gets(user1);
	write(fd2,user1,strlen(user1)+1);
	read(fd1,user2,20);	
	
//	fflush(stdout);
//getchar();

	if(fork()==0)
	{
		while(1)
		{
		read(fd2,str,1000);
	//	if(strstr(str,"quit"))
	//	exit(0);
		printf("\n%50s: %s\n",user2,str);


		}

	}
	else
	{
		signal(SIGPIPE,f);
		while(1)
		{
					
		printf("\n%s : @@\n",user1);
		gets(str);
		write(fd1,str,strlen(str)+1);
	
		}	






	}



}
