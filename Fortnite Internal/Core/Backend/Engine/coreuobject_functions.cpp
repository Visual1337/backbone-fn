#pragma once
#include <Core/Backend/Engine/coreuobject_classes.h>

namespace SDK
{
	auto TUObjectArray::GetByIndex( const uint32_t Index ) const -> UObject*
	{
		if (Index < 0 || Index > this->NumElements)
			return nullptr;

		const uint32_t ChunkIndex = Index / ElementsPerChunk;
		const uint32_t InChunkIdx = Index % ElementsPerChunk;

		return this->Objects[ChunkIndex][InChunkIdx].Object;
	}

	auto UObject::ProcessEvent( UFunction* Function, void* Parameters) -> void
	{
		if (auto VTable = *(void***)(this))
		{
			reinterpret_cast<void( __fastcall* )(UObject*, UObject*, void*)>(VTable[78])(this, Function, Parameters);
		}
	}

	auto UObject::StaticFindObject( UObject* Class, UObject* Outer, const wchar_t* Name, bool ExactClass) -> UObject*
	{
		static void* Address = nullptr;
		if (!Address)
		{
			Address = m_pattern_scan.Get( )->Search(Globals::Module, "\x48\x89\x5C\x24\x00\x55\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\xAC\x24\x00\x00\x00\x00\x48\x81\xEC\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00\x48\x33\xC4\x48\x89\x85\x00\x00\x00\x00\x48\x83\xFA", "xxxx?xxxxxxxxxxxxxxx????xxx????xxx????xxxxxx????xxx");
		}

		return reinterpret_cast<UObject * (__fastcall*)(UObject*, UObject*, const wchar_t*, bool)>(Address)(Class, Outer, Name, ExactClass);
	}
}