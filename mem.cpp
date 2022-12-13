#include "pch.h"
#include "mem.h"

uintptr_t MEM::FindDMAAddy(uintptr_t baseAddress, std::vector<unsigned int> offset)
{
	uintptr_t newAddr = baseAddress;

	for (unsigned int i = 0; i < offset.size(); i++)
	{
		newAddr = *(uintptr_t*)newAddr;
		newAddr += offset[i];
	}

	return newAddr;
}

MEM* mem = new MEM();
