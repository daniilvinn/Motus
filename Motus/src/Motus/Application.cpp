#include "motus_pch.h"

#include "Application.h"
#include "Logger.h"

namespace Motus {
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() 
	{
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			m_Window->OnUpdate();
		}
	}
}