#pragma once

namespace Settings
{
	namespace Aimbot
	{
		inline bool Active = true;
		inline bool TriggerBot = false;
		inline bool AimPrediction = true;
		inline bool TargetLine = true;
		inline bool DrawFOV = true;
		inline bool IgnoreBots = false;
		inline bool IgnoreKnocked = true;
		inline bool IgnoreNonVisble = false;
		inline int Smooth = 1;
		inline double FieldOfView = 80.0;
		inline double Smoothing = 10.0;
		inline double Distance = 100.0;
		inline int AimBone = 0;
		inline int KeyType = 0;

	}

	namespace Character
	{
		inline bool Active = true;
		inline int BoxESP = 1;
		inline int LineESP = 0;
		inline bool CornerESP = false;
		inline bool FilledESP = false;
		inline bool SkeletonESP = true;
		inline bool OnlyBehindWalls = true;
		inline bool DisplayName = true;
		inline bool Distance = true;
		inline bool ActiveWeapon = true;
		inline bool OOFArrows = true;
		inline bool SpecatorESP = false;
		inline bool InventoryESP = false;
		inline bool EyeDirection = false;
		inline bool RankedESP = false;
	}

	namespace Environment
	{
		inline bool Pickup = true;
		inline int MinimumTier = 0;
		inline bool Vehicle = true;
		inline bool VehicleChams = false;
		inline bool Building = true;
		inline bool BuildingTrap = false;
		inline bool WeakpointAimbot = true;
		inline bool SupplyDrop = false;
		inline bool Container = true;
		inline bool ContainerChams = false;
		inline bool DebugObjects = false;
		inline bool ControllerSupport = false;
		inline bool StormPrediction = false;
		inline double Distance = 150.0;
	}

	namespace SkinChanger
	{
		inline bool Active = false;
	}

	namespace Exploits
	{

	}

	namespace Miscellaneous
	{
		inline bool HideCrosshair = true;

		inline int Crosshair = 1;
		inline int Theme = 0;
	}
}