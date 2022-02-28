#include "motus_pch.h"

#include "Application.h"
#include "Logger.h"
#include <GLFW/glfw3.h>

//#define BIND_EVENT_FUNCTION(func) std::bind(&func, this, std::placeholders::_1)

// Thanks Yan TheCherno Chernikov for this macro <3
// https://github.com/TheCherno
#define BIND_EVENT_FUNCTION(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
// --------------------------------------

namespace Motus {
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create(WindowProperties()));

		m_Window->SetEventCallbackFunc(BIND_EVENT_FUNCTION(Application::OnEvent));

	}

	Application::~Application() 
	{
		
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			m_Window->OnUpdate();

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

		}
	}

	void Application::Shutdown()
	{
		glfwTerminate();
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(Application::OnWindowClosed));
#ifdef MT_TRACE_EVENTS
		MT_CORE_TRACE(event.GetLogInfo());
#endif

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(event);
			if (event.m_IsHandled) 
				break;
		}

	}
	bool Application::OnWindowClosed(WindowCloseEvent& event)
	{
		m_IsRunning = false;
		return true;
	}
}