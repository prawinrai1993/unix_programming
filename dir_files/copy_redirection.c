#include"my_headers.h"

main(int argc,char **argv)
{
int fd1,fd2;
char ch;
int size;

fd1=open(argv[1],O_RDONLY);
fd2=open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0777);
close(0);
close(1);
dup(fd1);
dup(fd2);
while(scanf("%c",&ch)==1)
	printf("%c",ch);


close(fd1);
close(fd2);

}
