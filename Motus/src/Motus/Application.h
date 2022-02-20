#pragma once

#include "Core.h"
#include "Window.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Motus {
	class MOTUS_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		bool OnEvent(Event& event);

	private: // Methods
		bool OnWindowClosed(WindowCloseEvent& event);
		bool m_IsRunning = true;

	private: // Data
		std::unique_ptr<Window> m_Window;
	};

	Application* CreateApplication();
}
