#include "pch.h"
#include "address.h"

#include "mem.h"
#include "offsets.hpp"

void Address::CalcAddresses()
{
	Character->varHealthMain = (uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::Character::varHealthMain);
	Character->varSprintSpeed = (uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::Character::varSprintSpeed);
	Character->varWalkSpeed = (uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::Character::varWalkSpeed);
}

Address* addr = new Address();
_Character* Character = new _Character();