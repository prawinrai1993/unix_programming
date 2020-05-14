#include"my_headers.h"

void long_list(int,char **);
void normal_list(int,char **);
void all_list(int argc,char **argv);
void inode_list(int,char **);
char * date(char *);
char * Time(char *);
char *permission(unsigned int);
char *file_type(unsigned int st_mode);
char * userid(int uid);
char * groupid(int gid);

main(int argc,char **argv)
{

char choice;

if((argc==2)&&(argv[1][0]=='-'))
	choice=argv[1][1];

else if((argc==3)&&(argv[1][0]=='-'))
	choice=argv[1][1];

else
	choice='d';



switch(choice)
{

case 'l' :long_list(argc,argv);
	break;

case 'd' :normal_list(argc,argv);
	break;
case 'a' :all_list(argc,argv); 
	break;
	
case 'i':inode_list(argc,argv);
	break;

case 'h' : printf("help : Usage  <./list>   <[-l(long list) -d(default) -h(help) -i(inode number)](optional)>\n\n");
	break;
default:printf("wrong switch supplied 'check ./list -h for usage <help>'\n\n");
	break;
}

}



void normal_list(int argc,char **argv)
{
struct dirent *ptr;
DIR * dp;

if((argc==3)&&(argv[1][0]=='-'))
{
	dp=opendir(argv[2]);
}
else if((argc==2)&&(argv[1][0]!='-'))
	dp=opendir(argv[1]);
else 
	dp=opendir("./");


while(ptr=readdir(dp))
{
	if(ptr->d_name[0]!='.')
	printf("%-20s",ptr->d_name);
}
printf("\n");
closedir(dp);
}

void all_list(int argc,char **argv)
{
struct dirent *ptr;
DIR * dp;

if((argc==3)&&(argv[1][0]=='-'))
{
	dp=opendir(argv[2]);
}
else if((argc==2)&&(argv[1][0]!='-'))
	dp=opendir(argv[1]);
else 
	dp=opendir("./");


while(ptr=readdir(dp))
{
	printf("%-20s  ",ptr->d_name);
}
printf("\n");
closedir(dp);
}






void inode_list(int argc,char **argv)
{
struct dirent *ptr;
DIR * dp;

if((argc==3)&&(argv[1][0]=='-'))
{
	dp=opendir(argv[2]);
}
else if((argc==2)&&(argv[1][0]!='-'))
	dp=opendir(argv[1]);
else
	dp=opendir("./");


printf("%-10s %-20s\n\n","inode no.","file name");
while(ptr=readdir(dp))
{
	if(ptr->d_name[0]!='.')
	printf("%-10d %-20s\n",ptr->d_ino,ptr->d_name);
}
printf("\n");
closedir(dp);
}



void long_list(int argc,char **argv)
{
struct dirent *ptr;
struct stat v;
DIR * dp;

if((argc==3)&&(argv[1][0]=='-'))
{
	dp=opendir(argv[2]);
}
else if((argc==2)&&(argv[1][0]!='-'))
	dp=opendir(argv[1]);
else
	dp=opendir("./");




printf("%-5s %-8s %-8s %-12s %-10s %-6s %-3s %-11s %-9s %-10s\n\n","f_typ","gid","uid","permissions","inode no.","size","lnk","mod_date","mod_time","file_name");

	while(ptr=readdir(dp))
	{
stat(ptr->d_name,&v);

	if(ptr->d_name[0]!='.')
printf("%-5s %-8s %-8s %-12s %-10d %-6u %-3d %-11s %-9s %-10s\n",file_type(v.st_mode),groupid(v.st_gid),userid(v.st_uid),permission(v.st_mode),ptr->d_ino,(unsigned int)v.st_size,v.st_nlink,date(ptr->d_name),Time(ptr->d_name),ptr->d_name);
	}	
printf("\n");
closedir(dp);
}



char * date(char *p)
{
char date[20];
static char str[20];
struct stat v;
struct tm *t;

lstat(p,&v);

t=localtime(&v.st_mtime);

strftime(date,20,"%F",t);

strcpy(str,date);

return str;

}

char * Time(char *p)
{
char time[20];
static char str[20];
struct stat v;
struct tm *t;

lstat(p,&v);

t=localtime(&v.st_mtime);

strftime(time,20,"%T",t);

strcpy(str,time);

return str;

}


char *permission(unsigned int st_mode)
{

static char str[20];

if((st_mode)&(S_IRUSR))
strcpy(str,"r");
else
strcpy(str,"-");


if((st_mode)&(S_IWUSR))
strcat(str,"w");
else
strcat(str,"-");


if((st_mode)&(S_IXUSR))
strcat(str,"x");
else
strcat(str,"-");

if((st_mode)&(S_IRGRP))
strcat(str,"r");
else
strcat(str,"-");


if((st_mode)&(S_IWGRP))
strcat(str,"w");
else
strcat(str,"-");


if((st_mode)&(S_IXGRP))
strcat(str,"x");
else
strcat(str,"-");


if((st_mode)&(S_IROTH))
strcat(str,"r");
else
strcat(str,"-");


if((st_mode)&(S_IWOTH))
strcat(str,"w");
else
strcat(str,"-");

if((st_mode)&(S_IXOTH))
strcat(str,"x");
else
strcat(str,"-");



return str;
}


char *file_type(unsigned int st_mode)
{

static char str[20];

if(S_ISSOCK(st_mode))
strcpy(str,"SOK");

else if(S_ISLNK(st_mode))
strcpy(str,"LNK");


else if(S_ISREG(st_mode))
strcpy(str,"REG");

else if(S_ISBLK(st_mode))
strcpy(str,"BLK");


else if(S_ISDIR(st_mode))
strcpy(str,"DIR");


else if(S_ISCHR(st_mode))
strcpy(str,"CHR");


else if(S_ISFIFO(st_mode))
strcpy(str,"FIFO");

return str;
}

char * userid(int uid)
{
	static char str[20];
	struct passwd *v;

	v=getpwuid(uid);
	strcpy(str,v->pw_name);
	return str;
}


char * groupid(int gid)
{
static char str[20];
struct group *v;

v=getgrgid(gid);

strcpy(str,v->gr_name);

return str;
}


