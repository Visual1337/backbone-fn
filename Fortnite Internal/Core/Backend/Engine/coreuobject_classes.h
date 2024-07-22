#pragma once
#include <Core/Linkers/Pattern.h>
#include <Core/Backend/Engine/coreuobject_structs.h>

namespace SDK
{
	class UObject;
	class UWorld;
	class UFunction;

	class TUObjectArray
	{
	public:
		enum
		{
			ElementsPerChunk = 0x10000,
		};
	public:
		struct FUObjectItem
		{
			class UObject* Object;
			uint8_t Pad[0x10];
		};

		FUObjectItem** Objects;
		uint8_t Pad_0[0x08];
		uint32_t MaxElements;
		uint32_t NumElements;
		uint32_t MaxChunks;
		uint32_t NumChunks;

		auto GetByIndex( const uint32_t Index ) const -> UObject*;
	};

	class UObject
	{
	public:
		UObject( ) { }
		~UObject( ) { }

	public:
		FName NamePrivate( )
		{
			return *(FName*)(this + 0x18);
		}

	public:
		auto ProcessEvent( UFunction* Function, void* Parameters ) -> void;
		static auto StaticFindObject( UObject* Class, UObject* Outer, const wchar_t* Name, bool ExactClass ) -> UObject*;

		template <typename T>
		static auto FindObject(
			const wchar_t* Name, UObject* Outer = nullptr) -> T*
		{
			return reinterpret_cast<T*>(UObject::StaticFindObject(nullptr, Outer, Name, false));
		}

	};

	class UFunction : public UObject
	{
	public:
		using UObject::UObject;
		UFunction( ) { }
		~UFunction( ) { }

	public:

	};
}