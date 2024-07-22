#pragma once
#include <Core/Backend/Layout/Imports.h>
#include <Core/Linkers/Settings.h>
#include <Core/Linkers/Callbacks.h>
#include <Core/Linkers/Engine.h>
#include <Core/Linkers/Render.h>
#include <Core/Linkers/Fortnite.h>

namespace Callbacks
{
	namespace GetControlRotation
	{
		inline SDK::FRotator* (*GetControlRotationOriginal)(SDK::APlayerController*, SDK::FRotator*);
		auto GetControlRotation( SDK::APlayerController* PlayerController, SDK::FRotator* Rotation ) -> SDK::FRotator*;
	}

	namespace GetTargetingTransform
	{
		inline SDK::FTransform* (*GetTargetingTransformOriginal)(SDK::AFortPawn* Pawn, void* a2, char a3, __int64 a4);
		auto GetTargetingTransform( SDK::AFortPawn* Pawn, void* a2, char a3, __int64 a4 ) -> SDK::FTransform*;
	}
}