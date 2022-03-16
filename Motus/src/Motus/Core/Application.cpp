#include "motus_pch.h"

#include "Application.h"
#include "Logger.h"
#include "Motus/ImGui/ImGUILayer.h"

#include <glad/glad.h>


namespace Motus {

	Application* Application::m_Instance = nullptr;

	Application::Application() 
	{
		MT_CORE_ASSERT(!m_Instance, "Application already exsists!");
		m_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create(WindowProperties()));
		m_Window->SetEventCallbackFunc(MT_BIND_EVENT_FUNCTION(Application::OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application() 
	{
		
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			//glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_ImGuiLayer->ImGuiBegin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->ImGuiEnd();

			m_Window->OnUpdate();
		}
	}

	void Application::Shutdown()
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(MT_BIND_EVENT_FUNCTION(Application::OnWindowClosed));

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