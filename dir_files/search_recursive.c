#include"my_headers.h"


static int find(char *path,char *name2search);

main(int argc,char **argv)
{
	char path[40],name2search[20];

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

	strcpy(name2search,argv[1]);

	cnt=find(path,name2search);

	printf("\n\n%d files found succesfully!!!!!!!!!!!!!!!!!!!!!\n\n",cnt);


}

static int find(char *path,char *name2search)
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
//			printf("%s..............\n",location);
			find(str,name2search);
		}
		else if(strstr(ptr->d_name,name2search))
			{
			printf(" %s%c%s\n",location,'/',ptr->d_name);	
			cnt++;
			}


	}

	return cnt;
}


