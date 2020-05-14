#include<stdio.h>

double xatof(const char *);

double xatof(const char *str)
{
int  n,sign_flag=0,char_flag=0,dot_flag=0,i;
double x=1,result=0,y=0;

if(str[0]=='-')
	{
	sign_flag=1;
	n=1;
	}
else
	n=0;

if(str[1]=='\0')
sign_flag=0;

for(i=n;str[i]!='\0';i++)
{
	


	if((str[i]=='.'))
	dot_flag=!dot_flag;


	if((str[i]>='0')&&(str[i]<='9')||(dot_flag==1))
{
	if(dot_flag==0)
	{
		y=str[i]-48;
		result=y+result;
		result*=10;
	}
	else if((dot_flag==1)&&(!(str[i]=='.')))
	{	
		x*=10;
		y=str[i]-48;
		result=y+result;
		result*=10;
	}
}
else
break;

}
x*=10;
if((sign_flag==0)||(result==0))
result=result/x;
else if(sign_flag==1)
result=-result/x;

return result;
//printf("atof:%lf\n\n",result);  //test

}

