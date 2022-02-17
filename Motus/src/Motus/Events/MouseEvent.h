#pragma once
#include "Event.h"
#include <stdint.h>

// TODO: Implement Mouse Event classes

namespace Motus {
	class MOTUS_API MouseMovedEvent : public Event {
	public:
		// Constructor
		MouseMovedEvent(uint16_t x, uint16_t y) 
			: m_PositionX(x), m_PositionY(y) {}

		// Methods
		std::string GetLogInfo() const  override {
			return std::string("MouseMovedEvent: ") + std::to_string(m_PositionX) + ", " + std::to_string(m_PositionY);
		}

		inline uint16_t GetX() const { return m_PositionX; }
		inline uint16_t GetY() const { return m_PositionY; }

		// Setting event type and category
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(MouseEventCategory | ApplicationEventCategory)
	private:
		uint16_t m_PositionX, m_PositionY;
	};

	class MOTUS_API MouseScrolledEvent : public Event {
	public:
		// Constructor
		MouseScrolledEvent(uint16_t xoffset, uint16_t yoffset)
			: m_OffsetX(xoffset), m_OffsetY(yoffset) {}
		
		// Methods
		std::string GetLogInfo() const override {
			return std::string("MouseScrolledEvent: ") + std::to_string(m_OffsetX) + ", " + std::to_string(m_OffsetY);
		}
		
		inline uint16_t GetX() const { return m_OffsetX; }
		inline uint16_t GetY() const { return m_OffsetY; }

		// Setting event type and category
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(MouseEventCategory | ApplicationEventCategory)
	private:
		uint16_t m_OffsetX, m_OffsetY;
	};

	class MOTUS_API MouseButtonPressedEvent : public Event {
	public:
		// Constructor
		MouseButtonPressedEvent(int keycode)
		: m_KeyCode(keycode){}

		// Methods
		std::string GetLogInfo() const override {
			return std::string("MouseButtonPressedEvent: ") + std::to_string(m_KeyCode);
		}

		inline int GetKeyCode() const { return m_KeyCode; }

		// Setting event type and category
		EVENT_CLASS_TYPE(MouseButtonPressed)
		EVENT_CLASS_CATEGORY(MouseEventCategory | ApplicationEventCategory)
	private:
		int m_KeyCode;
	};

	class MOTUS_API MouseButtonReleasedEvent : public Event {
	public:
		// Constructor
		MouseButtonReleasedEvent(int keycode)
			: m_KeyCode(keycode) {}

		// Methods
		std::string GetLogInfo() const override {
			return std::string("MouseButtonReleasedEvent: ") + std::to_string(m_KeyCode);
		}

		inline int GetKeyCode() const { return m_KeyCode; }

		// Setting event type and category
		EVENT_CLASS_TYPE(MouseButtonReleased)
		EVENT_CLASS_CATEGORY(MouseEventCategory | ApplicationEventCategory)
	private:
		int m_KeyCode;
	};



}