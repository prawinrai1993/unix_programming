#include"my_headers.h"


void f(int num)
{
static int cnt2,cnt3;

if(num==2)
cnt2++;
if(num==3)
cnt3++;

printf("process received signal%d......\n",num);

if(cnt2==3)
signal(2,SIG_DFL);
if(cnt3==5)
signal(3,SIG_DFL);



}


main()
{
printf("process_id......%d\n",getpid());
signal(2,f);
signal(3,f);

while(1);

}
