#pragma once
#include <Core/Backend/Layout/Imports.h>

#define RVA(Address, Size) ((uintptr_t)((UINT_PTR)(Address) + *(PINT)((UINT_PTR)(Address) + ((Size) - sizeof(INT))) + (Size)))

namespace Pattern
{
	class Interface_t
	{
	public:
		Interface_t( ) { }
		~Interface_t( ) { }

	public:
		auto Search(uintptr_t Module, const char* Pattern, const char* Mask) -> unsigned char*;

	public:
		auto CheckMask(unsigned char* Address, const char* Pattern, const char* Mask) -> bool;

		auto GetMask(unsigned char* Start, DWORD Range, const char* Pattern, const char* Mask) -> unsigned char*;

	public:
		auto Sponge(uintptr_t Module) -> PIMAGE_NT_HEADERS;
	};

	class PatternInterface : public Interface_t
	{
	public:
		using Interface_t::Interface_t;
		PatternInterface( ) { }
		~PatternInterface( ) { }

	public:
		auto Get( ) -> Interface_t*
		{
			return reinterpret_cast<Interface_t*>(this);
		}

	};
}

inline Pattern::PatternInterface m_pattern_scan = Pattern::PatternInterface( );