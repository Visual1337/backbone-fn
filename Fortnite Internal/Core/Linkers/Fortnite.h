#pragma once
#include <Core/Backend/Layout/Imports.h>
#include <Core/Linkers/Settings.h>
#include <Core/Linkers/Callbacks.h>
#include <Core/Linkers/Engine.h>
#include <Core/Linkers/Render.h>
#include <Core/Linkers/Mutex.h>
#include <Core/Linkers/Hook.h>

namespace Fortnite
{
	const pair<wchar_t*, wchar_t*> BonePairs[] =
	{
		MakePair( (wchar_t*)L"neck_01", (wchar_t*)L"upperarm_r" ),
		MakePair( (wchar_t*)L"neck_01", (wchar_t*)L"upperarm_l" ),
		MakePair( (wchar_t*)L"upperarm_l", (wchar_t*)L"lowerarm_l" ),
		MakePair( (wchar_t*)L"lowerarm_l", (wchar_t*)L"hand_l" ),
		MakePair( (wchar_t*)L"upperarm_r", (wchar_t*)L"lowerarm_r" ),
		MakePair( (wchar_t*)L"lowerarm_r", (wchar_t*)L"hand_r" ),
		MakePair( (wchar_t*)L"neck_01", (wchar_t*)L"pelvis" ),
		MakePair( (wchar_t*)L"pelvis", (wchar_t*)L"thigh_r" ),
		MakePair( (wchar_t*)L"pelvis", (wchar_t*)L"thigh_l" ),
		MakePair( (wchar_t*)L"thigh_r", (wchar_t*)L"calf_r" ),
		MakePair( (wchar_t*)L"calf_r", (wchar_t*)L"ik_foot_r" ),
		MakePair( (wchar_t*)L"thigh_l", (wchar_t*)L"calf_l" ),
		MakePair( (wchar_t*)L"calf_l", (wchar_t*)L"ik_foot_l" )
	};

	class FortniteHandler_t
	{
	public:
		FortniteHandler_t( ) { }
		~FortniteHandler_t( ) { }

	public:
		auto Initialize() -> void;
		auto IsSafeToRender( ) -> bool;
		auto InScreen( SDK::FVector2D ScreenLocation ) const -> bool;	
		auto InRect( double Radius, SDK::FVector2D ScreenLocation ) const -> bool;
		auto InCircle( double Radius, SDK::FVector2D ScreenLocation ) const -> bool;
		auto GetThemeColor( int ColorIndex ) -> SDK::FLinearColor;
		auto Project( SDK::FVector WorldLocation, SDK::FVector2D* ScreenLocation ) const -> bool;
		auto GetSocketLocation( SDK::USkeletalMeshComponent* Mesh, SDK::FString SocketName ) -> SDK::FVector;
		auto GetColorByTier( SDK::EFortRarity Rarity ) -> SDK::FLinearColor;
		auto GetStringByRank( int32_t Rank ) -> SDK::FString;
		auto GetColorByRank( int32_t Rank ) -> SDK::FLinearColor;
		auto GetContext( bool* Active, SDK::FRotator* Rotation ) const -> void;
		auto ApplyContext( bool Active , SDK::FRotator Rotation ) -> void;
		auto Rehook( SDK::APlayerController* PlayerController ) -> void;
		auto Tick( SDK::UWorld* World, SDK::ULocalPlayer* LocalPlayer, SDK::UCanvas* Canvas, SDK::APlayerController* PlayerController ) -> void;
		auto Main( SDK::UGameViewportClient* ViewportClient, SDK::UCanvas* Canvas ) -> bool;

	private:
		int CurrentFrame = 0;
		bool Initialized = false;
		ReturnMutex Mutex;

		SDK::FVector2D ScreenSize = SDK::FVector2D( );
		SDK::FVector2D ScreenCenter = SDK::FVector2D( );

		SDK::FVector CameraLocation = SDK::FVector( );
		SDK::FRotator CameraRotation = SDK::FRotator( );
		float FieldOfView = 0.f;
		double AimbotFOV = 0.0;

		double WorldDeltaSeconds = 0.0;

		double ClosestDistanceToCenter = DBL_MAX;
		SDK::APlayerPawn_Athena_C* ClosestPlayer = nullptr;

		bool bAimbotActive = false;
		SDK::FRotator AimbotRotation = SDK::FRotator();

		SDK::FVector2D Position = SDK::FVector2D( );
		SDK::FVector2D Size = SDK::FVector2D( );
		SDK::FVector2D Offset = SDK::FVector2D( );

		SDK::FLinearColor ThemeColor = SDK::FLinearColor( );

		SDK::FVector2D MousePosition = SDK::FVector2D( );
		bool LeftMouseClicked = false;
		bool LeftMouseDown = false;
		bool RightMouseClicked = false;
		bool RightMouseDown = false;
		bool WindowHovered = false; 
		bool WindowGrabbed = false;
		int LastFrameTime = 0;

		SDK::UMaterial* Material = nullptr;
		bool AlreadyInitialized = false;
		SDK::TUObjectArray* ObjectArray = nullptr;
		Render::RenderHandler Render = Render::RenderHandler( );
	};

	class FortniteHandler : public FortniteHandler_t
	{
	public:
		using FortniteHandler_t::FortniteHandler_t;
		FortniteHandler( ) { }
		~FortniteHandler( ) { }

	public:
		auto Get( ) -> FortniteHandler_t*
		{
			return reinterpret_cast<FortniteHandler_t*>(this);
		}
	};
}

inline Fortnite::FortniteHandler m_fortnite_handler = Fortnite::FortniteHandler( );