#pragma once
#include <Core/Backend/Layout/Imports.h>
#include <Core/Linkers/Engine.h>
#include <Core/Linkers/Hook.h>
#include <Core/Linkers/Fortnite.h>

using namespace Globals;
using namespace SDK;
using namespace Fortnite;

namespace Debug
{
	namespace ProcessEvent
	{
		inline void (*ProcessEventOriginal)(SDK::UObject*, SDK::UFunction*, void*) = nullptr;
		void ProcessEvent( SDK::UObject* Object, SDK::UFunction* Function, void* Parameters );

		inline Hook::ShadowVMT m_process_event = Hook::ShadowVMT();
	}
}