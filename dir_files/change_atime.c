#include"my_headers.h"

main(int argc,char **argv)
{


struct stat v1;
struct utimbuf v2;


if(argc<3)
{
	printf("ERROR: Usage ./change_time <filename1 time to change by time of filename2>  <filename2>\n");
	return;
}

lstat(argv[2],&v1);

v2.actime=(int)v1.st_atime;
v2.modtime=(int)v1.st_mtime;

if(utime(argv[1],&v2)==-1)
perror("utime");
else
printf("access time and modification time changed successfully!!!!!!!!!!!\n\n");



}
