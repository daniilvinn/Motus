#pragma once

#include "Base.h"
#include "Window.h"

#include "Motus/Events/Event.h"
#include "Motus/Events/ApplicationEvent.h"

#include "LayerStack.h"

#include <Motus/ImGui/ImGUILayer.h>

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
		bool OnWindowResize(WindowResizeEvent& event);

	private: // Data
		bool m_IsRunning = true;
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;
	private:
		static Application* m_Instance;
	};

	Application* CreateApplication();
}
