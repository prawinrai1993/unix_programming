#include<stdio.h>
#include<unistd.h>
#include<sys/reboot.h>
//#include<linux/reboot.h>
main(int argc,char **argv)
{

if(argc<2)
{
printf("invalid option options[-h(halt)r(restart)p(poweroff)]\n\n");
return;
}

switch(argv[1][1])
{
case 'h':reboot(RB_HALT_SYSTEM);
	perror("reboot");
	break;
//case 'r':reboot(LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2,LINUX_REBOOT_CMD_RESTART,0);
//	break;
//case 'p':reboot(LINUX_REBOOT_MAGIC1,LINUX_REBOOT_MAGIC2,LINUX_REBOOT_CMD_POWER_OFF,0);
//	break;
//default:printf("invalid option options[-h(halt)r(restart)p(poweroff)]\n\n");
//	break;
}


}
