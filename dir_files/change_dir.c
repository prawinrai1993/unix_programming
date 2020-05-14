#include"my_headers.h"


static int find(char *path,char *name2search);

main(int argc,char **argv)
{
	char path[40],name2search[20];

	int cnt;


	if(argc<2)
	{
		printf("error: Usage <./ch>  <foldername>");
		return;
	}



		strcpy(path,"/home");



	strcpy(name2search,argv[1]);

	cnt=find(path,name2search);



}

static int find(char *path,char *name2search)
{

	int fd;
	struct dirent *ptr=NULL;
	DIR *dp=NULL;
	char str[1000];
	static char location[1000];
	char change[100];
	static int cnt,i;
	bzero(change,100);
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
		if(strstr(ptr->d_name,name2search))
			{
			fd=open("script.sh",O_RDWR | O_CREAT | O_TRUNC,0777);
			strcpy(change,"cd ");
			strcat(change,location);	
			strcat(change,"/");
//			strcat(change," | gnome-terminal");
			write(fd,change,strlen(change));
			close(fd);
			cnt++;
			}
//			printf("%s..............\n",location);
			find(str,name2search);
		}


	}
	if(cnt==1)
	{
		printf("%s",change);
		system("./script.sh");
//		system(change);
//		execlp("./script.sh","./script.sh");
//		if(chdir(change)==-1)
//		perror("chdir");
	}

	return cnt;
}


