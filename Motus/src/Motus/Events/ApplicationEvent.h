#pragma once
#include "Event.h"
#include <sstream>

namespace Motus {
	// Window Resize Event implementation
	class MOTUS_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_WindowWidth(width), m_WindowHeight(height) {}

		std::string GetLogInfo() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_WindowWidth << ", " << m_WindowHeight;
			return ss.str();
		}

		inline unsigned int GetWindowWidth() const {
			return m_WindowWidth;
		}

		inline unsigned int GetWindowHeight() const {
			return m_WindowHeight;
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(ApplicationEventCategory)
	private:
		unsigned int m_WindowWidth;
		unsigned int m_WindowHeight;
	};

	// Window Close Event implementation
	class MOTUS_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() = default;
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(ApplicationEventCategory)
	};

	// Application Render Event implementation
	class MOTUS_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() = default;
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(ApplicationEventCategory)
	};

	// Application Update Event implementation
	class MOTUS_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() = default;
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(ApplicationEventCategory)
	};

	// Application On Tick Event implementation
	class MOTUS_API AppTickEvent : public Event {
	public:
		AppTickEvent() = default;
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(ApplicationEventCategory)
	};

} // namespace Motus