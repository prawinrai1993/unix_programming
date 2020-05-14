#include"my_headers.h"

main(int argc,char **argv)
{

struct stat v1,v2;

if(argc<3)
{
printf("ERROR: Usage ./cmp_time <filename1> <filename2>\n");
return;
}
	
stat(argv[1],&v1);
stat(argv[2],&v2);

if((v1.st_mtime)>(v2.st_mtime))
printf("file  '%s'  is newer than file  '%s' \n\n",argv[1],argv[2]);
else if((v1.st_mtime)<(v2.st_mtime))
printf("file  '%s'  is newer than file  '%s'\n\n",argv[2],argv[1]);
else
printf("both created at same time\n\n");

}
