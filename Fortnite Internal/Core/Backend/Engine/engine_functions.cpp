#pragma once
#include <Core/Backend/Engine/engine_classes.h>

namespace SDK
{
	auto USceneComponent::GetForwardVector( ) -> FVector
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"SceneComponent.GetForwardVector" );
		}

		struct
		{
			FVector ReturnValue;
		} Params{  };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto USceneComponent::GetSocketLocation( FName InSocketName ) -> FVector
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"SceneComponent.GetSocketLocation" );
		}

		struct
		{
			FName InSocketName;
			FVector ReturnValue;
		} Params{ InSocketName };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto AActor::GetVelocity( ) -> FVector
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"Actor.GetVelocity" );
		}

		struct
		{
			FVector ReturnValue;
		} Params{ };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UFont::GetStringSize( const TCHAR* Text ) -> int32
	{
		static void* Address = nullptr;
		if (!Address)
		{
			Address = m_pattern_scan.Get( )->Search( Globals::Module, "\x48\x83\xEC\x00\x4C\x8D\x4C\x24\x00\x4C\x8D\x44\x24\x00\xE8\x00\x00\x00\x00\x8B\x44\x24", "xxx?xxxx?xxxx?x????xxx" );
		}

		return reinterpret_cast<int32(__cdecl*)(UFont*, const TCHAR*)>(Address)(this, Text);
	}

	auto UCanvas::K2_DrawPolygon(
		UTexture* RenderTexture, FVector2D ScreenPosition, FVector2D Radius, int32_t NumberOfSides, FLinearColor RenderColor ) -> void
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"Canvas.K2_DrawPolygon" );
		}

		struct
		{
			UTexture* RenderTexture;
			FVector2D ScreenPosition;
			FVector2D Radius;
			int32_t NumberOfSides;
			FLinearColor RenderColor;
		} Params = { RenderTexture, ScreenPosition, Radius, NumberOfSides, RenderColor };

		this->ProcessEvent( Function, &Params );
	}

	auto UCanvas::K2_DrawLine(
		FVector2D ScreenPositionA, FVector2D ScreenPositionB, float Thickness, FLinearColor RenderColor ) -> void
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"Canvas.K2_DrawLine" );
		}

		struct
		{
			FVector2D ScreenPositionA;
			FVector2D ScreenPositionB;
			float Thickness;
			FLinearColor RenderColor;
		} Params = { ScreenPositionA, ScreenPositionB, Thickness, RenderColor };

		this->ProcessEvent( Function, &Params );
	}

	auto UCanvas::K2_DrawText(
		UFont* RenderFont, FString RenderText, FVector2D ScreenPosition, FVector2D Scale, FLinearColor RenderColor, FLinearColor ShadowColor, FVector2D ShadowOffset, bool bCentreX, bool bCentreY, bool bOutlined, FLinearColor OutlineColor ) -> void
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"Canvas.K2_DrawText" );
		}

		struct
		{
			UFont* RenderFont;
			FString RenderText;
			FVector2D ScreenPosition;
			FVector2D Scale;
			FLinearColor RenderColor;
			float Kerning;
			FLinearColor ShadowColor;
			FVector2D ShadowOffset;
			bool bCentreX;
			bool bCentreY;
			bool bOutlined;
			FLinearColor OutlineColor;
		} Params = { RenderFont, RenderText, ScreenPosition, Scale, RenderColor, 1.f, ShadowColor, ShadowOffset, bCentreX, bCentreY, bOutlined, OutlineColor };

		this->ProcessEvent( Function, &Params );
	}

	auto APlayerController::IsInputKeyDown( FKey Key ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"PlayerController.IsInputKeyDown" );
		}

		struct
		{
			FKey Key;
			bool ReturnValue;
		} Params = { Key };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto APlayerController::WasInputKeyJustPressed( FKey Key ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"PlayerController.WasInputKeyJustPressed" );
		}

		struct
		{
			FKey Key;
			bool ReturnValue;
		} Parameters = { Key };

		this->ProcessEvent( Function, &Parameters );

		return Parameters.ReturnValue;
	}

	auto APlayerController::GetMousePosition( ) -> SDK::FVector2D
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"PlayerController.GetMousePosition" );
		}

		struct
		{
			float LocationX;
			float LocationY;
		} Parameters = {};

		this->ProcessEvent( Function, &Parameters );

		return SDK::FVector2D( double( Parameters.LocationX ), double( Parameters.LocationY ) );
	}

	auto UCanvas::K2_DrawTexture(
		UTexture* RenderTexture, FVector2D ScreenPosition, FVector2D ScreenSize, FVector2D CoordinatePosition, FVector2D CoordinateSize, FLinearColor RenderColor, EBlendMode BlendMode, float Rotation, FVector2D PivotPoint ) -> void
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"Canvas.K2_DrawTexture" );
		}

		struct K2_DrawTexture_Params
		{
		public:
			UTexture* RenderTexture;
			FVector2D ScreenPosition;
			FVector2D ScreenSize;
			FVector2D CoordinatePosition;
			FVector2D CoordinateSize;
			FLinearColor RenderColor;
			EBlendMode BlendMode;
			float Rotation;
			FVector2D PivotPoint;
		};

		K2_DrawTexture_Params Params;
		Params.RenderTexture = RenderTexture;
		Params.ScreenPosition = ScreenPosition;
		Params.ScreenSize = ScreenSize;
		Params.CoordinatePosition = CoordinatePosition;
		Params.CoordinateSize = CoordinateSize;
		Params.RenderColor = RenderColor;
		Params.BlendMode = SDK::EBlendMode::BLEND_Translucent;
		Params.Rotation = Rotation;
		Params.PivotPoint = PivotPoint;

		this->ProcessEvent( Function, &Params );
	}

	auto UCanvas::K2_Project( FVector WorldLocation ) -> FVector
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"Canvas.K2_Project" );
		}

		struct {
			FVector WorldLocation;
			FVector ReturnValue;
		} Params = { WorldLocation };

		UObject::ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto APlayerState::IsABot( ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"PlayerState.IsABot" );
		}

		struct
		{
			bool ReturnValue;
		} Params = { };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UGameViewportClient::LineTraceSingle( UObject* World, const FVector& Start, const FVector& End ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetSystemLibrary.LineTraceSingle" );
		}

		struct
		{
			UObject* WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor)
			struct FVector                                     Start;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
			struct FVector                                     End;                                                      // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
			TEnumAsByte<ETraceTypeQuery>                       TraceChannel;                                             // (Parm, ZeroConstructor, IsPlainOldData)
			bool                                               bTraceComplex;                                            // (Parm, ZeroConstructor, IsPlainOldData)
			TArray<uint64_t>                                   ActorsToIgnore;                                           // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
			TEnumAsByte<EDrawDebugTrace>                       DrawDebugType;                                            // (Parm, ZeroConstructor, IsPlainOldData)
			struct FHitResult                                  OutHit;                                                   // (Parm, OutParm, IsPlainOldData)
			bool                                               bIgnoreSelf;                                              // (Parm, ZeroConstructor, IsPlainOldData)
			struct FLinearColor                                TraceColor;                                               // (Parm, ZeroConstructor, IsPlainOldData)
			struct FLinearColor                                TraceHitColor;                                            // (Parm, ZeroConstructor, IsPlainOldData)
			float                                              DrawTime;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
			unsigned char                                      Padding[0x8];                                       // 0x00AE(0x0002) MISSED OFFSET
			bool                                               ReturnValue;
		} params;
		params.WorldContextObject = World;
		params.Start = Start;
		params.End = End;
		params.TraceChannel = ETraceTypeQuery::TraceTypeQuery2;
		params.bTraceComplex = true;
		params.ActorsToIgnore = TArray<uint64_t>( );
		params.DrawDebugType = EDrawDebugTrace::None;
		params.bIgnoreSelf = true;
		params.TraceColor = FLinearColor( );
		params.TraceHitColor = FLinearColor( );
		params.DrawTime = 0.0f;

		this->ProcessEvent( Function, &params );

		return !params.ReturnValue;
	}

	auto UGameplayStatics::ObjectIsA(
		UObject* Object, UClass* ObjectClass ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"GameplayStatics.ObjectIsA" );
		}

		struct
		{
			UObject* Object;
			UObject* ObjectClass;
			bool ReturnValue;
		} Params = { Object, ObjectClass };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetStringLibrary::BuildString_Int( 
		FString AppendTo, FString Prefix, int InInt, FString Suffix ) -> FString
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetStringLibrary.BuildString_Int" );
		}

		struct
		{
			FString AppendTo;
			FString Prefix;
			int InInt;
			FString Suffix;
			FString ReturnValue;
		} Params = { AppendTo, Prefix, InInt, Suffix };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetStringLibrary::Conv_IntToString( int32_t inInt ) -> FString
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetStringLibrary.Conv_IntToString" );
		}

		struct
		{
			int32_t inInt;
			FString ReturnValue;
		} Params = { inInt };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetStringLibrary::BuildString_Double(
		FString AppendTo, FString Prefix, double InDouble, FString Suffix ) -> FString
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetStringLibrary.BuildString_Double" );
		}

		struct
		{
			FString AppendTo;
			FString Prefix;
			double InDouble;
			FString Suffix;
			FString ReturnValue;
		} Params = { AppendTo, Prefix, InDouble, Suffix };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetMathLibrary::Vector_Distance(
		FVector v1, FVector v2 ) -> double
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetMathLibrary.Vector_Distance" );
		}

		struct
		{
			FVector v1, v2;
			double ReturnValue;
		} Params = { v1, v2 };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetMathLibrary::Vector_Distance2D( FVector2D v1, FVector2D v2 ) -> double
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetMathLibrary.Vector_Distance2D" );
		}

		struct
		{
			FVector v1;
			FVector v2;
			double ReturnValue;
		} Params = { FVector( v1.X, v1.Y, 0.0 ), FVector( v2.X, v2.Y, 0.0 ) };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetMathLibrary::Pow( double Base, double Exp ) -> double
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetMathLibrary.MultiplyMultiply_FloatFloat" );
		}

		struct
		{
			double Base;
			double Exp;
			double ReturnValue;
		} Params = { Base, Exp };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetMathLibrary::Abs( double A ) -> double
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetMathLibrary.Abs" );
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetMathLibrary::Cos(
		double A ) -> double
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetMathLibrary.cos" );
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetMathLibrary::Sin(
		double A ) -> double
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetMathLibrary.sin" );
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetMathLibrary::Atan(
		double A ) -> double
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetMathLibrary.Atan" );
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetMathLibrary::Atan2(
		double Y, double X ) -> double
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetMathLibrary.Atan2" );
		}

		struct
		{
			double Y;
			double X;
			double ReturnValue;
		} Params = { Y, X };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetMathLibrary::Asin( double A ) -> double
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetMathLibrary.asin" );
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetMathLibrary::Sqrt( double A ) -> double
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetMathLibrary.Sqrt" );
		}

		struct
		{
			double A;
			double ReturnValue;
		} Params = { A };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetMathLibrary::FindLookAtRotation( FVector& Start, FVector& Target ) -> FRotator
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetMathLibrary.FindLookAtRotation" );
		}

		struct
		{
			FVector& Start;
			FVector& Target;
			FRotator ReturnValue;
		} Params = { Start, Target };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetMathLibrary::RInterpTo( FRotator& Current, FRotator& Target, float DeltaTime, float InterpSpeed ) -> FRotator
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetMathLibrary.RInterpTo" );
		}

		struct
		{
			FRotator& Current;
			FRotator& Target;
			float DeltaTime;
			float InterpSpeed;
			FRotator ReturnValue;
		} Params = { Current, Target, DeltaTime, InterpSpeed };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetMathLibrary::RInterpTo_Constant( FRotator& Current, FRotator& Target, float DeltaTime, float InterpSpeed ) -> FRotator
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetMathLibrary.RInterpTo_Constant" );
		}

		struct
		{
			FRotator& Current;
			FRotator& Target;
			float DeltaTime;
			float InterpSpeed;
			FRotator ReturnValue;
		} Params = { Current, Target, DeltaTime, InterpSpeed };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetStringLibrary::Conv_StringToName( FString InString ) -> FName
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetStringLibrary.Conv_StringToName" );
		}

		struct
		{
			FString InString;
			FName ReturnValue;
		} Params = { InString };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetStringLibrary::Contains( FString SearchIn, FString Substring, bool bUseCase, bool bSearchFromEnd ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetStringLibrary.Contains" );
		}

		struct
		{
			FString SearchIn;
			FString Substring;
			bool bUseCase;
			bool bSearchFromEnd;
			bool ReturnValue;
		} Params = { SearchIn , Substring , bUseCase , bSearchFromEnd };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetStringLibrary::Conv_NameToString( FName InName ) -> FString
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetStringLibrary.Conv_NameToString" );
		}

		struct
		{
			FName InName;
			FString ReturnValue;
		} Params = { InName };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}
	
	auto UFortKismetLibrary::OnSameTeam( AActor* ActorA, AActor* ActorB ) -> bool
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortKismetLibrary.OnSameTeam" );
		}

		struct
		{
			AActor* ActorA;
			AActor* ActorB;
			FString ReturnValue;
		} Params = { ActorA, ActorB };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UFortKismetLibrary::GetHumanReadableName( AActor* Actor ) -> FString
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"FortKismetLibrary.GetHumanReadableName" );
		}

		struct
		{
			AActor* Actor;
			FString ReturnValue;
		} Params = { Actor };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}

	auto UKismetSystemLibrary::GetObjectName( UObject* Object ) -> FString
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetSystemLibrary.GetObjectName" );
		}

		struct
		{
		public:
			UObject* Object;
			FString ReturnValue;
		}Parameters;

		Parameters.Object = Object;

		this->ProcessEvent( Function, &Parameters );

		return Parameters.ReturnValue;
	}

	auto UKismetSystemLibrary::GetComponentBounds(
		USceneComponent* Component, FVector* Origin, FVector* BoxExtent, float* SphereRadius ) -> void
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetSystemLibrary.GetComponentBounds" );
		}

		struct
		{
		public:
			USceneComponent* Component;
			FVector Origin;
			FVector BoxExtent;
			float SphereRadius;
		}Parameters;

		Parameters.Component = Component;

		this->ProcessEvent( Function, &Parameters );

		if (Origin != nullptr)
			*Origin = Parameters.Origin;

		if (BoxExtent != nullptr)
			*BoxExtent = Parameters.BoxExtent;

		if (SphereRadius != nullptr)
			*SphereRadius = Parameters.SphereRadius;
	}

	auto UKismetStringLibrary::Len( FString S ) -> int32_t
	{
		static UFunction* Function = nullptr;
		if (!Function)
		{
			Function = UObject::FindObject<UFunction>( L"KismetStringLibrary.Len" );
		}

		struct
		{
			FString S;
			int32_t ReturnValue;
		} Params = { S };

		this->ProcessEvent( Function, &Params );

		return Params.ReturnValue;
	}
}