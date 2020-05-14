#include"my_headers.h"


main()
{
int c;


c=fork();
if(c)
execlp("ps","ps","-e",NULL);
else
execlp("grep","grep","printf","test.c",NULL);


}
