#pragma once


class Address
{
public:
	uintptr_t moduleBase;
	uintptr_t baseAddress;

	void CalcAddresses();
};

class _Character
{
public:
	uintptr_t* varHealthMain;
	uintptr_t* varSprintSpeed;
	uintptr_t* varWalkSpeed;
};

extern Address* addr;
extern _Character* Character;