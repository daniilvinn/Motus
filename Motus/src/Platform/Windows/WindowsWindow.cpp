#include "motus_pch.h"
#include "WindowsWindow.h"

#include "Motus/Events/ApplicationEvent.h"
#include "Motus/Events/KeyEvent.h"
#include "Motus/Events/MouseEvent.h"

namespace Motus {

	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		MT_CORE_ERROR("GLFW Error({0}): {1}", error, description);
	}

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

		// GLFW callbacks setup
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			data.width = width;
			data.height = height;

			WindowResizeEvent event(width, height);

			glViewport(0, 0, width, height);

			data.EventCallback(event);
			});				// Window Resize
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
			});										// Window Close
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
			case GLFW_PRESS: {
				KeyPressedEvent event(key, 0);
				data.EventCallback(event);
				break;
			}
			case GLFW_REPEAT: {
				KeyPressedEvent event(key, 1);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE: {
				KeyReleasedEvent event(key);
				data.EventCallback(event);
				break;
			}
			default: {
				MT_CORE_ASSERT(false, "Invalid keyboard event action type");
				break;
			}
			}

			}); // Keyboard
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event(xpos, ypos);
			data.EventCallback(event);
			});				// Mouse Moved
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
			case GLFW_PRESS: 
			{
				MouseButtonPressedEvent event(button);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
				break;
			}
			
			default: {
				MT_CORE_ASSERT(false, "Invalid mouse event action type");
				break; 
			}
			}
		});	// Mouse Button
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event(xoffset, yoffset);
			data.EventCallback(event);
		});			// Scroll 
		glfwSetErrorCallback(GLFWErrorCallback);																	// Error cb

	}

	void WindowsWindow::Shutdown() {
		// ISSUE: causes GLFW error (GLFW library is not initialized) on window close
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