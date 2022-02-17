#pragma once

#ifdef MT_PLATFORM_WINDOWS
extern Motus::Application* Motus::CreateApplication();

// Entry Point
int main() {
	Motus::Logger::Init();
	MT_CORE_INFO("Logger initialized successfully.");

	Motus::Application* app = Motus::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error MOTUS_CORE::ERROR: Motus currently supports only Windows platform!
#endif