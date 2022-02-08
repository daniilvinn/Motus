#pragma once

#ifdef MT_PLATFORM_WINDOWS
	#ifdef MOTUS_BUILD_DLL
		#define MOTUS_API __declspec(dllexport)
	#else
		#define MOTUS_API __declspec(dllimport)
	#endif 
#else
	#error MOTUS_CORE::ERROR: Motus currently supports only Windows platform!
#endif