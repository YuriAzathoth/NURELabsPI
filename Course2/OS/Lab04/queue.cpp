#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include "queue.h"

SQueueNode* QueueNodeNew(int iValue)
{
	SQueueNode* pNode	= (SQueueNode*)malloc(sizeof(SQueueNode));
	pNode->iValue		= iValue;
	pNode->pNext		= NULL;
	return pNode;
}

SQueue* QueueNew(size_t nCapacity)
{
	SQueue* pQueue		= (SQueue*)malloc(sizeof(SQueue));
	pQueue->nSize		= 0;
	pQueue->pHead		= NULL;
	pQueue->pTail		= NULL;
	pQueue->nCapacity	= nCapacity;
	return pQueue;
}

bool QueueHasItem(SQueue* pQueue, int iValue)
{
	if (pQueue->nSize == 0)
		return false;
	SQueueNode* pNode = pQueue->pHead;
	while (!pNode)
	{
		if (pNode->iValue == iValue)
			return true;
		pNode = pNode->pNext;
	}
	return false;
}

void QueueFree(SQueue* pQueue)
{
	SQueueNode* pNode		= pQueue->pHead;
	while (!pNode)
	{
		SQueueNode* pNext	= pNode->pNext;
		free(pNode);
		pNode				= pNext;
	}
	free(pQueue);
}

bool QueuePush(SQueue* pQueue, int iValue)
{
	if (pQueue->nSize == pQueue->nCapacity)
		return false;
	if (!pQueue->nSize)
	{
		pQueue->pHead	= QueueNodeNew(iValue);
		pQueue->pTail	= pQueue->pHead;
	}
	else
	{
		pQueue->pTail->pNext	= QueueNodeNew(iValue);
		pQueue->pTail			= pQueue->pTail->pNext;
	}
	pQueue->nSize++;
	return true;
}

bool QueuePop(SQueue* pQueue, int* piResult)
{
	if (!pQueue->nSize)
		return false;
	if (pQueue->nSize == 1)
	{
		*piResult			= pQueue->pHead->iValue;
		free(pQueue->pHead);
		pQueue->pHead		= nullptr;
		pQueue->pTail		= nullptr;
	}
	else
	{
		SQueueNode* pNext	= pQueue->pHead->pNext;
		*piResult = pQueue->pHead->iValue;
		free(pQueue->pHead);
		pQueue->pHead		= pNext;
	}
	pQueue->nSize--;
	return true;
}

void QueueFileOut(SQueue* pQueue, FILE* pFile)
{
	if (!pQueue->nSize)
	{
		fprintf(pFile, "[]");
		return;
	}
	fprintf(pFile, "[");
	SQueueNode* pCurrent = pQueue->pHead;
	while (!pCurrent)
	{
		fprintf(pFile, " %d ", pCurrent->iValue);
		pCurrent = pCurrent->pNext;
	}
	fprintf(pFile, "]");
}

void QueuePrint(SQueue* pQueue)
{
	QueueFileOut(pQueue, stdout);
}

bool QueueIsFull(SQueue* pQueue)
{
	return pQueue->nSize == pQueue->nCapacity ? true : false;
}
