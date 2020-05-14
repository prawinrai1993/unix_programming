#include"my_headers.h"

main(int argc,char **argv)
{
	int fd=3;
	char ch;
	FILE *fp=NULL;

fp=fopen(argv[1],"r");

//fd=open(argv[1],O_RDONLY);

if(fd==-1)
{
perror("open");
return;
}

printf("fd=%d.......enter and continue",fd);

getchar();

while(read(fd,&ch,1))
{
	printf("%c",ch);
}


close(fd);


}
