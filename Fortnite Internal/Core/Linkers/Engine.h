#pragma once
#include <Core/Linkers/Pattern.h>

#include <Core/Backend/Engine/coreuobject_structs.h>
#include <Core/Backend/Engine/coreuobject_classes.h>

#include <Core/Backend/Engine/engine_structs.h>
#include <Core/Backend/Engine/engine_classes.h>

#include <Core/Backend/Engine/fortnite_structs.h>
#include <Core/Backend/Engine/fortnite_classes.h>

namespace SDK
{
	inline UFortKismetLibrary* FortLibrary = nullptr;
	inline UKismetSystemLibrary* SystemLibrary = nullptr;
	inline UKismetMathLibrary* MathLibrary = nullptr;
	inline UGameplayStatics* GameplayStatics = nullptr;
	inline UKismetStringLibrary* StringLibrary = nullptr;

	inline FKey LeftMouseButton;
	inline FKey RightMouseButton;
	inline FKey GamepadLeftTrigger;
	inline FKey Insert;
	inline FKey F8;
	inline FKey W;
	inline FKey A;
	inline FKey S;
	inline FKey D;
	inline FKey X;
	inline FKey Right;
	inline FKey SpaceBar;
	inline FKey LeftShift;
	inline FKey LeftAlt;
	inline FKey Capslock;

	inline UClass* PlayerPawn = nullptr;
	inline UClass* FortPickup = nullptr;
	inline UClass* BuildingTrap = nullptr;
	inline UClass* BuildingContainer = nullptr;
	inline UClass* BuildingWeakSpot = nullptr;
	inline UClass* AthenaSuperDingo = nullptr;
	inline UClass* FortAthenaVehicle = nullptr;
	inline UClass* AthenaSupplyDrop = nullptr;
	inline UClass* FortWeapon = nullptr;
	inline UClass* WeaponPickaxeAthena = nullptr;
	inline UClass* Material = nullptr;
	inline UClass* Texture = nullptr;
	inline UClass* LocalPlayer = nullptr;
	inline UClass* PlayerController = nullptr;
	inline UClass* GameViewportClient = nullptr;
	inline UClass* PlayerCameraManager = nullptr;
}