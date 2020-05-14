#include<stdio.h>

int (*p)(const char *,...);
main()
{

p=printf;

p("hello world\n");


}
