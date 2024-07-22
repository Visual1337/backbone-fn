#pragma once
#include <Core/Backend/Layout/Imports.h>
#include <Core/Linkers/DrawTransition.h>
#include <fstream>
#include <ostream>
#include <string>

bool DllMain( void* hModule, int  ul_reason_for_call, void* lpReserved )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH )
    {
       MessageBoxA( 0, 0, 0, 0 );
       Globals::Module = reinterpret_cast<uintptr_t>(GetModuleHandleA(0));

       auto Frontend = SDK::UObject::FindObject<SDK::UWorld>( L"Frontend", reinterpret_cast<SDK::UObject*>(-1) );
       auto OwningGameInstance = Frontend->OwningGameInstance( );
       auto LocalPlayer = OwningGameInstance->LocalPlayers( )[0];
       auto ViewportClient = LocalPlayer->ViewportClient( );
       auto PlayerController = LocalPlayer->PlayerController( );

       DrawTransition::m_draw_transition.Swap(ViewportClient, 114, DrawTransition::DrawTransition, &DrawTransition::DrawTransitionOriginal);
    }

    return true;
}