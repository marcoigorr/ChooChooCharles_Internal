#pragma once
#include "pch.h"

#define OFFSET std::vector<unsigned int>

OFFSET sumOffsets(OFFSET vector1, OFFSET vector2)
{
	OFFSET newVector = vector1;
	for (unsigned int i = 0; i < vector2.size(); i++)
	{
		newVector.push_back(vector2[i]);
	}
	return newVector;
}

namespace Offset
{
	OFFSET aPlayerController = { 0xDE8, 0x38, 0x0, 0x30 };
	OFFSET aCharacter = { 0xDE8, 0x38, 0x0, 0x30, 0x260 };
	OFFSET aCharlesRef = { 0xDE8, 0x38, 0x0, 0x30, 0x260, 0x8C0 };
	OFFSET aTrainRef = { 0xDE8, 0x38, 0x0, 0x30, 0x260, 0x760 };
	OFFSET aCharacterMovement = { 0xDE8, 0x38, 0x0, 0x30, 0x260, 0x288 };
	OFFSET aCapsuleComponent = { 0xDE8, 0x38, 0x0, 0x30, 0x260, 0x290 };

	namespace PlayerController
	{
		OFFSET bCanBeDamaged = sumOffsets(aPlayerController, { 0x59 });
		OFFSET ControlRotationPitch = sumOffsets(aPlayerController, { 0x288 });
		OFFSET ControlRotationYaw = sumOffsets(aPlayerController, { 0x28C });
	}

	namespace Character
	{
		OFFSET varHealthMain = sumOffsets(aCharacter, { 0x6C4 });
		OFFSET varSprintSpeed = sumOffsets(aCharacter, { 0x608 });
		OFFSET varWalkSpeed = sumOffsets(aCharacter, { 0x60C });
	}
}
