#include "motus_pch.h"

#include "Application.h"
#include "Motus/Events/KeyEvent.h"
#include "Logger.h"

namespace Motus {
	Application::Application() 
	{
		MT_CLIENT_INFO("Application created successfully.");
	}

	Application::~Application() 
	{
	}

	void Application::Run()
	{

		KeyPressedEvent e(56, 0);
		MT_CORE_TRACE(e.GetLogInfo().c_str());

		while (true)
		{

		}
	}
}