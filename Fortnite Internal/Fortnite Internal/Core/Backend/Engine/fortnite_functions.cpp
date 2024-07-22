#pragma once
#include <Core/Backend/Engine/fortnite_classes.h>

namespace SDK
{
	auto UFortItemDefinition::GetSmallPreviewImage( ) -> TSoftObjectPtr<UTexture2D>
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortItemDefinition.GetSmallPreviewImage" );
		}

		struct
		{
			TSoftObjectPtr<UTexture2D> ReturnValue;
		} Params = {};

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UFortWeaponRangedItemDefinition::HasLightweightProjectile( ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortWeaponRangedItemDefinition.HasLightweightProjectile" );
		}

		struct
		{
			bool ReturnValue;
		} Params = {};

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UFortWeaponRangedItemDefinition::HasPhysicsObjectProjectile( ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortWeaponRangedItemDefinition.HasPhysicsObjectProjectile" );
		}

		struct
		{
			bool ReturnValue;
		} Params = {};

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;

	}
	
	auto UFortWeaponRangedItemDefinition::IsProjectileWeapon( ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortWeaponRangedItemDefinition.IsProjectileWeapon" );
		}

		struct
		{
			bool ReturnValue;
		} Params = {};

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto AFortWeapon::CanFire( ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortWeapon.CanFire" );
		}

		struct
		{
			bool ReturnValue;
		} Params = {};

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto AFortWeapon::GetMuzzleLocation( ) -> FVector
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortWeapon.GetMuzzleLocation" );
		}

		struct
		{
			FVector ReturnValue;
		} Params = {};

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto AFortWeapon::GetBulletsPerClip( ) -> int32_t
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortWeapon.GetBulletsPerClip" );
		}

		struct
		{
			int32_t ReturnValue;
		} Params = {};

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto AFortWeapon::GetMagazineAmmoCount( ) -> int32_t
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortWeapon.GetMagazineAmmoCount" );
		}

		struct
		{
			int32_t ReturnValue;
		} Params = {};

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto AFortWeapon::GetTargetingSourceLocation( ) -> FVector
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortWeapon.GetTargetingSourceLocation" );
		}

		struct
		{
			FVector ReturnValue;
		} Parameters = { };

		UObject::ProcessEvent( Function, &Parameters );

		return Parameters.ReturnValue;
	}

	auto AFortPawn::PawnStopFire( uint8 FireModeNum ) -> void
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortPawn.PawnStopFire" );
		}

		struct
		{
			uint8 FireModeNum;
		} Parameters = { FireModeNum };

		UObject::ProcessEvent( Function, &Parameters );
	}

	auto AFortPawn::PawnStartFire( uint8 FireModeNum ) -> void
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortPawn.PawnStartFire" );
		}

		struct
		{
			uint8 FireModeNum;
		} Parameters = { FireModeNum };

		UObject::ProcessEvent( Function, &Parameters );
	}

	auto AFortPawn::IsDBNO( ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function) 
		{
			Function = UObject::FindObject<UFunction>( L"FortPawn.IsDBNO" );
		}

		struct 
		{
			bool ReturnValue;
		} Parameters = { };

		UObject::ProcessEvent( Function, &Parameters );

		return Parameters.ReturnValue;
	}

	auto AFortPawn::IsDead( ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortPawn.IsDead" );
		}

		struct
		{
			bool ReturnValue;
		} Parameters = { };

		UObject::ProcessEvent( Function, &Parameters );

		return Parameters.ReturnValue;
	}

	auto AFortPlayerPawn::IsInVehicle( ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortPawn.IsInVehicle" );
		}

		struct
		{
			bool ReturnValue;
		} Parameters = { };

		UObject::ProcessEvent( Function, &Parameters );

		return Parameters.ReturnValue;
	}

	auto AFortPlayerPawn::HasRespawnedInAir( ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortPawn.HasRespawnedInAir" );
		}

		struct
		{
			bool ReturnValue;
		} Parameters = { };

		UObject::ProcessEvent( Function, &Parameters );

		return Parameters.ReturnValue;
	}

	auto AFortPlayerPawn::IsDrivingVehicle( ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortPawn.IsDrivingVehicle" );
		}

		struct
		{
			bool ReturnValue;
		} Parameters = { };

		UObject::ProcessEvent( Function, &Parameters );

		return Parameters.ReturnValue;
	}

	auto AFortPlayerPawn::IsParachuteOpen( ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortPawn.IsParachuteOpen" );
		}

		struct
		{
			bool ReturnValue;
		} Parameters = { };

		UObject::ProcessEvent( Function, &Parameters );

		return Parameters.ReturnValue;
	}

	auto AFortPlayerPawn::IsSkyDiving( ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortPawn.IsSkyDiving" );
		}

		struct
		{
			bool ReturnValue;
		} Parameters = { };

		UObject::ProcessEvent( Function, &Parameters );

		return Parameters.ReturnValue;
	}

	auto AFortPlayerPawn::IsSprinting( ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortPawn.IsSprinting" );
		}

		struct
		{
			bool ReturnValue;
		} Parameters = { };

		UObject::ProcessEvent( Function, &Parameters );

		return Parameters.ReturnValue;
	}

	auto AFortPlayerPawn::GetGender( bool* IsMale, bool* IsFemale ) -> void
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortPawn.GetGender" );
		}

		struct
		{
			bool* IsMale;
			bool* IsFemale;
		} Parameters = { };

		UObject::ProcessEvent( Function, &Parameters );

		*Parameters.IsMale = *IsMale;
		*Parameters.IsFemale = *IsFemale;
	}
}