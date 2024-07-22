#pragma once
#include <Core/Backend/Layout/Imports.h>
#include <Core/Linkers/Pattern.h>

namespace Hook
{
	enum class Status : int
	{
		UnknownFailure,
		Success,
		AlreadyHooked,
		NotContained,
	};

	class ShadowVMT
	{
	public:
		ShadowVMT( ) {  }
		~ShadowVMT( ) { }

	public:
		template < typename Type >
		auto Swap(
			void* Address, int VirtualIndex, void* Function, Type* Original ) -> Hook::Status
		{
			auto VirtualTable = *(uintptr_t**)(Address);

			auto AllocationSize = Hook::ShadowVMT::GetAllocationSize( VirtualTable );
			if (AllocationSize <= VirtualIndex)
			{
				return Hook::Status::NotContained;
			}

			auto VirtualFunction = VirtualTable[VirtualIndex];
			auto IsAlreadyHooked = Hook::ShadowVMT::IsAlreadyHooked( VirtualFunction, VirtualIndex );
			if (IsAlreadyHooked)
			{
				return Hook::Status::AlreadyHooked;
			}

			*Original = reinterpret_cast<Type>(VirtualFunction);

			auto AllocationBase = reinterpret_cast<uintptr_t*>(new uintptr_t[AllocationSize]);
			for (int Index = 0; Index < AllocationSize; Index++)
			{
				AllocationBase[Index] = VirtualTable[Index]; // (Index == VirtualIndex) ? reinterpret_cast<uintptr_t>(Function) :
			}

			AllocationBase[VirtualIndex] = reinterpret_cast<uintptr_t>(Function);

			*(uintptr_t**)(Address) = AllocationBase;

			Hook::ShadowVMT::ApplyContext( VirtualFunction, VirtualIndex );

			return Hook::Status::Success;
		}

		template < typename Type >
		auto Revert(
			void* Address, Type* Original ) -> Hook::Status
		{
			auto VirtualTable = *(uintptr_t**)(Address);

			auto FoundFunction = ShadowVMT::IsAlreadyHooked( this->LastHookedFunction, this->LastHookedVirtualIndex );
			if (!FoundFunction)
				return Hook::Status::NotContained;

			VirtualTable[this->LastHookedVirtualIndex] = reinterpret_cast<uintptr_t>(*Original);

			*(uintptr_t**)(Address) = VirtualTable;

			Hook::ShadowVMT::ApplyContext( uintptr_t( 0 ), 0 );

			return Hook::Status::Success;
		}

	private:
		auto GetAllocationSize( uintptr_t* VTable ) -> int;

		auto IsAlreadyHooked( uintptr_t Function, int Index ) const -> bool;

	private:
		auto ApplyContext( uintptr_t Function, int VirtualIndex ) -> void;

		auto Allocate( int AllocationSize, uint32 Aligment ) -> uintptr_t*;

	private:
		uintptr_t LastHookedFunction = uintptr_t( 0 );
		int LastHookedVirtualIndex = 0;
	};
}