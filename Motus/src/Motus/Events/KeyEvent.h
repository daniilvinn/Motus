#pragma once
#include "Event.h"
#include <sstream>

namespace Motus {
	// Abstract Key Event class implementation
	class MOTUS_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return m_KeyCode; };
		EVENT_CLASS_CATEGORY(InputEventCategory | KeyboardEventCategory)
		KeyEvent(int keycode) : m_KeyCode(keycode) {}
		int m_KeyCode;
	};

	class MOTUS_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount) {}
		inline int GetRepeatCount() const { return m_RepeatCount; }
		std::string GetLogInfo() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: Key Code(" << m_KeyCode << "), Repeat Count(" << m_RepeatCount << ")";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class MOTUS_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {};
		std::string GetLogInfo() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: Key Code(" << m_KeyCode << ")";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)
	};

	class MOTUS_API KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(int keycode) : KeyEvent(keycode){}
		std::string GetLogInfo() const override {
			std::stringstream ss;
			ss << "KeyTypedEvent: Key Code(" << m_KeyCode << ")";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyTyped)
	};

}