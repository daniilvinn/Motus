#pragma once
#include "Base.h"
#include <spdlog/spdlog.h>
#include <memory>

// Logger Class Definition
namespace Motus {
	class MOTUS_API Logger
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Log macros definitions are available if Motus is on Debug build.
#ifdef MT_DEBUG
	#define MT_CORE_FATAL(...)		Motus::Logger::GetCoreLogger()->critical(__VA_ARGS__)
	#define MT_CORE_ERROR(...)		Motus::Logger::GetCoreLogger()->error(__VA_ARGS__)
	#define MT_CORE_WARN(...)		Motus::Logger::GetCoreLogger()->warn(__VA_ARGS__)
	#define MT_CORE_INFO(...)		Motus::Logger::GetCoreLogger()->info(__VA_ARGS__)
	#define MT_CORE_TRACE(...)		Motus::Logger::GetCoreLogger()->trace(__VA_ARGS__)

	#define MT_CLIENT_FATAL(...)	Motus::Logger::GetClientLogger()->critical(__VA_ARGS__)
	#define MT_CLIENT_ERROR(...)	Motus::Logger::GetClientLogger()->error(__VA_ARGS__)
	#define MT_CLIENT_WARN(...)		Motus::Logger::GetClientLogger()->warn(__VA_ARGS__)
	#define MT_CLIENT_INFO(...)		Motus::Logger::GetClientLogger()->info(__VA_ARGS__)
	#define MT_CLIENT_TRACE(...)	Motus::Logger::GetClientLogger()->trace(__VA_ARGS__)
// If it is not, macros do basically nothing
#else
	#define MT_CORE_FATAL
	#define MT_CORE_ERROR
	#define MT_CORE_WARN
	#define MT_CORE_INFO
	#define MT_CORE_TRACE

	#define MT_CLIENT_FATAL
	#define MT_CLIENT_ERROR
	#define MT_CLIENT_WARN
	#define MT_CLIENT_INFO
	#define MT_CLIENT_TRACE
#endif