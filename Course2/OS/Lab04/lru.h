#ifndef LRU_H
#define LRU_H

void PageReplace		(size_t queueCapacity, const int* pages, size_t nSize);
void CachePageReplace	(size_t cacheCapacity, const int* pages, size_t nSize);

#endif
