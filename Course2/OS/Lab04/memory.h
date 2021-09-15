#ifndef MEMORY_H
#define MEMORY_H

void*	MemoryMalloc	(size_t nSize);
void	MemoryFree		(void* pvPtr);
void	PrintFreeBlocks	(FILE* pFile);

#endif
