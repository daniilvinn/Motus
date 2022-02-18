#include "motus_pch.h"
#include "WindowsWindow.h"

namespace Motus{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProperties& props) {
		return new WindowsWindow(props);
	};

	WindowsWindow::WindowsWindow(const WindowProperties& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}
	
	void WindowsWindow::Init(const WindowProperties& props) {
		m_Data.title = props.m_Title;
		m_Data.width = props.m_WindowWidth;
		m_Data.height = props.m_WindowHeight;

		MT_CORE_INFO("Creating window {0} ({1}, {2})", props.m_Title, props.m_WindowWidth, props.m_WindowHeight);

		if (!s_GLFWInitialized) {
			int InitValide = glfwInit();
			MT_CORE_ASSERT(InitValide, "Failed to initialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(
			static_cast<int>(props.m_WindowWidth),
			static_cast<int>(props.m_WindowHeight),
			props.m_Title.c_str(),
			nullptr,
			nullptr
		);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled)	glfwSwapInterval(1);
		else			glfwSwapInterval(0);
		m_Data.VSync =	enabled;
	}

	bool WindowsWindow::IsVSync() const {
		return m_Data.VSync;
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

}