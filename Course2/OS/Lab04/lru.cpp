#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include "lru.h"
#include "queue.h"

struct SCacheNode
{
	SCacheNode*	pPrev;
	SCacheNode*	pNext;
	int			iValue;
};

struct SCache
{
	SCacheNode*	pHead;
	SCacheNode*	pTail;
	size_t		nCap;
	size_t		nSize;
};

SCacheNode* CacheNodeNew(int iValue)
{
	SCacheNode* pNode	= (SCacheNode*)malloc(sizeof(SCacheNode));
	pNode->iValue		= iValue;
	pNode->pNext		= pNode->pPrev = NULL;
	return pNode;
}

void CachePromoteToHead(SCache* pCache, SCacheNode* pNode)
{
	if (pNode == pCache->pHead)
		return;
	if (pNode == pCache->pTail)
	{
		SCacheNode* newTail		= pNode->pPrev;
		newTail->pNext			= NULL;
		pCache->pTail			= newTail;
		pCache->pHead->pPrev	= pNode;
		pNode->pNext			= pCache->pHead;
		pCache->pHead			= pNode;
		pCache->pHead->pPrev	= NULL;
	}
	else
	{
		SCacheNode* pNext		= pNode->pNext;
		SCacheNode* pPrev		= pNode->pPrev;
		pNode->pNext			= pCache->pHead;
		pCache->pHead->pPrev	= pNode;
		pCache->pHead			= pNode;
		pNext->pPrev			= pPrev;
		pPrev->pNext			= pNext;
	}
}

int CacheRemoveTail(SCache* pCache)
{
	SCacheNode* pTail			= pCache->pTail;
	int tailValue				= pTail->iValue;
	pCache->pTail				= pTail->pPrev;
	pCache->pTail->pNext		= NULL;
	free(pTail);
	return tailValue;
}

void CacheAdd(SCache* pCache, int iValue)
{
	SCacheNode* pHeadNew	= CacheNodeNew(iValue);
	if (pCache->nSize == 0)
	{
		pCache->pHead		= pHeadNew;
		pCache->pTail		= pCache->pHead;
	}
	else
	{
		pCache->pHead->pPrev	= pHeadNew;
		pHeadNew->pNext			= pCache->pHead;
		pCache->pHead			= pHeadNew;
	}
}

SCacheNode* CacheFind(SCache* pCache, int iValue)
{
	SCacheNode* pNode = pCache->pHead;
	while (pNode != NULL)
	{
		if (pNode->iValue == iValue)
			return pNode;
		pNode = pNode->pNext;
	}
	return NULL;
}

SCache* CacheNew(size_t nCap)
{
	SCache* pCache	= (SCache*)malloc(sizeof(SCache));
	pCache->nCap	= nCap;
	pCache->nSize	= 0;
	pCache->pHead	= pCache->pTail = NULL;
	return pCache;
}

void CacheDelete(SCache* pCache)
{
	SCacheNode* pNode = pCache->pHead;
	while (pNode != NULL)
	{
		SCacheNode* pNext = pNode->pNext;
		free(pNode);
		pNode = pNext;
	}
	free(pCache);
}

bool CacheContain(SCache* pCache, int iValue)
{
	return CacheFind(pCache, iValue) != nullptr;
}

bool CacheIsFull(SCache* pCache)
{
	return pCache->nSize == pCache->nCap ? true : false;
}

int CachePush(SCache* pCache, int iValue)
{
	SCacheNode* pNode = CacheFind(pCache, iValue);
	if (!pNode)
	{
		if (CacheIsFull(pCache))
		{
			int iResult = CacheRemoveTail(pCache);
			CacheAdd(pCache, iValue);
			return iResult;
		}
		else
		{
			CacheAdd(pCache, iValue);
			pCache->nSize++;
			return NULL;
		}
	}
	else
	{
		CachePromoteToHead(pCache, pNode);
		return NULL;
	}
}

void CacheFileOut(SCache* pCache, FILE* pFile)
{
	if (pCache->nSize == 0)
	{
		fprintf(pFile, "[]");
		return;
	}
	fprintf(pFile, "[");
	SCacheNode* pNode = pCache->pHead;
	while (pNode != NULL)
	{
		fprintf(pFile, " %d ", pNode->iValue);
		pNode = pNode->pNext;
	}
	fprintf(pFile, "]");
}

void CachePrint(SCache* pCache)
{
	CacheFileOut(pCache, stdout);
}


void PrintAlreadyInCache(SCache* pCache, int iValue, const char* szIdent)
{
	printf("%sPage is alerady in the cache\n", szIdent);
	printf("%scache: ", szIdent);
	CachePrint(pCache);
	printf("\n");
}

void CachePageReplace(size_t cacheCapacity, const int* piPages, size_t nSize)
{
	SCache* pCache = CacheNew(cacheCapacity);
	int iPageFaults = 0;
	const char* szIdent = "    ";

	printf("\nLRU page replacement algorithm\n");
	for (size_t i = 0; i < nSize; i++)
	{
		int iPage = piPages[i];
		printf("  Requesting for page %d\n", iPage);
		if (CacheIsFull(pCache))
		{
			if (!CacheContain(pCache, iPage))
			{
				int swapped = CachePush(pCache, iPage);
				printf("%sSwapping off page\t# %d\n", szIdent, swapped);
				printf("%sIncreasing page faults counter\t= %d\n", szIdent, ++iPageFaults);
				printf("%scache: ", szIdent);
				CachePrint(pCache);
				printf("\n");
			}
			else
			{
				CachePush(pCache, iPage);
				PrintAlreadyInCache(pCache, iPage, szIdent);
			}
		}
		else
		{
			if (!CacheContain(pCache, iPage))
			{
				CachePush(pCache, iPage);
				printf("%sPushing page to the cache...\n", szIdent);
				printf("%sIncreasing page faults counter\t= %d\n", szIdent, ++iPageFaults);
				printf("%scache: ", szIdent);
				CachePrint(pCache);
				printf("\n");
			}
			else
			{
				CachePush(pCache, iPage);
				PrintAlreadyInCache(pCache, iPage, szIdent);
			}
		}
	}
	printf("Page faults (total)\t= %d\n", iPageFaults);
	CacheDelete(pCache);
}

void PageReplace(size_t nQueueCapacity, const int* piPages, size_t nSize)
{
	SQueue* pQueue		= QueueNew(nQueueCapacity);
	int iPageFaults		= 0;
	const char* szIdent	= "    ";

	printf("\nDemonstrating page replacement algorithm:\n");
	for (size_t i = 0; i < nSize; i++)
	{
		int iPage = piPages[i];
		printf("  Requesting for page %d\n", iPage);
		if (QueueIsFull(pQueue))
		{
			if (!QueueHasItem(pQueue, iPage))
			{
				int swapped;
				QueuePop(pQueue,	&swapped);
				QueuePush(pQueue,	iPage);
				printf("%sSwapping off page %d\n", szIdent, swapped);
				printf("%sIncreasing page faults counter\t= %d\n", szIdent, ++iPageFaults);
				printf("%squeue: ",	szIdent);
				QueuePrint(pQueue);
				printf("\n");
			}
			else
				printf("%sPage is already in the queue\n", szIdent);
		}
		else
		{
			if (!QueueHasItem(pQueue, iPage))
			{
				QueuePush(pQueue, iPage);
				printf("%sPushing page to the queue...\n", szIdent);
				printf("%sIncreasing page faults counter\t= %d\n", szIdent, ++iPageFaults);
				printf("%squeue: ", szIdent);
				QueuePrint(pQueue);
				printf("\n");
			}
			else
				printf("    Page is already in the queue\n");
		}
	}
	printf("Page faults (total): %d\n", iPageFaults);
	QueueFree(pQueue);
}
