#include "motus_pch.h"

#include "Application.h"
#include "Logger.h"
#include <GLFW/glfw3.h>

#define BIND_EVENT_FUNCTION(func) std::bind(&func, this, std::placeholders::_1)

namespace Motus {
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create(WindowProperties()));

		m_Window->SetEventCallbackFunc(BIND_EVENT_FUNCTION(Application::OnEvent));

	}

	Application::~Application() 
	{
		glfwTerminate();
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(Application::OnWindowClosed));
#ifdef MT_TRACE_EVENTS
		MT_CORE_TRACE(event.GetLogInfo());
#endif
		return true;
	}
	bool Application::OnWindowClosed(WindowCloseEvent& event)
	{
		m_IsRunning = false;
		return true;
	}
}