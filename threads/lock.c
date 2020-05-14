#include"my_headers.h"


pthread_t tid_1,tid_2,tid_3;
pthread_mutex_t m1,m2,m3;
void * f1(void *ptr)
{
	int i;
//	printf("\nin f1:%d\n",getpid());
	for(i=1;i<27;i++)
{
	pthread_mutex_lock(&m1);
//	usleep(100);
	printf("%c",i+64);
	pthread_mutex_unlock(&m2);
}

	pthread_exit(0);
}

void * f2(void *ptr)
{
	int i;
//	printf("\nin f2:%d\n",getpid());
	for(i=1;i<27;i++)
{
	pthread_mutex_lock(&m2);
//	usleep(100);
	printf("%d",i);
	pthread_mutex_unlock(&m3);
}

	pthread_exit(0);
}

void * f3(void *ptr)
{
	int i;
//	printf("\nin f3:%d\n",getpid());

	for(i=1;i<27;i++)
{
	pthread_mutex_lock(&m3);
//	usleep(100);
	printf("%c",i+96);
	pthread_mutex_unlock(&m1);
}
	fflush(stdout);
	pthread_exit(0);
}

main()
{
	pthread_mutex_init(&m1,NULL);
	pthread_mutex_init(&m2,NULL);
	pthread_mutex_init(&m3,NULL);
//	printf("\nin main:%d",getpid());
	pthread_create(&tid_1,NULL,f1,NULL);
	pthread_create(&tid_2,NULL,f2,NULL);
	pthread_create(&tid_2,NULL,f3,NULL);
	pthread_join(tid_1,0);
	pthread_join(tid_2,0);
	pthread_join(tid_3,0);
	pthread_exit(0);
}
