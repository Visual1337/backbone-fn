#pragma once
#include <Core/Linkers/Render.h>

namespace Render
{
	auto RenderHandler_t::Init( ) -> void
	{
		if (!this->Initialized)
		{
			this->RenderFont = SDK::UObject::FindObject<SDK::UFont>( L"Engine/EngineFonts/Roboto.Roboto", reinterpret_cast<SDK::UObject*>(-1) );

			this->Initialized = true;
		}
	}

	auto RenderHandler::Setup( SDK::UCanvas* Canvas ) -> void
	{
		Render::RenderHandler_t::Init( );

		this->Canvas = Canvas;
	}

	auto RenderHandler_t::Line( SDK::FVector2D ScreenPositionA, SDK::FVector2D ScreenPositionB, SDK::FLinearColor RenderColor, float Thickness ) -> void
	{
		this->Canvas->K2_DrawLine( ScreenPositionA, ScreenPositionB, Thickness, RenderColor );
	}

	auto RenderHandler_t::Rect( SDK::FVector2D ScreenPosition, SDK::FVector2D Size, SDK::FLinearColor RenderColor, float Thickness, bool Filled, bool Rounded ) -> void
	{
		auto RectFilled( [&]( SDK::FVector2D Position, SDK::FVector2D Size, SDK::FLinearColor RenderColor, float Thickness ){
			for (double i = 0; i < Size.Y; i++)
			{
				this->Canvas->K2_DrawLine( SDK::FVector2D( Position.X, Position.Y + i ), SDK::FVector2D( Position.X + Size.X, Position.Y + i ), Thickness, RenderColor );
			} } );

		if (Rounded)
		{
			auto Rounding = 7.0;

			if (Filled)
			{
				RectFilled( SDK::FVector2D( ScreenPosition.X + Rounding, ScreenPosition.Y ), SDK::FVector2D( Size.X - (Rounding * 2.0), Size.Y ), RenderColor, Thickness );
				RectFilled( SDK::FVector2D( ScreenPosition.X, ScreenPosition.Y + Rounding ), SDK::FVector2D( Size.X, Size.Y - (Rounding * 2.0) ), RenderColor, Thickness );
			}

			auto Diamond( [&]( SDK::FVector2D ScreenPosition, SDK::FVector2D Radius, SDK::FLinearColor RenderColor ){
				SDK::FVector2D DiamondPoints[4];
				DiamondPoints[0] = { ScreenPosition.X, ScreenPosition.Y - Radius.Y };
				DiamondPoints[1] = { ScreenPosition.X + Radius.X, ScreenPosition.Y };
				DiamondPoints[2] = { ScreenPosition.X, ScreenPosition.Y + Radius.Y };
				DiamondPoints[3] = { ScreenPosition.X - Radius.X, ScreenPosition.Y };

				this->Canvas->K2_DrawPolygon( nullptr, DiamondPoints[0], Radius, 4, RenderColor ); 
				} );

			Diamond( SDK::FVector2D( ScreenPosition.X + Rounding - 2.0, ScreenPosition.Y + Rounding + 3.0 ), SDK::FVector2D( Rounding - 1.0, Rounding - 2.0 ), RenderColor );
			Diamond( SDK::FVector2D( ScreenPosition.X + Size.X - Rounding + 1.0, ScreenPosition.Y + Rounding + 3.0 ), SDK::FVector2D( Rounding - 1.0, Rounding - 2.0 ), RenderColor );
			Diamond( SDK::FVector2D( ScreenPosition.X + Rounding - 2.0, ScreenPosition.Y + Size.Y - Rounding + 5.0 ), SDK::FVector2D( Rounding - 1.0, Rounding - 2.0 ), RenderColor );
			Diamond( SDK::FVector2D( ScreenPosition.X + Size.X - Rounding + 1.0, ScreenPosition.Y + Size.Y - Rounding + 5.0 ), SDK::FVector2D( Rounding - 1.0, Rounding - 2.0 ), RenderColor );
		}
		else if (Filled)
		{
			RectFilled( ScreenPosition, Size, RenderColor, Thickness );
		}
		else
		{
			Render::RenderHandler_t::Line( SDK::FVector2D( ScreenPosition.X, ScreenPosition.Y ), SDK::FVector2D( ScreenPosition.X + Size.X, ScreenPosition.Y ), RenderColor, Thickness );
			Render::RenderHandler_t::Line( SDK::FVector2D( ScreenPosition.X + Size.X, ScreenPosition.Y ), SDK::FVector2D( ScreenPosition.X + Size.X, ScreenPosition.Y + Size.Y ), RenderColor, Thickness );
			Render::RenderHandler_t::Line( SDK::FVector2D( ScreenPosition.X + Size.X, ScreenPosition.Y + Size.Y ), SDK::FVector2D( ScreenPosition.X, ScreenPosition.Y + Size.Y ), RenderColor, Thickness );
			Render::RenderHandler_t::Line( SDK::FVector2D( ScreenPosition.X, ScreenPosition.Y + Size.Y ), SDK::FVector2D( ScreenPosition.X, ScreenPosition.Y ), RenderColor, Thickness );
		}
	}
	 
	auto RenderHandler_t::Text( SDK::FString Content, SDK::FVector2D Position, SDK::FLinearColor RenderColor, bool CenteredX , bool CenteredY , bool Outlined ) -> void
	{
		this->Canvas->K2_DrawText( this->RenderFont, Content, Position, SDK::FVector2D( 1.0, 1.0 ), RenderColor, SDK::FLinearColor( ), SDK::FVector2D( ), CenteredX, CenteredY, Outlined, SDK::FLinearColor( 0.004f, 0.004f, 0.004f, 1.f ) );
	}

	auto RenderHandler_t::Circle( SDK::FVector2D ScreenPosition, SDK::FLinearColor RenderColor, double Radius, double Segments ) -> void
	{
		double Step = M_PI * 2.0 / Segments;
		int Count = 0;
		SDK::FVector2D Vectors[128];

		for (double Degree = 0; Degree < M_PI * 2.0; Degree += Step)
		{
			double X_1 = Radius * SDK::MathLibrary->Cos( Degree ) + ScreenPosition.X;
			double Y_1 = Radius * SDK::MathLibrary->Sin( Degree ) + ScreenPosition.Y;
			double X_2 = Radius * SDK::MathLibrary->Cos( Degree + Step ) + ScreenPosition.X;
			double Y_2 = Radius * SDK::MathLibrary->Sin( Degree + Step ) + ScreenPosition.Y;

			Vectors[Count].X = X_1;
			Vectors[Count].Y = Y_1;
			Vectors[Count + 1].X = X_2;
			Vectors[Count + 1].Y = Y_2;

			Render::RenderHandler_t::Line( SDK::FVector2D( Vectors[Count].X, Vectors[Count].Y ), SDK::FVector2D( X_2, Y_2 ), RenderColor, 1.f );
		}
	}

	auto RenderHandler::Tick( ) -> void
	{
		bool IsSafeToRender = Render::RenderHandler::IsSafeToRender( );
		if (IsSafeToRender)
		{
			for (int i = 0; i < this->LastDefaultIndex; i++)
			{
				DrawListMember Member = DefaultDrawList[i];

				if (Member.DrawType == 1)
				{
					Render::RenderHandler_t::Line( Member.PositionA, Member.PositionB, Member.Color, Member.Thickness );
				}
				else if (Member.DrawType == 2)
				{
					Render::RenderHandler_t::Rect( Member.PositionA, Member.PositionB, Member.Color, Member.Thickness, Member.Filled, Member.Rounded );
				}
				else if (Member.DrawType == 3)
				{
					Render::RenderHandler_t::Text( Member.Content, Member.PositionA, Member.Color, false, false, Member.Outlined );
				}
				else if (Member.DrawType == 4)
				{
					Render::RenderHandler_t::Circle( Member.PositionA, Member.Color, Member.Radius, Member.Segments );
				}
			}

			for (int i = 0; i < this->LastForegroundIndex; i++)
			{
				DrawListMember Member = ForegroundDrawList[i];

				if (Member.DrawType == 1)
				{
					Render::RenderHandler_t::Line( Member.PositionA, Member.PositionB, Member.Color, Member.Thickness );
				}
				else if (Member.DrawType == 2)
				{
					Render::RenderHandler_t::Rect( Member.PositionA, Member.PositionB, Member.Color, Member.Thickness, Member.Filled, Member.Rounded );
				}
				else if (Member.DrawType == 3)
				{
					Render::RenderHandler_t::Text( Member.Content, Member.PositionA, Member.Color, false, false, Member.Outlined );
				}
				else if (Member.DrawType == 4)
				{
					Render::RenderHandler_t::Circle( Member.PositionA, Member.Color, Member.Radius, Member.Segments );
				}
			}

			Render::RenderHandler::ClearTargets( );
		}
	}

	auto RenderHandler::Line( SDK::FVector2D PositionA, SDK::FVector2D PositionB, SDK::FLinearColor RenderColor, float Thickness, bool ForceForeground ) -> void
	{
		DrawListMember Member;

		Member.DrawType = 1;
		Member.PositionA = PositionA;
		Member.PositionB = PositionB;
		Member.Color = RenderColor;
		Member.Thickness = Thickness;

		if (ForceForeground)
		{
			ForegroundDrawList[LastForegroundIndex] = Member;
			LastForegroundIndex += 1;
		}
		else
		{
			DefaultDrawList[LastDefaultIndex] = Member;
			LastDefaultIndex += 1;
		}
	}

	auto RenderHandler::IsSafeToRender( ) const -> bool
	{
		if (this->RenderFont && this->Initialized)
			return true;
		return false;
	}

	auto RenderHandler::ClearTargets( ) -> void
	{
		this->LastForegroundIndex = 0;
		this->LastDefaultIndex = 0;
	}

	auto RenderHandler::Rect( SDK::FVector2D PositionA, SDK::FVector2D PositionB, SDK::FLinearColor RenderColor, float Thickness, bool Filled, bool Rounded, bool ForceForeground) -> void
	{
		DrawListMember Member;

		Member.DrawType = 2;
		Member.PositionA = PositionA;
		Member.PositionB = PositionB;
		Member.Color = RenderColor;
		Member.Thickness = Thickness;
		Member.Rounded = Rounded;
		Member.Filled = Filled;

		if (ForceForeground)
		{
			ForegroundDrawList[LastForegroundIndex] = Member;
			LastForegroundIndex += 1;
		}
		else
		{
			DefaultDrawList[LastDefaultIndex] = Member;
			LastDefaultIndex += 1;
		}
	}

	auto RenderHandler::Text( SDK::FString Content, SDK::FVector2D Position, SDK::FLinearColor RenderColor, bool CenteredX, bool CenteredY, bool Outlined, bool ForceForeground ) -> void
	{
		DrawListMember Member;

		Member.DrawType = 3;
		Member.Content = Content;
		Member.PositionA = Position;
		Member.Color = RenderColor;
		Member.CenteredX = CenteredX;
		Member.CenteredY = CenteredY;
		Member.Outlined = Outlined;

		if (ForceForeground)
		{
			ForegroundDrawList[LastForegroundIndex] = Member;
			LastForegroundIndex += 1;
		}
		else
		{
			DefaultDrawList[LastDefaultIndex] = Member;
			LastDefaultIndex += 1;
		}
	}

	auto RenderHandler::Circle( SDK::FVector2D Position, SDK::FLinearColor RenderColor, double Radius, double Segments, bool ForceForeground ) -> void
	{
		DrawListMember Member;

		Member.DrawType = 4;
		Member.PositionA = Position;
		Member.Color = RenderColor;
		Member.Radius = Radius;
		Member.Segments = Segments;

		if (ForceForeground)
		{
			ForegroundDrawList[LastForegroundIndex] = Member;
			LastForegroundIndex += 1;
		}
		else
		{
			DefaultDrawList[LastDefaultIndex] = Member;
			LastDefaultIndex += 1;
		}
	}
}