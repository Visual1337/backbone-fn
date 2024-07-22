#pragma once
#include <Core/Linkers/Hook.h>

using namespace Globals;

namespace Hook
{

	auto ShadowVMT::Allocate(
		int AllocationSize, uint32 Alignment) -> uintptr_t*
	{
		static void* Address = nullptr;
		if (!Address) {
			Address = m_pattern_scan.Get( )->Search(Module, "\x48\x89\x5C\x24\x00\x55\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x83\xEC\x00\x4C\x8B\x25\x00\x00\x00\x00\x33\xED", "xxxx?xxxxxxxxxxxxxx?xxx????xx");
		}

		return reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t(__cdecl*)(uintptr_t, int)>(Address)(AllocationSize, Alignment));
	}

	auto ShadowVMT::GetAllocationSize(
		uintptr_t* VirtualTable) -> int
	{
		int VirtualIndex = 0;
		for (;; VirtualIndex++)
		{
			auto VirtualFunction = VirtualTable[VirtualIndex];
			if (VirtualFunction)
				continue;

			return VirtualIndex;
		}
	}

	auto ShadowVMT::IsAlreadyHooked(
		uintptr_t Function, int VirtualIndex) const -> bool
	{
		if (this->LastHookedFunction == Function || this->LastHookedVirtualIndex == VirtualIndex) {
			return true;
		}

		return false;
	}

	auto ShadowVMT::ApplyContext(
		uintptr_t Function, int VirtualIndex) -> void
	{
		this->LastHookedFunction = Function;
		this->LastHookedVirtualIndex = VirtualIndex;
	}
}