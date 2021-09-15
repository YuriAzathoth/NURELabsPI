#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include "memory.h"

typedef DWORD* ADDRESS;

void* MemoryMalloc(size_t nSize)
{
	SYSTEM_INFO Info;
	GetSystemInfo(&Info);
	ADDRESS dwCurrentAddress	= (ADDRESS)Info.lpMinimumApplicationAddress;
	ADDRESS dwMaxAddress		= (ADDRESS)Info.lpMaximumApplicationAddress;

	while (dwCurrentAddress < dwMaxAddress)
	{
		MEMORY_BASIC_INFORMATION MemInfo;
		VirtualQuery((LPCVOID)dwCurrentAddress, &MemInfo, sizeof(MEMORY_BASIC_INFORMATION));
		if (MemInfo.State == MEM_FREE && MemInfo.RegionSize >= nSize)
			return VirtualAlloc((LPVOID)dwCurrentAddress, nSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		dwCurrentAddress		+= MemInfo.RegionSize;
	}
	return NULL;
}

void MemoryFree(void* pvPtr)
{
	VirtualFree(pvPtr, 0, MEM_RELEASE);
}

void PrintMemoryInfo(FILE* pFile, PMEMORY_BASIC_INFORMATION pBuffer)
{
	fprintf(pFile, "  Base address\t\t= 0x%llX\n",		pBuffer->BaseAddress);
	fprintf(pFile, "    Allocation base\t= 0x%llX\n",	pBuffer->AllocationBase);
	fprintf(pFile, "    Region size\t\t= %llu\n",		pBuffer->RegionSize);
	fprintf(pFile, "    State\t\t= 0x%llX\n",			pBuffer->State);
	fprintf(pFile, "    Type\t\t= 0x%llX\n",			pBuffer->Type);
	fprintf(pFile, "    Allocation protect\t= 0x%X\n",	pBuffer->AllocationProtect);
	fprintf(pFile, "    Protect\t\t= 0x%X",				pBuffer->Protect);
}

void PrintFreeBlocks(FILE* pFile)
{
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	ADDRESS dwMinAddress	= (ADDRESS)sysInfo.lpMinimumApplicationAddress;
	ADDRESS dwMaxAddress	= (ADDRESS)sysInfo.lpMaximumApplicationAddress;
	ADDRESS dwCurrAddress	= dwMinAddress;

	fprintf(pFile, "Free blocks:\n");
	while (dwCurrAddress < dwMaxAddress)
	{
		MEMORY_BASIC_INFORMATION MemInfo;
		VirtualQuery((LPCVOID)dwCurrAddress, &MemInfo, sizeof(MEMORY_BASIC_INFORMATION));
		if (MemInfo.State == MEM_FREE)
		{
			PrintMemoryInfo(pFile, &MemInfo);
			fprintf(pFile, "\n");
		}
		dwCurrAddress		+= MemInfo.RegionSize;
	}
}
