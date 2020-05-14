#include"my_headers.h"


static int find(char *path,int inode2search);

main(int argc,char **argv)
{
	char path[40];
	int inode2search;
	struct stat v;
	int cnt;


	if(argc<2)
	{
		printf("error: Usage <./search> <filename> <path(optional)>");
		return;
	}



	if(argc==2)
		strcpy(path,"./");


	if(argc==3)
		strcpy(path,argv[2]);

	stat(argv[1],&v);

	inode2search=v.st_ino;

	cnt=find(path,inode2search);

	printf("\n\n%d files links found succesfully!!!!!!!!!!!!!!!!!!!!!\n\n",cnt);


}

static int find(char *path,int inode2search)
{

	struct dirent *ptr=NULL;
	DIR *dp=NULL;
	char str[1000];
	static char location[1000];
	static int cnt;

	dp=opendir(path);
	if(dp==NULL)
	  return;

	while(ptr=readdir(dp))
	{
		if(((ptr->d_name[0])!='.') && ((ptr->d_type)==4))
		{
			strcpy(str,path);
			strcat(str,"/");
			strcat(str,ptr->d_name);
			strcpy(location,str);
	//		printf("%s..............\n",str);
			find(str,inode2search);
		}
		else if(ptr->d_ino==inode2search)
			{
			printf(" %s%c%s\n",location,'/',ptr->d_name);	
			cnt++;
			}


	}

	return cnt;
}


