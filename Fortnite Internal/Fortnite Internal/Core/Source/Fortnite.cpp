#pragma once
#include <Core/Linkers/Fortnite.h>

namespace Fortnite
{
	auto FortniteHandler_t::Initialize( ) -> void
	{
		if (!this->Initialized)
		{
            this->Size = SDK::FVector2D( 722.0, 359.0 );
            this->Position = SDK::FVector2D( 200.0, 200.0 );

			SDK::MathLibrary = SDK::UObject::FindObject<SDK::UKismetMathLibrary>(L"Engine.Default__KismetMathLibrary");
			SDK::GameplayStatics = SDK::UObject::FindObject<SDK::UGameplayStatics>(L"Engine.Default__GameplayStatics");
			SDK::FortLibrary = SDK::UObject::FindObject<SDK::UFortKismetLibrary>(L"FortniteGame.Default__FortKismetLibrary");
			SDK::SystemLibrary = SDK::UObject::FindObject<SDK::UKismetSystemLibrary>(L"Engine.Default__KismetSystemLibrary");
			SDK::StringLibrary = SDK::UObject::FindObject<SDK::UKismetStringLibrary>(L"Engine.Default__KismetStringLibrary");

            SDK::LeftMouseButton = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"LeftMouseButton") }, 0 };
            SDK::RightMouseButton = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"RightMouseButton") }, 0 };
            SDK::GamepadLeftTrigger = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"Gamepad_LeftTrigger") }, 0 };
            SDK::Insert = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"Insert") }, 0 };
            SDK::F8 = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"F8") }, 0 };
            SDK::W = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"W") }, 0 };
            SDK::A = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"A") }, 0 };
            SDK::S = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"S") }, 0 };
            SDK::D = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"D") }, 0 };
            SDK::X = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"X") }, 0 };
            SDK::SpaceBar = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"SpaceBar") }, 0 };
            SDK::LeftShift = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"LeftShift") }, 0 };
            SDK::LeftAlt = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"LeftAlt") }, 0 };
            SDK::Capslock = SDK::FKey{ SDK::FName{ SDK::StringLibrary->Conv_StringToName(L"Capslock") }, 0 };

            SDK::PlayerPawn = SDK::UObject::FindObject<SDK::UClass>(L"FortniteGame.FortPlayerPawnAthena");
            SDK::LocalPlayer = SDK::UObject::FindObject<SDK::UClass>(L"Engine.LocalPlayer");
            SDK::PlayerController = SDK::UObject::FindObject<SDK::UClass>(L"Engine.PlayerController");
            SDK::PlayerCameraManager = SDK::UObject::FindObject<SDK::UClass>(L"Engine.PlayerCameraManager");
            SDK::GameViewportClient = SDK::UObject::FindObject<SDK::UClass>(L"Engine.GameViewportClient");
            SDK::Material = SDK::UObject::FindObject<SDK::UClass>(L"Engine.Material");
            SDK::Texture = SDK::UObject::FindObject<SDK::UClass>(L"Engine.Texture");
            SDK::FortPickup = SDK::UObject::FindObject<SDK::UClass>(L"FortniteGame.FortPickup");
            SDK::BuildingContainer = SDK::UObject::FindObject<SDK::UClass>(L"FortniteGame.BuildingContainer");
            SDK::BuildingWeakSpot = SDK::UObject::FindObject<SDK::UClass>(L"FortniteGame.BuildingWeakSpot");
            SDK::AthenaSuperDingo = SDK::UObject::FindObject<SDK::UClass>(L"FortniteGame.AthenaSuperDingo");
            SDK::FortAthenaVehicle = SDK::UObject::FindObject<SDK::UClass>(L"FortniteGame.FortAthenaVehicle");
            SDK::AthenaSupplyDrop = SDK::UObject::FindObject<SDK::UClass>(L"FortniteGame.FortAthenaSupplyDrop");
            SDK::FortWeapon = SDK::UObject::FindObject<SDK::UClass>(L"FortniteGame.FortWeaponRanged");
            SDK::WeaponPickaxeAthena = SDK::UObject::FindObject<SDK::UClass>(L"FortniteGame.FortWeaponPickaxeAthena");
            SDK::BuildingTrap = SDK::UObject::FindObject<SDK::UClass>(L"FortniteGame.BuildingTrap");

            this->Initialized = true;

            this->CurrentFrame = 0;
		}
	}

    auto FortniteHandler_t::IsSafeToRender( ) -> bool
    {
        if (this->Mutex.ShouldReturn( ))
            return false;

        ReturnLock Lock(&this->Mutex);
        return true;
    }

    auto FortniteHandler_t::InScreen( SDK::FVector2D ScreenLocation ) const -> bool
    {
        if (ScreenLocation.X < 5.0 || ScreenLocation.X > this->ScreenSize.X - (5.0 * 2) && ScreenLocation.Y < 5.0 || ScreenLocation.Y > this->ScreenSize.Y - (5.0 * 2))
            return false;
        return true;
    }

    auto FortniteHandler_t::InRect( double Radius, SDK::FVector2D ScreenLocation ) const -> bool
    {
        return this->ScreenCenter.X >= (this->ScreenCenter.X - Radius) && this->ScreenCenter.X <= (this->ScreenCenter.X + Radius) &&
            ScreenLocation.Y >= (ScreenLocation.Y - Radius) && ScreenLocation.Y <= (ScreenLocation.Y + Radius);
    }

    auto FortniteHandler_t::InCircle( double Radius, SDK::FVector2D ScreenLocation ) const -> bool
    {
        if (FortniteHandler_t::InRect( Radius, ScreenLocation ))
        {
            double dx = this->ScreenCenter.X - ScreenLocation.X; dx *= dx;
            double dy = this->ScreenCenter.Y - ScreenLocation.Y; dy *= dy;
            return dx + dy <= Radius * Radius;
        } return false;
    }

    auto FortniteHandler_t::GetThemeColor( int Index ) -> SDK::FLinearColor
    {
        switch (Index)
        {
        case 0:
            return SDK::FLinearColor( ).FromRGB( 254, 166, 253 );
            break;
        case 1:
            return SDK::FLinearColor( ).FromRGB( 204, 102, 27 );
            break;
        case 2:
            return SDK::FLinearColor( ).FromRGB( 101, 202, 254 );
            break;
        case 3:
            return SDK::FLinearColor( ).FromRGB( 153, 102, 229 );
            break;
        case 4:
            return SDK::FLinearColor( ).FromRGB( 254, 0, 0 );
            break;
        default:
            return SDK::FLinearColor( ).FromRGB( 254, 166, 253 );
            break;
        }
    }

    auto FortniteHandler_t::Project(
        SDK::FVector WorldLocation, SDK::FVector2D* ScreenLocation ) const -> bool
    {
        auto Canvas = this->Render.Canvas;
        SDK::FVector ReturnValue = Canvas->K2_Project( WorldLocation );

        if (ReturnValue.Z <= 0.0)
        {
            ReturnValue.X *= -1.0;
            ReturnValue.Y *= -1.0;

            ReturnValue.X += this->ScreenSize.X;
            ReturnValue.Y += this->ScreenSize.Y;
        }

        if (ReturnValue.Z > 0.0)
        {
            *ScreenLocation = SDK::FVector2D( ReturnValue.X, ReturnValue.Y );
        }

        return ScreenLocation;
    }

    auto FortniteHandler_t::GetSocketLocation( 
        SDK::USkeletalMeshComponent* Mesh, SDK::FString SocketName ) -> SDK::FVector
    {
        auto GetSocketName( [&]( SDK::FString SocketName ){
            auto SocketData = SocketName.c_str( );
            static map<wchar_t*, SDK::FName> Names;
            auto it = Names.find( SocketData );
            if (it != Names.end( ))
                return it->second;

            Names.insert( SocketData, SDK::StringLibrary->Conv_StringToName( SocketName ) );
            return Names.find( SocketData )->second;
        });

        return Mesh->GetSocketLocation( GetSocketName( SocketName ) );
    }

    auto FortniteHandler_t::GetColorByTier( SDK::EFortRarity Tier ) -> SDK::FLinearColor
    {
        switch (Tier)
        {
        case SDK::EFortRarity::Common:
            return SDK::FLinearColor( ).FromRGB( 100, 100, 100 );
            break;
        case SDK::EFortRarity::Uncommon:
            return SDK::FLinearColor( ).FromRGB( 58, 156, 3 );
            break;
        case SDK::EFortRarity::Rare:
            return SDK::FLinearColor( ).FromRGB( 0, 134, 222);
            break;
        case SDK::EFortRarity::Epic:
            return SDK::FLinearColor( ).FromRGB( 166, 68, 226 );
            break;
        case SDK::EFortRarity::Legendary:
            return SDK::FLinearColor( ).FromRGB( 245, 110, 2 );
            break;
        case SDK::EFortRarity::Mythic:
            return SDK::FLinearColor( ).FromRGB( 232, 186, 1 );
            break;
        default:
            return SDK::FLinearColor( );
            break;
        }
    }

    auto FortniteHandler_t::GetStringByRank( int32_t Rank ) -> SDK::FString
    {
        switch (Rank)
        {
        case 0:
        case 1:
        case 2:
            return L"Bronze";
        case 3:
        case 4:
        case 5:
            return L"Silver";
        case 6:
        case 7:
        case 8:
            return L"Gold";
        case 9:
        case 10:
        case 11:
            return L"Platinum";
        case 12:
        case 13:
        case 14:
            return L"Diamond";
        case 15:
            return L"Elite";
        case 16:
            return L"Champion";
        case 17:
            return L"Unreal";
        default:
            return L"Unranked";
        }
    }

    auto FortniteHandler_t::GetColorByRank( int32_t Rank ) -> SDK::FLinearColor
    {
        switch (Rank)
        {
        case 0:
        case 1:
        case 2:
            return SDK::FLinearColor().FromRGB( 196, 103, 52 );
        case 3:
        case 4:
        case 5:
            return SDK::FLinearColor( ).FromRGB( 161, 188, 235 );
        case 6:
        case 7:
        case 8:
            return SDK::FLinearColor( ).FromRGB( 254, 218, 34 );
        case 9:
        case 10:
        case 11:
            return SDK::FLinearColor( ).FromRGB( 94, 174, 174 );
        case 12:
        case 13:
        case 14:
            return SDK::FLinearColor( ).FromRGB( 114, 146, 254 );
        case 15:
            return SDK::FLinearColor( ).FromRGB( 165, 170, 162 );
        case 16:
            return SDK::FLinearColor( ).FromRGB( 255, 78, 29 );
        case 17:
            return SDK::FLinearColor( ).FromRGB( 174, 129, 254 );
        default:
            return SDK::FLinearColor( ).FromRGB( 0, 220, 255 );
        }
    }

    auto FortniteHandler_t::GetContext( bool* Active, SDK::FRotator* Rotation ) const -> void
    {
        *Active = this->bAimbotActive;
        *Rotation = this->AimbotRotation;
    }

    auto FortniteHandler_t::ApplyContext( bool Active, SDK::FRotator Rotation ) -> void
    {
        this->bAimbotActive = Active;
        this->AimbotRotation = Rotation;
    }

    auto FortniteHandler_t::Rehook( SDK::APlayerController* PlayerController ) -> void
    {
        static SDK::APlayerController* OriginalPlayerController = nullptr;
        if (OriginalPlayerController != PlayerController)
        {
            auto m_get_control_rotation = Hook::ShadowVMT( );
            m_get_control_rotation.Swap( PlayerController, 237, Callbacks::GetControlRotation::GetControlRotation, &Callbacks::GetControlRotation::GetControlRotationOriginal );
            OriginalPlayerController = PlayerController;
        }
    }

    auto FortniteHandler_t::Tick( SDK::UWorld* World, SDK::ULocalPlayer* LocalPlayer, SDK::UCanvas* Canvas, SDK::APlayerController* PlayerController ) -> void
    {
        this->CurrentFrame++;
        this->ThemeColor = FortniteHandler_t::GetThemeColor( Settings::Miscellaneous::Theme );

        FortniteHandler_t::Rehook( PlayerController );
        FortniteHandler_t::ApplyContext( false, SDK::FRotator( ) );

        auto CameraLocation = *(unsigned long long*)(World + 0x110);
        this->CameraLocation = *(SDK::FVector*)(CameraLocation);

        auto CameraRotation = *(unsigned long long*)(World + 0x120);

        this->CameraRotation.Yaw = *(double*)(CameraRotation);
        this->CameraRotation.Pitch = *(double*)(CameraRotation + 0x20);
        this->CameraRotation.Roll = *(double*)(CameraRotation + 0x1D0);

        this->CameraRotation.Yaw = ((SDK::MathLibrary->Atan2( this->CameraRotation.Pitch * -1.0, this->CameraRotation.Yaw ) * (180.0 / M_PI)) * -1.0) * -1.0;
        this->CameraRotation.Pitch = SDK::MathLibrary->Asin( this->CameraRotation.Roll ) * (180.0 / M_PI);
        this->CameraRotation.Roll = 0.0;

        auto ViewState = (*(SDK::TArray <SDK::UObject*>*)(LocalPlayer + 0xd0))[1];
        float FieldOfView = SDK::MathLibrary->Atan( 1.0 / *(double*)(ViewState + 0x700) ) * 2.f;
        this->FieldOfView = FieldOfView * (180.f / M_PI);
        this->AimbotFOV = (Settings::Aimbot::FieldOfView * this->ScreenSize.X / this->FieldOfView) / 2.0;

        auto ClipX = Canvas->ClipX( );
        auto ClipY = Canvas->ClipY( );

        this->ScreenSize = SDK::FVector2D( ClipX, ClipY );
        this->ScreenCenter = SDK::FVector2D( ClipX / 2.0, ClipY / 2.0 );

        this->Render.Setup( Canvas );
    }

    auto FortniteHandler_t::Main( SDK::UGameViewportClient* ViewportClient, SDK::UCanvas* Canvas ) -> bool
    {
        do
        {
            if (!false)
                continue;

        } while (false);

        auto World = ViewportClient->World( );
        if (!World) return false;

        auto OwningGameInstance = World->OwningGameInstance( );
        if (!OwningGameInstance) return false;

        auto LocalPlayer = OwningGameInstance->LocalPlayers( )[0];
        if (!LocalPlayer) return false;

        auto PlayerController = LocalPlayer->PlayerController( );
        if (!PlayerController) return false;

        auto PlayerCameraManager = PlayerController->PlayerCameraManager( );
        if (!PlayerCameraManager) return false;

        auto AcknowledgedPawn = PlayerController->AcknowledgedPawn( );

        Fortnite::FortniteHandler_t::Tick( World, LocalPlayer, Canvas, PlayerController );

        if (Settings::Aimbot::DrawFOV)
        {
            this->Render.Circle( this->ScreenCenter, SDK::FLinearColor( 1.f, 1.f, 1.f, 1.f ), this->AimbotFOV, 128.0, true );
        }

        SDK::TArray <SDK::APlayerPawn_Athena_C*> PlayerArray;
        SDK::GameplayStatics->GetAllActorsOfClass( World, SDK::PlayerPawn, &PlayerArray );
        for (int i = 0; i < PlayerArray.NumElements; i++)
        {
            auto Player = PlayerArray[i];
            if (!Player)
                continue;

            if (Player == AcknowledgedPawn)
                continue;

            auto Teammate = SDK::FortLibrary->OnSameTeam( Player, AcknowledgedPawn );
            if (Teammate) continue;

            auto Wound = Player->IsDBNO( );
            auto Dead = Player->IsDead( );
            if (Dead) continue;

            auto Mesh = Player->Mesh( );
            if (!Mesh) continue;

            auto PlayerState = Player->PlayerState( );
            if (!PlayerState) continue;
            auto IsABot = PlayerState->IsABot( );

            auto HeadPosition = SDK::FVector2D( );
            auto HeadLocation = FortniteHandler_t::GetSocketLocation( Mesh, SDK::FString( L"head" ) );
            if (!FortniteHandler_t::Project( HeadLocation, &HeadPosition )) continue;
            if (!FortniteHandler_t::InScreen( HeadPosition )) continue;

            auto RootPosition = SDK::FVector2D( );
            auto RootLocation = FortniteHandler_t::GetSocketLocation( Mesh, SDK::FString( L"root" ) );
            if (!FortniteHandler_t::Project( RootLocation, &RootPosition )) continue;
            auto Distance = SDK::MathLibrary->Vector_Distance( this->CameraLocation, RootLocation ) * 0.01;

            SDK::FLinearColor RenderColor = this->ThemeColor;
            SDK::FLinearColor TextColor = SDK::FLinearColor( ).FromRGB( 255, 255, 255 );

            auto Visable = ViewportClient->LineTraceSingle( World, this->CameraLocation, HeadLocation );
            if (!Visable)
            {
                RenderColor = SDK::FLinearColor( ).FromRGB( 89, 10, 8 );
            }

            auto DistanceToCenter = SDK::MathLibrary->Vector_Distance2D( this->ScreenCenter, HeadPosition );
            if (DistanceToCenter < this->ClosestDistanceToCenter)
            {
                this->ClosestPlayer = Player;
                this->ClosestDistanceToCenter = DistanceToCenter;
            }

            if (Settings::Character::Active)
            {
                auto Origin = SDK::FVector( );
                auto Extent = SDK::FVector( );
                auto SphereRadius = 0.f;
                SDK::SystemLibrary->GetComponentBounds( Mesh, &Origin, &Extent, &SphereRadius );

                double MostLeft = DBL_MAX;
                double MostRight = DBL_MIN;
                double MostTop = DBL_MAX;
                double MostBottom = DBL_MIN;

                for (int i = 0; i < 8; i++)
                {
                    SDK::FVector Corner = SDK::FVector( );

                    if (i & 1)
                    {
                        Corner.X = 1.0 * Extent.X;
                    }
                    else
                    {
                        Corner.X = -1.0 * Extent.X;
                    }

                    if (i & 2)
                    {
                        Corner.Y = 1.0 * Extent.Y;
                    }
                    else
                    {
                        Corner.Y = -1.0 * Extent.Y;
                    }

                    if (i & 2)
                    {
                        Corner.Z = 1.0 * Extent.Z;
                    }
                    else
                    {
                        Corner.Z = -1.0 * Extent.Z;
                    }

                    SDK::FVector2D Origin2D = SDK::FVector2D( );
                    if (!FortniteHandler_t::Project( Origin + Corner, &Origin2D )) continue;

                    if (Origin2D.X < MostLeft)
                    {
                        MostLeft = Origin2D.X;
                    }

                    if (Origin2D.X > MostRight)
                    {
                        MostRight = Origin2D.X;
                    }

                    if (Origin2D.Y < MostTop)
                    {
                        MostTop = Origin2D.Y;
                    }

                    if (Origin2D.Y > MostBottom)
                    {
                        MostBottom = Origin2D.Y;
                    }
                }

                MostTop += 15.0;

                double ActorHeight = MostBottom - MostTop;
                double ActorWidth = MostRight - MostLeft;

                double CornerWidth = ActorWidth / 5.0;
                double CornerHeight = ActorHeight / 3.5;

                double TopTextOffset = 10.0;
                double BottomTextOffset = 10.0;

                SDK::FVector2D BottomMiddle = SDK::FVector2D( MostLeft + (ActorWidth / 2.0), MostBottom );

                if (Settings::Character::BoxESP == 1)
                {
                    this->Render.Line( SDK::FVector2D( MostLeft, MostTop ), SDK::FVector2D( MostRight, MostTop ), RenderColor, 1.f, false );
                    this->Render.Line( SDK::FVector2D( MostLeft, MostBottom ), SDK::FVector2D( MostRight, MostBottom ), RenderColor, 1.f, false );
                    this->Render.Line( SDK::FVector2D( MostLeft, MostBottom ), SDK::FVector2D( MostLeft, MostTop ), RenderColor, 1.f, false );
                    this->Render.Line( SDK::FVector2D( MostRight, MostTop ), SDK::FVector2D( MostRight, MostBottom ), RenderColor, 1.f, false );
                }
                else if (Settings::Character::BoxESP == 2)
                {
                    this->Render.Line( SDK::FVector2D( MostLeft, MostTop ), SDK::FVector2D( MostLeft, MostTop + CornerHeight ), RenderColor, 1.f, false );
                    this->Render.Line( SDK::FVector2D( MostLeft, MostTop ), SDK::FVector2D( MostLeft + CornerWidth, MostTop ), RenderColor, 1.f, false );

                    this->Render.Line( SDK::FVector2D( MostLeft + ActorWidth - CornerWidth, MostTop ), SDK::FVector2D( MostLeft + ActorWidth, MostTop ), RenderColor, 1.f, false );
                    this->Render.Line( SDK::FVector2D( MostLeft + ActorWidth, MostTop ), SDK::FVector2D( MostLeft + ActorWidth, MostTop + CornerHeight ), RenderColor, 1.f, false );

                    this->Render.Line( SDK::FVector2D( MostLeft, MostTop + ActorHeight - CornerHeight ), SDK::FVector2D( MostLeft, MostTop + ActorHeight ), RenderColor, 1.f, false );
                    this->Render.Line( SDK::FVector2D( MostLeft, MostTop + ActorHeight ), SDK::FVector2D( MostLeft + CornerWidth, MostTop + ActorHeight ), RenderColor, 1.f, false );

                    this->Render.Line( SDK::FVector2D( MostLeft + ActorWidth - CornerWidth, MostTop + ActorHeight ), SDK::FVector2D( MostLeft + ActorWidth, MostTop + ActorHeight ), RenderColor, 1.f, false );
                    this->Render.Line( SDK::FVector2D( MostLeft + ActorWidth, MostTop + ActorHeight - CornerHeight ), SDK::FVector2D( MostLeft + ActorWidth, MostTop + ActorHeight ), RenderColor, 1.f, false );
                }

                if (Settings::Character::LineESP == 1)
                {
                    this->Render.Line( HeadPosition, SDK::FVector2D( this->ScreenCenter.X, 0.0 ), RenderColor, 2.f, false );
                }
                else if (Settings::Character::LineESP == 2)
                {
                    this->Render.Line( BottomMiddle, this->ScreenCenter, RenderColor, 2.f, false );
                }
                else if (Settings::Character::LineESP == 3)
                {
                    this->Render.Line( BottomMiddle, SDK::FVector2D( this->ScreenCenter.X, this->ScreenCenter.Y * 2.0 ), RenderColor, 2.f, false );
                }

                if (Settings::Character::FilledESP)
                {
                    auto DefaultTexture = Canvas->DefaultTexture( );

                    Canvas->K2_DrawTexture( DefaultTexture, SDK::FVector2D( MostLeft, MostTop ), SDK::FVector2D( ActorWidth, ActorHeight ), SDK::FVector2D( ), SDK::FVector2D( 1.0, 1.0 ), SDK::FLinearColor( 0.0f, 0.0f, 0.0f, 0.20f ), SDK::EBlendMode::BLEND_Translucent, 0.f, SDK::FVector2D( ) );
                }

                if (Settings::Character::SkeletonESP)
                {
                    for (const auto& Pair : BonePairs)
                    {
                        auto WorldLocationFirst = FortniteHandler_t::GetSocketLocation( Mesh, Pair.first );
                        auto WorldLocationSecond = FortniteHandler_t::GetSocketLocation( Mesh, Pair.second );

                        auto ScreenPositionFirst = SDK::FVector2D( );
                        auto ScreenPositionSecond = SDK::FVector2D( );

                        if (!FortniteHandler_t::Project( WorldLocationFirst, &ScreenPositionFirst )) continue;
                        if (!FortniteHandler_t::Project( WorldLocationSecond, &ScreenPositionSecond )) continue;

                        this->Render.Line( ScreenPositionFirst, ScreenPositionSecond, RenderColor, 1.f, false );
                    }
                }

                if (Settings::Character::RankedESP)
                {
                    auto HabaneroComponent = PlayerState->HabaneroComponent( );
                    if (HabaneroComponent)
                    {
                        auto Rank = HabaneroComponent->RankedProgress( ).Rank;
                        auto String = FortniteHandler_t::GetStringByRank( Rank );
                        auto TextColor = FortniteHandler_t::GetColorByRank( Rank );

                        this->Render.Text( String, SDK::FVector2D( BottomMiddle.X, MostTop - TopTextOffset ), TextColor, true, false, true, true );

                        TopTextOffset += TopTextOffset + 2.0;
                    }
                }

                if (Settings::Character::DisplayName)
                {
                    auto SeasonLevelUIDisplay = PlayerState->SeasonLevelUIDisplay( );
                    auto HumanReadableName = SDK::FortLibrary->GetHumanReadableName( Player );
                    HumanReadableName = IsABot ? SDK::FString( L"BOT/NPC" ) : HumanReadableName;
                    auto ConvertedText = SDK::StringLibrary->BuildString_Int( HumanReadableName, SDK::FString( L" (" ), int( SeasonLevelUIDisplay ), SDK::FString( L")" ) );
                    this->Render.Text( ConvertedText, SDK::FVector2D( BottomMiddle.X, MostTop - TopTextOffset ), TextColor, true, false, true, true );
                    TopTextOffset += TopTextOffset + 2.0;
                }

                if (Settings::Character::EyeDirection)
                {
                    auto RootComponent = Player->RootComponent( );
                    auto FowardVector = RootComponent->GetForwardVector( ) * 120.0;
                    auto ForwardPosition = SDK::FVector2D( );
                    FortniteHandler_t::Project( FowardVector, &ForwardPosition );

                    this->Render.Line( HeadPosition, ForwardPosition, RenderColor, 1.5f, false );
                }

                if (Settings::Character::ActiveWeapon)
                {
                    auto CurrentWeapon = Player->CurrentWeapon( );
                    if (CurrentWeapon)
                    {
                        auto IsHoldingWeapon = SDK::GameplayStatics->ObjectIsA( CurrentWeapon, SDK::FortWeapon );
                        if (IsHoldingWeapon)
                        {
                            auto WeaponData = CurrentWeapon->WeaponData( );
                            if (WeaponData)
                            {
                                auto& ItemName = WeaponData->ItemName( ).GetStringRef( );
                                auto CurrentAmmo = CurrentWeapon->GetMagazineAmmoCount( );
                                auto MaxAmmo = CurrentWeapon->GetBulletsPerClip( );

                                if (MaxAmmo && CurrentAmmo)
                                {
                                    auto Rarity = WeaponData->Rarity( );
                                    auto Color = FortniteHandler_t::GetColorByTier( Rarity );

                                    auto ConvertedText = SDK::StringLibrary->BuildString_Int( ItemName, L" (", CurrentAmmo, L"/" );
                                    ConvertedText = SDK::StringLibrary->BuildString_Int( ConvertedText, L"", MaxAmmo, L")" );

                                    this->Render.Text( ConvertedText, SDK::FVector2D( BottomMiddle.X, MostBottom + BottomTextOffset ), Color, true, false, true, false );

                                    BottomTextOffset += BottomTextOffset + 2.0;
                                }
                            }
                        }
                    }
                }

                if (Settings::Character::Distance)
                {
                    auto ConvertedText = SDK::StringLibrary->BuildString_Int( SDK::FString( ), SDK::FString( ), int( Distance ), SDK::FString( L"m" ) );
                    this->Render.Text( ConvertedText, SDK::FVector2D( BottomMiddle.X, MostBottom + BottomTextOffset ), TextColor, true, false, true, false );
                    BottomTextOffset += BottomTextOffset + 2.0;
                }
            }
        }

        if (AcknowledgedPawn)
        {
            auto CurrentWeapon = AcknowledgedPawn->CurrentWeapon( );
            if (CurrentWeapon)
            {
                auto IsHoldingWeapon = SDK::GameplayStatics->ObjectIsA( CurrentWeapon, SDK::FortWeapon );
                if (IsHoldingWeapon)
                {
                    auto StartLocation = CurrentWeapon->GetTargetingSourceLocation( );

                    auto AimbotPawn = this->ClosestPlayer;
                    if (AimbotPawn)
                    {
                        auto Wound = AimbotPawn->IsDBNO( );
                        if (Settings::Aimbot::IgnoreKnocked && !Wound || !Settings::Aimbot::IgnoreKnocked)
                        {
                            auto Mesh = AimbotPawn->Mesh( );
                            if (Mesh)
                            {
                                SDK::FString TargetSocketName = L"head";
                                if (Settings::Aimbot::AimBone == 1)
                                    TargetSocketName = L"neck_01";
                                else if (Settings::Aimbot::AimBone == 2)
                                    TargetSocketName = L"spine_05";

                                auto AimbotPosition = SDK::FVector2D( );
                                auto AimbotLocation = FortniteHandler_t::GetSocketLocation( Mesh, TargetSocketName );
                                if (FortniteHandler_t::Project( AimbotLocation, &AimbotPosition ))
                                {
                                    if (FortniteHandler_t::InCircle( this->AimbotFOV, AimbotPosition ))
                                    {
                                        auto IsVisble = ViewportClient->LineTraceSingle( World, this->CameraLocation, AimbotLocation );
                                        if (Settings::Aimbot::IgnoreNonVisble && IsVisble || !Settings::Aimbot::IgnoreNonVisble)
                                        {
                                            auto PlayerDistance = SDK::MathLibrary->Vector_Distance( StartLocation, AimbotLocation );

                                            if (Settings::Aimbot::TargetLine)
                                            {
                                                auto MuzzlePosition = SDK::FVector2D( );
                                                auto MuzzleLocation = CurrentWeapon->GetMuzzleLocation( );
                                                if (FortniteHandler_t::Project( MuzzleLocation, &MuzzlePosition ))
                                                {
                                                    this->Render.Line( MuzzlePosition, AimbotPosition, this->ThemeColor, 1.5f, false );
                                                }
                                            }

                                            if (Settings::Aimbot::TriggerBot)
                                            {
                                                auto CanFire = CurrentWeapon->CanFire( );
                                                auto WeaponCoreAnimation = CurrentWeapon->WeaponCoreAnimation( );
                                                if (CanFire && IsVisble && WeaponCoreAnimation == SDK::EFortWeaponCoreAnimation::Shotgun)
                                                {
                                                    AcknowledgedPawn->PawnStartFire( 1 );
                                                    AcknowledgedPawn->PawnStopFire( 1 );
                                                }
                                            }

                                            auto AimbotKey = SDK::RightMouseButton;
                                            if (Settings::Aimbot::KeyType == 1)
                                                AimbotKey = SDK::LeftShift;
                                            else if (Settings::Aimbot::KeyType == 2)
                                                AimbotKey = SDK::LeftAlt;

                                            auto AimbotKeyDown = PlayerController->IsInputKeyDown( AimbotKey ) || PlayerController->IsInputKeyDown( SDK::GamepadLeftTrigger );
                                            if (AimbotKeyDown)
                                            {
                                                if (Settings::Aimbot::AimPrediction)
                                                {
                                                    auto ItemDefinition = CurrentWeapon->WeaponData( );
                                                    bool HasLightweightProjectile = ItemDefinition->HasLightweightProjectile( );
                                                    if (HasLightweightProjectile)
                                                    {
                                                        auto CurrentVelocity = AimbotPawn->GetVelocity( );
                                                        if (AimbotPawn->IsInVehicle( ) || AimbotPawn->IsDrivingVehicle( ))
                                                        {
                                                            auto CurrentVehicle = AimbotPawn->CurrentVehicle( );

                                                            CurrentVelocity = CurrentVehicle->GetVelocity( );
                                                        }

                                                        auto LocalVelocity = AcknowledgedPawn->GetVelocity( );
                                                        if (AcknowledgedPawn->IsInVehicle( ) || AcknowledgedPawn->IsDrivingVehicle( ))
                                                        {
                                                            auto CurrentVehicle = AcknowledgedPawn->CurrentVehicle( );

                                                            LocalVelocity = CurrentVehicle->GetVelocity( );
                                                        }

                                                        auto RelativeVelocity = CurrentVelocity - LocalVelocity;

                                                        double ProjectileSpeed = static_cast<double>(CurrentWeapon->ProjectileSpeed( ));
                                                        double ProjectileGravity = static_cast<double>(CurrentWeapon->ProjectileGravity( ));

                                                        double TimeToTarget = PlayerDistance / ProjectileSpeed;

                                                        AimbotLocation.X += RelativeVelocity.X * TimeToTarget;
                                                        AimbotLocation.Y += RelativeVelocity.Y * TimeToTarget;

                                                        double Difference = StartLocation.Z - AimbotLocation.Z;
                                                        double HorizontalDistance = SDK::MathLibrary->Sqrt( SDK::MathLibrary->Pow( StartLocation.X - AimbotPosition.X, 2.0 ) + SDK::MathLibrary->Pow( StartLocation.Y - AimbotPosition.Y, 2.0 ) );
                                                        double VerticalAngle = SDK::MathLibrary->Atan2( SDK::MathLibrary->Abs( Difference ), HorizontalDistance );

                                                        double Angle = VerticalAngle * (180.0 / M_PI);
                                                        double Factor = SDK::MathLibrary->Abs( Angle - 90.0 ) / 90.0;
                                                        ProjectileGravity *= Factor;

                                                        AimbotLocation.Z += RelativeVelocity.Z * TimeToTarget + (SDK::MathLibrary->Abs( ProjectileGravity * -980.0 ) * (TimeToTarget * TimeToTarget)) * 0.5;
                                                    }

                                                    auto TargetRotation = SDK::MathLibrary->FindLookAtRotation( this->CameraLocation, AimbotLocation );

                                                    if (Settings::Aimbot::Smooth && Settings::Aimbot::Smoothing >= 0.0)
                                                    {
                                                        if (Settings::Aimbot::Smooth == 1)
                                                            TargetRotation = SDK::MathLibrary->RInterpTo( this->CameraRotation, TargetRotation, WorldDeltaSeconds, Settings::Aimbot::Smoothing );
                                                        else if (Settings::Aimbot::Smooth == 2)
                                                            TargetRotation = SDK::MathLibrary->RInterpTo_Constant( this->CameraRotation, TargetRotation, WorldDeltaSeconds, Settings::Aimbot::Smoothing );

                                                        TargetRotation += (TargetRotation - this->CameraRotation);
                                                    }

                                                    FortniteHandler_t::ApplyContext( true, TargetRotation );
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        static bool IsAllowedToRender = true;
        if (IsAllowedToRender)
        {
            auto IsAllowedToTick = this->LastFrameTime != this->CurrentFrame;
            if (IsAllowedToTick)
            {
                this->Offset = SDK::FVector2D( );
                this->MousePosition = PlayerController->GetMousePosition( );

                this->LeftMouseClicked = PlayerController->WasInputKeyJustPressed( SDK::LeftMouseButton );
                this->LeftMouseDown = PlayerController->IsInputKeyDown( SDK::LeftMouseButton );
                this->RightMouseClicked = PlayerController->WasInputKeyJustPressed( SDK::RightMouseButton );
                this->RightMouseDown = PlayerController->IsInputKeyDown( SDK::RightMouseButton );

                auto CheckHovered( [&]( SDK::FVector2D Position, SDK::FVector2D Size ){
                    if (this->MousePosition.X > Position.X && this->MousePosition.Y > Position.Y)
                        if (this->MousePosition.X < Position.X + Size.X && this->MousePosition.Y < Position.Y + Size.Y)
                            return true;
                    return false; } );

                static SDK::FVector2D ClickPosition = SDK::FVector2D( );
                this->WindowHovered = CheckHovered( SDK::FVector2D( this->Position.X, this->Position.Y - 5.0 ), SDK::FVector2D( this->Size.X, 20.0 ) );
                this->WindowGrabbed = this->WindowGrabbed ? this->LeftMouseDown : this->WindowHovered && this->LeftMouseDown;
                if (this->WindowGrabbed)
                {
                    if (!ClickPosition)
                    {
                        ClickPosition = SDK::FVector2D( this->MousePosition.X - this->Position.X, this->MousePosition.Y - this->Position.Y );
                    }

                    this->WindowHovered = true;
                }

                if (ClickPosition)
                {
                    this->Position = SDK::FVector2D( this->MousePosition.X - (this->Size.X / 2.0), this->MousePosition.Y - (20.0 / 2.0) );
                }

                if (!this->LeftMouseDown)
                {
                    ClickPosition = SDK::FVector2D( );
                }

                this->Render.Rect( this->Position, SDK::FVector2D( this->Size.X, 28.0 ), SDK::FLinearColor( ).FromRGB( 13, 13, 13 ), 1.f, true, false, true );
                this->Render.Text( SDK::FString( L"Backbone Fortnite Internal" ), SDK::FVector2D( this->Position.X + (this->Size.X / 2.0), this->Position.Y + 13.0 ), SDK::FLinearColor( ).FromRGB( 255, 255, 255 ), true, true, false, true );

                this->Render.Rect( SDK::FVector2D( this->Position.X, this->Position.Y + 28.0 ), this->Size, SDK::FLinearColor( ).FromRGB( 20, 20, 20 ), 1.f, true, false, true );
                this->Render.Rect( SDK::FVector2D( this->Position.X + 10.0 , this->Position.Y + 35.0 ), SDK::FVector2D( 218.0, this->Size.Y - 15.0 ), SDK::FLinearColor( ).FromRGB( 31, 31, 31 ), 1.f, true, false, true );

                this->Render.Line( SDK::FVector2D( this->Position.X, this->Position.Y + 28.0 ), SDK::FVector2D( this->Position.X + this->Size.X, this->Position.Y + 28.0 ), this->ThemeColor, 1.5f, true );

                this->Offset += SDK::FVector2D( 10.0 , 35.0 );

                auto Button( [&]( SDK::FString Content, bool Active ){
                    auto Size = SDK::FVector2D( 218.0, 28.0 );
                    auto Position = this->Offset + this->Position;
                    auto Hovered = CheckHovered( Position, Size );
                    auto Clicked = this->LeftMouseClicked && Hovered;
                    auto TextColor = SDK::FLinearColor( ).FromRGB( 90, 90, 90 );
                    auto RenderColor = SDK::FLinearColor( ).FromRGB( 31, 31, 31 );
                    if (Active) {
                        TextColor = SDK::FLinearColor( ).FromRGB( 255, 255, 255 );
                        RenderColor = SDK::FLinearColor( ).FromRGB( 46, 46, 46 );
                    }
                    if (Clicked) Active = !Active;

                    this->Render.Rect( Position, Size, RenderColor, 1.f, true, false, true );
                    this->Render.Text( Content, SDK::FVector2D( Position.X + (Size.X / 2.0), Position.Y + 12.0 ), TextColor, false, true, false, true );

                    this->Offset.Y += Size.Y;
                    return Clicked; } );

                static int MenuTab = 0;
                if (Button( SDK::FString( L"Aimbot" ), MenuTab == 0 )) MenuTab = 0;
                if (Button( SDK::FString( L"Character" ), MenuTab == 1 )) MenuTab = 1;
                if (Button( SDK::FString( L"Environment" ), MenuTab == 2 )) MenuTab = 2;
                if (Button( SDK::FString( L"Skin Changer" ), MenuTab == 3 )) MenuTab = 3;
                if (Button( SDK::FString( L"Exploits" ), MenuTab == 4 )) MenuTab = 4;
                if (Button( SDK::FString( L"Miscellaneous" ), MenuTab == 5 )) MenuTab = 5;

                this->Render.Rect( SDK::FVector2D( this->Position.X + 238.0, this->Position.Y + 35.0 ), SDK::FVector2D( 475.0, this->Size.Y - 15.0 ), SDK::FLinearColor( ).FromRGB( 26, 26, 26 ), 1.f, true, false, true );

                this->Offset = SDK::FVector2D( 243.0, 40.0 );

                auto Checkbox( [&]( SDK::FString Content, bool* Toggle ){
                    auto Size = SDK::FVector2D( 18.0, 18.0 );
                    auto Position = this->Position + this->Offset;
                    auto Hovered = CheckHovered( Position, Size );
                    auto Clicked = this->LeftMouseClicked && Hovered;
                    auto TextColor = SDK::FLinearColor( ).FromRGB( 143, 143, 143 );
                    auto RenderColor = SDK::FLinearColor( ).FromRGB( 46, 46, 46 );
                    if (*Toggle)
                    {
                        TextColor = SDK::FLinearColor( ).FromRGB( 255, 255, 255 );
                        RenderColor = this->ThemeColor;
                    }
                    if (Clicked) *Toggle = !*Toggle;

                    this->Render.Rect( Position, Size, RenderColor, 1.f, true, false, true );
                    this->Render.Rect( Position, Size, SDK::FLinearColor( ).FromRGB( 13, 13, 13 ), 1.5f, false, false, true );

                    auto TextWidth = this->Render.RenderFont->GetStringSize( Content.c_str() );
                    this->Render.Text( Content, SDK::FVector2D( Position.X + Size.X + 5.0 + (int)(TextWidth / 2), Position.Y + (18.0 / 2.0) ), TextColor, false, false, false, true );
                    this->Offset.Y += Size.Y + 5.0; } );

                auto Combobox( [&]( SDK::FString Content, int* Value, SDK::FString Arguments[], int NumArguments ){
                    this->Offset.Y += 5.0;
                    auto Size = SDK::FVector2D( 180.0, 20.0 );
                    auto Position = this->Position + this->Offset;
                    auto TextColor = SDK::FLinearColor( ).FromRGB( 255, 255, 255 );
                    auto RenderColor = SDK::FLinearColor( ).FromRGB( 13, 13, 13 );
                    this->Render.Rect( Position, Size, RenderColor, 1.f, true, false, true );
                    this->Render.Rect( Position, Size, SDK::FLinearColor( ).FromRGB( 13, 13, 13 ), 1.5f, false, false, true );
                    auto TextWidth = this->Render.RenderFont->GetStringSize( Content.c_str( ) );
                    this->Render.Text( Content, SDK::FVector2D( Position.X + Size.X + 5.0 + (int)(TextWidth / 2), Position.Y + (Size.Y / 2.0) ), TextColor, true, true, true, true );
                    this->Render.Text( Arguments[*Value], SDK::FVector2D( Position.X + (Size.X / 2.0), Position.Y + (Size.Y / 2.0) ), SDK::FLinearColor( ).FromRGB( 143, 143, 143 ), true, true, false, true );
                    this->Render.Text( L"<", SDK::FVector2D( Position.X + 8.0, Position.Y + (Size.Y / 2.0) - 1.0 ), TextColor, true, true, false, true );
                    this->Render.Text( L">", SDK::FVector2D( Position.X + Size.X - 8.0 , Position.Y + (Size.Y / 2.0) - 1.0 ), TextColor, true, true, false, true );

                    if (this->MousePosition.X > Position.X && this->MousePosition.Y > Position.Y && this->MousePosition.X < Position.X + 20.f && this->MousePosition.Y < Position.Y + 20.0)
                    {
                        if (this->LeftMouseClicked)
                        {
                            *Value -= 1;

                            if (*Value < 0)
                            {
                                *Value = NumArguments - 1;
                            }
                        }
                    }

                    if (this->MousePosition.X > Position.X + (180.0 - 20.f) && this->MousePosition.Y > Position.Y && this->MousePosition.X < Position.X + ( + 180.0) && this->MousePosition.Y < Position.Y + ( 20.0))
                    {
                        if (this->LeftMouseClicked)
                        {
                            *Value += 1;

                            if (*Value > NumArguments - 1)
                            {
                                *Value = 0;
                            }
                        }
                    }

                    this->Offset.Y += Size.Y + 3.0; } );

                auto Slider( [&]( SDK::FString Content, double Min, double Max, double* Value ){
                    this->Offset.Y += 2.0;
                    auto Size = SDK::FVector2D( 200.0 - 20.0, 11.0 );
                    auto Position = this->Position + this->Offset;
                    auto Hovered = CheckHovered( Position, SDK::FVector2D( Size.X + 10.0, Size.Y ) );
                    auto Dragging = this->LeftMouseDown && Hovered;
                    auto TextColor = SDK::FLinearColor( ).FromRGB( 255, 255, 255 );
                    auto RenderColor = this->ThemeColor;

                    auto TextWidth = this->Render.RenderFont->GetStringSize( Content.c_str( ) );
                    this->Render.Text( Content, SDK::FVector2D( Position.X + Size.X + 5.0 + (int)(TextWidth / 2), Position.Y + (9.0 / 2.0)), TextColor, false, true, false, true );
                    this->Render.Rect( Position, SDK::FVector2D( *Value * (Size.X / Max), Size.Y ), RenderColor, 1.f, true, false, true );
                    if (*Value > Min && *Value < Max - 1)
                        this->Render.Rect( SDK::FVector2D( Position.X + *Value * (Size.X / Max), Position.Y ), SDK::FVector2D( 10.0, Size.Y ), SDK::FLinearColor( ).FromRGB( 13, 13, 13 ), 1.f, true, false, true );
                    this->Render.Rect( Position, Size, SDK::FLinearColor( ).FromRGB( 13, 13, 13 ), 1.5f, false, false, true );

                    if (Dragging)
                    {
                        if (this->MousePosition.X < Position.X + 4.0)
                        {
                            *Value = Min;
                        }
                        else if (this->MousePosition.X > Position.X + Size.X  )
                        {
                            *Value = Max;
                        }
                        else
                        {
                            *Value = (this->MousePosition.X - (Position.X)) * (Max / Size.X);
                        }

                        auto Percentage = SDK::StringLibrary->Conv_IntToString( *Value );
                        auto TextWidth = this->Render.RenderFont->GetStringSize( Percentage.c_str( ) );
                        this->Render.Text( Percentage, SDK::FVector2D( Position.X + TextWidth + *Value * (Size.X / Max), Position.Y + (Size.Y / 2.0) ), SDK::FLinearColor( 1.f, 1.f, 1.f, 1.f ), false, true, true, true );
                    }

                    this->Offset.Y += Size.Y + 5.0; } );

                if (MenuTab == 0)
                {
                    Checkbox( L"Memory Aim", &Settings::Aimbot::Active );
                    Checkbox( L"Trigger Bot", &Settings::Aimbot::TriggerBot );
                    Checkbox( L"Draw FOV", &Settings::Aimbot::DrawFOV );
                    Checkbox( L"Target Line", &Settings::Aimbot::TargetLine );
                    Checkbox( L"Engine Prediction", &Settings::Aimbot::AimPrediction );
                    Checkbox( L"Ignore Non-Visible", &Settings::Aimbot::IgnoreNonVisble );
                    Checkbox( L"Ignore Despawning", &Settings::Aimbot::IgnoreKnocked );
                    Slider( L"FOV", 0.0, 80.0, &Settings::Aimbot::FieldOfView );

                    SDK::FString SmoothingTypes[]{ L"None", L"Interpolate", L"Constant" };
                    Combobox( L"Type", &Settings::Aimbot::Smooth, SmoothingTypes, sizeof( SmoothingTypes ) / sizeof( SDK::FString ) );
                    if (Settings::Aimbot::Smooth)
                        Slider( SDK::FString( L"Smoothing" ), 0.0, 20.0, &Settings::Aimbot::Smoothing );

                    SDK::FString AimTypes[]{ L"Head", L"Neck", L"Chest" };
                    Combobox( L"AimBone", &Settings::Aimbot::AimBone, AimTypes, sizeof( AimTypes ) / sizeof( SDK::FString ) );

                    SDK::FString KeyTypes[]{ L"RMB", L"LShift", L"LAlt" };
                    Combobox( L"KeyType", &Settings::Aimbot::KeyType, KeyTypes, sizeof( KeyTypes ) / sizeof( SDK::FString ) );
                    this->Offset.Y += 2.0;

                    Slider( L"Aim Distance", 0.0, 150.0, &Settings::Aimbot::Distance );
                }
                else if (MenuTab == 1)
                {
                    Checkbox( L"Character ESP" , &Settings::Character::Active );
                    Checkbox( L"Filled Box ESP" , &Settings::Character::FilledESP );   
                    Checkbox( L"Active Weapon" , &Settings::Character::ActiveWeapon );
                    Checkbox( L"Inventory ESP" , &Settings::Character::InventoryESP );
                    Checkbox( L"Skeleton ESP" , &Settings::Character::SkeletonESP );
                    Checkbox( L"Username ESP" , &Settings::Character::DisplayName );
                    Checkbox( L"Distance ESP" , &Settings::Character::Distance );
                    Checkbox( L"Specator ESP" , &Settings::Character::SpecatorESP );
                    Checkbox( L"OOF Arrows", &Settings::Character::OOFArrows );
                    Checkbox( L"Ranked ESP" , &Settings::Character::RankedESP );

                    SDK::FString BoxTypes[]{ L"None", L"2D", L"Corner" };
                    Combobox( L"Box ESP", &Settings::Character::BoxESP, BoxTypes, sizeof( BoxTypes ) / sizeof( SDK::FString ) );

                    SDK::FString LineTypes[]{ L"None", L"Top", L"Middle", L"Bottom" };
                    Combobox( L"Line ESP", &Settings::Character::LineESP, LineTypes, sizeof( LineTypes ) / sizeof( SDK::FString ) );
                }
                else if (MenuTab == 2)
                {
                    Checkbox( L"Pickup ESP", &Settings::Environment::Pickup );
                    Checkbox( L"Vehicle ESP", &Settings::Environment::Vehicle );
                    Checkbox( L"Vehicle Chams", &Settings::Environment::VehicleChams );
                    Checkbox( L"Building ESP", &Settings::Environment::Building );
                    Checkbox( L"Building Trap ESP", &Settings::Environment::BuildingTrap );
                    Checkbox( L"Drone/Chest/AmmoBox ESP", &Settings::Environment::Container );
                    Checkbox( L"Chest/AmmoBox/Safe Chams", &Settings::Environment::ContainerChams );
                    Checkbox( L"Storm Prediction ESP", &Settings::Environment::StormPrediction );
                    Checkbox( L"SupplyDrop/Llama ESP", &Settings::Environment::SupplyDrop );
                    Checkbox( L"Weakpoint Aimbot", &Settings::Environment::WeakpointAimbot );
                    Slider( L"Distance", 0.0, 200.0, &Settings::Environment::Distance );
                }
                else if (MenuTab == 3)
                {

                }
                else if (MenuTab == 4)
                {

                }
                else if (MenuTab == 5)
                {
                    //Checkbox( L"Debug Objects", &Settings::Environment::DebugObjects );
                    Checkbox( L"Controller Support", &Settings::Environment::ControllerSupport );
                    Checkbox( L"Hide Game Crosshair", &Settings::Miscellaneous::HideCrosshair );

                    SDK::FString CrosshairTypes[]{ L"None", L"Standard", L"Standard2", L"Dot", L"Warrior" };
                    Combobox( L"Crosshair", &Settings::Miscellaneous::Crosshair, CrosshairTypes, sizeof( CrosshairTypes ) / sizeof( SDK::FString ) );

                    SDK::FString ThemeTypes[]{ L"Pink", L"Orange", L"Light Blue", L"Purple", L"Red" };
                    Combobox( L"Theme", &Settings::Miscellaneous::Theme, ThemeTypes, sizeof( ThemeTypes ) / sizeof( SDK::FString ) );
                }

                this->Render.Rect( SDK::FVector2D( this->MousePosition.X - 4.0, this->MousePosition.Y - 4.0 ), SDK::FVector2D( 4.0, 4.0 ), SDK::FLinearColor( ).FromRGB( 6, 6, 6 ), 1.f, true, false, true );

                this->LastFrameTime = this->CurrentFrame;
            }
        }

        IsAllowedToRender = PlayerController->WasInputKeyJustPressed( SDK::Insert ) ? !IsAllowedToRender : IsAllowedToRender;

        this->Render.Tick( );

        return true;
    }
}