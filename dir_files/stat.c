#include"my_headers.h"

main(int argc,char **argv)
{
struct stat v;

if(argc<2)
{
	printf("ERROR: Usage: ./detail <file_name>\n");
	return;
}

if(stat(argv[1],&v)==-1)
perror("stat");
else
printf("       file: '%s'\n",argv[1]);
printf("       size: %d\n",(int)v.st_size);
printf("      links: %d\n",(int)v.st_nlink);
printf("      inode: %d\n",(int)v.st_ino);
printf("        uid: %d\n",(int)v.st_uid);
printf("        gid: %d\n",(int)v.st_gid);
printf(" protection: %d\n",(int)v.st_mode);
printf("change time: %d\n",(int)v.st_mtime);





}
