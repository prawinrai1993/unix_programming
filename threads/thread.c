#include"my_headers.h"

pthread_t tid_1,tid_2,tid_3;
pthread_attr_t v;
void * f1(void *ptr)
{

	int i,j;
	struct sched_param t;
	//	sched_setscheduler(0,SCHED_FIFO,&t);
	printf("\nin f1:%d",getpid());
	//sleep(9);
	for(i=0;i<100000;i++)
		for(j=0;j<10000;j++);
	printf("\nf1.............exiting%d\n",getpid());
	//while(1);
	pthread_exit(0);

}

void * f2(void *ptr)
{
	int i,j;
	struct sched_param t;
	//	sched_setscheduler(0,SCHED_FIFO,&t);
	printf("\nin f2:%d\n",getpid());
	//sleep(6);
	for(i=0;i<10000;i++)
		for(j=0;j<1000;j++);
	printf("\nf2.............exiting%d\n",getpid());
	//while(1);
	pthread_exit(0);
}

void * f3(void *ptr)
{
	int i,j;
	struct sched_param t;
	//	sched_setscheduler(0,SCHED_FIFO,&t);
	printf("\nin f3:%d\n",getpid());
	//sleep(3);
	for(i=0;i<10000;i++)
		for(j=0;j<1000;j++);
	printf("\nf3.............exiting%d\n",getpid());
	//while(1);
	pthread_exit(0);
}


int main()
{
	int ret;
	struct sched_param t;
	printf("\nin main:%d",getpid());
	//pthread_attr_getschedpolicy(&v,&v.schedpolicy);
	//printf("policy=%u\n",v.pol);

	//	ret=pthread_attr_setschedpolicy(&v,SCHED_FIFO);
	sched_setscheduler(0,SCHED_FIFO,&t);
	pthread_attr_init(&v);
	printf("ret=%d.......\n",ret);
	pthread_create(&tid_1,&v,f1,NULL);
	pthread_create(&tid_2,&v,f2,NULL);

	long int x=sysconf(_POSIX_THREAD_CPUTIME);
	printf("value=%ld.......\n",x);
	//#define _POSIX_THREAD_CPUTIME 100000
	pthread_create(&tid_3,&v,f3,NULL);
	//sleep(10);
	pthread_join(tid_1,0);
	pthread_join(tid_2,0);
	pthread_join(tid_3,0);
	pthread_exit(0);
}
