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
	OFFSET aPlayerController =	{ 0xDE8, 0x38, 0x0, 0x30 };
	OFFSET aCharacter =			{ 0xDE8, 0x38, 0x0, 0x30, 0x260 };
	OFFSET aCharlesRef =		{ 0xDE8, 0x38, 0x0, 0x30, 0x260, 0x8C0 };
	OFFSET aTrainRef =			{ 0xDE8, 0x38, 0x0, 0x30, 0x260, 0x760 };
	OFFSET aCharacterMovement = { 0xDE8, 0x38, 0x0, 0x30, 0x260, 0x288 };
	OFFSET aCapsuleComponent =	{ 0xDE8, 0x38, 0x0, 0x30, 0x260, 0x290 };

	namespace PlayerController
	{
		OFFSET bCanBeDamaged =				sumOffsets(aPlayerController, { 0x59 });
		OFFSET ControlRotationPitch =		sumOffsets(aPlayerController, { 0x288 });
		OFFSET ControlRotationYaw =			sumOffsets(aPlayerController, { 0x28C });
	}

	namespace Character
	{
		OFFSET varHealthMain =				sumOffsets(aCharacter, { 0x6C4 });
		OFFSET varSprintSpeed =				sumOffsets(aCharacter, { 0x608 });
		OFFSET varWalkSpeed =				sumOffsets(aCharacter, { 0x60C });
		OFFSET JumpMaxCount =				sumOffsets(aCharacter, { 0x344 });
		OFFSET CancelFallDamageonReset =	sumOffsets(aCharacter, { 0x799 });
		OFFSET CanMove =					sumOffsets(aCharacter, { 0x758 });
		OFFSET CanInventory =				sumOffsets(aCharacter, { 0x759 });
		OFFSET CanJump =					sumOffsets(aCharacter, { 0x75A });
	}
	
	namespace TrainRef
	{  
		OFFSET TrainHealth =					sumOffsets(aTrainRef, { 0xA40 });
		OFFSET ForwardMaxSpeed =				sumOffsets(aTrainRef, { 0x7D4 });
		OFFSET BackwardMaxSpeed =				sumOffsets(aTrainRef, { 0x7D8 });
		OFFSET TrainSpeed =						sumOffsets(aTrainRef, { 0x7E0 });
		OFFSET AccelerationMultiplier =			sumOffsets(aTrainRef, { 0x818 });
		OFFSET BreakingMultiplier =				sumOffsets(aTrainRef, { 0x820 });
		OFFSET StoppingTrain =					sumOffsets(aTrainRef, { 0x81C });
		OFFSET CurrentPositiononRail =			sumOffsets(aTrainRef, { 0x7E4 });
		OFFSET BrokenDown =						sumOffsets(aTrainRef, { 0x978 });
		OFFSET ArmorLevelMultiplier =			sumOffsets(aTrainRef, { 0x97C });
		OFFSET DamageLevelMultiplier =			sumOffsets(aTrainRef, { 0x984 });
		OFFSET SpeedLevelMultiplier =			sumOffsets(aTrainRef, { 0x980 });
		OFFSET RangeGunDamage =					sumOffsets(aTrainRef, { 0x96C });
		OFFSET RangeGunSlowingMultiplier =		sumOffsets(aTrainRef, { 0x974 });  
		OFFSET RangeGunJamTHRESHHOLD =			sumOffsets(aTrainRef, { 0xA28 });
		OFFSET RangeGunJamming =				sumOffsets(aTrainRef, { 0xA20 });
		OFFSET RangeGunJammed =					sumOffsets(aTrainRef, { 0xA24 });
		OFFSET MachineGunDamage =				sumOffsets(aTrainRef, { 0x968 });
		OFFSET MachineGunSlowingMultiplier =	sumOffsets(aTrainRef, { 0x970 });
		OFFSET MachineGunJamTHRESHHOLD =		sumOffsets(aTrainRef, { 0xA10 });
		OFFSET MachineGunJamming =				sumOffsets(aTrainRef, { 0xA08 });
		OFFSET MachineGunJammed =				sumOffsets(aTrainRef, { 0xA0C });
		OFFSET FlamethrowerJamming =			sumOffsets(aTrainRef, { 0xA2C });
		OFFSET FlamethrowerJammed =				sumOffsets(aTrainRef, { 0xA30 });
		OFFSET FlamethrowerJamTHRESHHOLD =		sumOffsets(aTrainRef, { 0xA34 });
	}

	namespace CharacterMovement
	{
		OFFSET JumpZVelocity =	sumOffsets(aCharacterMovement, { 0x158 });
		OFFSET GravityScale =	sumOffsets(aCharacterMovement, { 0x150 });
		OFFSET Mass =			sumOffsets(aCharacterMovement, { 0x208 });
	}

	namespace CapsuleComponent
	{
		OFFSET RelativeLocationX = sumOffsets(aCapsuleComponent, { 0x11C });
		OFFSET RelativeLocationY = sumOffsets(aCapsuleComponent, { 0x120 });
		OFFSET RelativeLocationZ = sumOffsets(aCapsuleComponent, { 0x124 });
	}
}
