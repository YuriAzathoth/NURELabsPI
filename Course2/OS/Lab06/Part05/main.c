#include <sys/unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define THREADS_COUNT 10
#define REPEATS_COUNT 5

void do_action(uint8_t id, const char* action)
{
	printf("%d: %s\n", id, action);
    usleep(rand() & 200 + 200);
}

void* do_eat(void* id_ptr)
{
	uint8_t id = *(uint8_t*)id_ptr;
	for (uint8_t i = 0; i < REPEATS_COUNT; i++)
	{
		do_action(id, "Thinking...");
		do_action(id, "Grabbed spoon 1");
		do_action(id, "Grabbed spoon 2");
		do_action(id, "Eating...");
		do_action(id, "Put spoon 1");
		do_action(id, "Put spoon 2");
		do_action(id, "Done");
	}
	return 0;
}

int main()
{
	pthread_t	threads[THREADS_COUNT];
	uint8_t		thread_ids[THREADS_COUNT];

	srand(time(0));

    for (uint8_t id = 0; id < THREADS_COUNT; id++)
    {
		thread_ids[id] = id;
		pthread_create(&threads[id], 0, do_eat, (void*)&thread_ids[id]);
    }

    for (uint8_t id = 0; id < THREADS_COUNT; id++)
		pthread_join(threads[id], 0);

	return 0;
}
