#include"my_headers.h"

main(int argc,char **argv)
{

int fd1,fd2,size;
char *buf;
fd1=open(argv[1],O_RDONLY);

size=lseek(fd1,0,2);
lseek(fd1,0,0);
buf=sbrk(size);
read(fd1,buf,size);
printf("%s\n",buf);
close(fd1);
fd2=open(argv[2],O_CREAT | O_WRONLY | O_TRUNC,0777);

write(fd2,buf,size);

close(fd2);

}
