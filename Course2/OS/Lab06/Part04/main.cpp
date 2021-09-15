#include <sys/wait.h>
#include <clocale>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <pthread.h>
#include <iostream>
#include <queue>
using namespace std;

typedef uint64_t		TMessage;
typedef queue<TMessage>	TMsgQueue;

constexpr uint64_t MAX_16BIT = static_cast<uint64_t>(1 << 15);
constexpr uint64_t MAX_48BIT = static_cast<uint64_t>(1 << 31) + MAX_16BIT;

pthread_mutex_t mxPrint	= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mxRand	= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mxRead	= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mxWrite	= PTHREAD_MUTEX_INITIALIZER;

void* WriteNews(void* pNews)
{
	thread_local TMsgQueue* pMsgQueue	= reinterpret_cast<TMsgQueue*>(pNews);

	pthread_mutex_lock(&mxRand);
	thread_local TMessage Message		= MAX_16BIT + rand() % MAX_48BIT;
	pthread_mutex_unlock(&mxRand);

	pthread_mutex_lock(&mxPrint);
	cout << "Write:\t" << Message << endl;
	pthread_mutex_unlock(&mxPrint);

	pthread_mutex_lock(&mxWrite);
	pMsgQueue->push(Message);
	pthread_mutex_unlock(&mxWrite);

	return nullptr;
}

void* ReadNews(void* pNews)
{
	thread_local TMsgQueue* pMsgQueue = reinterpret_cast<TMsgQueue*>(pNews);

	while (pMsgQueue->empty());

	pthread_mutex_lock(&mxPrint);
	cout << "Read:\t" << pMsgQueue->back() << endl;
	pthread_mutex_unlock(&mxPrint);

	pthread_mutex_lock(&mxRead);
	pMsgQueue->pop();
	pthread_mutex_unlock(&mxRead);

	return nullptr;
}

int main()
{
	TMsgQueue	News;
	constexpr	uint8_t THREADS_COUNT = 50;
	pthread_t	thrAuthors[THREADS_COUNT];
	pthread_t	thrUsers[THREADS_COUNT];

	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));

	for (uint8_t i = 0; i < THREADS_COUNT; i++)
	{
		pthread_create(&thrAuthors[i],	0, WriteNews,	reinterpret_cast<void*>(&News));
		pthread_create(&thrUsers[i],	0, ReadNews,	reinterpret_cast<void*>(&News));
	}

	for (uint8_t i = 0; i < THREADS_COUNT; i++)
	{
		pthread_join(thrAuthors[i], 0);
		pthread_join(thrUsers[i], 0);
	}

	return 0;
}
