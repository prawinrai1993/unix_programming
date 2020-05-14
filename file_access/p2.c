#include"my_headers.h"

main()
{

	int fd,i;
	char str[10];
	struct flock v;

fd=open("datafile",O_RDONLY);


printf("press enter to read :");
getchar();
/*
v.l_type=F_WRLCK;
v.l_whence=0;
v.l_start=0;
v.l_len=0;


fcntl(fd,F_SETLKW,&v);
*/

for(i=0;i<10;i++)
{
	read(fd,str+i,1);
	printf("%c........\n",str+i);
	sleep(1);
}

/*
v.l_type=F_UNLCK;

fcntl(fd,F_SETLKW,&v);
*/
	printf("%s............\n\n\n",str);

	printf("read done succesfully!!!!!!!!!\n\n\n");

}

