#pragma once
#include <Motus/Core.h>

#include <string>
#include <functional>

namespace Motus {


	// All possible event types
	enum class EventType {
		None = 0,
		WindowClose, WindowMoved, WindowResize, WindowFocus, WindowUnfocus,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// All possible event categories, stored as bit value to be able to 
	// store event with 2 or more categories in one `int` variable.
	enum EventCategory {
		None = 0,
		ApplicationEventCategory	= BIT(1),
		InputEventCategory			= BIT(2),
		KeyboardEventCategory		= BIT(3),
		MouseEventCategory			= BIT(4)
	};

// Macros to minimize code further
#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetEventName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetEventCategoryFlags() const override { return category; }
// ===============================



	// Event base class
	class MOTUS_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual int GetEventCategoryFlags() const = 0;

		// DEBUG ONLY methods.
		// TODO: disable these methods in all builds except Debug
		virtual const char* GetEventName() const = 0;
		virtual std::string GetLogInfo() const { return GetEventName(); };
		// ======================================================
		
		inline bool IsInCategory(EventCategory category) {
			return GetEventCategoryFlags() & category;
		}

	protected:
		bool m_IsHandled = false;
	};


	// Event Dispatcher Class implementation 
	class EventDispatcher
	{
		template <typename T>
		using EventFunction = std::function<bool(T&)>;
	public:
		// Constructor
		EventDispatcher(Event& event)
			: m_Event(event) {}

		// F will be deduced by the compiler
		template<typename T>
		bool Dispatch(EventFunction<T> function)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_IsHandled |= function(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& outputStream, const Event& event) {
		return outputStream << event.GetLogInfo();
	};




} // namespace Motus