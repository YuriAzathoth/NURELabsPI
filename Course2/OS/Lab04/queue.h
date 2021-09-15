#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>

struct SQueueNode
{
	int			iValue;
	SQueueNode*	pNext;
};

struct SQueue
{
	SQueueNode*	pHead;
	SQueueNode*	pTail;
	size_t		nCapacity;
	size_t		nSize;
};

SQueue*	QueueNew		(size_t nCapacity);
void	QueueFree		(SQueue* pQueue);
bool	QueueHasItem	(SQueue* pQueue, int iValue);
bool	QueuePush		(SQueue* pQueue, int iValue);
bool	QueuePop		(SQueue* pQueue, int* piResult);
bool	QueueIsFull		(SQueue* pQueue);
void	QueueFileOut	(SQueue* pQueue, FILE* pFile);
void	QueuePrint		(SQueue* pQueue);

#endif
