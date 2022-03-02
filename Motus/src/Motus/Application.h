#pragma once

#include "Core.h"
#include "Window.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "LayerStack.h"

namespace Motus {
	class MOTUS_API Application
	{
	public:
		Application();
		virtual ~Application();
		virtual void Run();
		virtual void Shutdown();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		void OnEvent(Event& event);

		inline static Application& Get() { return *m_Instance; };
		inline Window& GetWindow() { return *m_Window; }

	private: // Methods
		bool OnWindowClosed(WindowCloseEvent& event);
		bool m_IsRunning = true;

	private: // Data
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
	private:
		static Application* m_Instance;
	};

	Application* CreateApplication();
}
