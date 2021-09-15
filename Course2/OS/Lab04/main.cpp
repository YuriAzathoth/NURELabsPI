#include <cstdio>
#include <windows.h>
#include "memory.h"
#include "queue.h"
#include "lru.h"

void PrintSystemInfo()
{
	SYSTEM_INFO Info;
	MEMORYSTATUSEX MemStatus;
	MemStatus.dwLength = sizeof(MemStatus);

	GetSystemInfo(&Info);
	printf("System information:\n");
	printf("  Memory\n");
	printf("    Page size\t\t\t= %ld bytes\n",				Info.dwPageSize);
	printf("    Minimum application address\t= 0x%llX\n",	Info.lpMinimumApplicationAddress);
	printf("    Maximum application address\t= 0x%llX\n",	Info.lpMaximumApplicationAddress);
	printf("    Allocation granularity\t= %ld\n",			Info.dwAllocationGranularity);

	GlobalMemoryStatusEx(&MemStatus);
	printf("  Memory usage\n");
	printf("    Memory load\t\t\t= %ld%%\n",				MemStatus.dwMemoryLoad);
	printf("    Physical memory (total)\t= %.2fMb\n",		(double)MemStatus.ullTotalPhys		/ 1000000.0);
	printf("    Physical memory (avail)\t= %.2fMb\n",		(double)MemStatus.ullAvailPhys		/ 1000000.0);
	printf("    Virtual memory (total)\t= %.2fMb\n",		(double)MemStatus.ullTotalVirtual	/ 1000000.0);
	printf("    Virtual memory (avail)\t= %.2fMb\n",		(double)MemStatus.ullAvailVirtual	/ 1000000.0);
}

int main()
{
	constexpr size_t	SIZE = 20;
	constexpr int		REFERENCE[SIZE] = { 1, 2, 3, 1, 5, 4, 3, 2, 5, 7, 6, 2, 3, 8, 8, 7, 6, 3, 2, 3 };

	printf("Before allocation\n");
	PrintSystemInfo();
	void* pMemoryPool = MemoryMalloc(1000000000l);
	printf("\nAfter allocation\n");
	PrintSystemInfo();
	MemoryFree(pMemoryPool);
	printf("\nMemory released\n");
	PrintSystemInfo();

	FILE* pFile = fopen("out.log", "wa");
	PrintFreeBlocks(pFile);
	fclose(pFile);

	PageReplace			(5, REFERENCE, SIZE);
	CachePageReplace	(5, REFERENCE, SIZE);

	return 0;
}
