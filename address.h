#pragma once


class Address
{
public:
	uintptr_t moduleBase;
	uintptr_t baseAddress;

	uintptr_t aPlayerController;
	uintptr_t aCharacter;
	uintptr_t aCharlesRef;
	uintptr_t aTrainRef;
	uintptr_t aCharacterMovement;
	uintptr_t aCapsuleComponent;

	void CalcAddresses();
};

class _PlayerController
{
public:
	uintptr_t* bCanBeDamaged;
	uintptr_t* ControlRotationPitch;
	uintptr_t* ControlRotationYaw;
};

class _Character
{
public:
	uintptr_t* varHealthMain;
	uintptr_t* varSprintSpeed;
	uintptr_t* varWalkSpeed;
	uintptr_t* JumpMaxCount;
	uintptr_t* CancelFallDamageonReset;
	uintptr_t* CanMove;
	uintptr_t* CanInventory;
	uintptr_t* CanJump;
};

class _TrainRef
{
public:
	uintptr_t* TrainHealth;
	uintptr_t* ForwardMaxSpeed;
	uintptr_t* BackwardMaxSpeed;
	uintptr_t* TrainSpeed;
	uintptr_t* AccelerationMultiplier;
	uintptr_t* BreakingMultiplier;
	uintptr_t* StoppingTrain;
	uintptr_t* CurrentPositiononRail;
	uintptr_t* BrokenDown;
	uintptr_t* ArmorLevelMultiplier;
	uintptr_t* DamageLevelMultiplier;
	uintptr_t* SpeedLevelMultiplier;
	uintptr_t* RangeGunDamage;
	uintptr_t* RangeGunSlowingMultiplier;
	uintptr_t* RangeGunJamTHRESHHOLD;
	uintptr_t* RangeGunJamming;
	uintptr_t* RangeGunJammed;
	uintptr_t* MachineGunDamage;
	uintptr_t* MachineGunSlowingMultiplier;
	uintptr_t* MachineGunJamTHRESHHOLD;
	uintptr_t* MachineGunJamming;
	uintptr_t* MachineGunJammed;
	uintptr_t* FlamethrowerJamming;
	uintptr_t* FlamethrowerJammed;
	uintptr_t* FlamethrowerJamTHRESHHOLD;
};

class _CharacterMovement
{
public:
	uintptr_t* JumpZVelocity;
	uintptr_t* GravityScale;
	uintptr_t* Mass;
};

class _CapsuleComponent
{
public:
	uintptr_t* RelativeLocationX;
	uintptr_t* RelativeLocationY;
	uintptr_t* RelativeLocationZ;
};

extern Address* addr;
extern _PlayerController* PlayerController;
extern _Character* Character;
extern _TrainRef* TrainRef;
extern _CharacterMovement* CharacterMovement;
extern _CapsuleComponent* CapsuleComponent;