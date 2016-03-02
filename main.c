#include "shttpd.h"

pthread_mutex_t fuck;
/*just for test*/
void *  test_job(void * arg)
{
	int num = *(int *)arg;
	pthread_mutex_lock(&fuck);
	printf("job %d is proccessing by worker id %ld\n", num, pthread_self());
	pthread_mutex_unlock(&fuck);
	sleep(4);
	pthread_mutex_lock(&fuck);
	printf("This job num: %d, finished by thread: %ld\n", num, pthread_self());
	pthread_mutex_unlock(&fuck);
	return 0;
}

void  test_request(void * arg)
{
	int i;
	struct Gthread_pool_task * tmp_task;
	struct Gthread_pool * pool = (struct Gthread_pool *)arg;
	assert(arg);
	int * args = (int *)malloc(sizeof(int)*10);
	for(i = 0; i<10; i++)
	{
		args[i] = i;
		tmp_task = (struct Gthread_pool_task *)malloc(sizeof(struct Gthread_pool_task));
		add_job(pool, test_job, &args[i]);
		printf("add task num %d\n", args[i]);
	}
}

int main()
{	
	struct Gthread_pool test_pool;
	Gthread_pool_init(&test_pool, 100, 20, 5);
	test_request(&test_pool);
	sleep(15);
	close_pool(&test_pool);
	while(1);
	return 0;	
}
