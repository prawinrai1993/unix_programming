#include"my_headers.h"

main()
{

	int fd,i;
	char str[]="123456789";
	struct flock v;

fd=open("datafile",O_WRONLY | O_CREAT | O_APPEND,0666);


printf("press enter to write :");
getchar();

v.l_type=F_WRLCK;
v.l_whence=0;
v.l_start=0;
v.l_len=0;


fcntl(fd,F_SETLKW,&v);


for(i=0;str[i];i++)
{
	write(fd,str+i,1);
	printf("%s\n",str+i);
	sleep(1);
}


v.l_type=F_UNLCK;

fcntl(fd,F_SETLKW,&v);

	printf("writing done succesfully!!!!!!!!!\n");

}

