#include"my_headers.h"

void f(int num)
{
printf("ctrl + c has been disabled\n");

}

main()
{
signal(19,SIG_IGN);
signal(2,f);

while(1)
{
printf("%d\n",getpid());
sleep(1);
}


}
