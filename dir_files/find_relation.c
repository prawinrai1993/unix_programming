#include"my_headers.h"

main(int argc,char **argv)
{

struct stat v1,v2,v3,v4;

if(argc<3)
{
printf("ERROR: Usage ./find_rel <filename1> <filename2>\n");
return;
}
	
lstat(argv[1],&v1);
lstat(argv[2],&v2);
stat(argv[1],&v3);
stat(argv[2],&v4);

//printf("%d   %d  \n",(int)v1.st_ino,(int)v2.st_ino);

//printf("%d   %d  \n",(int)v3.st_ino,(int)v4.st_ino);


if(((int)(v1.st_ino))==((int)(v2.st_ino)))
printf("file  '%s'  is HARD LINKED to file  '%s' \n\n",argv[1],argv[2]);
else if(((int)(v3.st_ino))==((int)(v4.st_ino)))
printf("file  '%s'  is Symbolic LINKED to file  '%s' \n\n",argv[1],argv[2]);
else
printf("files have no relation\n\n");



}
