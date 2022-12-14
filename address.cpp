#include "pch.h"
#include "address.h"

#include "mem.h"
#include "offsets.hpp"

void Address::CalcAddresses()
{
	aPlayerController =		mem->FindDMAAddy(baseAddress, Offset::aPlayerController);
	aCharacter =			mem->FindDMAAddy(baseAddress, Offset::aCharacter);
	aCharlesRef =			mem->FindDMAAddy(baseAddress, Offset::aCharlesRef);
	aTrainRef =				mem->FindDMAAddy(baseAddress, Offset::aTrainRef);
	aCharacterMovement =	mem->FindDMAAddy(baseAddress, Offset::aCharacterMovement);
	aCapsuleComponent =		mem->FindDMAAddy(baseAddress, Offset::aCapsuleComponent);

	PlayerController->bCanBeDamaged =			(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::PlayerController::bCanBeDamaged);
	PlayerController->ControlRotationPitch =	(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::PlayerController::ControlRotationPitch);
	PlayerController->ControlRotationYaw =		(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::PlayerController::ControlRotationYaw);

	Character->varHealthMain =				(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::Character::varHealthMain);
	Character->varSprintSpeed =				(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::Character::varSprintSpeed);
	Character->varWalkSpeed =				(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::Character::varWalkSpeed);
	Character->JumpMaxCount =				(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::Character::JumpMaxCount);
	Character->CancelFallDamageonReset =	(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::Character::CancelFallDamageonReset);
	Character->CanMove =					(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::Character::CanMove);
	Character->CanInventory =				(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::Character::CanInventory);
	Character->CanJump =					(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::Character::CanJump);

	TrainRef->TrainHealth =					(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::TrainHealth);
	TrainRef->ForwardMaxSpeed =				(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::ForwardMaxSpeed);
	TrainRef->BackwardMaxSpeed =			(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::BackwardMaxSpeed);
	TrainRef->TrainSpeed =					(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::TrainSpeed);
	TrainRef->AccelerationMultiplier =		(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::AccelerationMultiplier);
	TrainRef->BreakingMultiplier =			(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::BreakingMultiplier);
	TrainRef->StoppingTrain =				(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::StoppingTrain);
	TrainRef->CurrentPositiononRail =		(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::CurrentPositiononRail);
	TrainRef->BrokenDown =					(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::BrokenDown);
	TrainRef->ArmorLevelMultiplier =		(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::ArmorLevelMultiplier);
	TrainRef->DamageLevelMultiplier =		(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::DamageLevelMultiplier);
	TrainRef->SpeedLevelMultiplier =		(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::SpeedLevelMultiplier);
	TrainRef->RangeGunDamage =				(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::RangeGunDamage);
	TrainRef->RangeGunSlowingMultiplier =	(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::RangeGunSlowingMultiplier);
	TrainRef->RangeGunJamTHRESHHOLD =		(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::RangeGunJamTHRESHHOLD);
	TrainRef->RangeGunJamming =				(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::RangeGunJamming);
	TrainRef->RangeGunJammed =				(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::RangeGunJammed);
	TrainRef->MachineGunDamage =			(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::MachineGunDamage);
	TrainRef->MachineGunSlowingMultiplier = (uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::MachineGunSlowingMultiplier);
	TrainRef->MachineGunJamTHRESHHOLD =		(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::MachineGunJamTHRESHHOLD);
	TrainRef->MachineGunJamming =			(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::MachineGunJamming);
	TrainRef->MachineGunJammed =			(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::MachineGunJammed);
	TrainRef->FlamethrowerJamming =			(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::FlamethrowerJamming);
	TrainRef->FlamethrowerJammed =			(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::FlamethrowerJammed);
	TrainRef->FlamethrowerJamTHRESHHOLD =	(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::TrainRef::FlamethrowerJamTHRESHHOLD);

	CharacterMovement->JumpZVelocity =	(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::CharacterMovement::JumpZVelocity);
	CharacterMovement->GravityScale =	(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::CharacterMovement::GravityScale);
	CharacterMovement->Mass =			(uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::CharacterMovement::Mass);

	CapsuleComponent->RelativeLocationX = (uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::CapsuleComponent::RelativeLocationX);
	CapsuleComponent->RelativeLocationY = (uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::CapsuleComponent::RelativeLocationY);
	CapsuleComponent->RelativeLocationZ = (uintptr_t*)mem->FindDMAAddy(baseAddress, Offset::CapsuleComponent::RelativeLocationZ);
}

Address* addr = new Address();
_PlayerController* PlayerController = new _PlayerController();
_Character* Character = new _Character();
_TrainRef* TrainRef = new _TrainRef();
_CharacterMovement* CharacterMovement = new _CharacterMovement();
_CapsuleComponent* CapsuleComponent = new _CapsuleComponent();