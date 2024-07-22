#pragma once
#include <Core/Backend/Engine/coreuobject_classes.h>
#include <Core/Backend/Engine/engine_structs.h>

namespace SDK
{
	// Forward declaration for fortnite classes
	class AFortPlayerStateAthena;
	class APlayerPawn_Athena_C;

	class UTexture : public UObject
	{
	public:
		using UObject::UObject;
		UTexture( ) { }
		~UTexture( ) { }

	public:

	};

	class UTexture2D : public UTexture
	{
	public:
		using UTexture::UTexture;
		UTexture2D( ) { }
		~UTexture2D( ) { }

	public:

	};

	class UFont : public UObject
	{
	public:
		using UObject::UObject;
		UFont( ) { }
		~UFont( ) { }

	public:
		auto GetStringSize( const TCHAR* Text ) -> int32;
	};

	class UCanvas : public UObject
	{
	public:
		using UObject::UObject;
		UCanvas( ) { }
		~UCanvas( ) { }

	public:
		float ClipX( )
		{
			return *(float*)(this + 0x30);
		}

		float ClipY( )
		{
			return *(float*)(this + 0x34);
		}

		UTexture2D* DefaultTexture( )
		{
			return *(UTexture2D**)(this + 0x70);
		}

	public:
		auto K2_DrawPolygon( UTexture* RenderTexture, FVector2D ScreenPosition, FVector2D Radius, int32_t NumberOfSides, FLinearColor RenderColor ) -> void;
		auto K2_DrawLine( FVector2D ScreenPositionA, FVector2D ScreenPositionB, float Thickness, FLinearColor RenderColor ) -> void;
		auto K2_DrawText(UFont* RenderFont, FString RenderText, FVector2D ScreenPosition, FVector2D Scale, FLinearColor RenderColor, FLinearColor ShadowColor, FVector2D ShadowOffset, bool bCentreX, bool bCentreY, bool bOutlined, FLinearColor OutlineColor ) -> void;
		auto K2_DrawTexture( UTexture* RenderTexture, FVector2D ScreenPosition, FVector2D ScreenSize, FVector2D CoordinatePosition, FVector2D CoordinateSize, FLinearColor RenderColor, EBlendMode BlendMode, float Rotation, FVector2D PivotPoint ) -> void;
		auto K2_Project( FVector WorldLocation ) -> FVector;

	};

	class UClass : public UObject
	{
	public:
		using UObject::UObject;
		UClass( ) { }
		~UClass( ) { }

	public:

	};

	class UItemDefinitionBase : public UObject
	{
	public:
		using UObject::UObject;
		UItemDefinitionBase( ) { }
		~UItemDefinitionBase( ) { }

	public:
		FText ItemName( )
		{
			return *(FText*)(this + 0x40);
		}
	};

	class UMaterial : public UObject
	{
	public:
		using UObject::UObject;
		UMaterial( ) { }
		~UMaterial( ) { }

	public:

	};

	class UActorComponent : public UObject
	{
	public:
		using UObject::UObject;
		UActorComponent( ) { }
		~UActorComponent( ) { }

	public:

	};

	class USceneComponent : public UActorComponent
	{
	public:
		using UActorComponent::UActorComponent;
		USceneComponent( ) { }
		~USceneComponent( ) { }

	public:
		auto GetForwardVector( ) -> FVector;
		auto GetSocketLocation( FName InSocketName ) -> FVector;
	};

	class UPrimitiveComponent : public USceneComponent
	{
	public:
		using USceneComponent::USceneComponent;
		UPrimitiveComponent( ) { }
		~UPrimitiveComponent( ) { }

	public:

	};

	class AActor : public UObject
	{
	public:
		using UObject::UObject;
		AActor( ) { }
		~AActor( ) { }

	public:
		USceneComponent* RootComponent( )
		{
			return *(USceneComponent**)(this + 0x198);
		}

	public:
		auto GetVelocity( ) -> FVector;
	};

	class APlayerState : public UObject
	{
	public:
		using UObject::UObject;
		APlayerState( ) { }
		~APlayerState( ) { }

	public:
		auto IsABot( ) -> bool;
	};

	class UMeshComponent : public UPrimitiveComponent
	{
	public:
		using UPrimitiveComponent::UPrimitiveComponent;
		UMeshComponent( ) { }
		~UMeshComponent( ) { }

	public:

	};

	class USkinnedMeshComponent : public UMeshComponent
	{
	public:
		using UMeshComponent::UMeshComponent;
		USkinnedMeshComponent( ) { }
		~USkinnedMeshComponent( ) { }

	public:

	};

	class USkeletalMeshComponent : public USkinnedMeshComponent
	{
	public:
		using USkinnedMeshComponent::USkinnedMeshComponent;
		USkeletalMeshComponent( ) { }
		~USkeletalMeshComponent( ) { }

	public:

	};

	class APawn : public AActor
	{
	public:
		using AActor::AActor;
		APawn( ) { }
		~APawn( ) { }

	public:
		AFortPlayerStateAthena* PlayerState( )
		{
			return *(AFortPlayerStateAthena**)(this + 0x2B0);
		}
	};

	class APlayerCameraManager : public AActor
	{
	public:
		using AActor::AActor;
		APlayerCameraManager( ) { }
		~APlayerCameraManager( ) { }

	public:

	};

	class AController : public UObject
	{
	public:
		using UObject::UObject;
		AController( ) { }
		~AController( ) { }

	public:

	};

	class APlayerController : public AController
	{
	public:
		using AController::AController;
		APlayerController( ) { }
		~APlayerController( ) { }

	public:
		APlayerCameraManager* PlayerCameraManager( )
		{
			return *(APlayerCameraManager**)(this + 0x348);
		}

		APlayerPawn_Athena_C* AcknowledgedPawn( )
		{
			return *(APlayerPawn_Athena_C**)(this + 0x338);
		}

	public:
		auto GetMousePosition( ) -> SDK::FVector2D;
		auto IsInputKeyDown( FKey Key ) -> bool;
		auto WasInputKeyJustPressed( FKey Key ) -> bool;
	};

	class UGameViewportClient : public UObject
	{
	public:
		using UObject::UObject;
		UGameViewportClient( ) { }
		~UGameViewportClient( ) { }

	public:

		UWorld* World( )
		{
			return *(UWorld**)(this + 0x78);
		}

	public:
		auto LineTraceSingle( UObject* World, const FVector& Start, const FVector& End ) -> bool;
	};

	class UPlayer : public UObject
	{
	public:
		using UObject::UObject;
		UPlayer( ) { }
		~UPlayer( ) { }

	public:
		APlayerController* PlayerController( )
		{
			return *(APlayerController**)(this + 0x30);
		}
	};

	class ULocalPlayer : public UPlayer
	{
	public:
		using UPlayer::UPlayer;
		ULocalPlayer( ) { }
		~ULocalPlayer( ) { }

	public:
		UGameViewportClient* ViewportClient( )
		{
			return *(UGameViewportClient**)(this + 0x78);
		}
	};

	class UGameInstance : public UObject
	{
	public:
		using UObject::UObject;
		UGameInstance( ) { }
		~UGameInstance( ) { }

	public:
		TArray <ULocalPlayer*> LocalPlayers( )
		{
			return *(TArray <ULocalPlayer*>*)(this + 0x38);
		}
	};

	class UWorld : public UObject
	{
	public:
		using UObject::UObject;
		UWorld( ) { }
		~UWorld( ) { }

	public:
		UGameInstance* OwningGameInstance( )
		{
			return *(UGameInstance**)(this + 0x1d8);
		}
	};

	class UFortKismetLibrary : public UObject
	{
	public:
		using UObject::UObject;
		UFortKismetLibrary( ) { }
		~UFortKismetLibrary( ) { }

	public:
		auto GetHumanReadableName( AActor* Actor ) -> FString;
		auto OnSameTeam( AActor* ActorA, AActor* ActorB ) -> bool;
	};

	class UKismetMathLibrary : public UObject
	{
	public:
		using UObject::UObject;
		UKismetMathLibrary( ) { }
		~UKismetMathLibrary( ) { }

	public:
		auto Sin( double A ) -> double;
		auto Cos( double A ) -> double;
		auto Abs( double A ) -> double;
		auto Atan( double A ) -> double;
		auto Atan2( double Y, double X ) -> double;
		auto Asin( double A ) -> double;
		auto Sqrt( double A ) -> double;
		auto Pow( double Base, double Exp ) -> double;
		auto Vector_Distance( FVector v1, FVector v2 ) -> double;
		auto Vector_Distance2D( FVector2D v1, FVector2D v2 ) -> double;
		auto FindLookAtRotation( FVector& Start, FVector& Target ) -> FRotator;
		auto RInterpTo( FRotator& Current, FRotator& Target, float DeltaTime, float InterpSpeed ) -> FRotator;
		auto RInterpTo_Constant( FRotator& Current, FRotator& Target, float DeltaTime, float InterpSpeed ) -> FRotator;
	};

	class UGameplayStatics : public UObject
	{
	public:
		using UObject::UObject;
		UGameplayStatics( ) { }
		~UGameplayStatics( ) { }

	public:
		auto ObjectIsA( UObject* Object, UClass* ObjectClass ) -> bool;

		template <typename Type>
		auto GetAllActorsOfClass(
			UObject* WorldContextObject, UClass* ActorClass, TArray<Type*>* OutActors ) -> void
		{
			static UFunction* Function = nullptr;
			if (!Function)
			{
				Function = UObject::FindObject<UFunction>( L"GameplayStatics.GetAllActorsOfClass" );
			}

			struct
			{
				UObject* WorldContextObject;
				UClass* ActorClass;
				TArray<Type*> OutActors;
			} Parameters = { WorldContextObject, ActorClass };

			this->ProcessEvent( Function, &Parameters );

			*OutActors = Parameters.OutActors;
		}
	};

	class UKismetSystemLibrary : public UObject
	{
	public:
		using UObject::UObject;
		UKismetSystemLibrary( ) { }
		~UKismetSystemLibrary( ) { }

	public:
		auto GetObjectName( UObject* Object ) -> FString;
		auto GetComponentBounds( USceneComponent* Component, FVector* Origin, FVector* BoxExtent, float* SphereRadius ) -> void;
	};

	class UKismetStringLibrary : public UObject
	{
	public:
		using UObject::UObject;
		UKismetStringLibrary( ) { }
		~UKismetStringLibrary( ) { }

	public:
		auto Conv_StringToName( FString InString ) -> FName;
		auto Conv_NameToString( FName InName ) -> FString;
		auto Contains( FString SearchIn, FString Substring, bool bUseCase, bool bSearchFromEnd ) -> bool;
		auto BuildString_Int( FString AppendTo, FString Prefix, int InInt, FString Suffix ) -> FString;
		auto BuildString_Double( FString AppendTo, FString Prefix, double InDouble, FString Suffix ) -> FString;
		auto Conv_IntToString( int32_t inInt ) -> FString;
		auto Len( FString S ) -> int32_t;
	};
}