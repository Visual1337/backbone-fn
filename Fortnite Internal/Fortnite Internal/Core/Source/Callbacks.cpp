#pragma once
#include <Core/Linkers/Callbacks.h>

namespace Callbacks
{
	auto GetControlRotation::GetControlRotation( SDK::APlayerController* PlayerController, SDK::FRotator* Rotation ) -> SDK::FRotator*
	{
		GetControlRotationOriginal( PlayerController, Rotation );

		auto Handler = m_fortnite_handler.Get( );

		bool bAimbotActive = false;
		SDK::FRotator AimbotRotationTarget = SDK::FRotator( );
		Handler->GetContext( &bAimbotActive, &AimbotRotationTarget );

		if (bAimbotActive && AimbotRotationTarget)
		{
			*Rotation = AimbotRotationTarget;
		}

		return Rotation;
	}

	auto GetTargetingTransform::GetTargetingTransform( SDK::AFortPawn* Pawn, void* a2, char a3, __int64 a4 ) -> SDK::FTransform*
	{
		auto Transform = GetTargetingTransformOriginal( Pawn, a2, a3, a4 );

		auto Handler = m_fortnite_handler.Get( );

		bool bAimbotActive = false;
		SDK::FRotator AimbotRotationTarget = SDK::FRotator( );
		Handler->GetContext( &bAimbotActive, &AimbotRotationTarget );

		if (bAimbotActive && AimbotRotationTarget)
		{

		}

		return Transform;
	}
}