#include"my_headers.h"

main()
{
char str[100],ch;
int fd1,fd2;
int a,b,res;
	if(mkfifo("f1",0666)==-1)
	perror("mkfifo");
	if(mkfifo("f2",0666)==-1)
	perror("mkfifo");


	fd1=open("f1",O_RDWR);
	fd2=open("f2",O_RDWR);
	while(1)
	{
		read(fd1,str,100);

		sscanf(str,"%d %c %d",&a,&ch,&b);	
		bzero(str,100);
		switch(ch)
		{
		case '+': res=a+b;
			sprintf(str,"%d",res);
			break;
		case '-': res=a-b;
			sprintf(str,"%d",res);
			break;
		case '*': res=a*b;
			sprintf(str,"%d",res);
			break;
		case '/': res=a/b;
			sprintf(str,"%d",res);
		break;
		default:sprintf(str,"%s","invalid operation selected!!!!!!!!!\n");	
			break;
		}

		write(fd2,str,strlen(str)+1);
	

	}
}
