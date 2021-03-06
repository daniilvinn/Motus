#pragma once
#include "Motus/Core/Window.h"
#include <GLFW/glfw3.h>

namespace Motus {

	// Windows window class implementation
	class MOTUS_API WindowsWindow : public Window
	{
	public:
		// Constructor / Destructor
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();
		// Update methods
		void OnUpdate() override;

		// Getters / setters
		inline uint16_t GetWidth()  const override { return m_Data.width; }
		inline uint16_t GetHeight() const override { return m_Data.height; }
		inline std::string GetTitle() const override { return m_Data.title; }
		void* GetNative() override;
		inline GraphicsAPIContext* GetContext() override { return m_Context; };
		void SetEventCallbackFunc(const EventCallbackFunc& func) override { m_Data.EventCallback = func; };

		// VSync control methods
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();
	private:

		struct WindowData {
			std::string title;
			uint16_t width;
			uint16_t height;
			bool VSync;

			EventCallbackFunc EventCallback;
		};

		GraphicsAPIContext* m_Context;
		WindowData m_Data;
		GLFWwindow* m_Window;
	};

}