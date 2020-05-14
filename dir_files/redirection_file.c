#include"my_headers.h"

main()
{

struct termios v;
char ch='A';

int fd;
signal(1,SIG_IGN);

	tcgetattr(0,&v);
	v.c_lflag&=~ICANON;
	v.c_lflag&=~ECHO;

	tcsetattr(0,TCSANOW,&v);
//	printf("enter a char : ");
	//ch=getchar();
	//printf("you have entered : %c",ch);
	close(1);

	fd=open("datafile",O_WRONLY | O_CREAT | O_APPEND,00666);
	fcntl(fd,F_DUPFD,0);

	while(1)
	{
	//	ch=getchar();
		printf("%c",ch++);
	//	if(ch==10)
	//	break;
	}

	v.c_lflag|=ICANON;
	v.c_lflag|=ECHO;

	tcsetattr(0,TCSANOW,&v);
close(fd);


//fd=open(stdin,O_WRONLY);
//fd=open("/dev/pts/0",O_RDWR);
//fcntl(fd,F_DUPFD,0);
}
