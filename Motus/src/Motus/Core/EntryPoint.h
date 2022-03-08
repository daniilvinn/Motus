#pragma once

#ifdef MT_PLATFORM_WINDOWS
extern Motus::Application* Motus::CreateApplication();

// Entry Point
int main() {
	Motus::Logger::Init();

	Motus::Application* Application = Motus::CreateApplication();
	Application->Run();
	Application->Shutdown();

	delete Application;
}
#else
	#error MOTUS_CORE::ERROR: Motus currently supports only Windows platform!
#endif