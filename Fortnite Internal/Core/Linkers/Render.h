#pragma once
#include <Core/Linkers/Engine.h>

namespace Render
{
	struct DrawListMember
	{
		int DrawType;

		SDK::FString Content;

		SDK::FVector2D PositionA, PositionB;
		SDK::FLinearColor Color;

		float Thickness;

		double Radius;
		double Segments;
		bool Filled;

		bool Rounded;
		bool Outlined;
		bool CenteredX;
		bool CenteredY;
	};
	
	class RenderHandler_t
	{
	public:
		RenderHandler_t() { }
		~RenderHandler_t() { }

	public:
		auto Init( ) -> void;

	public:
		auto Line( SDK::FVector2D ScreenPositionA, SDK::FVector2D ScreenPositionB, SDK::FLinearColor RenderColor, float Thickness ) -> void;
		auto Rect( SDK::FVector2D ScreenPosition, SDK::FVector2D Size, SDK::FLinearColor RenderColor, float Thickness, bool Filled, bool Rounded ) -> void;
		auto Text( SDK::FString Content, SDK::FVector2D Position, SDK::FLinearColor RenderColor, bool CenteredX, bool CenteredY, bool Outlined ) -> void;
		auto Circle( SDK::FVector2D ScreenPosition, SDK::FLinearColor RenderColor, double Radius, double Segments ) -> void;

	public:
		SDK::UCanvas* Canvas = nullptr;
		SDK::UFont* RenderFont = nullptr;

		bool Initialized = false;

	};

	class RenderHandler : public RenderHandler_t
	{
	public:
		using RenderHandler_t::RenderHandler_t;
		RenderHandler( ) { }
		~RenderHandler() { }

	public:
		auto Tick( ) -> void;
		auto Setup( SDK::UCanvas* Canvas ) -> void;

	public:
		auto Line( SDK::FVector2D PositionA, SDK::FVector2D PositionB, SDK::FLinearColor RenderColor, float Thickness, bool ForceForeground ) -> void;
		auto Rect( SDK::FVector2D ScreenPosition, SDK::FVector2D Size, SDK::FLinearColor RenderColor, float Thickness, bool Filled, bool Rounded, bool ForceForeground ) -> void;
		auto Text( SDK::FString Content, SDK::FVector2D Position, SDK::FLinearColor RenderColor, bool CenteredX, bool CenteredY, bool Outlined, bool ForceForeground ) -> void;
		auto Circle( SDK::FVector2D Position, SDK::FLinearColor RenderColor, double Radius, double Segments, bool ForceForeground ) -> void;

	private:
		auto ClearTargets( ) -> void;
		auto IsSafeToRender( ) const -> bool;

	private:
		int LastForegroundIndex = 0;
		DrawListMember ForegroundDrawList[9999];

		int LastDefaultIndex = 0;
		DrawListMember DefaultDrawList[9999];

	};
}