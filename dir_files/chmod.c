#include"my_headers.h"

main(int argc,char **argv)
{

int i;
if(argc<3)
{
printf("ERROR :USAGE ./Chmod <premissions> <file_name>\n");
return;
}

chmod(argv[2],0066);

}
