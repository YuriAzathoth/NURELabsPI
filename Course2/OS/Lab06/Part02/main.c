#include <sys/unistd.h>
#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define THREADS_COUNT 10000
pthread_t threads[THREADS_COUNT];

void* test_thread(void* p)
{
	sleep(1);
	return 0;
}

int main()
{
	for (size_t i = 0; i < THREADS_COUNT; i++)
		if (pthread_create(&threads[i], 0, test_thread, 0))
		{
			printf("Max thread count = %llu\n", i);
			return -1;
		}
    return 0;
}
