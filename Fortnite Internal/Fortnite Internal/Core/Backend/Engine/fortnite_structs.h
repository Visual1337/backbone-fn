#pragma once

namespace SDK
{
	struct FRankedProgressReplicatedData
	{
	public:
		FString RankType;
		int32 Rank;
		uint8 Pad_1F5F[0x4];
	};

	enum class EFortRarity : uint8
	{
		Common = 0,
		Uncommon = 1,
		Rare = 2,
		Epic = 3,
		Legendary = 4,
		Mythic = 5,
		Transcendent = 6,
		Unattainable = 7,
		NumRarityValues = 8,
		EFortRarity_MAX = 9,
	};

	enum class EFortWeaponCoreAnimation : uint8
	{
		Melee = 0,
		Pistol = 1,
		Shotgun = 2,
		PaperBlueprint = 3,
		Rifle = 4,
		MeleeOneHand = 5,
		MachinePistol = 6,
		RocketLauncher = 7,
		GrenadeLauncher = 8,
		GoingCommando = 9,
		AssaultRifle = 10,
		TacticalShotgun = 11,
		SniperRifle = 12,
		TrapPlacement = 13,
		ShoulderLauncher = 14,
		AbilityDecoTool = 15,
		Crossbow = 16,
		C4 = 17,
		RemoteControl = 18,
		DualWield = 19,
		AR_BullPup = 20,
		AR_ForwardGrip = 21,
		MedPackPaddles = 22,
		SMG_P90 = 23,
		AR_DrumGun = 24,
		Consumable_Small = 25,
		Consumable_Large = 26,
		Balloon = 27,
		MountedTurret = 28,
		CreativeTool = 29,
		ExplosiveBow = 30,
		AshtonIndigo = 31,
		AshtonChicago = 32,
		MeleeDualWield = 33,
		Unarmed = 34,
		MAX = 35
	};
}