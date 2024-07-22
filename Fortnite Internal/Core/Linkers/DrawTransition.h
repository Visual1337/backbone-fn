#pragma once
#include <Core/Backend/Layout/Imports.h>
#include <Core/Linkers/Engine.h>

#include <Core/Linkers/Hook.h>
#include <Core/Linkers/Fortnite.h>
#include <Core/Linkers/Settings.h>

using namespace Globals;
using namespace SDK;
using namespace Fortnite;

namespace DrawTransition
{
	inline void (*DrawTransitionOriginal)(SDK::UGameViewportClient*, SDK::UCanvas*);
	void DrawTransition(SDK::UGameViewportClient* ViewportClient, SDK::UCanvas* Canvas);

	inline Hook::ShadowVMT m_draw_transition = Hook::ShadowVMT( );
}