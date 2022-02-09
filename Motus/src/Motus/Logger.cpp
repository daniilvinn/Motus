#include "Logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Motus {
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

	void Logger::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		
		s_CoreLogger = spdlog::stdout_color_mt("MOTUS");
		s_ClientLogger = spdlog::stdout_color_mt("APPLICATION");

		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}