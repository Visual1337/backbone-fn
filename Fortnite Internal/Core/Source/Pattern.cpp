#pragma once
#include <Core/Linkers/Pattern.h>

namespace Pattern
{
	auto Interface_t::Search( 
		uintptr_t Module, const char* Pattern, const char* Mask) -> unsigned char*
	{
		auto NTHeaders = Pattern::Interface_t::Sponge(Module);
		auto SizeOfModule = NTHeaders->OptionalHeader.SizeOfImage;

		for (int i = 0; i < SizeOfModule - strlen(Mask); i++)
		{
			auto Address = (unsigned char*)(Module + i);
			auto Range = (unsigned char*)SizeOfModule - Address;

			auto CheckMask = Pattern::Interface_t::CheckMask(Address, Pattern, Mask);
			if (!CheckMask) {
				continue;
			}

			if (Address)
			{
				return Address;
			}

			Address = Pattern::Interface_t::GetMask(Address, Range, Pattern, Mask);
			continue;
		}

		return nullptr;
	}

	auto Interface_t::GetMask(
		unsigned char* Address, DWORD Range, const char* Pattern, const char* Mask) -> unsigned char*
	{
		for (int i = 0; i < Range - strlen(Mask); i++)
		{
			auto CurrentAddress = (unsigned char*)(Address + i);
			auto CheckMask = Pattern::Interface_t::CheckMask(CurrentAddress, Pattern, Mask);
			if (CheckMask)
				return CurrentAddress;
		}

		return nullptr;
	}

	auto Interface_t::CheckMask(
		unsigned char* Address, const char* Pattern, const char* Mask) -> bool
	{
		for (; *Mask; Pattern++, Mask++, Address++) {
			if (*Mask == '?' || *Address == *(unsigned char*)(Pattern)) {
				continue;
			}

			return false;
		}

		return true;
	}

	auto Interface_t::Sponge(
		uintptr_t Module) -> PIMAGE_NT_HEADERS
	{
		return (PIMAGE_NT_HEADERS)((unsigned char*)Module + PIMAGE_DOS_HEADER(Module)->e_lfanew);
	}
}