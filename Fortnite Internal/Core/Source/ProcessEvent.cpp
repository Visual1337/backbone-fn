#pragma once
#include <Core/Linkers/ProcessEvent.h>

namespace Debug
{
	auto ProcessEvent::ProcessEvent(
		SDK::UObject* ClassObject, SDK::UFunction* Function, void* Parameters ) -> void
	{
		auto ObjectName = SDK::SystemLibrary->GetObjectName( Function );

		int bufferSize = WideCharToMultiByte( CP_ACP, 0, ObjectName.c_str( ), -1, NULL, 0, NULL, NULL );
		char* multiByteStr = new char[bufferSize];
		WideCharToMultiByte( CP_ACP, 0, ObjectName.c_str( ), -1, multiByteStr, bufferSize, NULL, NULL );
		MessageBoxA( 0, multiByteStr, 0, 0 );
		delete[] multiByteStr;

		//if (SDK::StringLibrary->Contains( ObjectName, FString( L"GetHUD" ), true, false ))
		//{
		//	MessageBoxA( 0, "ProcessEvent::MyHUD::ProcessEvent", 0, 0 );

		//	auto PlayerController = reinterpret_cast<SDK::APlayerController*>(ClassObject);

		//	struct
		//	{
		//		SDK::AHUD* ReturnValue;
		//	} *Params = reinterpret_cast<decltype(Params)>(Parameters);

		//}

		ProcessEvent::ProcessEventOriginal( ClassObject, Function, Parameters );
	}
}