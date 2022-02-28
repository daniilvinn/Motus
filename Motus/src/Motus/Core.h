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

#define MOTUS_NAMESPACE_BEGIN namespace Motus {
#define MOTUS_NAMESPACE_END }

#ifdef MT_DEBUG
	#ifndef MT_ENABLE_ASSERTS
		#define MT_ENABLE_ASSERTS
		#define MT_CORE_ASSERT(expression, ...) if(!(expression)){\
												MT_CORE_ERROR("Assertion failed: {}",__VA_ARGS__); __debugbreak();}\
												else{}
		#define MT_ASSERT(expression, ...)		if(!(expression)){\
												MT_CLIENT_ERROR("Assertion failed: {}",__VA_ARGS__); __debugbreak();}\
												else{}
	#endif
#else
	#define MT_CORE_ASSERT(expression, ...)
	#define MT_ASSERT(expression, ...)
#endif

#define BIT(x) (1 << x)