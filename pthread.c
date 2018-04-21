#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int sum;
void *runner(void *param);

int main()
{
	pthread_t tid;
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr,runner,NULL);

	pthread_join(tid, NULL);

	printf("sum = %d\n", sum);

	return 0;
}

void *runner(void *param)
{
	sum = 42;
	sleep(5);
	pthread_exit(0);
}

