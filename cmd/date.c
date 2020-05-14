#include<stdio.h>
#include<time.h>
#include<sys/types.h>
main()
{
time_t t;

time(&t);

printf("%s",ctime(&t));


}
