#pragma once
#include <Core/Linkers/DrawTransition.h>

void DrawTransition::DrawTransition(
	SDK::UGameViewportClient* ViewportClient, SDK::UCanvas* Canvas)
{
	auto Handler = m_fortnite_handler.Get( );
	{
		Handler->Initialize( );
		bool IsSafeToRender = Handler->IsSafeToRender( );
		if (!IsSafeToRender) 
			return DrawTransition::DrawTransitionOriginal(ViewportClient, Canvas);
	}

	Handler->Main(ViewportClient, Canvas);

	return DrawTransition::DrawTransitionOriginal(ViewportClient, Canvas);
}