#include"my_headers.h"

main(int argc,char **argv)
{
struct dirent *ptr=NULL;
DIR* dp=NULL;
int i=0;


if(argc<2)
{
	printf("Error: Usage synatx <./search_file> <filname>  <path(optional)> <exact(optional)>\n\n");
	return;
}

if(argc==2)
	dp=opendir("./");
else if((argc==3)||(argc==4))
{
	dp=opendir(argv[2]);
	if(dp==NULL)
	{
		printf("NO directory found!!!!!!!!\n");
		return;
	}

}


while(ptr=readdir(dp))
{	
	if(strcmp(argv[3],"exact")==0)
	{	
		if(strcmp(argv[1],ptr->d_name)==0)
		{
			printf("'filename' = %s 'inode_number' = %d\n\n",ptr->d_name,ptr->d_ino);
		}
	}
	else 
	{
	if(strstr(ptr->d_name,argv[1]))
		{
			printf("'filename' = %s 'inode_number'= %d\n\n",ptr->d_name,ptr->d_ino);
		}
	}
}



printf("%d results found!!!!!!!!!\n\n",i);

}
