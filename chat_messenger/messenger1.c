#include"my_headers.h"


void f(int num)
{
printf("user is offline!!!!!!!!!!!!\n");
fflush(stdout);	
	printf("exiting..........\n");

}


main()
{
int fd1,fd2;
char str[1000];
char user1[20],user2[20];
mkfifo("fifo1",0666);
mkfifo("fifo2",0666);




		fd1=open("fifo1",O_RDWR);

	fd2=open("fifo2",O_RDWR);
	read(fd2,user2,20);	

	printf("\nenter name of user: ");
	gets(user1);
	write(fd1,user1,strlen(user1)+1);

if(fork()==0)
	{
		signal(13,f);	
		while(1)
		{
		printf("\n%s : @@\n",user1);
		gets(str);
		write(fd2,str,strlen(str)+1);

		}

	}
else
	{
		while(1)
		{
		read(fd1,str,1000);
		printf("\n%40s : %s\n",user2,str);
		}


	}



}
