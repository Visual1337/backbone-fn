#pragma once
#include <Core/Backend/Engine/engine_classes.h>
#include <Core/Backend/Engine/fortnite_structs.h>

namespace SDK
{
	class UFortItemDefinition : public UItemDefinitionBase
	{
	public:
		using UItemDefinitionBase::UItemDefinitionBase;
		UFortItemDefinition( ) { }
		~UFortItemDefinition( ) { }

	public:
		EFortRarity Rarity( )
		{
			return *(EFortRarity*)(this + 0x9a);
		}

	public:
		auto GetSmallPreviewImage( ) -> TSoftObjectPtr<UTexture2D>;
	};

	class UFortWorldItemDefinition : public UFortItemDefinition
	{
	public:
		using UFortItemDefinition::UFortItemDefinition;
		UFortWorldItemDefinition( ) { }
		~UFortWorldItemDefinition( ) { }

	public:

	};

	class UFortWeaponItemDefinition : public UFortWorldItemDefinition
	{
	public:
		using UFortWorldItemDefinition::UFortWorldItemDefinition;
		UFortWeaponItemDefinition( ) { }
		~UFortWeaponItemDefinition( ) { }

	public:

	};

	class UFortWeaponRangedItemDefinition : public UFortWeaponItemDefinition
	{
	public:
		using UFortWeaponItemDefinition::UFortWeaponItemDefinition;
		UFortWeaponRangedItemDefinition( ) { }
		~UFortWeaponRangedItemDefinition( ) { }

	public:
		auto IsProjectileWeapon( ) -> bool;
		auto HasLightweightProjectile( ) -> bool;
		auto HasPhysicsObjectProjectile( ) -> bool;	
	};

	class AFortWeapon : public AActor
	{
	public:
		using AActor::AActor;
		AFortWeapon( ) { }
		~AFortWeapon( ) { }

	public:
		float ProjectileGravity( )
		{
			return *(float*)(this + 0x1CE4);
		}

		float ProjectileSpeed( )
		{
			return *(float*)(this + 0x1CE0);
		}

		UFortWeaponRangedItemDefinition* WeaponData( )
		{
			return *(UFortWeaponRangedItemDefinition**)(this + 0x510);
		}

		EFortWeaponCoreAnimation WeaponCoreAnimation( )
		{
			return *(EFortWeaponCoreAnimation*)(this + 0x1300);
		}

	public:
		auto CanFire( ) -> bool;
		auto GetMuzzleLocation( ) -> FVector;
		auto GetBulletsPerClip( ) -> int32_t;
		auto GetMagazineAmmoCount( ) -> int32_t;
		auto GetTargetingSourceLocation( ) -> FVector;
	};

	class AFortWeaponRanged : public AFortWeapon
	{
	public:
		using AFortWeapon::AFortWeapon;
		AFortWeaponRanged( ) { }
		~AFortWeaponRanged( ) { }

	public:

	};

	class UFortPlayerStateComponent : public UActorComponent
	{
	public:
		using UActorComponent::UActorComponent;
		UFortPlayerStateComponent( ) { }
		~UFortPlayerStateComponent( ) { }

	public:

	};

	class UFortPlayerStateComponent_Habanero : public UFortPlayerStateComponent
	{
	public:
		using UFortPlayerStateComponent::UFortPlayerStateComponent;
		UFortPlayerStateComponent_Habanero( ) { }
		~UFortPlayerStateComponent_Habanero( ) { }

	public:
		FRankedProgressReplicatedData RankedProgress( )
		{
			return *(FRankedProgressReplicatedData*)(this + 0xB8);
		}
	};

	class AFortPlayerState : public APlayerState
	{
	public:
		using APlayerState::APlayerState;
		AFortPlayerState( ) { }
		~AFortPlayerState( ) { }

	public:
		UFortPlayerStateComponent_Habanero* HabaneroComponent( )
		{
			return *(UFortPlayerStateComponent_Habanero**)(this + 0x9F0);
		}
	};

	class AFortPlayerStateZone : public AFortPlayerState
	{
	public:
		using AFortPlayerState::AFortPlayerState;
		AFortPlayerStateZone( ) { }
		~AFortPlayerStateZone( ) { }

	public:

	};

	class AFortPlayerStateAthena : public AFortPlayerStateZone
	{
	public:
		using AFortPlayerStateZone::AFortPlayerStateZone;
		AFortPlayerStateAthena( ) { }
		~AFortPlayerStateAthena( ) { }

	public:
		int32_t SeasonLevelUIDisplay( )
		{
			return *(int32_t*)(this + 0x1228);
		}
	};

	class ACharacter : public APawn
	{
	public:
		using APawn::APawn;
		ACharacter( ) { }
		~ACharacter( ) { }

	public:
		USkeletalMeshComponent* Mesh( )
		{
			return *(USkeletalMeshComponent**)(this + 0x318);
		}
	};

	class AFortPawn : public ACharacter
	{
	public:
		using ACharacter::ACharacter;
		AFortPawn( ) { }
		~AFortPawn( ) { }

	public:
		AFortWeaponRanged* CurrentWeapon( )
		{
			return *(AFortWeaponRanged**)(this + 0xA68);
		}

	public:
		auto IsDBNO( ) -> bool;
		auto IsDead( ) -> bool;
		auto PawnStopFire( uint8 FireModeNum ) -> void;
		auto PawnStartFire( uint8 FireModeNum ) -> void;
	};

	class AFortPlayerPawn : public AFortPawn
	{
	public:
		using AFortPawn::AFortPawn;
		AFortPlayerPawn( ) { }
		~AFortPlayerPawn( ) { }

	public:
		AActor* CurrentVehicle( )
		{
			return *(AActor**)(this + 0x2a10);
		}

	public:
		auto IsInVehicle( ) -> bool;
		auto IsSkyDiving( ) -> bool;
		auto IsSprinting( ) -> bool;
		auto IsParachuteOpen( ) -> bool;
		auto IsDrivingVehicle( ) -> bool;
		auto HasRespawnedInAir( ) -> bool;
		auto GetGender( bool* IsMale, bool* IsFemale ) -> void;
	};

	class AFortPlayerPawnAthena : public AFortPlayerPawn
	{
	public:
		using AFortPlayerPawn::AFortPlayerPawn;
		AFortPlayerPawnAthena( ) { }
		~AFortPlayerPawnAthena( ) { }

	public:

	};

	class APlayerPawn_Athena_Generic_Parent_C : public AFortPlayerPawnAthena
	{
	public:
		using AFortPlayerPawnAthena::AFortPlayerPawnAthena;
		APlayerPawn_Athena_Generic_Parent_C( ) { }
		~APlayerPawn_Athena_Generic_Parent_C( ) { }

	public:

	};

	class APlayerPawn_Athena_Generic_C : public APlayerPawn_Athena_Generic_Parent_C
	{
	public:
		using APlayerPawn_Athena_Generic_Parent_C::APlayerPawn_Athena_Generic_Parent_C;
		APlayerPawn_Athena_Generic_C( ) { }
		~APlayerPawn_Athena_Generic_C( ) { }

	public:

	};

	class APlayerPawn_Athena_C : public APlayerPawn_Athena_Generic_C
	{
	public:
		using APlayerPawn_Athena_Generic_C::APlayerPawn_Athena_Generic_C;
		APlayerPawn_Athena_C( ) { }
		~APlayerPawn_Athena_C( ) { }

	public:

	};
}