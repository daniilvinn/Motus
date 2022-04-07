#pragma once

// TODO: to be improved
#ifdef MT_PLATFORM_WINDOWS
	#ifdef MT_DYNAMIC
		#ifdef MOTUS_BUILD_DLL
			#define MOTUS_API __declspec(dllexport)
		#else
			#define MOTUS_API __declspec(dllimport)
		#endif
	#elif defined(MT_STATIC)
		#define MOTUS_API 
	#elif defined(MT_STATIC) && defined (MT_DYNAMIC)
		#error MOTUS_LINK::ERROR: Motus can't be linked both dynamically and statically!
	#else
		#error MOTUS::LINK::ERROR: MT_STATIC or MT_DYNAMIC macro must be defined!
	#endif
#else
	#error MOTUS_CORE::ERROR: Motus currently supports only Windows platform!
#endif

#define MOTUS_NAMESPACE_BEGIN namespace Motus {
#define MOTUS_NAMESPACE_END }

#if defined(MT_DEBUG) || defined(MT_RELEASE)
	#ifndef MT_ASSERTS_ENABLED
		#define MT_ASSERTS_ENABLED
		#ifdef MT_PLATFORM_WINDOWS
			#define MT_CORE_ASSERT(expression, ...) if(!(expression)){\
													MT_CORE_ERROR("Assertion failed: {}",__VA_ARGS__); __debugbreak();}\
													else{}
			#define MT_ASSERT(expression, ...)		if(!(expression)){\
													MT_CLIENT_ERROR("Assertion failed: {}",__VA_ARGS__); __debugbreak();}\
													else{}
		#endif
	#endif
#else
	#define MT_CORE_ASSERT(expression, ...)
	#define MT_ASSERT(expression, ...)
#endif

#define BIT(x) (1 << x)

// Thanks Yan TheCherno Chernikov for this macro <3
// https://github.com/TheCherno
#define MT_BIND_EVENT_FUNCTION(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
// --------------------------------------


#include <memory>

namespace Motus {
	template <typename T>
	using Scope = std::unique_ptr<T>;

	template <typename T>
	using Ref = std::shared_ptr<T>;

	template <typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template <typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}