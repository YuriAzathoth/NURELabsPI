#include <sys/unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define THREADS_COUNT 10
pthread_t threads[THREADS_COUNT];

void* test_thread(void* p)
{
	printf("Thread begin\n");
	sleep(1);
	printf("Thread end\n");
	return 0;
}

int main()
{
	for (int i = 0; i < THREADS_COUNT; i++)
		if (pthread_create(&threads[i], 0, test_thread, 0))
		{
			perror("pthread_create");
			return -1;
		}


	for (int i = 0; i < THREADS_COUNT; i++)
		pthread_join(threads[i], 0);
	perror("pthread_join");

    return 0;
}
