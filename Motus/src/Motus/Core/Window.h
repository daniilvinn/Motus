#pragma once

#include "Base.h"
#include "Motus/Events/Event.h"
#include "Motus/Renderer/Context.h"

namespace Motus {

	struct WindowProperties {
		std::string m_Title;
		uint16_t m_WindowWidth;
		uint16_t m_WindowHeight;

		WindowProperties(
			const std::string& title = "Motus Engine", 
			uint16_t width = 1600, 
			uint16_t height = 900
		) : m_Title(title), m_WindowWidth(width), m_WindowHeight(height) {}

	};


	// Desktop Window interface class declaration.
	class MOTUS_API Window
	{
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual ~Window();

		virtual void OnUpdate() = 0;

		virtual void SetEventCallbackFunc(const EventCallbackFunc& callback) = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		// Get Window Properties 
		virtual inline uint16_t GetWidth() const = 0;
		virtual inline uint16_t GetHeight() const = 0;
		virtual inline std::string GetTitle() const = 0;
		virtual inline GraphicsAPIContext* GetContext() = 0;
		virtual void* GetNative() = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};
}