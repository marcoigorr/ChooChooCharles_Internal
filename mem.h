#pragma once

class MEM
{
public:
	uintptr_t FindDMAAddy(uintptr_t baseAddress, std::vector<unsigned int> offset);
};

extern MEM* mem;

