#pragma once

namespace SDK
{
	enum class EDrawDebugTrace : uint8
	{
		None = 0,
		ForOneFrame = 1,
		ForDuration = 2,
		Persistent = 3,
		EDrawDebugTrace_MAX = 4,
	};

	enum class EBlendMode : uint8_t
	{
		BLEND_Opaque = 0,
		BLEND_Masked = 1,
		BLEND_Translucent = 2,
		BLEND_Additive = 3,
		BLEND_Modulate = 4,
		BLEND_AlphaComposite = 5,
		BLEND_AlphaHoldout = 6,
		BLEND_TranslucentColoredTransmittance = 7,
		BLEND_TranslucentGreyTransmittance = 2,
		BLEND_ColoredTransmittanceOnly = 4
	};

	enum class ETraceTypeQuery : uint8
	{
		TraceTypeQuery1 = 0,
		TraceTypeQuery2 = 1,
		TraceTypeQuery3 = 2,
		TraceTypeQuery4 = 3,
		TraceTypeQuery5 = 4,
		TraceTypeQuery6 = 5,
		TraceTypeQuery7 = 6,
		TraceTypeQuery8 = 7,
		TraceTypeQuery9 = 8,
		TraceTypeQuery10 = 9,
		TraceTypeQuery11 = 10,
		TraceTypeQuery12 = 11,
		TraceTypeQuery13 = 12,
		TraceTypeQuery14 = 13,
		TraceTypeQuery15 = 14,
		TraceTypeQuery16 = 15,
		TraceTypeQuery17 = 16,
		TraceTypeQuery18 = 17,
		TraceTypeQuery19 = 18,
		TraceTypeQuery20 = 19,
		TraceTypeQuery21 = 20,
		TraceTypeQuery22 = 21,
		TraceTypeQuery23 = 22,
		TraceTypeQuery24 = 23,
		TraceTypeQuery25 = 24,
		TraceTypeQuery26 = 25,
		TraceTypeQuery27 = 26,
		TraceTypeQuery28 = 27,
		TraceTypeQuery29 = 28,
		TraceTypeQuery30 = 29,
		TraceTypeQuery31 = 30,
		TraceTypeQuery32 = 31,
		TraceTypeQuery_MAX = 32,
		ETraceTypeQuery_MAX = 33,
	};

	struct FHitResult
	{
		unsigned char UnknownData69[0x4]; // 0x00(0x04)
		int32_t FaceIndex; // 0x04(0x04)
		float Time; // 0x08(0x04)
		float Distance; // 0x0c(0x04)
		char pad_C[0x4]; // 0x10(0x04)
		struct FVector Location; // 0x14(0x18)
		struct FVector ImpactPoint; // 0x2c(0x18)
		struct FVector Normal; // 0x44(0x18)
		struct FVector ImpactNormal; // 0x5c(0x18)
		struct FVector TraceStart; // 0x74(0x18)
		struct FVector TraceEnd; // 0x8c(0x18)
		float PenetrationDepth; // 0xa4(0x04)
		int32_t MyItem; // 0xa8(0x04)
		int32_t Item; // 0xac(0x04)
		char ElementIndex; // 0xb0(0x01)
		char bBlockingHit : 1; // 0xb1(0x01)
		char bStartPenetrating : 1; // 0xb1(0x01)
		char pad_B1_2 : 6; // 0xb1(0x01)
		char pad_B2[0x2]; // 0xb2(0x02)
		void* PhysMaterial; // 0xb4(0x08)
		void* HitObjectHandle; // 0xbc(0x20)
		void* Component; // 0xdc(0x08)
		char pad_E4[0xC]; // 0xe4(0x0c)
		struct FName BoneName; // 0xf0(0x04)
		struct FName MyBoneName; // 0xf4(0x04)
	};
}